/**
 * @mainpage
 * A random variable, X ,
 * follows Poisson distribution with mean of 2.5.
 * Find the probability with which the random variable is equal to 5.
 */
#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

/**
** factorial function @param n
*/
int factorial(int n) {
	if (n < 0) throw std::invalid_argument("argument for factorial must be not negative");
	if (n < 2) {return 1;}
	return n * factorial(n - 1);
}



/**
 * @brief poison distribution
 * @detail The Poisson probability, which is
 * the probability of getting exactly k successes
 * when the average number of successes is lambda.
 * exponential const e = 2.71828
 * @param lambda is the average number of successes that occur in a specified region.
 * @param k is the actual number of successes that occur in a specified region.
 * @return poison distribution
 */
double poisson_distribution(double lambda, int k) {
	double p_d{0};
	if (k == 0) return 0;
	p_d = pow(lambda, k) * exp(-lambda) / factorial(k);
	return p_d;
}

#define DEBUG

int main() {
	double mean{0};
	int probability_for{0};
#ifdef DEBUG
	mean = 2.5;
	probability_for = 5;
#else
	cin >> mean >> probability_for;
#endif

	cout << setprecision(3) << fixed << poisson_distribution(mean, probability_for) << endl;
	return 0;
}
