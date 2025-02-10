class Solution {
public:
    string clearDigits(string s) {
        int countDigit = 0;
        string ans = "";
        for(int i=s.length()-1;i>=0;i--){
            if(isdigit(s[i])){
                countDigit++;
            }
            else{
                if(countDigit){
                    countDigit--;
                }
                else{
                    ans.push_back(s[i]);
                }
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
