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

     static bool compare(const string& a,const string& b){
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n = words.size();

        vector<int> dp(n,1);

        int ans= 1;

        for(int idx=0;idx<n;idx++){
            for(int prev = 0; prev < n; prev++){
                if(isPred(words[prev],words[idx]) && 1+dp[prev] > dp[idx])
                    dp[idx] = 1 + dp[prev];
            }
            ans = max(ans,dp[idx]);
        }

        return ans;
    }
};