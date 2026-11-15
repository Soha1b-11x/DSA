class Solution {
public:
    long long countValidSubstrings(string s) {
        long long count=0;
        int n=s.length();
        int l=0,r=0;

        while(r<n){
            if(r>=2 && s[r-2]=='a' && s[r-1]=='b' && s[r]=='c') l = r - 1;
            count += r-l+1;
            r++;
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna