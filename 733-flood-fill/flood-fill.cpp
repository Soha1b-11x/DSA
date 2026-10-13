class Solution {
private:
    void dfs(vector<vector<int>>& arr, int initColor, int sr, int sc , int color){
        vector<int>delrow = {0 , -1 , 0 , 1};
        vector<int>delcol = {-1 , 0 , 1 , 0};
        int r = arr.size() , c = arr[0].size();
        arr[sr][sc] = color;
        for(int i=0;i<4;i++){
            int newRow = sr+delrow[i];
            int newCol = sc+delcol[i];
            if(newRow >= 0 && newRow < r && newCol >= 0 && newCol < c && arr[newRow][newCol] == initColor){
                arr[newRow][newCol] = color;
                dfs(arr , initColor , newRow , newCol , color);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> arr = image;
        int initColor = image[sr][sc];
        if(image[sr][sc]==color) return image;
        dfs(arr , initColor , sr , sc , color);
        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna