class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mp;
        int n=text.length();

        for(int i=0;i<n;i++){
            mp[text[i]]++;
        }

        string s = "balloon";
        int count = INT_MAX;
        mp['l'] /= 2;
        mp['o'] /= 2;

        for(int i=0;i<7;i++){
            count = min(count, mp[s[i]]);
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna