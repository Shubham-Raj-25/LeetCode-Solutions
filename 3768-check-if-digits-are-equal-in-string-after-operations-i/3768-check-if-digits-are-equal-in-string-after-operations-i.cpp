class Solution {
public:
    bool hasSameDigits(string s) {
        if(s.length() == 2){
            return s[0] == s[1];
        }
        string s_new;
        
        for(int i=0;i<s.length()-1;i++){
            char c = int (s[i] - '0' + s[i+1]-'0') %10 + '0';
            s_new.push_back(c);
        }
        return hasSameDigits(s_new);
    }
};

/*

3902
22

*/ 