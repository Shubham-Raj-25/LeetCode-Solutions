class Solution {
public:
    bool isSubsequence(string word, string s){
        int i=0,j=0;
        while(i<word.length() && j<s.length()){
            if(word[i]==s[j])
                i++;
            j++;
        }

        return i==word.length();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for(auto word:dictionary){
            if(word.length()>ans.length() || (word.length()==ans.length()) && word<ans)
                if(isSubsequence(word,s))
                    ans = word;
        }

        return ans;

    }
};