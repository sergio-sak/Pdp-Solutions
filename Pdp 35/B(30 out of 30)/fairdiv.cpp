/* USER: sakellaropoulos35pdp 
LANG: C++ 
TASK: fairdiv */  
  
#include <bits/stdc++.h>  
  
using namespace std;  
  
const int Max_Number = 1e6+5;  
  
int N, A[Max_Number], sum[Max_Number], a, b, c, temporary_a, temporary_b, temporary_c , temporary_right = 0;  
  
void abc_calc(int function_right, int function_left)  
    {  
        a = sum[function_left];  
        b = sum[function_right] - sum[function_left];  
        c = sum[N]-sum[function_right] ;  
    }  
  
int main()  
    {  
        freopen("fairdiv.in", "r", stdin);  
        scanf("%d", &N);  
  
        for(int i = 1; i <= N; i++)  
            {  
                scanf("%d", &A[i]);  
                sum[i] = sum[i - 1] + A[i];  
            }  
  
        int left = N, right = N;  
  
        abc_calc(right, left);  
  
        for(left = N; left >= 1; left--)  
            {  
                do  
                    {  
                        temporary_right = right;  
                        right--;  
                    }  
                while (sum[N] - sum[right] < sum[right] - sum[left] && right>=left);  
  
                if (sum[right] - sum[left] < sum[N] - sum[right])  
                    {  
                        right = temporary_right;  
                    }  
  
                if(sum[left] >= sum[right] - sum[left] && right >= left)  
                    {  
                        abc_calc(right, left);  
                    }  
            }  
        freopen("fairdiv.out", "w", stdout);  
        printf("%d %d %d", a, b, c);  
    }  
