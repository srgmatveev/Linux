#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

double median(vector<int> data)
{
    double median{0};
    
    using data_size = vector<int>::size_type;
    data_size size = data.size();
    if (!size) return 0;

    
    std::sort(data.begin(),data.end());
    data_size mid = size/2;
    return size % 2 == 0 ? (double)(data[mid] + data[mid-1]) / 2 : (double)data[mid];
}

double q1(vector<int> vec) {
    using vec_size = vector<int>::size_type;
    vec_size size = vec.size();
    
    if (!size) return 0;
    std::sort(vec.begin(),vec.end());
    std::vector<int> q1{};
    std::copy(vec.begin(), vec.begin()+ size/2, std::back_inserter(q1));
    return median(q1);
}


double q3(vector<int> vec) {
    using vec_size = vector<int>::size_type;
    vec_size size = vec.size();
    if (!size) return 0;
    std::sort(vec.begin(),vec.end());
    std::vector<int> q3{};
   
    
    (size % 2 == 0) ?
        std::copy(vec.begin()+ size/2, vec.end(), std::back_inserter(q3)) : std::copy(vec.begin()+ size/2+1, vec.end(),                 std::back_inserter(q3));
   
    return median(q3);
}

int main() {
    int n{0};
    vector<int> data{};
    scanf("%d",&n);
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>() , std::back_inserter(data));
    std::sort(data.begin(), data.end());
    std::cout<< q1(data)<<endl;
    std::cout<< median(data)<<endl;
     std::cout<< q3(data)<<endl;
    return 0;
}
