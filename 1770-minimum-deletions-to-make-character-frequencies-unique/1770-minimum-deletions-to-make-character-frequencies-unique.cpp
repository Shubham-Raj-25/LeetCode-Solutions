class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        
        for(auto it:s)
            freq[it-'a']++;
        
        unordered_set<int> seen;

        int ans = 0;

        for(int i=0;i<26;i++){
            while(freq[i] && seen.find(freq[i])!=seen.end()){
                freq[i]--;
                ans++;
            }
            seen.insert(freq[i]);
        }

        return ans;
    }
};