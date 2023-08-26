#include <bits/stdc++.h>

long N, M, P, count = 0, indx = 0, word_index = 0;
std::string word;
char inp;

int main()
{
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);

    scanf("%ld", &N);
    std::cin.ignore();
    getline(std::cin, word);
    scanf("%ld", &M);

    for(int i = 0; i < M; ++i){
        inp = getchar();
        if(inp == word[word_index]){
            if(count == 0)
                indx = i;
            count++;
            word_index++;
            if (count == N - 1&& M == N){
                    printf("%ld\n", indx);
                    return 0;
            }
            if (count == N){
                printf("%ld\n", indx);
                return 0;
            }     
        }
        else{
            count = 0;
            indx = 0;
            word_index = 0;
        }
    }
    printf("F\n");
    return 0;
}
