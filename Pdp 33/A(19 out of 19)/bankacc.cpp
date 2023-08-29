#include <bits/stdc++.h>

std::unordered_map<int, int> info;
int N, X, temp_acc, temp_price, withdraw_v;
char A;
std::vector<std::string> results;

int main() {
    freopen("bankacc.in", "r", stdin);
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; ++i) {
        scanf(" %c", &A);
        if (A == 'd') {
            scanf("%d %d", &temp_acc, &temp_price);
            info[temp_acc] += temp_price;
            results.push_back("s");
        }
        else if (A == 'w'){

            scanf("%d %d", &temp_acc, &withdraw_v);
            if (info[temp_acc] >= withdraw_v) {
                info[temp_acc] -= withdraw_v;
                results.push_back("s");
            }
            else{
                results.push_back("f");
            }
        }
        else{
            scanf("%d", &temp_acc);
            results.push_back(std::to_string(info[temp_acc]));
        }
    }
    freopen("bankacc.out", "w", stdout);
    for (const auto& result : results) {
        std::cout << result << "\n";
    }

    return 0;
}