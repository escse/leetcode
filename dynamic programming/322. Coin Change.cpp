class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        return coinChangeDFS(coins, amount, dp);
    }
    int coinChangeDFS(vector<int> &coins, int amount, vector<int> &dp) {
        if (amount < 0) return - 1;
        if (dp[amount] != INT_MAX) return dp[amount];
        for (int i = 0; i < coins.size(); ++i) {
            int tmp = coinChangeDFS(coins, amount - coins[i], dp);
            if (tmp >= 0) dp[amount] = min(dp[amount], tmp + 1);
        }
        return dp[amount] = dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};