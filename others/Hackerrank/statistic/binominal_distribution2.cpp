#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
using namespace std;
/** @mainpage
**A manufacturer of metal pistons finds that, on average,
**12% of the pistons they manufacture are rejected because they are incorrectly sized. 
**What is the probability that a batch of 10 pistons will contain:
**
**    No more than 2 rejects?
**    At least 2rejects?
**
*/

/**
** factorial function @param n
*/
int factorial(int n) {
    if (n < 0) throw std::invalid_argument("argument for factorial must be not negative");
    if (n < 2) {return 1;}
    return n * factorial(n - 1);
}

double comb(int n, int x) {

    return (double) factorial(n) / (factorial(x) * factorial(n - x));
}

/**
** binomial probability, meaning the probability of having exactly x successes out of n trials.
** @param x The number of successes
** @param n The total number of trials
** @param p he probability of success of 1 trial
** @return binomial probability
*/
double b(int x, int n, double p) {
    
    return (double) comb(n, x) * pow(p, x) * pow((1 - p), (n - x));
}

double sum(int range_beg, int range_end , int n,  double value) {
    double sum_tmp{0};
    for (int i = range_beg; i <= range_end; i++)
        sum_tmp += b(i, n, value);

    return sum_tmp;
}

#define DEBUG

int main() {
    double reject_percent{0};
    int n{0};
#ifdef DEBUG
    reject_percent = 12;
    n = 10;
#else
    std::cin>>reject_percent>>n;
#endif
    
    std::cout << std::setprecision(3) << std::fixed << sum(8, 10 , n, (double)(1-reject_percent/100) ) << std::endl;
    std::cout << std::setprecision(3) << std::fixed << sum(2, 10 , n, (double)reject_percent/100 ) << std::endl;
    
    return 0;
}
