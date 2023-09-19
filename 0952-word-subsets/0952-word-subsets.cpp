class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> w2f;

        for(auto it:words2){
            unordered_map<char,int> temp;
            for(auto c:it)
                temp[c]++;
            for(auto it:temp)
                if(it.second>w2f[it.first])
                    w2f[it.first] = it.second;
        }
        
        vector<string> ans;

        for(auto word: words1){
            bool check = true;
            unordered_map<char,int> temp;
            for(auto c:word)
                temp[c]++;
            for(auto it:w2f)
                if(it.second > temp[it.first]){
                    check = false;
                    break;
                }
            if(check) ans.push_back(word);
        }

        return ans;
    }
};