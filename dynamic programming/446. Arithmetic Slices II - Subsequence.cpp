class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        if (n == 0) return res;
        unordered_map<long, int> dp[n];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long d = (long)A[i] - A[j];
                dp[i][d] += 1;
                if (dp[j].count(d)) {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};