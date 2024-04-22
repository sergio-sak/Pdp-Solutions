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

std::deque<int> q;
vi nums, minwind, maxwind, ans;
int N, M, C, num;

int main()
{
    #ifdef CONTEST //This code is the worst code ive ever written
        freopen("sound.in", "r", stdin); 
        freopen("sound.out", "w", stdout);
    #else
        freopen("sound.in", "r", stdin);
    #endif
    
    scanf("%d %d %d\n", &N, &M, &C);

    FOR(i, 0, N) {
        scanf("%d", &num);
        nums.pb(num);
    }

    for(int i = 0; i < M; ++i) {
        while(!q.empty() && nums[i] < nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    for(int i = M; i < nums.size(); ++i) {
        minwind.push_back(nums[q.front()]);
        if(q.front() <= i - M) q.pop_front();
        while(!q.empty() && nums[i] < nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    minwind.push_back(nums[q.front()]);

    while(!q.empty()) {
        q.pop_front();
    }

    for(int i = 0; i < M; ++i) {
        while(!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    for(int i = M; i < nums.size(); ++i) {
        maxwind.push_back(nums[q.front()]);
        if(q.front() <= i - M) q.pop_front();
        while(!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    maxwind.push_back(nums[q.front()]);

    FOR(i, 1, maxwind.size()+1) {
        if(maxwind[i-1] - minwind[i-1] <= C){
            ans.pb(i);
        }
    }
    if(ans.size() == 0) {
        printf("NULL");
    }
    else {
        for(int el : ans) {
            printf("%d\n", el);
        }
    }
    return 0;
}
