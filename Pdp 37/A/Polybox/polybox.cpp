#include <cstdio>

long long N, perimeter, oldW, W, H;

signed main()
{
    scanf("%lld", &N);
    scanf("%lld", &N);

    for(int i = 1; i <= N; ++i) {
        scanf("%lld %lld", &W, &H);
        perimeter += (H + H);
        perimeter += (W >= oldW) ? W - oldW : oldW - W;    
        oldW = W;
    }
    perimeter += W;
    
    printf("%lld\n", perimeter);
    return 0;
}