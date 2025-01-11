class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> mp;
        int oddCount = 0;

        if(k > s.length()){
            return false;
        }
        for(char c : s){
            mp[c]++;
        }
        for(auto it: mp){
            oddCount += it.second % 2;
        }

        return oddCount <= k;
    }
};