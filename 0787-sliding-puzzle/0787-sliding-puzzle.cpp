class Solution {
private:
    void swap_helper(int i, int j, string& word,queue<string>& q,unordered_set<string>& vis){
        swap(word[i],word[j]);
        if(!vis.count(word))
            vis.insert(word), q.push(word);
        swap(word[i],word[j]);
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string word;
        unordered_set<string> vis;
        queue<string> q;
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                word += to_string(board[i][j]);
        q.push(word);
        int swaps = 0;

        while(q.size()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == "123450") return swaps;

                int idx = curr.find("0");

                if(idx != 2 && idx != 5) // move right
                    swap_helper(idx,idx+1,curr,q,vis);
                if(idx != 0 && idx != 3) // move left
                    swap_helper(idx,idx-1,curr,q,vis);
                if(idx < 3) // move down
                    swap_helper(idx,idx+3,curr,q,vis);
                if(idx >= 3) // move up
                    swap_helper(idx,idx-3,curr,q,vis);
            }
            swaps++;
        }

        return -1;
    }
};