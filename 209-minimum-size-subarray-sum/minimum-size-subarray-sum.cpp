class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // brute force
        int ans = INT_MAX;
        int n = nums.size();
        int l=0,r=0;
        int sum=0;

        while(r<n){
            sum += nums[r];
            
            while(sum >= target && l<r){
                ans = min(ans , r-l+1);
                sum -= nums[l];
                l++;
            }
            if(sum >= target) ans = min(ans , r-l+1);
            r++;
        }
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     int j;
        //     for(j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum >= target) break;
        //     }
        //     if(sum >= target) ans = min(ans , j-i+1);
        // }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna