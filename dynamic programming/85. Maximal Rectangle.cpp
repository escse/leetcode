class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<int> height(n);
        for (int i = 0; i < m; ++i) {
            // height.resize(matrix[i].size());
            for (int j = 0; j < n; ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        stack<int> s;
        s.push(heights[0]);
        int n = heights.size();
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (heights[i] >= s.top()) {
                s.push(heights[i]);
            } else {
                int k = 1;
                while (!s.empty() && s.top() > heights[i]) {
                    res = max(res, k * s.top());
                    s.pop();
                    ++k;
                }

                while (k--) {
                    s.push(heights[i]);
                }
            }
        }
        int i = 0;
        while (!s.empty()) {
            ++i;
            res = max(res, i * s.top());
            s.pop();
        }
        return res;
    }
};