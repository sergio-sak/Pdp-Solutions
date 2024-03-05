#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("testcases/chemicals.in1","r",stdin);
    freopen("chemicals.out","w",stdout);

    long long n,k;
    scanf("%lld %lld",&n,&k);
    vector <long long> a(n + 1);
    for (long long i = 1; i <= n; ++i) scanf("%lld",&a[i]);
    unordered_map <long long,long long> rems;
    long long i = 1;
    long long j = 1;
    long long ans = 0;
    while (j <= n)
    {
        long long x = (k - (a[j] % k)) % k;
        if (rems[x] > 0)
        {
            rems[a[i] % k]--;
            i++;
        }
        else
        {
            ans = max(ans,j - i + 1);
            j++;
            if (j <= n) rems[a[j] % k]++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}