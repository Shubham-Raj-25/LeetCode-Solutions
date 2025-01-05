class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.length();
        vector<int> delta(len+1,0);
        
        for(auto shift : shifts){
            if(shift[2] == 0){
                shift[2] = -1;
            }
            delta[shift[0]] += shift[2];
            delta[shift[1]+1] -= shift[2];
        }
        int prefix = 0;
        for(int i=0;i<len;i++){
            prefix += delta[i];
            char c = s[i];
            int to_move = prefix;
            if(to_move <= 0){
                to_move = -to_move;
                while(to_move--){
                    if(c == 'a'){
                        c = 'z';
                    }
                    else{
                        c = c - 1;
                    }
                }
            }
            else{
                while(to_move--){
                    if(c == 'z'){
                        c = 'a';
                    }else{
                        c = c + 1;
                    }
                }     
            }

            s[i] = c;
        }
        return s;
    }
};