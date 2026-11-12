class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int longestDecreas = 1;
        int longestIncreas = 1;

        //longest increasing
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                count++;
                longestIncreas = max(longestIncreas, count);
            }else{
                count = 1;
            }
        }

        count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count++;
                longestDecreas = max(longestDecreas, count);
            }else count = 1;
        }

        return max(longestDecreas, longestIncreas);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna