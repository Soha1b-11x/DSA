class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=n-1;i>1;i--){
            int left = 0, right = i-1;
            while(left < right){
                if(nums[left]+nums[right] > nums[i]){
                    count += right-left; // all pairs (left..right-1, right) work
                    right--;
                }else{
                    left++;
                }
            }
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna