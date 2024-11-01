class Solution {
public:
    string makeFancyString(string s) {
        string ans =  "";
        char last_char = 'A';
        int count = 0;
        for(char c : s){
            if(c == last_char){
                count++;
            }
            else{
                last_char = c;
                count = 1;
            }
            if(count < 3)
                ans.push_back(c);
        }

        return ans;
    }
};