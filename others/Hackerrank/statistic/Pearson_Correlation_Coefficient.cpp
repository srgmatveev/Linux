#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

#define DEBUG

template <class T, class U>
U mean(const vector<T> &a)
{
	U tmp{0};
	size_t count = a.size();
	for (auto& i : a) tmp += i;
	return (count > 0) ? (U) tmp / count : 0;
}

template <class T, class U>
U standard_deviation(const vector<T> &vec) {
	const U mu = mean<T, U>(vec);
	U square_distance{0};
	size_t n = vec.size();

	for (auto& i : vec) square_distance += (U)pow(abs(i - mu), 2);

	if (n > 0) return (U) sqrt(square_distance / n);
	return 0;
}

template <class T, class W, class Z, class U>
U pearson_correlation_coefficient(const vector<T> &x, const vector<T> &y,
                                  const W& x_mean, const W& y_mean, const Z & n) {
	T sum{0};
	U x_standard_deviation = standard_deviation<T, U> (x);
	U y_standard_deviation = standard_deviation<T, U> (y);

	for (Z i = 0; i < n; i++)
		sum += ((x.at(i) - x_mean) * (y.at(i) - y_mean));


	return (not n or not x_standard_deviation or not y_standard_deviation) ? 0 :
	       (U) sum / (n * x_standard_deviation * y_standard_deviation);
}

int main() {
	int n{0}; // number of elements of datasets
	std::vector<double> x{}, y{};
#ifdef DEBUG
	n = 10;
	x = {10, 9.8, 8, 7.8, 7.7, 7, 6, 5, 4, 2 };
	y = {200, 44, 32, 24, 22, 17, 15, 12, 8, 4};
#else
	std::cin >> n;
	std::copy_n(std::istream_iterator<double>(std::cin), n, std::back_inserter(x));
	std::copy_n(std::istream_iterator<double>(std::cin), n, std::back_inserter(y));
#endif

	double x_mean = mean<double, double>(x);
	double x_st_deviation = standard_deviation<double, double>(x);
	double y_mean = mean<double, double>(y);
	double y_st_deviation = standard_deviation<double, double>(y);
	cout.precision(3);
	cout << fixed <<
	     pearson_correlation_coefficient<double, double, int, double>(x, y, x_mean, y_mean, n)
	     << endl;
	return 0;
}