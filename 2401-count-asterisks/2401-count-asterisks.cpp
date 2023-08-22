class Solution {
public:
    int countAsterisks(string s) {
        int pair = 0;
        int i = 0;
        int ans = 0;
        while(i<s.length()){
            if(s[i]=='|')
                pair++;
            if(pair%2==0 && s[i]=='*') ans++;
            i++;
        }
        return ans;
    }
};