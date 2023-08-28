#include <bits/stdc++.h>

long N, K, count = 1;
std::vector<double> pointsv1(1);
double temp, sum = 0, average1, average2;

int main()
{   
    #ifdef CONTEST
        freopen("ensemble.in", "r", stdin);
        freopen("ensemble.out", "w", stdout);
    #else
        freopen("Files/ensemble.in6", "r", stdin);
    #endif
    scanf("%ld %ld", &N, &K);
    for(int i = 1; i <= N; ++i){
        scanf("%lf", &temp);
        pointsv1.push_back(temp);
    }
    std::sort(pointsv1.begin(), pointsv1.end());
    std::vector<double> pointsv2(pointsv1.begin(), pointsv1.end());
    for(int i = K+1; i <= N - K; ++i){
        sum += pointsv1[i];
        if(count <= K+1){
            pointsv2[count] = pointsv2[K+1];
            count++;
        }
        if (count == K+1)
        {
            count = N - K;
        }
        if (count <= N && count > K+1)
        {
            pointsv2[count] = pointsv2[N-K];
            count++;
        }
    }
    average1 = sum/(N-2*K);
    sum = 0;
    for(int i = 1; i <= N; ++i){
        sum+=pointsv2[i];
    }
    average2 = sum/N;
    printf("%.2lf %.2lf\n", average1, average2);
    return 0;
}
