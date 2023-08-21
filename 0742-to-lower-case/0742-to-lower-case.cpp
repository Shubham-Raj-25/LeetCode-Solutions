class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(auto it:s)
            ans.push_back(tolower(it));
        return ans;
    }
};