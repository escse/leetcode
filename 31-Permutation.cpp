#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto rfirst = nums.rbegin();
        auto rlast  = nums.rend();
        auto pivot = next(rfirst);
        while(pivot != rlast && *prev(pivot) <= *pivot)
            ++pivot;
        if (pivot == rlast)
            reverse(rfirst, rlast);
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*pivot, *change);
        reverse(rfirst, pivot);
    }
};

template <typename T>
ostream& operator<< (ostream& cout, vector<T> vec) {
    for_each(vec.begin(), vec.end(), [&](T& elem) {cout << elem << " ";});
    return cout;
}

int main() {
    vector<int> list;
    for (int i = 0; i< 10; ++i) 
        list.push_back(i);
    auto sol = Solution();
    for (int i = 0; i < 10; i++) {
        sol.nextPermutation(list);
        cout << list << endl;    
    }
}