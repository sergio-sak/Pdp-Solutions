#include <bits/stdc++.h>

int main()
{
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    int N, count = 1, max_height;
    scanf("%d", &N);
    std::vector<int> heights(N+1);
    for(int i = 1; i <= N; ++i)
        {
            scanf("%d", &heights[i]);
        }
    max_height = heights[heights.size()-1];
    for(int i = heights.size()-1; i > 0; --i)
        {
            if(heights[i-1] > max_height)
                {
                    count++;
                    max_height = heights[i-1];
                }
        }
    printf("%d", count);
    return 0;
}