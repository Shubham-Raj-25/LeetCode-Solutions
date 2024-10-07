class Solution {
public:
    int minLength(string s) {
        bool found = true;
        while(found){
            found = false;
            for(int i=0;i<s.length()-1;i++){
                if((s[i]=='A' && s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D')){
                    if(s.length()==2) return 0;
                    string temp;
                    found = true;
                    for(int j=0;j<s.length();j++){
                        if(j==i || j==i+1) continue;
                        temp.push_back(s[j]);
                    }
                    s = temp;
                    break;
                }
            }            
            }
        return s.length();
    }
};