class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // brute force
        if(s.length()==1)
            return false;
        
        string temp = "";
        for(int i=0;i<s.length()/2;i++){
            temp = s.substr(0,i+1);
            // cout << temp << endl;
            bool check = true;
            for(int k=i+1;k<s.length();k+=temp.length()){
                if(s.substr(k,temp.length())!=temp){
                    // cout << "here" << endl;
                    check = false;
                    break;
                }
            }
            if(check)
                return true;
        }

        return false;
    }
};