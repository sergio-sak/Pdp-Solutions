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

std::vector<char> odds;
std::string str;
mcll freq;
char chr;
ll N, T;

bool check_symmetry() {
    return true;
}

int main()
{
    #ifdef CONTEST
        freopen("symstr.in", "r", stdin);
        freopen("symstr.out", "w", stdout);
    #else
        freopen("symstr.in", "r", stdin);
    #endif
    scanf("%lld %lld\n", &T, &N);

    while(T--) {
        std::getline(std::cin, str);
        FOR(i, 0, str.size()) {
            freq[str[i]]++;
        }
        FOR(i, 'A', 'Z') {
            if(freq[i] % 2 == 1) odds.pb(i);
        }
        if(odds.size() % 2 == 1){
            printf("0\n");
            continue;
        }
        else {
            
        }
        
        printf("1\n");
        freq.clear();
    }
    return 0;
}
