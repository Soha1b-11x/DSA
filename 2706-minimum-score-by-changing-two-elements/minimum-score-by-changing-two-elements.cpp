class Solution {
    int first2(vector<int> nums){
        int n=nums.size();
        nums[0] = nums[2];
        nums[1] = nums[2];
        int high = nums[n-1]-nums[0];  
        return high;
    }

    int last2(vector<int> nums){
        int n=nums.size();
        nums[n-1] = nums[n-3];
        nums[n-2] = nums[n-3];
        int high = nums[n-1]-nums[0];
        return high;
    }

    int firstLast(vector<int> nums){
        int n=nums.size();
        nums[0] = nums[1];
        nums[n-1] = nums[n-2];
        int high = nums[n-1]-nums[0];
        return high;
    }

public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int score = INT_MAX;
        
        score = min(score, first2(nums));
        score = min(score, last2(nums));
        score = min(score, firstLast(nums));

        return score;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna