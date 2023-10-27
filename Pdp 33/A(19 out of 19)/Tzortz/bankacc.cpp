#include <bits/stdc++.h>
using namespace std;

int N,templog,tempcash;
unordered_map<int,int> A; 
char c;
int main()
{
    freopen("bankacc.in", "r", stdin);
    freopen("bankacc.out", "w", stdout);
    scanf("%d", &N);
    
    for (int i = 1; i<=N; ++i){
        scanf(" %c", &c);
        if (c == 'd') {
            scanf("%d %d", &templog, &tempcash);
            A[templog]+=tempcash;
            printf("s\n");
        }
        else if (c == 'w') {
            scanf("%d %d",&templog ,&tempcash);
            if (tempcash <= A[templog]){
                A[templog]-=tempcash;
                printf("s\n");
            }
            else
                printf("f\n");
        }
        else{
            scanf("%d",&templog);
            printf("%d\n", A[templog]);
        }
    }   
    return 0;
}
