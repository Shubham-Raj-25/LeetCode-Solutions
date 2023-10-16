class Solution {
public:
    bool hamming(string& a, string& b){
        if(a.length()!=b.length()) return false;
        int diff = 0;
        for(int i=0;i<a.length();i++)
            if(a[i]!=b[i]) diff++;
        
        return diff==1;
    }

    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        vector<vector<string>> dp(n) ; // this will store longest subsequence found till i-th index

        for(int i=0;i<n;i++)
            dp[i].push_back(words[i]);
        
        int maxi = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(hamming(words[i],words[j]) && groups[i]!=groups[j]){
                    if(dp[j].size()+1 > dp[i].size()){
                        dp[i] = dp[j];
                        dp[i].push_back(words[i]);
                        maxi = max(maxi,(int)dp[i].size());
                    }
                }
            }
        }
        vector<string> ans;
        for(int i=0;i<n;i++)
            if(dp[i].size() == maxi){
                return dp[i];
            }
        return {"bye"};
    }
};