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

ll N, left = 1, right;
char chr;
std::string s1 = "-", s2 = "-";

int main()
{
    #ifdef CONTEST
        freopen("dnaseq.in", "r", stdin);
        freopen("dnaseq.out", "w", stdout);
    #else
        freopen("dnaseq.in", "r", stdin);
    #endif
    scanf("%lld\n", &N);

    FOR(i, 0, N) {
        chr = getchar();
        s1 += chr;
    }

    getchar();

    FOR(i, 0, N) {
       chr = getchar();
        s2 += chr;
    }

    right = N;
    while(left <= N) {
        if(s1[left] != s2[left]) break;
        left++;
    }

    while(right >= 1) {
        if(s1[right] != s2[right]) break;
        right--;
    }

    for(int i = left; i <= right; ++i) {
        if(s1[i] != s2[right - i + left]) {
            printf("no\n");
            return 0;
        }
    }

    if(left > right) printf("0");
    else printf("%lld\n", right-left);
    return 0;
}
