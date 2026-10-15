class Solution {
private:
    vector<vector<char>> bfs(vector<vector<char>>& board , int sr , int sc){
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<int>delrow = {0, -1, 0, 1};
        vector<int>delcol = {-1, 0, 1, 0};
        bool getEdge = false;
        vector<vector<char>>arr = board;
        arr[sr][sc] = 'X';
        int row = arr.size(), col = arr[0].size();

        if(sr == 0 || sr == row-1 || sc == 0 || sc == col-1) return board;

        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newRow = delrow[i]+r;
                int newCol = delcol[i]+c;
                if(newRow >= 0 && newRow < row && newCol >=0 && newCol < col && arr[newRow][newCol]=='O'){
                    arr[newRow][newCol] = 'X';
                    q.push({newRow,newCol});
                    if(newRow == 0 || newRow == row-1 || newCol == 0 || newCol == col-1) getEdge = true;
                }
            }
        }

        if(getEdge) return board;
        return arr;
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size() , col = board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O') board = bfs(board,i,j);
            }
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna