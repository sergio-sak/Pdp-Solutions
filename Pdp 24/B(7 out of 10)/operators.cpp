#include <bits/stdc++.h>

long N, low_neg = 0, low_pos = 0, num, min = 1000000,count = 0, ans1, ans2;
std::vector<long> nums(1, -1000000);
int main()
{
    #ifdef CONTEST
        freopen("operators.in", "r", stdin);
        freopen("operators.out", "w", stdout);
    #else
        freopen("Files/operators.in3", "r", stdin);
    #endif
    
    scanf("%ld", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%ld", &num);
        nums.push_back(num);
        if(num > nums[low_neg] && num < 0)
            low_neg = i;
        else if(num < -1*nums[low_pos] && num > 0)
            low_pos = i;
    }
    std::cout<<low_neg<<" "<<low_pos<<std::endl;
    for(int i = low_neg; i >= 1; --i){
        for(int j = low_pos; j <= N; ++j){
            if(std::abs(nums[i]) >= std::abs(nums[j])){
                if(std::abs(nums[i])-std::abs(nums[j]) <= min){
                    ans1 = nums[i];
                    ans2 = nums[j];
                    min = std::abs(nums[i])-std::abs(nums[j]);
                }
            }

            else if(std::abs(nums[i])<std::abs(nums[j])){
                if(std::abs(nums[j])-std::abs(nums[i]) <= min){
                    ans1 = nums[i];
                    ans2 = nums[j];
                    min = std::abs(nums[j])-std::abs(nums[i]);
                }
            }         
        }
    }
    if(ans1>ans2)
        std::swap(ans1, ans2);
    printf("%ld %ld\n", ans1, ans2);
    return 0;
}
// std::cout<<low_neg<<" "<<low_pos;
// if(nums[i] == -11 && nums[j] == 11){
//                 std::cout<<std::abs(nums[i]) - std::abs(nums[j]);
//                 std::cout<<min;
//                 std::cout<<"HEakdlsj"<<std::endl;
// }
