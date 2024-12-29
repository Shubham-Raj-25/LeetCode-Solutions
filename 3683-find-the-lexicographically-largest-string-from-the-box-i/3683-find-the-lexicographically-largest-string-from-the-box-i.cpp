class Solution {
public:
    string answerString(string word, int numFriends) {
        // sliding window of word.len - numF + 1
        if(numFriends == 1){
            return word;
        }
        string ans = "";
        int maxLen = word.length() - numFriends + 1;
        for(int i = 0; i < word.length(); i++){
            ans = max(ans,word.substr(i,maxLen));
        }
        return ans;
    }
};