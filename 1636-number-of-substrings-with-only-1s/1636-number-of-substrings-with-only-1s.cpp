class Solution {
public:
    int mod = 1e9+7;

    int numSub(string s) {
        long long i = 0, ans = 0;

        while(i<s.length()){
            while(i<s.length() && s[i]=='0') i++;
            long long len = 0;
            while(i<s.length() && s[i]=='1'){
                len++;
                i++;
            }
            ans = (ans + (((long long)(len+1)*(long long)len)/2)%mod)%mod;
        }

        return ans;
    }
};