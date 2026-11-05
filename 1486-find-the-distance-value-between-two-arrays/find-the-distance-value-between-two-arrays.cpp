class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        int n = arr1.size();
        int m = arr2.size();

        for(int i=0;i<n;i++){
            int curr = arr1[i];
            bool isValid = true;
            for(int j=0;j<m;j++){
                if(abs(curr-arr2[j]) <= d){
                    isValid = false;
                    break;
                }
            }
            if(!isValid) continue;
            count++;
        }
        
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna