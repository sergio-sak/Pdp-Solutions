#include <bits/stdc++.h>

std::vector<std::pair<int, std::vector<int>>> students;
std::vector<int> unis;
std::vector<int> result;
int N, M, temp_unis, temp_moria, uni_amount, temp_coices;

int main()
{
    freopen("erasmus.in", "r", stdin);
    scanf("%d %d", &N, &M);
    result.resize(M, -1);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &temp_unis);
        unis.push_back(temp_unis);
    }

    for (int i = 0; i < M; ++i) {
        scanf("%d", &temp_moria);
        scanf("%d", &uni_amount);
        std::vector<int> temp_vec;
        for (int i = 0; i < uni_amount; ++i) {
            scanf("%d", &temp_coices);
            temp_vec.push_back(temp_coices);
        }
        students.push_back(std::make_pair(temp_moria, temp_vec));
    }

    std::vector<int> original_positions(M);
    for (int i = 0; i < M; ++i) {
        original_positions[i] = i;
    }

    std::sort(original_positions.begin(), original_positions.end(), [&](int a, int b) {
        return students[a].first > students[b].first;
    });

    for (int i = 0; i < M; ++i) {
        int idx = original_positions[i];
        for (int j = 0; j < students[idx].second.size(); ++j) {
            int uni = students[idx].second[j];
            if (unis[uni - 1] > 0) {
                unis[uni - 1]--;
                result[idx] = uni;
                break;
            }
        }
    }
    freopen("erasmus.out", "w", stdout);
    for (int i = 0; i < M; ++i) {
        if (result[i] == -1)
            printf("%s\n","NONE");
        else
            printf("%d\n", result[i]);
    }

    return 0;
}