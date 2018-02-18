#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

double mean(const vector<int> &a)
{
    double tmp{0};
    int count = a.size();
    for (auto& i:a) tmp+=i;    
    return (count>0)? (double) tmp/count:0;
}


double standard_deviation(const vector<int> vec){
    const double mu = mean(vec);
    double square_distance{0};
    int n = vec.size();
    
    for(auto& i : vec) square_distance += (double)pow(abs(i-mu),2); 
    
    if(n>0) return (double) sqrt(square_distance/n);
    return 0;
}

int main() {
    int n{0};
    vector<int> data{};
    scanf("%d",&n);
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>() , std::back_inserter(data)); 
    std::cout<<setprecision(1)<<fixed<<standard_deviation(data)<<std::endl;    
    return 0;
}