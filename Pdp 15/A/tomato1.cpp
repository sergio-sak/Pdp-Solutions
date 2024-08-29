#include <cstdio>

#define si(n) scanf("%d", &n);

int N, M, D, rightmost = 0, ans;

signed main()
{
    si(N); si(M); si(D);

    for(int i = 0; i < M; ++i) {
        int unripe; si(unripe);
        if(unripe - D <= rightmost) {
            ans += unripe-rightmost;
            if(unripe + D > N) ans += N-unripe;
            else if(unripe + D <= rightmost) ans += unripe + D - rightmost, rightmost = unripe + D;
            else if(unripe + D <= N) {ans += D; rightmost = unripe + D;}
            continue;
        }
        if(unripe + D > N) ans += N-unripe;
        else if(unripe + D <= rightmost) ans += unripe + D - rightmost, rightmost = unripe + D;
        else if(unripe - D > rightmost && unripe + D <= N) {
            ans += 2*D + 1;
            rightmost = unripe + D;
        }
        // printf("%hu\n", ans);
    }

    printf("%d\n", N-ans);
    return 0;
}
