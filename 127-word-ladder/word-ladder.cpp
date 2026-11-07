class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord, 1});
        unordered_set<string>s(wordList.begin(), wordList.end());
        s.erase(beginWord);

        while(!q.empty()){
            auto [str, size] = q.front();
            q.pop();
            if(str == endWord) return size;
            for(int i=0;i<str.length();i++){
                char original = str[i];
                for(char ch = 'a';ch<='z'; ch++){
                    str[i] = ch;
                    if(s.count(str)){
                        s.erase(str);
                        q.push({str, size+1});
                    }
                }
                str[i]=original;
            }
        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna