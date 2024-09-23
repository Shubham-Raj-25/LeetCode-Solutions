class Solution {
public:
    int func(int idx, string s, unordered_set<string>& dict, vector<int>& dp){
        if(idx == s.length())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        string temp = "";

        dp[idx] = s.length();

        for(int cut=idx;cut<s.length();cut++){
            temp.push_back(s[cut]);
            int currExtra = dict.count(temp) == 0 ? temp.length() : 0;
            int futureExtra = func(cut+1,s,dict,dp);
            dp[idx] = min(dp[idx], currExtra + futureExtra);
        }   
        return dp[idx];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        vector<int> dp(s.length(),-1);
        for(string word : dictionary) dict.insert(word);
        return func(0,s,dict,dp);
    }
};