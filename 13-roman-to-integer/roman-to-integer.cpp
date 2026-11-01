class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int val = 0;
        for(int i=0;i<s.length();i++){
            if(i>0 && mp[s[i]] > mp[s[i-1]]){
                val -= 2*mp[s[i-1]];
            }
            val += mp[s[i]];
        }
        
        return val;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna