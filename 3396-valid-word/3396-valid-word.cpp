class Solution {
public:
    bool isValid(string word) {
        unordered_set<char> vowels = {'a','A', 'e', 'E', 'i', 'I','o', 'O','u', 'U'};
       
        if(word.length() < 3)
            return false;

        bool vowel = false, consonent = false , special_char = false;

        for(char c : word){
            if(isalpha(c)){
                if(vowels.find(c) != vowels.end())
                    vowel = true;
                else
                    consonent = true;
            }
            else if(!isdigit(c)){
                special_char = true;
            }
        }
        return (vowel && consonent) && !special_char;

    }
};