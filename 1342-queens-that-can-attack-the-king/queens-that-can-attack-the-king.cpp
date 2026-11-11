class Solution {
    bool canAttackOnPlus(vector<vector<char>>& arr, int sr, int sc){
        int row = 8, col = 8;
        int r = sr-1; 
        //can attack on row up
        while(r>=0){
            if(arr[r][sc]=='K') return true;
            else if(arr[r][sc]=='Q') break;
            r--;
        }
        //can attack on row down
        r= sr+1;
        while(r<8){
            if(arr[r][sc]=='K') return true;
            else if(arr[r][sc]=='Q') break;
            r++;
        }
        
        int c = sc-1;
        //can attack on col left
        while(c>=0){
            if(arr[sr][c]=='K') return true;
            else if(arr[sr][c]=='Q') break;
            c--;
        }
        //can attack on col right
        c = sc+1;
        while(c<8){
            if(arr[sr][c]=='K') return true;
            else if(arr[sr][c]=='Q') break;
            c++;
        }
        return false; 
    }

    bool canAttackOnCross(vector<vector<char>>& arr, int sr, int sc){
        // check topleft
        int r = sr-1, c = sc-1;
        while(r>=0 && c>=0){
            if(arr[r][c]=='K') return true;
            else if(arr[r][c]=='Q') break;
            r--, c--;
        }
        // check top right
        r = sr-1, c = sc+1;
        while(r>=0 && c<8){
            if(arr[r][c]=='K') return true;
            else if(arr[r][c]=='Q') break;
            r--, c++;
        }
        // check bottom left
        r = sr +1, c = sc-1;
        while(r<8 && c>=0){
            if(arr[r][c]=='K') return true;
            else if(arr[r][c]=='Q') break;
            r++, c--;
        }
        //check bottom right
        r = sr+1, c = sc+1;
        while(r<8 && c<8){
            if(arr[r][c]=='K') return true;
            else if(arr[r][c]=='Q') break;
            r++, c++;
        }

        return false;
    }

    void check(vector<vector<char>>& arr, vector<vector<int>>& attack, int sr, int sc){
        bool plus = canAttackOnPlus(arr, sr, sc);
        bool cross = canAttackOnCross(arr, sr, sc);
        if(plus || cross) attack.push_back({sr, sc});
    }
    
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // build board
        vector<vector<char>>arr(8, vector<char>(8, 'x'));
        // place queens & king
        for(auto queen : queens){
            int r=queen[0], c=queen[1];
            arr[r][c] = 'Q';
        }
        arr[king[0]][king[1]] = 'K';

        vector<vector<int>>attack;

        for(auto queen : queens){
            int sr = queen[0], sc = queen[1];
            check(arr, attack, sr, sc);
        }

        return attack;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna