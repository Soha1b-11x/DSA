class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0 ,end = -1;
        int n = nums.size();

        //find end point
        int maxSoFar = nums[0];
        for(int i=1;i<n;i++){
            if(maxSoFar > nums[i]) end = i;
            else maxSoFar = nums[i];
        }

        //fint start point
        int minSoFar = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(minSoFar < nums[i]) start = i;
            else minSoFar = nums[i];
        }

        return end-start+1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna