class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> maxFreq, wordCharFreq;
        vector<string> ans;
        bool isSubset;

        for(string word : words2){
            for(char c : word){
                wordCharFreq[c]++;
                maxFreq[c] = max(maxFreq[c],wordCharFreq[c]);
            }
            wordCharFreq.clear();
        }

        for(string word : words1){
            isSubset = true;
            for(char c : word){
                wordCharFreq[c]++;
            }
            for(auto it : maxFreq){
                wordCharFreq[it.first] -= it.second;
                if(wordCharFreq[it.first] < 0){
                    isSubset = false;
                    break;
                }
            }
            if(isSubset){
                ans.push_back(word);
            }
            wordCharFreq.clear();
        }

        return ans;
    }
};