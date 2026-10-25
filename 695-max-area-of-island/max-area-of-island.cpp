class Solution {
private:
    int bfs(vector<vector<int>>& arr, int sr, int sc){
        vector<int>delrow = {0, 1, 0, -1};
        vector<int>delcol = {-1, 0, 1, 0};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        arr[sr][sc] = 0;
        int size = 1;
        int row = arr.size(), col = arr[0].size();

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newRow = delrow[i] + r;
                int newCol = delcol[i] + c;
                if(newCol >= 0 && newCol < col && newRow >= 0 && newRow < row && arr[newRow][newCol]==1){
                    q.push({newRow, newCol});
                    arr[newRow][newCol] = 0;
                    size++;
                }
            }
        }

        return size;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int size = bfs(grid, i, j);
                    ans = max(ans, size);
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna