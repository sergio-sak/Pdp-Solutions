#include <bits/stdc++.h>

int M, N, K, temp = 0, max = 0, count = 0, rem = 0, index_of_max;

int main()
{
    freopen("voting.in", "r", stdin); scanf("%d %d %d", &N, &M, &K);
    std::vector<int> v, freq(M);
    rem = N - K;
    v.push_back(0); freq.push_back(0);

    for(int i = 1; i <= K; ++i)
        {
            scanf("%d", &temp);
            v.push_back(temp);
            freq[v[i]]++;
        }
    for(int i = 1; i <= M; ++i)
        {
            if(freq[i] > max){
                max = freq[i];
                index_of_max = i;
            }
        }
    for(int i = 1; i <= M; ++i)
        {
            
            if(freq[i] + rem > max){
                count++;
            }
            else if(freq[i] + rem == max && i == index_of_max && rem == 0)
                count++;
        }
    freopen("voting.out", "w", stdout);
    std::cout<<count<<"\n";
    return 0;
}