class Solution {
public:
    bool checkString(string s) {
        
        bool found_b = false;

        for(auto c:s){
            if(c == 'a' && found_b)
                return false;
            if(c == 'b')
                found_b = true;
        }

        return true;
    }
};