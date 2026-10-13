class Solution {
private:
    int BFS(vector<vector<int>>& grid , int sr , int sc){
        bool getEdge = false;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int row = grid.size() , col = grid[0].size();
        int cells = 0;

        grid[sr][sc] = 0; // mark as visited || water
        if(sr == 0 || sr == row-1 || sc == 0 || sc == col-1) getEdge = true;

        // up down left right
        vector<int>delrow = {0 , -1 , 0 , 1};
        vector<int>delcol = {-1 , 0 , 1 , 0};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newRow = r+delrow[i];
                int newCol = c+delcol[i];
                if(newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == 1){
                    q.push({newRow , newCol});
                    grid[newRow][newCol] = 0; // mark as visited || water
                    if(newRow == 0 || newRow == row-1 || newCol == 0 || newCol == col-1) getEdge = true;
                }
            }
            cells++;
        }

        if(getEdge) return 0;
        return cells;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size() , col = grid[0].size();
        int ans = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) {
                    int val = BFS(grid , i , j);
                    ans += val;
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna