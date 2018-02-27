
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int direction[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int num = 0;
        int index = 0;
        int x = 0, y = -1;
        while (num < n * n) {
            x += direction[index][0];
            y += direction[index][1];
            res[x][y] = ++num;
            if (x == 0 && y == n-1 || x == n-1 && y == n- 1 || x == n-1 && y == 0 || res[x+direction[index][0]][y+direction[index][1]]){
                index = (index + 1) % 4;
            }
        }
        return res;
    }
};
