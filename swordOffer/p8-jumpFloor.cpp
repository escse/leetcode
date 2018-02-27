class Solution {
public:
    int jumpFloor(int number) {
        memset(res, 0, 1000);
        res[1] = 1;
        res[2] = 2;
        for (int i = 3; i <= number; ++i) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[number];
    }
private:
    int res[1000];
};