class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // step 1: sort each row
        for(int i = 0; i<m; i++){
            sort(grid[i].begin(), grid[i].end());
        }

        int ans = 0;

        // step 2: for each column take max across rows
        for(int col = 0; col<n; col++){
            int mx = 0;
            for(int row = 0; row<m; row++){
                mx = max(mx, grid[row][col]);
            }
            ans += mx;
        }

        return ans;
    }
};