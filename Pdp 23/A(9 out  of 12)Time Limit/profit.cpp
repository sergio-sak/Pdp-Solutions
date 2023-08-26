#include <bits/stdc++.h>

int N, left = 1, right = 0;
float max = 0;
std::vector<float> prices;

int main()
{
    freopen("profit.in1", "r", stdin);
    #ifdef CONTEST
    freopen("profit.out", "w", stdout);
    #endif
    
    prices.push_back(0);
    scanf("%d", &N);
    
    for(int i = 1; i <= N; ++i){
            prices.push_back(0);
            scanf("%f",  &prices[i]);
    }
    right = prices.size()-1;
    do{
        if(prices[right]/prices[left] > max)
            max = prices[right]/prices[left];
        left++;
        if(left==right){
            right--;
            left = 1;
        }
    }while(right!=1);
    printf("%.3f\n", max);
    return 0;
}