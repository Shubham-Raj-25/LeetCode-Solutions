class Solution {
public:

     bool isPred(string& a, string& b){
        if(b.length()!=a.length()+1)
            return false;
        int i = 0, j = 0;
        bool unequal = false;
        while(i<a.length() && j<b.length()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                if(!unequal){
                    j++;
                    unequal = true;
                }
                else
                    return false;
            }
        }

        return true;
    }


    int func(int curr, int prev, int len, vector<string>& words, vector<vector<int>>& mp){
        if(curr == words.size())
            return 0;
        
        if(mp[curr][prev+1]!=-1)
            return mp[curr][prev+1];
        
        // pick
        int pick = 0;
        if(prev == -1 || isPred(words[prev],words[curr]))
            pick = 1+ func(curr+1,curr,len+1,words,mp);
        
        // notPick
        int notPick = func(curr+1,prev,len,words,mp);

        return mp[curr][prev+1] = max(pick,notPick);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.length() < b.length();
        });
        int n = words.size();
        vector<vector<int>> mp(n+1, vector<int>(n+1,-1));
        return func(0,-1,0,words,mp);
    }
};