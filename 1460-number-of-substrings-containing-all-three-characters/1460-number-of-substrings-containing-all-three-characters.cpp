class Solution {
private:
    bool isValid(vector<int>& freq){
        int nonZero = 0;
        for(auto it : freq){
            nonZero += it != 0;
        }
        return nonZero == 3;
    }
public:
    int numberOfSubstrings(string s) {
        int r = 0, ans = 0;
        vector<int> freq(3,0); 
        for(int l=0;l<s.size();l++){
            while(r<s.size() && !isValid(freq)){
                freq[s[r] - 'a']++;
                r++;
            }
            if(isValid(freq))
                ans += s.length()-r + 1;
            freq[s[l]-'a']--;
        }
        return ans;
    }
};