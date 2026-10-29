class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>>reverseAdj(v);
        //reverse adj
        for(int i=0;i<v;i++){
            // i->it
            // it->i
            for(auto it:graph[i]){
                reverseAdj[it].push_back(i);
            }
        }

        //create indegree
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it:reverseAdj[i]){
                indegree[it]++;
            }
        }

        //push indegreee 0 in queue
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>arr;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            arr.push_back(node);

            for(auto it:reverseAdj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        sort(arr.begin(),arr.end());
        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna