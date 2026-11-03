class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++) maxVal = max(nums[i],maxVal);

        int moves = 0;
        for(int i=0;i<n;i++){
            moves += maxVal-nums[i];
        }

        return moves;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna