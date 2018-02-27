class Solution {
public:
    void reOrderArray(vector<int> &array) {
        stable_partition(array.begin(), array.end(), [](int c) {return c&1;});
    }
};