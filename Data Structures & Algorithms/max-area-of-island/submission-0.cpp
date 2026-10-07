class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int maxCnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int cnt = 0;
                    dfs(i,j, grid, vis, cnt);
                    maxCnt = max(maxCnt, cnt);
                }
            }
        }
        return maxCnt;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int& cnt){
        int n = grid.size();
        int m = grid[0].size();

        if(r<0 || r>=n || c<0 || c>=m || vis[r][c] || grid[r][c]!=1){
            return;
        }

        vis[r][c] = 1;
        cnt++;

        dfs(r+1,c, grid, vis, cnt);
        dfs(r-1,c, grid, vis, cnt);
        dfs(r,c+1, grid, vis, cnt);
        dfs(r,c-1, grid, vis, cnt);
    }
};
