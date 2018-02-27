class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        if (array.empty() || array[0].empty()) return false;
        int m = array.size();
        int n = array[0].size();
        int row = 0, col = n - 1;
        while (true) {
            if (array[row][col] == target) return true;
            if (array[row][col] < target) ++row;
            else --col;
            if (col < 0 || row >= m) return false;
        }
    }
};