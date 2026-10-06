class KthLargest {
private:
    priority_queue<int , vector<int> , greater<int>> q ; //min heap
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            if(q.size()>k) q.pop();
        }
        kth = k;
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>kth) q.pop();
        return q.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna