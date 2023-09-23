class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        string vow = "aeiou";
        for(int i=0;i<s.length();i++){
            char c = tolower(s[i]);
            if(vow.find(c)!=vow.npos){
                if(i<s.length()/2)
                    cnt1++;
                else
                    cnt2++;
            }
        }

        return cnt1==cnt2;
    }
};