#include <bits/stdc++.h>

long long count = 0, N, efficiency;
long double a, b, c; 
std::vector<std::pair<long long,long long>> result;

bool comp(std::pair<long long,long long> p1, std::pair<long long,long long> p2){
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

int main()
{
    #ifndef CONTEST
        freopen("hydrocarbons.in1", "r", stdin);
    #endif

    #ifdef CONTEST
        freopen("hydrocarbons.in", "r", stdin);
        freopen("hydrocarbons.out", "w", stdout);
    #endif

    scanf("%lld", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%Lf %Lf %Lf", &a, &b, &c);
        efficiency = (int)a - a * (b / 3000.0) - c * a / 40.0;
        if(efficiency >0){
            result.push_back(std::make_pair(i, efficiency));
            count++;
        }
    }
    std::sort(result.begin(), result.end(), comp);
    printf("%lld\n", count);
    for(const auto &element : result)
        {
            printf("%lld ", element);
        }
    return 0;
}
