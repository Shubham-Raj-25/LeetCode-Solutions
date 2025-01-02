class Solution {
public:
    unordered_set<char> vowels;
    bool isValid(string &s){ // O(1)
        return vowels.count(s[0]) && vowels.count(s.back()); 
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vowels = {'a','e','i','o','u'};
        int n = words.size();
        vector<int> prefix, ans;
        int sum = 0;
        for(auto word : words){
            sum += isValid(word);
            prefix.push_back(sum);
        }

        for(auto query : queries){
            int l = query[0], r = query[1];
            ans.push_back(prefix[r] - prefix[l] + isValid(words[l]));
        }

        return ans;
    }   
};