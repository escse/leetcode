#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        const auto rfirst = nums.rbegin();//reverse_iterator<vector<int>::iterator>(nums.end());
        const auto rlast = nums.rend();//reverse_iterator<vector<int>::iterator>(nums.begin());
        auto pivot = next(rfirst);
        while (pivot != rlast && *pivot >= *prev(pivot))
            ++pivot;
        if (pivot == rlast) {
            reverse(rfirst, rlast);
            return;
        }
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*change, *pivot);
        reverse(rfirst, pivot);
    }
};

template <typename T>
ostream &operator<<(ostream &cout, vector<T> vec)
{
    for_each(vec.begin(), vec.end(), [&](T &elem) { cout << elem << " "; });
    return cout;
}

int main()
{
    vector<int> list;
    for (int i = 0; i < 2; ++i)
        list.push_back(i);
    auto sol = Solution();
    for (int i = 0; i < 10; i++)
    {
        sol.nextPermutation(list);
        cout << list << endl;
    }
}