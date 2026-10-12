class Solution {
public:
    void BFS(vector<vector<int>>& isConnected , vector<bool>& isVis , int start){
        queue<int>q;
        q.push(start);
        isVis[start] = true;

        while(!q.empty()){
            int src = q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++){
                if(!isVis[i] && isConnected[src][i]==1){
                    isVis[i] = true;
                    q.push(i);
                }
            }
        }
        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>isVis(n , false);
        int component = 0;

        for(int i=0;i<n;i++){
            if(!isVis[i]){
                BFS(isConnected , isVis , i);
                component++;
            }
        }

        return component;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna