class Solution {
public:
    int minChanges(string s) {
        int ans = 0, i = 0;
        int currZeros = 0, currOnes = 0;
        
        while(i<s.length()){
            while(i<s.length() && s[i] == '0'){
                i++;
                currZeros++;
            }
            
            if(currZeros%2){
                ans++;
                currOnes++;
            }
            currZeros = 0;
            
            while(i<s.length() && s[i] == '1'){
                i++;
                currOnes++;
            }
            if(currOnes%2){
                ans ++;
                currZeros++;
            }
            currOnes = 0;
        }
        
        return ans;
        
    }
};