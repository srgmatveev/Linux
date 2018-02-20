#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
using namespace std;
/** @mainpage
**The ratio of boys to girls for babies born in Russia is 1.09 : 1.
**If there is 1 child born per birth,
**what proportion of Russian families
**with exactly 6 children will have at least 3  boys?
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
        sum_tmp += b(i, 6, value);

    return sum_tmp;
}

#define DEBUG

int main() {
    double boys{0}, girls{0};
#ifdef DEBUG
    boys = 1.09;
    girls = 1;
#else
    std::cin>>boys>>girls;
#endif
    if (boys + girls == 0) return -1;
    std::cout << std::setprecision(3) << std::fixed << sum(3, 6 , 6, boys / (boys + girls) ) << std::endl;
    return 0;
}
