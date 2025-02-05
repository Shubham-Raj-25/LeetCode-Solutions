class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length()){
            return false;
        }

        if(s1 == s2){
            return true;
        }

        int firstDiff = -1, secondDiff = -1;

        for(int i=0;i<s1.length();i++){
            if(s1[i] != s2[i]){
                if(firstDiff == -1){
                    firstDiff = i;
                }
                else if(secondDiff == -1){
                    secondDiff = i;
                }
                else{
                    return false;
                }
            }
        }
        
        if(secondDiff == -1){
            return false;
        }

        return s1[firstDiff] == s2[secondDiff] && s1[secondDiff] == s2[firstDiff];
    }
};