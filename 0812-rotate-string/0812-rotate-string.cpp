class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.length() != s.length())
            return false;
        
        goal += goal;
        
        for(int i=0;i<goal.length()-s.length();i++)
            if(s == goal.substr(i,s.length()))
                return true;
        
        return false;
    }
};