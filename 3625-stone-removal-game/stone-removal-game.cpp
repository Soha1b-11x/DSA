class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        if(n<10) return false;
        
        while(n>0){
            n -= remove;
            remove--;
            if(n < remove && remove%2 == 1) return true;
            if(n < remove && remove%2 == 0) return false;
        }
        
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna