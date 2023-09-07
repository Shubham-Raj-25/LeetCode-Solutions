class Solution {
public:
    
    bool check(string& word, unordered_set<string>& st){
        int n = word.length();
        vector<bool> dp(n+1,false);
        dp[0] = true;

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && st.find(word.substr(j,i-j))!=st.end())
                    {
                        dp[i] = true;
                        break;
                    }
            }
        }

        return dp[n];
    
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;
        for(auto it:words)
            st.insert(it);

        vector<string> ans;
        
        for(auto word:words){
            st.erase(word);
            if(!words.empty() && check(word,st))
                ans.push_back(word);
            st.insert(word);
        }

        return ans;
    }
};