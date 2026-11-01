class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int n=s.length();
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i]==')') count--;
            if(count >= 1) ans.push_back(s[i]);
            if(s[i]=='(') count++;
            
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna