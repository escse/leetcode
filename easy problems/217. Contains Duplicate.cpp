class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        sort(nums.begin(), nums.end());
        return adjacent_find(nums.begin(), nums.end(), [](int x, int y){return x == y;}) != nums.end() ;
    }
};