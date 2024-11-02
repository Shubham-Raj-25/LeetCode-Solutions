class Solution {
public:
    bool isCircularSentence(string s) {
        int i = 0;
      
        int e = 0;
        
        while(i< s.length()){
            if(s[i] == ' '){
                if(s[i-1]!=s[i+1])
                    return false;
            }
            i++;
        }
        if(s[0]!=s[i-1])
            return false;
        
        return true;
    }
};