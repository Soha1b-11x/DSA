class Solution {
private:
    int noOfAliveNeabour(vector<vector<int>>& arr, int sr, int sc){
        int row = arr.size(), col = arr[0].size();
        int alive = 0;
        vector<int> delrow = {0, 1, 0, -1, 1, -1, 1, -1};
        vector<int> delcol = {-1, 0, 1, 0, 1, 1, -1, -1};

        for(int i=0;i<8;i++){
            int r = sr+delrow[i];
            int c = sc+delcol[i];
            if(r >= 0 && r < row && c >= 0 && c < col && arr[r][c]==1) alive++;
        }

        return alive;
    }
public:
    void gameOfLife(vector<vector<int>>& arr) {
        int row = arr.size(), col = arr[0].size();
        vector<vector<int>> newArr = arr;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int alive = noOfAliveNeabour(arr , i , j);
                if(alive < 2 && arr[i][j]==1) newArr[i][j] = 0;
                if(alive >=2 && alive<=3 && arr[i][j]==1) continue;
                if(alive > 3 && arr[i][j]==1) newArr[i][j] = 0;
                if(alive == 3 && arr[i][j]==0) newArr[i][j] = 1;
            }
        }

        arr = newArr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna