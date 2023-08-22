class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber){
            columnNumber --;
            int toAdd = columnNumber % 26;
            ans += 'A' + toAdd;
            columnNumber /= 26;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};