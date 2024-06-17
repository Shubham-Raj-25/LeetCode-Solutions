class Solution {
public:
    int findMinStep(string board, string hand) {
        vector<int> freq(26,0);
        for(auto c : hand)
            freq[c-'A']++;
        unordered_map<string,int> dp;
        return dfs(board,freq,dp);
    }

    int dfs(string& board,vector<int>& freq,unordered_map<string,int>& dp){
        string key = board + "#" + serialize(freq);
        
        if(dp.find(key) != dp.end())
            return dp[key];
        
        int r = INT_MAX;

        if(board.length() == 0)
            r = 0;
        else{
            for(int i=0;i<board.length();i++){
                for(int j=0;j<26;j++){
                    bool worthTrying = false;
                    if( (board[i]-'A' == j) || (0 < i && board[i] == board[i-1] && board[i]-'A' !=j))
                        worthTrying = true;
                    
                    if(freq[j] && worthTrying){
                        board.insert(board.begin() + i, j + 'A');
                        freq[j]--;

                        string newStr = updateBoard(board);
                        int steps = dfs(newStr, freq, dp);
                        if(steps != -1)
                            r = min(r, steps+1);
                        
                        freq[j]++;
                        board.erase(board.begin()+i);
                    }

                }
            }
        }
        if(r == INT_MAX)
            r = -1;
        dp[key] = r;
        return r;
    }

    string updateBoard(string board){
        int start = 0, end = 0, len = board.length();

        while(start < len){
            while(end < len && board[start] == board[end])
                end++;
            
            if(end - start >= 3){
                string newBoard = board.substr(0,start) + board.substr(end);
                return updateBoard(newBoard);
            } else {
                start = end;
            }
        }
        return board;
    }

    string serialize(vector<int>& freq){
        string key = "";
        for(int i=0;i<26;i++)
            if(freq[i])
                key += to_string((char)i + 'A') + to_string(freq[i]);
        return key;
    }  
};