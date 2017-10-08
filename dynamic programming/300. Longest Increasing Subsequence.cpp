class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n];
        // vector<int> dp(n);
        int imax = numeric_limits<int>::max();
        fill(dp, dp + n, imax);
        for (int i = 0; i < n; ++i) {
            *lower_bound(dp, dp+n, nums[i]) = nums[i];
        }
        return lower_bound(dp, dp+n, imax) - dp;
    }
};