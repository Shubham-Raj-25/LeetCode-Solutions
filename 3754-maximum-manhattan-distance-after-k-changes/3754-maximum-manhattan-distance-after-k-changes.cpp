class Solution {
public:
    int maxDistance(string s, int k_) {
        unordered_map<char,int> mp;
        int k = k_;
        int ans = 0;
        
        for(char c : s){
            k = k_;
            mp[c]++;
            int vertical = abs(mp['N'] - mp['S']);    
            int mini = min(mp['N'],mp['S']);
            vertical += 2 * min(mini,k);
            k -= min(mini,k);
            
            int horizontal = abs(mp['W'] - mp['E']);
            mini = min(mp['W'],mp['E']);
            horizontal += 2 * min(mini,k);
            
            ans = max(ans, vertical+horizontal);
        }
        
        return ans;
    }
};