class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        int ans = 0;
        for(char c : s){
            freq[c - 'a'] += 1;
        }
        
        for(int i : freq){
            if(i % 2){ // odd
                ans += 1;
            }
            else if(i != 0){
                ans += 2;
            }
        }
        
        return ans;
    }
};

