class Solution {
public:
    string digitSum(string s, int k) {
        string ans = s;

        while(ans.length() > k){
            string tmp="";
            int sum=0;
            int count=0;
            for(int i=0;i<ans.length();i++){
                sum+=ans[i]-'0';
                count++;
                count %= k;
                if(count == 0){
                    tmp += to_string(sum);
                    // cout<<sum<<" ";
                    sum = 0;
                }
            }
            if(count != 0) tmp += to_string(sum);
            // cout<<"New ans = " << tmp;
            ans = tmp;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna