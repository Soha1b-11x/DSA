class Solution {
public:
    void binarySearch(vector<vector<int>>& intervals , unordered_map<int,int>&mp , int endi , int& startj){
        int n = intervals.size();
        int s=0,e=n-1;

        while(s<=e){
            int m = s+(e-s)/2;
            if(intervals[m][0] >= endi){
                startj = intervals[m][0];
                e=m-1;
            }else{
                s=m+1;
            }
        }
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int,int>mp;

        for(int i=0;i<intervals.size();i++){
            mp[intervals[i][0]] = i;
        }

        sort(intervals.begin(),intervals.end());
        vector<int>v(intervals.size(),-1);

        for(int i=0;i<intervals.size();i++){
            int starti = intervals[i][0];
            int endi = intervals[i][1];
            int startj = INT_MAX;
            // cout << starti <<" "<<endi <<" "<< startj ;
            binarySearch(intervals , mp , endi , startj);
            // cout << " "<< startj <<" "<<endl;
            if(startj != INT_MAX){
                v[mp[starti]] = mp[startj];
            }
        }
        return v;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna