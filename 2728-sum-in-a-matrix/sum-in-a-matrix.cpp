class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        vector<priority_queue<int>>arr;
        int n = nums.size();
        int m = nums[0].size();
        int score = 0;

        //put all in priority queue array
        for(int i=0;i<n;i++){
            priority_queue<int>q;
            for(int j=0;j<m;j++){
                q.push(nums[i][j]);
            }
            arr.push_back(q);
        }
        
        for(int i=0;i<m;i++){
            int maxVal = INT_MIN;
            for(int j=0;j<n;j++){
                maxVal = max(arr[j].top(),maxVal);
                arr[j].pop();
            }
            score += maxVal;
        }

        return score;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna