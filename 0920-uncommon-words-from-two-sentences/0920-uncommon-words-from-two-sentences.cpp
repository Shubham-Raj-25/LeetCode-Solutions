class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        vector<string> ans;

        string temp = "";
        for(int i=0;i<s1.length();i++){
            temp = "";
            while(i < s1.length() && s1[i] != ' ')
                temp.push_back(s1[i++]);
            mp[temp]++;
        }

        for(int i=0;i<s2.length();i++){
            temp = "";
            while(i < s2.length() && s2[i] != ' ')
                temp.push_back(s2[i++]);
            mp[temp]++;
        }

        for(auto it: mp)
            if(it.second == 1)
                ans.push_back(it.first);

        return ans;
    }
};