class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,bool> mp;
        for(auto it: arr1){
            string data = to_string(it);
            for(int i=1;i<=data.length();i++)
                mp[data.substr(0,i)] = true;
        }

        int ans = 0;

        for(auto it: arr2){
            string data = to_string(it);
            for(int i=1;i<=data.length();i++)
                if(mp.find(data.substr(0,i)) != mp.end())
                    ans = max(ans,i);
        }        

        return ans;
    }
};