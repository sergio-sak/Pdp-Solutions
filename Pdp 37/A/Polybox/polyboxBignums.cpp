/* USER: user55.37pdp
LANG: C++
TASK: polybox */

#include <iostream>
#include <algorithm>
#include <string>

#define pb push_back
#define all(v) (v).begin(), (v).end()

short type;
long long REPS, perimeter, oldW, W, H;
std::string Sperimeter, SoldW, SW, SH;

std::string add(std::string s1, std::string s2) {
    std::reverse(all(s1));
    std::reverse(all(s2));

    int N = s1.size(), M = s2.size();
    s1.append(60-N, '0');
    N = 60;
    s2.append(60-M, '0');
    M = 60;

    std::string res(60, '0');
    
    int carry = 0;
    for(int i = 0; i < N; ++i) {
        int num = (s1[i] - '0') + (s2[i] - '0') + carry;

        res[i] = (char)((res[i] - '0') + ((num % 10) + '0'));

        carry = num / 10;
    }

    // if(carry) res.pb(carry + '0');

    std::reverse(all(res));
    return res;
}

std::string subtract(std::string s1, std::string s2) {
    std::reverse(all(s1));
    std::reverse(all(s2));

    int N = s1.size(), M = s2.size();
    s1.append(60-N, '0');
    N = 60;
    s2.append(60-M, '0');
    M = 60;
    std::string res(60, '0');

    int carry = 0;
    for(int i = 0; i < N; ++i) {
        int num1 = s1[i] - '0', num2 = (s2[i] - '0') + carry; 
        carry = 0;
        if(num1 >= num2) {
            res[i] = (num1 - num2) + '0';
        } else {
            carry = 1;
            res[i] = (10 + num1 - num2) + '0';
        }
    }

    std::reverse(all(res));

    return res;
}

signed main()
{
    freopen("polybox.in", "r", stdin);
    freopen("polybox.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin>>type>>REPS;

    if(type != 4) {
        for(int i = 1; i <= REPS; ++i) {
            std::cin>>W>>H;
            perimeter += (H + H);
            perimeter += (W >= oldW) ? W - oldW : oldW - W;    
            oldW = W;
        }
        perimeter += W;
        
        std::cout<<perimeter<<"\n";
        return 0;
    }

    for(int i = 1; i <= REPS; ++i) {
        std::cin>>SW>>SH;

        std::reverse(all(SW));
        std::reverse(all(SH));
        SW.append(60-SW.size(), '0');
        SH.append(60-SH.size(), '0');
        std::reverse(all(SW));
        std::reverse(all(SH));

        Sperimeter = add(Sperimeter, add(SH, SH));
        Sperimeter = (SW >= SoldW) ? add(Sperimeter, subtract(SW, SoldW)) : add(Sperimeter, subtract(SoldW, SW));    
        SoldW = SW;
    }
    Sperimeter = add(Sperimeter, SW);


    size_t pos = Sperimeter.find_first_not_of('0');//Na mhn vgazei errosr
    if (pos != std::string::npos) {
        Sperimeter = Sperimeter.substr(pos);
    }
    std::cout<<Sperimeter<<"\n";
    return 0;
}