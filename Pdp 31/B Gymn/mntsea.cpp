#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define INF 1000000000
#define MAXN 1000005
#define EPS 1e-9

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pllll;
typedef std::set<int> si;
typedef std::set<ll> sll;
typedef std::unordered_map<int , int> mii;
typedef std::unordered_map<ll , ll> mllll;
typedef std::unordered_map<char , int> mci;
typedef std::unordered_map<char , ll> mcll;

mii hmap;
int N, ms;
unsigned long long ans;
char chr;

unsigned long long bc(ll n, ll k) {
    if (k > n - k) 
        k = n - k;
    int c = 1;
    for (int i = 0; i < k; ++i) {
        c = c * (n - i) / (i + 1);
    }
    return c;
}


int main()
{
    #ifdef CONTEST
        freopen("mntsea.in", "r", stdin);
        freopen("mntsea.out", "w", stdout);
    #else
        freopen("mntsea.in", "r", stdin);
    #endif
    scanf("%lld\n", &N);
    
    hmap[0]++;
    for(int i = 0; i < N; ++i){
        scanf("%c ", &chr);
        if(chr == 'm') ms++;
        else ms--;
        hmap[ms]++;
    }

    for(auto el : hmap) {
        if(el.second != 1) {
            ans += bc(el.second, 2);
        }
    }

    printf("%lld\n", ans);
    return 0;
}
