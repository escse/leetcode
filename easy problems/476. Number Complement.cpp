class Solution {
public:
    int findComplement(int num) {
        int cnt = 0;
        int n = num;
        while (n) {
            n >>= 1;
            ++cnt;
        }
        return (1 << cnt) - num - 1;
    }
};