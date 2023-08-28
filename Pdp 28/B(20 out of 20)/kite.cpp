#include <bits/stdc++.h>

long long left=0, right=1, N, K, temp, result = 0;
bool y = false;

int main()
{
    freopen("kite.in", "r", stdin); scanf("%d %d", &N, &K);

    std::vector<long>M, sum;
    M.push_back(0);
    sum.push_back(0);

    for(int i = 1; i <= N; i++)
        {
            scanf("%d", &temp);
            M.push_back(temp);
            sum.push_back(sum[i-1]+M[i]);  
        }
    
    do
        {
            if(sum[right]-sum[left]>K){
                left++;
            }
            else if(sum[right]-sum[left]<K){
                right++;
            }
            else{
                if(y == false){
                    result = right - left;
                    y = true;
                }
                if(right - left < result)
                    result = right - left;
                left++;
            }      
        } 
    while (right<=N&&left<=right);
    freopen("kite.out", "w", stdout);
    printf("%d\n", result);
    return 0;
}