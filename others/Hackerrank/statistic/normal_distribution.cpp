#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double normal_distribution (double x, double mean, double st_deviation) {
        return 0.5*(1 + erf((x - mean) / (st_deviation * sqrt(2))));
    }

int main() {
   double mean{0}, deviation{0};
   double first_hours{0};
   double second_hours_beg{0}, second_hours_end{0};
   cin>>mean>>deviation>>first_hours>>second_hours_beg>>second_hours_end; 
   cout<<setprecision(3)<<fixed<<normal_distribution(first_hours, mean, deviation)<<endl;
    cout<<setprecision(3)<<fixed<<normal_distribution(second_hours_end, mean, deviation) - normal_distribution(second_hours_beg, mean, deviation)<<endl;
    return 0;
}