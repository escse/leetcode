#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


#define m 1000000007
#define N 1005
class Solution {
public:
    int kInversePairs(int n, int k) {
        memset(dp, 0, sizeof(dp));
        return getkInversePairs(n, k);
    }
private:
    long dp[N][N];
    long getkInversePairs(int n, int k) {
        if (2 * k > n * (n - 1)) return 0;
        if (k < 0) return 0;
        if (n == 0) return 0;
        if (k == 0) return 1;
        if (!dp[n][k])
            dp[n][k] = (getkInversePairs(n - 1, k) + getkInversePairs(n, k - 1) - getkInversePairs(n-1, k-n) + m ) % m;
        return dp[n][k];
    }
};



int main(int argc, const char *argv[]) {
    cout << Solution().kInversePairs(500,500);    
    return 0;
}


// V2
#define m 1000000007
#define N 1005

int dp[N][N];

class Solution {
public:
    int kInversePairs(int n, int k) {
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = 1;
            int j = 1;
            int l = min(k, i * (i - 1) / 2);
            while (j <= l) {
                if (j < i) {
                    dp[j][i] = (dp[j][i - 1] + dp[j - 1][i]) % m;    
                } else {
                    dp[j][i] = (dp[j][i - 1] + dp[j - 1][i] - dp[j-i][i-1]) % m;
                    if (dp[j][i] < 0) dp[j][i] += m;
                }
                ++j;
            }
        }
        return dp[k][n];
    }
};

public class Solution {
    public int kInversePairs(int n, int k) {
        int[] d = new int[k+1];
        d[0] = 1;
        for(int i = 2;i <= n;i++){
           for(int j = 1;j <= k;j++){
                d[j] = (d[j] + d[j-1]) % 1000000007;
           }
           for(int j = k;j >= i;j--){
                d[j] = (d[j] - d[j-i] + 1000000007) % 1000000007;
           }
        }
        return d[k];
    }
}