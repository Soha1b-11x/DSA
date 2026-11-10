class Solution {
    int BFS(vector<vector<int>>& arr){
        queue<pair<int,int>>q;
        q.push({0, 0});
        int row=arr.size(), col=arr[0].size();
        int delrow[] = {0, 0, 1, 1, 1, -1, -1, -1};
        int delcol[] = {1, -1, 0, 1, -1, 0, 1, -1};
        int dist = 1;
        if(row==1 && col==1) return dist;
        arr[0][0] = 1; // mark as visited

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [sr, sc] = q.front();
                q.pop();

                for(int i=0;i<8;i++){
                    int newRow = sr+delrow[i];
                    int newCol = sc+delcol[i];
                    if(newRow == row-1 && newCol == col-1) return dist+1;
                    if(newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && arr[newRow][newCol]==0){
                        arr[newRow][newCol] = 1; // mark ass visited
                        q.push({newRow, newCol});
                    }
                }   
            }
            dist++;
        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        if(grid[0][0] != 0 || grid[r-1][c-1] != 0) return -1;

        return BFS(grid);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna