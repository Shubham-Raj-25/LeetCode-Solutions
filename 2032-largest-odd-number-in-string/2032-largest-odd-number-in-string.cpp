class Solution {
public:
    string largestOddNumber(string num) {
        int j = num.length()-1;
        string ans = "";
        for(;j>=0;j--){
            if((num[j]-48)%2!=0){
                for(int k=0;k<=j;k++)
                    ans.push_back(num[k]);
                break;
            }
                
        }

        return ans;
    }
};