class Solution {
private:
    void DFS(int src, vector<vector<int>>& graph, vector<int>&isColor, bool& ans){
        if(!ans) return;
        int color = isColor[src];
        for(int nxt : graph[src]){
            if(isColor[nxt]==-1){
                if(color==1) isColor[nxt]=0, DFS(nxt, graph, isColor, ans);
                if(color==0) isColor[nxt]=1, DFS(nxt, graph, isColor, ans);
            }else if(color == isColor[nxt]){
                ans = false; return;
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>isColor(v,-1);
        bool ans = true;
        for(int i=0;i<v;i++){
            if(isColor[i]==-1){
                isColor[i]=0; //color by 0
                DFS(i, graph, isColor, ans);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna