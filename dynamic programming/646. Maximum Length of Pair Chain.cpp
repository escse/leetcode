class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& l, const vector<int>& r){return l[1] < r[1];});
        int ddl = pairs[0][0] - 1;
        int res = 0;
        for (auto &v: pairs) {
            if (v[0] > ddl) {
                ++res;
                ddl = v[1];
            }
        }
        return res;
    }
};