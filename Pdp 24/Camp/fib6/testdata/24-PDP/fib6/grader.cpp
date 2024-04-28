#include <cstdio>
#include <cstdlib>
#include <cstring>

int isfib (int a)
{
  if (a == 0 || a == 1)
    return 1;
  int x = 1, y = 2;
  while (y < a) {
    int t = y;
    y = y + x;
    x = t;
  }
  return y == a;
}

int main(void) {
	FILE *in = fopen("fib6.in", "r");
	FILE *usersol = fopen("fib6.out", "r");
	FILE *info = fopen("fib6.info", "r");
	FILE *ans = fopen("fib6.ans", "w");

        int X;
	fscanf(in, "%d", &X);
        int count;
        if (fscanf(info, "%d", &count) == 0)
          count = -1;
        if (count < 0) {
          char buffer[64];
          fgets(buffer, 64, usersol);
          if (strcmp(buffer, "impossible\n") == 0)
            fprintf(ans, "1\n");
          else
            fprintf(ans, "0\n");
        }
        else {
          int n;
          if (fscanf(usersol, "%d", &n) == 1 && n == count) {
            int sum=0;
            for (int i=0; i<n; i++) {
              int a;
              if (fscanf(usersol, "%d", &a) != 1 || !isfib(a)) {
                fprintf(ans, "0\n");
                break;
              }
              sum += a;
            }
            if (sum == X)
              fprintf(ans, "1\n");
            else
              fprintf(ans, "0\n");
          }
          else
            fprintf(ans, "0\n");          
        }

	fclose(in);
	fclose(usersol);
	fclose(info);
	fclose(ans);

	return 0;
}
