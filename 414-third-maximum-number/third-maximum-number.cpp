class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = nums[nums.size()-1];
        int count = 0;

        for(int i=nums.size()-2;i>=0;i--){
            if(i+1 < nums.size() && nums[i]!=nums[i+1]) count++;
            if(count == 2){
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna