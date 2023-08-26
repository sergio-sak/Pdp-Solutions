#include <bits/stdc++.h>

std::vector<std::pair<long, long>> arr;
long indx, value, C, L;

bool comp(std::pair<long, long> p1, std::pair<long, long> p2){
    if(p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main()
{
    
    freopen("hydrogen.in", "r",stdin);
    #ifdef CONTEST
    freopen("hydrogen.out", "w", stdout);
    #endif
    
    
    arr.push_back(std::make_pair(0, 0));
    scanf("%li", &C);
    for(int i = 1; i <= C; ++i){
        scanf("%li %li", &indx, &value);
        if(value != 0){
            arr.push_back(std::make_pair(value, indx));
        }
    }
    
    std::sort(arr.begin(), arr.end(), comp);
    
    std::cout<<arr.size()-1<<"\n";
    for(int i = arr.size()-1; i > 0; --i){
       std::cout << arr[i].second<<"\n";
    }
    return 0;
}