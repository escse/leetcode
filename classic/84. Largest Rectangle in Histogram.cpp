#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
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

int main(int argc, const char *argv[]) {
    vector<int> v{6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
    cout << Solution().largestRectangleArea(v);
    return 0;
}