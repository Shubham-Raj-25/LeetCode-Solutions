class Solution {
public:

    int func(int curr, string s, vector<int>& dp, unordered_set<string>& st){
        if(curr >= s.length())
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        dp[curr] = s.length();

        string currStr = "";

        for(int cut=curr;cut<s.length();cut++){
            currStr.push_back(s[cut]);
            int currExtra = st.find(currStr) == st.end() ? currStr.length() : 0;
            int futureExtra = func(cut+1,s,dp,st);
            dp[curr] = min(dp[curr],currExtra+futureExtra);
        }

        return dp[curr];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.length(),-1);
        unordered_set<string> st;
        for(auto it:dictionary) st.insert(it);
        return func(0,s,dp,st);
    }
};