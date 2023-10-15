class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int last = -1;
        for(int i=0;i<words.size();i++){
            if(groups[i]!=last){
                ans.push_back(words[i]);
                last = groups[i];
            }
        }

        return ans;
    }
};