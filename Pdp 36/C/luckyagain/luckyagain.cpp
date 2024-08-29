#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
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
typedef std::string sr;
typedef std::set<int> si;
typedef std::set<ll> sll;
typedef std::unordered_map<int , int> mii;
typedef std::unordered_map<ll , ll> mllll;
typedef std::unordered_map<char , int> mci;
typedef std::unordered_map<char , ll> mcll;

ll N, ans, num;
sr str1, str2, temp_str; 
std::vector<sr> odd, even;
mllll oddh, evenh; //odd/even Hmap

ll str_sum(sr str) {
    ll sum = 0;
    for(int i = 0; i < str.size(); ++i) {
        sum += str[i] - '0';
    }
    return sum;
}

bool comp(sr s1, sr s2) {
    return std::stoi(s1) > std::stoi(s2);
}

int main()
{
    #ifdef CONTEST
        freopen("luckyagain.in", "r", stdin);
        freopen("luckyagain.out", "w", stdout);
    #else
        freopen("luckyagain.in1", "r", stdin);
    #endif
    scanf("%lld", &N);

    FOR(i, 0, N) {
        scanf("%lld", &num);
        temp_str = std::to_string(num);
        if(temp_str.size()&1){
            odd.pb(temp_str);
            oddh[str_sum(temp_str)]++;
        }
        else {
            even.pb(temp_str);
            evenh[str_sum(temp_str)]++;
        }
    }

    std::sort(all(odd), comp);
    std::sort(all(even), comp);
    
    ll curtotalsum = 0, cursum = 0;

    for(sr cur : odd) {
        curtotalsum = str_sum(cur); cursum = 0; oddh[curtotalsum]--;

        //Odd Normal
        FOR(i, 0, cur.size()/2) {
            cursum += cur[i] - '0';
        }
        
        FOR(i, cur.size()/2, cur.size()) {
            cursum += cur[i] - '0';
            if(cur[i] == '0' && i == cur.size()-1)
                continue;
            if(oddh.find(cursum - (curtotalsum-cursum)) != oddh.end())
                ans += oddh[cursum - (curtotalsum-cursum)];
        }

        cursum = 0;
        //Odd reverse
        for(int i = cur.size()-1; i > cur.size()/2; --i) {
            cursum += cur[i] - '0';
        }

        for(int i =  cur.size()/2; i >= 0; --i) {
            cursum += cur[i] - '0';
            if(cur[i] == '0' && i == 0)
                continue;
            if(oddh.find(cursum - (curtotalsum-cursum)) != oddh.end())
                ans += oddh[cursum - (curtotalsum-cursum)];
        }
    }

    for(sr cur : even) {
        curtotalsum = str_sum(cur); cursum = 0; evenh[curtotalsum]--;
        
        //Even Normal
        FOR(i, 0, cur.size()/2) {
            cursum += cur[i] - '0';
        }
        
        FOR(i, cur.size()/2, cur.size()) {
            cursum += cur[i] - '0';
            if(evenh.find(cursum - (curtotalsum-cursum)) != evenh.end())
                ans += evenh[cursum - (curtotalsum-cursum)];
        }

        //Even Reverse
        cursum = 0;
        for(int i = cur.size()-1; i > cur.size()/2; --i) {
            cursum += cur[i] - '0';
        }
        for(int i =  cur.size()/2; i >= 0; --i) {
            cursum += cur[i] - '0';
            if(evenh.find(cursum - (curtotalsum-cursum)) != evenh.end())
                ans += evenh[cursum - (curtotalsum-cursum)];
        }
    }
    printf("%lld\n", ans);
    return 0;
}