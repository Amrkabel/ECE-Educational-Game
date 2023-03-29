#ifndef PROGLEV1_H
#define PROGLEV1_H
#include "Programming.h"
Programming inputs_lev1(){
    std::string s = "Code: \n   1 #include <iostream>.2.3int main(){.4  int n;.5    std::cout<<'Enter a positive integer: ';.6  std::cin>>n;.7.8    int factorial = 1;.9    for (int i = 1; i<=n; i++){.10      factorial*=i;.11    }.12.13 std::cout << 'Factorial of ' << n << ' is ' << factorial << std::endl;.14.15    return 0;.16}";
    std::vector<int> err(2);
    err[0] = 5;
    err[1] = 13;

    Programming p(s, err);
    return p;
}

#endif // PROGLEV1_H
