class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> freq(26,0);
        int ans = 0;
        
        for(char c : s){
            freq[c-'a']++;
        }

        for(char c = 'a'; c <= 'z'; c++){
            if(freq[c-'a'] < 2){
                continue;
            }
            int i = 0;
            while(s[i] != c){
                i++; // first appearance
            }
            
            i++;

            freq[c-'a']--;

            unordered_set<char>st;
            while(1){
                char m = s[i];
                if(m == c){
                    freq[c-'a']--;
                    if(freq[c-'a'] == 0)
                        break;
                }
                st.insert(m);
                i++;
            }
            ans += st.size();
        }

        return ans;
    }
};