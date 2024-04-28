#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_prev_divisible(int N, vector<int>& sequence) {
    int max_num = sequence[0]; 

    for (int i = 1; i < N; ++i) {
        bool divisibleall = true;
        for (int j = 0; j < i; ++j) { 
            if (sequence[i] % sequence[j] != 0) {
                divisibleall = false;
                break;
            }
        }
        if (divisibleall) {
            max_num = max(max_num, sequence[i]);
        }
    }

    return max_num;
}

int main() {
    #ifdef CONTEST
        freopen("prevdiv.in", "r", stdin);
        freopen("prevdiv.out", "w", stdout);
    #else
        freopen("prevdiv.in", "r", stdin);
    #endif

    int N,i=0,b=0;
    scanf("%d ", &N);
    vector<int> sequence(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d ", &sequence[i]);;
    }

    int result = max_prev_divisible(N, sequence);

    printf("%d ", result);

    return 0;
}