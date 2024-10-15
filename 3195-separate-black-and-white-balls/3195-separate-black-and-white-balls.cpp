class Solution {
public:
    long long minimumSteps(string s) {
        int j = 0;
        long long ans = 0;

        string p = s;
        sort(p.begin(),p.end());
        
        while(j<p.length() && p[j] != '1') j++;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                ans += j - i;
                j++;
            }
        }

        return ans;
    }
};