#include <bits/stdc++.h>

int N, temp, left, right;
std::vector<int> seti, res;

int main()
{
    seti.push_back(-1);
    freopen("seti.in7", "r", stdin);
    #ifdef CONTEST
        freopen("seti.out", "w", stdout);
    #endif 
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &temp);
        seti.push_back(temp);
    }
    for(int i = 1; i <= N; ++i){
            left = i;
            right = i;
        while(left>=1 && right < seti.size()){
            left--;
            right++;
            if(seti[right] == seti[left] && (float)seti[left] < (float)(1.0*seti[i])/2.0){
                res.push_back(i);
                break;
            }
        }
    }
   std::cout<<res.size()<<"\n";
   for(int i = 0; i < res.size(); ++i){
       std::cout<<res[i]<<"\n";
    }
    return 0;
}