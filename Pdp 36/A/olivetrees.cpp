#include <bits/stdc++.h>

std::stack<long long> mst;
std::vector<long long> heights;
long long N = 0, M = 0, res = -1, temp = 0, height = 0, cur = 0, cur_scanf = 0;

int main()
{
    freopen("olivetrees.in", "r", stdin);
    freopen("olivetrees.out", "w", stdout);
    scanf("%lld %lld", &N, &M);

    heights.push_back(0);
    for(long long i = 0; i < M; ++i){
        scanf("%lld", &cur_scanf);
        heights.push_back(N-cur_scanf);
    } 
    heights.push_back(0);
    
    mst.push(0);
    for(long long i = 1; i <= M + 1; ++i){
        while(mst.size() > 1 && heights[mst.top()] >= heights[i]){
            cur = mst.top();
            mst.pop();
            res = std::max(res, heights[cur] * (i - mst.top() - 1));
        }
        mst.push(i);
    }
    printf("%lld", res);
    return 0;
}

