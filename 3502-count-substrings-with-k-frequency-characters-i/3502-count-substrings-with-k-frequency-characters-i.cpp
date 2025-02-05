class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            vector<int> freq(26,0);
            int maxFreq = 0;
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;
                maxFreq = max(maxFreq,freq[s[j]-'a']);
                ans += maxFreq >= k;
            }
        }
        return ans;
    }
};

/*

// abacb ( aba: 3 + bacb: 2  3 + 2 -1 = 4
// k = 2
// atleast one character + atleast k times
// 1 <= s.length <= 3000 (O(N^2))
3000 * 3000 = 9 * 10^6 = 10^7

*/ 