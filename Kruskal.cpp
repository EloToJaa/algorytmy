#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (b); i >= (a); --i)
#define TRAV(x,T) for(auto& x: (T))
#define ALL(T) T.begin(), T.end()
#define TAB(T,a,b) (T)+a, (T)+((b)+1)
#define VAR(x) #x<<" = "<<x<<" " 
#define sz(x) (int)(x).size()
#define nwd __gcd
#define pb push_back
#define st first
#define nd second
#define lc (v<<1)
#define rc (v<<1|1)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define deb if(0)
const int N = 1e6, NT = N + 2;

int REP[NT], ILE[NT];

void Init(int n) {
    FOR(i, 1, n) {
        REP[i] = i;
        ILE[i] = 1;
    }
}

void Union(int a, int b) { // O(1)
    if(ILE[a] > ILE[b]) swap(a, b);
    REP[a] = b;
    ILE[b] += ILE[a];
}

int Find(int a) { // O(stala ackermana)
    if(REP[a] != a) REP[a] = Find(REP[a]);
    return REP[a];
}

struct Edge {
    int a, b, w;
} K[NT];

void Kruskal(int n, int m) {
    Init(n);
    sort(TAB(K, 1, m), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });
    int a, b;
    FOR(i, 1, m) {
        a = Find(K[i].a);
        b = Find(K[i].b);
        if(a != b) {
            Union(a, b);
        }
    }
}