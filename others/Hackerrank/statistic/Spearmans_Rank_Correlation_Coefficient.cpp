#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <iomanip>

using namespace std;

#define DEBUG

int main() {
	int n{0}; // number of elements of datasets
	std::vector<double> x{}, y{}, d{};
	std::map<double, int> map_x, map_y;
	double sum_d{0};
#ifdef DEBUG
	n = 10;
	x = {10, 9.8, 8, 7.8, 7.7, 1.7, 6, 5, 1.4, 2 };
	y = {200, 44, 32, 24, 22, 17, 15, 12, 8, 4};
#else
	std::cin >> n;
	std::copy_n(std::istream_iterator<double>(std::cin), n, std::back_inserter(x));
	std::copy_n(std::istream_iterator<double>(std::cin), n, std::back_inserter(y));
#endif

	for (auto& i : x) map_x[i];
	for (auto& i : y) map_y[i];

	for (int i = 0; i < x.size(); ++i) {
		d.push_back(
		    std::distance(map_x.begin(), map_x.find(x.at(i))) -
		    std::distance(map_y.begin(), map_y.find(y.at(i)))
		);

	}
	for (auto& i : d)
		sum_d += pow(i, 2);
	if (n > 0)
		cout << setprecision(3) << fixed << (1 - 6 * sum_d / (n * (pow(n, 2) - 1))) << endl;
}