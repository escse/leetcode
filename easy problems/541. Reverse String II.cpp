class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size() / (2 * k);
        auto it = s.begin();
        for (int i = 0; i < n; ++i) {
            reverse(it + i * 2 * k, it + i * 2 * k + k);
        }
        reverse(it + n * 2 * k, min(it + n * 2 * k + k, s.end()));
        return s;
    }
};