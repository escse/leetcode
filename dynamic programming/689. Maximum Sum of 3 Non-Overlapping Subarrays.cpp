#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int a, b ,c;
        int size = nums.size();
        int sizev = size - k + 1;
        int val[sizev];
        int max_front[sizev];
        int max_last[sizev];
        partial_sum(nums.begin(), nums.end(), nums.begin());
        
        val[0] = nums[k-1];
        for (int i = 1; i < sizev; ++i) {
            val[i] = nums[i + k - 1] - nums[ i - 1];
        }
        
        int tmp;
        max_front[0] = 0;
        for (int i = 1; i < sizev; ++i) {
            if (val[max_front[i-1]] < val[i]) {
                max_front[i] = i;
            } else {
                max_front[i] =  max_front[i-1];
            }
        }
        max_last[sizev-1] = sizev-1;
        for (int i = sizev - 2; i >= 0; --i) {
            if (val[max_last[i+1]] <= val[i]) {
                max_last[i] = i;
            } else {
                max_last[i] =  max_last[i+1];
            }
        }
        int res = 0;
        for (int i = k; i < sizev - k; ++i) {
            if (res < (tmp = val[i] + val[max_front[i-k]] + val[max_last[i+k]])) {
                res = tmp;
                a = max_front[i-k];
                b = i;
                c = max_last[i+k];
            }            
        }
        return vector<int>{a,b,c};
    }
};

int main(int argc, const char *argv[]) {
    vector<int> s{1,2,1,2,6,7,5,1,1,2,1,2,6,7,5,1,1,2,1,2,6,7,5,1,1,2,1,2,6,7,5,1};
    Solution().maxSumOfThreeSubarrays(s, 4);
    return 0;
}