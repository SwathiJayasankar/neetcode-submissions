class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m || vis[r][c] || grid[r][c] != '1'){
            return;
        }

        vis[r][c] = 1;

        dfs(r+1, c, grid, vis);
        dfs(r-1, c, grid, vis);
        dfs(r, c+1, grid, vis);
        dfs(r, c-1, grid, vis);
    }
};
