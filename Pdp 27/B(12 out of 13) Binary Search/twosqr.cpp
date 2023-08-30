#include <bits/stdc++.h>

long long N, number, max = 0, mindx = 1000000000;
std::vector<long long> results;

long long binary_search(long long indx, long long num) {
    long long low = 0, mid, high = sqrt(num);
    while(low <= high) {

        mid = (low + high) / 2;

        if((mid * mid + indx * indx) == num) {
            if(mindx >= mid)
                mindx = mid;
            // std::cout<<"FOUND!!!!!!!!!!!!!!!!!!!!!!!!\nNumber: "<<num<<" Index: "<<indx<<" Mid: "<<mid<<" Sum of Squares: "<<(mid * mid + indx * indx)<<"\n";
            return mid;
        }

        else if((mid * mid + indx * indx) > num) {
            high = mid - 1;
        }

        else if((mid * mid + indx * indx) < num) {
            low = mid + 1;
        }
    }
    // std::cout<<"Number: "<<num<<" Index: "<<indx<<" Mid: "<<mid<<" Sum of Squares: "<<(mid * mid + indx * indx)<<"\n";
    return -1;
}

int main()
{
    #ifdef CONTEST
        freopen("twosqr.in", "r", stdin);
        freopen("twosqr.out", "w", stdout);
    #else
        freopen("Files/twosqr.in12", "r", stdin);
    #endif

    scanf("%ld", &N);

    for(long long i = 0; i < N; ++i) {

        scanf("%ld", &number);
        if(number == 0){
            results.push_back(1);
            continue;
        }
        for(long long j = 0; j < sqrt(number); ++j) {
            if(j >= mindx){
                mindx = 1000000000;
                break;
            }
            if(binary_search(j, number) >= 0){
                max++;    
            }


        }
        results.push_back(max);
        max = 0;
    }
    //int ic = 1;
    for(const auto& element : results) {
        //printf("%ld: %ld\n", ic, element);
        printf("%ld\n", element);
        //ic++;
    }
    return 0;
}
