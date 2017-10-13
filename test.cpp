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
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        copy(nums1.begin(), nums1.begin() + m, nums1.begin() + n);
        auto it = nums1.begin();
        auto it1 = nums1.begin() + n;
        auto it2 = nums2.begin();
        while (it != nums1.begin() + m + n) {
            if (it1 == nums1.end()) {
                copy(it2, nums2.end(), it);
                break;
            }
            if (it2 == nums2.end()) {
                break;
            }
            if (*it1 < *it2) {
                swap(*it++, *it1++);
            } else {
                swap(*it++, *it2++);
            }
        }
        
    }
};

int main(int argc, const char *argv[]) {
    vector<int> n1{1,3,5,7};
    n1.resize(8);
    vector<int> n2{2,4,6,8};
    Solution().merge(n1,4, n2, 4);
    print(n1);  
    return 0;
}