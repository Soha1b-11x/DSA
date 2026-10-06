class Solution {
public:
    int minAddToMakeValid(string s) {
        int start = 0 , end = 0;
        int needToAdd = 0;
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(st.empty()){ needToAdd++; }
                else st.pop();
            }
        }

        return st.size() + needToAdd;
    }
};