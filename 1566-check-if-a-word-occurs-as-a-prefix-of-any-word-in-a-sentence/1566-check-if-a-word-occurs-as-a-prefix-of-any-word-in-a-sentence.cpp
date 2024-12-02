class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word_idx = 1, len = searchWord.length();
        
        for(int i=0;i<sentence.length();i++){
            string word = "";
            while(i < sentence.length() && sentence[i]!= ' ')
                {
                    word += sentence[i];
                    i++;
                }
            if(word.substr(0,len) == searchWord)
                return word_idx;
            word_idx++;
        }

        return -1;
    }
};