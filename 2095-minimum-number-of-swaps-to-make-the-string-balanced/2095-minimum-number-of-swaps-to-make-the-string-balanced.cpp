class Solution {
public:
    int minSwaps(string s) {
        int ans = 0, cl = 0, op = 0;
        int j = s.length()-1;
        for(int i=0;i<s.length();i++){
            if(s[i] == '[')
                op++;
            else
                cl++;
            
            if(cl > op){
                while(s[j] != '[') j--;
                swap(s[i],s[j]);
                op++;
                cl--;
                ans++;
            }
        }

        return ans;
    }
};