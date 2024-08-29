#include <cstdio>
int N, maxdiff = -0xf, max = -0xf, num;

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &num);
        max = (max < num) ? num : max;
        maxdiff = (maxdiff < max - num) ? max - num : maxdiff;
    }

    printf("%d\n", maxdiff);
    return 0;
}
