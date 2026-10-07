class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int l=0,r=0;
        unordered_map<char,int>mp;
        int count = 0;
        int minLen = INT_MAX , startIdx = 0;

        //initilize map
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }

        while(r<n){
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;

            while(count == t.length()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    startIdx = l;
                }

                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx , minLen);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna