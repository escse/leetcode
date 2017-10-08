#include <iostream>
using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        if (num == 0) return 1;
        int k = getK(num);
        int residual = num % (1 << k);
        if (residual == 0 || k == 1) return  dp[k];
        if (residual >= (1 << (k-1))) {
            return dp[k] + dp[k-1] - 1; 
        }
        return dp[k] + findIntegers(residual) - 2;
    }
    
private:
    const int dp[32] = {2, 3, 4, 6, 9, 14, 22, 35, 56, 90, 145, 234, 378, 611, 988, 1598, 2585, 4182, 6766, 10947, 17712, 28658, 46369, 75026, 121394,196419, 317812, 514230, 832041, 1346270, 2178310, 3524579};
    int getK(int num) {
        int k = 0;        
        while (num > 0) {
            num >>= 1;
            ++k;
        }
        return k - 1;
    }
};


int main(int argc, const char *argv[]) {
    int k;
    cin >> k;
    cout << Solution().findIntegers(k);
    return 0;
}
