class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> B;
        for (int i = 1; i < A.size(); ++i) {
            B.push_back(A[i]-A[i-1]);
        }
        int n = 1;
        int res = 0;
        for (int i = 1; i < B.size(); ++i) {
            if (B[i] == B[i-1]) n += 1;
            else {
                res += n * (n - 1) / 2;
                n = 1;
            }
        }
        res += n * (n - 1) / 2;
        return res;
    }
};