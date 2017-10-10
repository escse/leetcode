class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, cur = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                ++cur;
            } else {
                res = max(res, cur);
                cur = 0;
            }
        }
        res = max(res, cur);
        return min(res + 1, n);
    }
};