class Solution {
    void solve(string s, vector<string>& arr, int idx, int n){
        if(idx==n){
            arr.push_back(s);
            return;
        }

        if(isalpha(s[idx])){
            string lower = s;
            lower[idx] = tolower(s[idx]);
            solve(lower, arr, idx+1, n);

            string upper = s;
            upper[idx] = toupper(s[idx]);
            solve(upper, arr, idx+1, n);
        }else{
            solve(s, arr, idx+1, n);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>arr;
        int n = s.length();
        solve(s, arr, 0, n);
        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna