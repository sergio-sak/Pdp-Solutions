#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pl;

ll N;
long double a, b, c;
std::vector<std::pair<long double, long long>> efficiencies;

bool compare(std::pair<long double, long long> a, std::pair<long double, long long> b)
{
    if (std::fabs(a.first - b.first) < 1e-9)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    #ifdef CONTEST
        freopen("hydrocarbons.in", "r", stdin);
        freopen("hydrocarbons.out", "w", stdout);
    #else
        freopen("hydrocarbons.in1", "r", stdin);
    #endif
    
    scanf("%lld", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%Lf %Lf %Lf", &a, &b, &c);
        long double efficiency = a - a * (b / 3000) - c * a/40;
        if(efficiency > 0 && std::fabs(efficiency) > 0.000001){
            efficiencies.push_back(std::make_pair(efficiency, i));
        }
    }
    std::sort(efficiencies.begin(), efficiencies.end(), compare);
    printf("%d\n", efficiencies.size());
    for(int i = efficiencies.size() - 1; i >= 0; --i)
    {
        printf("%lld ", efficiencies[i].second);
    }
    return 0;
}
