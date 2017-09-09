class Solution {
public:
    int numDecodings(string s) {
        dp[0] = 1;
        dp[1] = getSingle(s[0]);
        for (int i = 2; i <= s.size(); ++i) {
            dp[i%2] = (dp[(i-1) % 2] * getSingle(s[i-1]) + dp[(i-2)%2] * getDouble(s[i-2], s[i-1])) % 1000000007;
        }
        return dp[s.size()%2];
    }
private:
    long dp[2];
    inline int getSingle(char c) {
        return (c == '*' ? 9: c == '0'? 0:1);
    }
    inline int getDouble(char c1, char c2) {
        if (c1 == '*') c1 = 58;
        if (c2 == '*') c2 = 58;
        return record[c1-48][c2-48];
    }
    int record[11][11] = {
        {0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,9},
        {1,1,1,1,1,1,1,0,0,0,6},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {2,2,2,2,2,2,2,1,1,1,15}
    };
};