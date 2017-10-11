#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
// #include <bits/stdc++.h>

using namespace std;
template<typename T>
void print(const T& t) {
    using type = typename T::value_type;
    for_each(t.begin(), t.end(), [](const type& e){std::cout << e << " ";});
    std::cout << std::endl;
}

#define it(v) v.begin(),v.end()

int main(int argc, const char *argv[]) {
    vector<int> v{1,3,4,5,6,2,4,6,8};
    v.erase(remove_if(v.begin(), v.end(), [](int x){return x&1 ==0;}), v.end());
    print(v);
    return 0;
}