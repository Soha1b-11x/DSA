class Solution {
private:
    long long isLandSum(vector<vector<int>>& arr, int k, int sr, int sc){
        long long sum = arr[sr][sc];
        arr[sr][sc]=0;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {-1, 0, 1, 0};
        int row=arr.size(), col=arr[0].size();

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newRow=r+delrow[i];
                int newCol=c+delcol[i];
                if(newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && arr[newRow][newCol]!=0){
                    sum += arr[newRow][newCol];
                    q.push({newRow,newCol});
                    arr[newRow][newCol]=0;
                }
            }
        }

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    long long sumIsland = isLandSum(grid , k , i , j);
                    if(sumIsland%k == 0) count++;
                }
            }
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna