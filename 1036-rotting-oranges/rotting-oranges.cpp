class Solution {
private:
    int bfs(vector<vector<int>>& arr , queue<pair<int,int>>&q){
        int time = 0; 
        vector<int>delrow = {0 , -1 , 0 , 1};
        vector<int>delcol = {-1 , 0 , 1 , 0};
        int row = arr.size() , col = arr[0].size();

        while(!q.empty()){
            int size = q.size();
            bool rottenAny = false;
            for(int i=0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int newRow = r+delrow[j];
                    int newCol = c+delcol[j];
                    if(newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && arr[newRow][newCol]==1){
                        arr[newRow][newCol] = 2; // now it rottenn
                        q.push({newRow , newCol});
                        rottenAny = true;
                    }
                }
            }
            if(rottenAny) time++;
        }

        return time;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        //init queue;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }

        int time = bfs(grid , q);
        
        //check any fresh orange
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return time;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna