class Solution {
private:
    void traverse(vector<vector<int>>& arr, int& ans, int& sum, int sr, int sc){
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};
        int row = arr.size();
        int col = arr[0].size();

        for(int i=0;i<4;i++){
            int newRow = sr+delrow[i];
            int newCol = sc+delcol[i];
            if(newRow >= 0 && newRow < row && newCol >=0 && newCol < col && arr[newRow][newCol]!=0){
                int curr = arr[newRow][newCol];
                arr[newRow][newCol] = 0; //like mark as visited;
                sum += curr;
                ans = max(ans, sum);
                traverse(arr, ans, sum, newRow, newCol);
                sum -= curr; //backtrack put original val;
                arr[newRow][newCol] = curr; //backtrack put original val;
            }
        }
    }
public:
    int getMaximumGold(vector<vector<int>>& arr) {
        int ans = 0;
        
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]!=0){
                    int curr = arr[i][j];
                    int sum=curr;
                    arr[i][j] = 0; //like mark as visited;
                    ans = max(ans, sum);
                    traverse(arr, ans, sum, i, j);
                    arr[i][j] = curr;
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna