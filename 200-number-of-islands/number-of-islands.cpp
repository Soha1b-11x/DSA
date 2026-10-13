class Solution {
public:
    void BFS(vector<vector<bool>>&isVis , int i , int j){
        queue<pair<int,int>>q;
        q.push({i , j});
        int r = isVis.size() , c = isVis[0].size();

        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop(); int row = p.first , col = p.second;
            isVis[row][col] = true;
            //left
            if(col-1>=0 && isVis[row][col-1]==false){ q.push({row , col-1}); isVis[row][col-1] = true; }
            //right
            if(col+1<c && isVis[row][col+1]==false){ q.push({row , col+1}); isVis[row][col+1] = true; }
            //down
            if(row+1<r && isVis[row+1][col]==false){ q.push({row+1 , col}); isVis[row+1][col] = true; }
            //up
            if(row-1>=0 && isVis[row-1][col]==false){ q.push({row-1 , col}); isVis[row-1][col] = true; }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>isVis;
        int r = grid.size();
        int c = grid[0].size();

        // init isVis
        for(int i=0;i<r;i++){
            vector<bool>row;
            for(int j = 0;j<c;j++){
                if(grid[i][j]=='1') row.push_back(false);
                else row.push_back(true);
            }
            isVis.push_back(row);
        }

        int isLand = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!isVis[i][j]) { BFS(isVis , i , j); isLand++;}
            }
        }

        return isLand;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna