class Solution {
public:
    int countSubstrings(string s) {
        memset(dp, 0, 1005);
        return dfs(s, s.size()-1);
    }
private:
    int dp[1005];
    int dfs(string& s, int n) {
        if (n == 0) return 1;
        if (dp[n]) return dp[n];
        dp[n] = dfs(s, n-1) + 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == s[n] && ispalindromic(s, i, n)) ++dp[n];
        }
        return dp[n];
    }
    bool ispalindromic(string& s, int b, int e) {
        if (b > e) return false;
        while (b < e) {
            if (s[b++] != s[e--]) return false;
        }
        return true;
    }
};



class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            for(int j = 0; i-j>=0 && i+j<n && s[i-j]==s[i+j]; ++j) ++res;
            for(int j = 0; i-j-1>=0 && i+j<n && s[i-j-1]==s[i+j]; ++j) ++res;
        }
        return res;
    }
};


