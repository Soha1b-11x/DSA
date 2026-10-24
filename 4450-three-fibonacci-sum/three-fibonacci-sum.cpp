class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long sum = 2;
        int fst=0,sec=1,trd=1;
        if(sum == n) return true;

        while(sum < n){
            sum -= fst;
            fst = sec;
            int copy3rd = trd;
            trd = sec+trd;
            sec = copy3rd;
            sum += trd;
            if(sum == n) return true;
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna