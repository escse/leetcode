class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int  m = 2100;
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        memset(dp, 0, sizeof(dp));
        set<int> s1;
        set<int> s2;
        s1.insert(nums[0]);
        s1.insert(-nums[0]);
        dp[0][nums[0]] += 1;
        dp[0][(-nums[0] + m) % m] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            s2.clear();
            for (auto k: s1) {
                dp[i][(nums[i] + k + m ) % m] += dp[i-1][(k + m ) % m];
                dp[i][(- nums[i] + k + m ) % m] += dp[i-1][(k + m ) % m];
                s2.insert(nums[i] + k);
                s2.insert(-nums[i] + k);
            }
            s1 = s2;
        }
        if (s1.find(S) == s1.end()) {
            return 0;
        }
        return dp[nums.size()-1][(S + m) % m];
    }
private:
    int dp[21][2100];
};

// good method
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};