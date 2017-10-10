class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        memset(dp, 0, sizeof(dp));
        if (K == 0) return 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j][1] =  1.0 * count_if(direction, direction + 8, 
                    [i, j, N](int *d){return i + d[0] >= 0 && j + d[1] >= 0 && i + d[0] < N && j + d[1] < N;}) / 8.0;
            }
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (k == K && (i!=r ||j !=c)) continue;
                    vector<double> s;
                    transform(direction, direction + 8, back_inserter(s), 
                        [i, j, k, N, this](int *d) {
                            if (i + d[0] >= 0 && j + d[1] >= 0 && i + d[0] < N && j + d[1] < N) 
                                return dp[i+d[0]][j+d[1]][k-1]; 
                            else return 0.0;
                        }
                    );
                    dp[i][j][k] =  accumulate(s.begin(), s.end(), 0.0) / 8;;
                }
            }    
        }
        
        return dp[r][c][K];
    }
private:
    double dp[25][25][101];
    int direction[8][2] = {{2,1},{1,2},{2,-1},{1, -2}, {-1, 2},{-2, 1},{-2, -1},{-1,-2}};
};