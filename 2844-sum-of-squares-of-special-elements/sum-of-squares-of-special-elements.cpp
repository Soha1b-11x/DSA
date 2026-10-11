class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            if(n % (i+1) == 0){
                ans += nums[i]*nums[i];
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna