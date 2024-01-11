#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, temp, max1 = -1, max2 = -1, indx;
vll max2sum;

int main()
{
    #ifdef CONTEST
        freopen("max2sum.in", "r", stdin);
        freopen("max2sum.out", "w", stdout);
    #else
        freopen("max2sum.in", "r", stdin);
    #endif
    
    scanf("%lld", &N);

    for(int i = 0; i < N; i++){
        scanf("%lld", &temp);
        max2sum.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        if(max1<max2sum[i]-i){
            max1 = max2sum[i]-i;
            indx = i;
        }
    }

    for(int i = 0; i < N; i++){
        if(i!=indx && max2<max2sum[i]+i)
            max2 = max2sum[i]+i;
    }
    printf("%lld\n", max1+max2);
    return 0;
}
