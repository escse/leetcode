#include <iostream>
#include <string>
#include <cstring>
using namespace std;



class Solution {
public:
    int strangePrinter(string s) {
        int size = s.size();
        memset(dp, 0, sizeof(dp));
        return dfs(s, 0, size - 1);
    }
private:
    int dp[101][101];
    int dfs(const string& s, int l, int r) {
        if (l > r) return 0;
        if (dp[l][r]) return dp[l][r];
        dp[l][r] = dfs(s, l, r - 1) + 1;
        for (int i = l; i < r; ++i) {
            if (s[i] == s[r]) {
                dp[l][r] = min(dp[l][r], dfs(s, l, i) + dfs(s, i + 1, r - 1));
            }
        }
        return dp[l][r];
    }
};