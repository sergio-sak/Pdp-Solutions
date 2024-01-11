#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, temp, max1_1 = -1, max1_2 = -1, max2_1 = -1, max2_2 = -1, indx1, indx2;
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
        if(max1_1<max2sum[i]-i){
            max1_1 = max2sum[i]-i;
            indx1 = i;
        }
        if(max2_1<max2sum[i]+i){
            max2_1 = max2sum[i]+i;
            indx2 = i;
        }
    }

    for(int i = 0; i < N; i++){
        if(i!=indx1 && max1_2<max2sum[i]+i)
            max1_2 = max2sum[i]+i;

        if(i!=indx2 && max2_2<max2sum[i]-i)
            max2_2 = max2sum[i]-i;
    }
    printf("%lld\n", std::max(max1_1+max1_2, max2_1+max2_2));
    return 0;
}
