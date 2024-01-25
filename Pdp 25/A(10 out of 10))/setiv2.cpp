#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N, temp, indx = 1;
std::vector<float> nums;
vll res;

int main()
{
    #ifdef CONTEST
        freopen("seti.in", "r", stdin);
        freopen("seti.out", "w", stdout);
    #else
        freopen("Files/seti.in1", "r", stdin);
    #endif
    
    scanf("%lld", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &temp);
        nums.push_back(1.0*temp);
    }

    for(int i = 0; i < N; i++){
        //std::cout<<nums[i]<<" ";
        while (indx+i < N && i - indx >= 0){
            if(nums[i + indx] == nums[i - indx] && nums[i + indx] < (1.0*nums[i])/2){
                //std::cout<<"\t"<<nums[i-indx]<<" "<<i-indx<<" "<<nums[i+indx]<<" "<<i+indx<<"\n";
                res.push_back(i+1);
                break;
            }
            indx++;
        }
        indx = 1;
    }
    printf("%lld\n", res.size());
    for(auto i : res)
        printf("%lld\n", i);
    return 0;
}
