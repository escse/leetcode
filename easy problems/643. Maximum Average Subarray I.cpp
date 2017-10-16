class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int res;
        if (nums.size() < k) return accumulate(nums.begin(), nums.end(), 0.0) / k;
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        res = sum;
        auto it = nums.begin() + k;
        while (it != nums.end()) {
            sum += *it - *(it - k);
            res = max(res, sum);
            ++it;
        }
        return 1.0 * res / k;
    }
};