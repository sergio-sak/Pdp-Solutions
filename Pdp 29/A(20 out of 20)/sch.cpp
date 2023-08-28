#include <iostream>
#include <bits/stdc++.h>

long N, S;
std::unordered_map<long, long> sch;

bool comp(std::pair<long, long> p1, std::pair<long, long> p2){   
    return p1.second > p2.second;
}

int main() {
    #ifndef CONTEST
        freopen("sch.in3", "r", stdin);
    #endif
    #ifdef CONTEST
        freopen("sch.in", "r", stdin);
        freopen("sch.out", "w", stdout);
    #endif
    scanf("%ld", &N);
    for (int i = 1; i <= N; ++i){
        scanf("%ld", &S);
        sch[S]++;
    }

    std::vector<std::pair<long, long>> schVector(sch.begin(), sch.end());

    std::sort(schVector.begin(), schVector.end(), comp);

    int count = 0;
    for (const auto& element : schVector) {
        if(count == 3)
            break;
        std::cout << element.first << " "; 
        count++;
    }

    return 0;
}
