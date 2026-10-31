class Solution {
private:
    vector<int>maxR(vector<vector<int>>& arr){
        int n = arr.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            int val = 0;
            for(int j=0;j<n;j++){
                val = max(arr[i][j], val);
            }
            v.push_back(val);
        }
        return v;
    }

    vector<int>maxC(vector<vector<int>>& arr){
        int n = arr.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            int val = 0;
            for(int j=0;j<n;j++){
                val = max(arr[j][i], val);
            }
            v.push_back(val);
        }
        return v;
    }

public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>maxRow = maxR(grid);
        vector<int>maxCol = maxC(grid);
        int sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = min(maxRow[i],maxCol[j]);
                sum += val-grid[i][j];
            }
        }

        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna