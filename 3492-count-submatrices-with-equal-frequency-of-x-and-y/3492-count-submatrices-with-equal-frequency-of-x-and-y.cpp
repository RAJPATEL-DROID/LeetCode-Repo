class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        
        vector<vector<pair<int, int>>> sum(m + 1, vector<pair<int, int>>(n + 1, {0, 0}));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j].first = sum[i-1][j].first + sum[i][j-1].first - sum[i-1][j-1].first + (grid[i-1][j-1] == 'X');
                sum[i][j].second = sum[i-1][j].second + sum[i][j-1].second - sum[i-1][j-1].second + (grid[i-1][j-1] == 'Y');
            }
        }
        
        // Check all submatrices that include the top-left corner
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (sum[i][j].first > 0 && sum[i][j].first == sum[i][j].second) {
                    count++;
                }
            }
        }
        
        return count;
    }
};