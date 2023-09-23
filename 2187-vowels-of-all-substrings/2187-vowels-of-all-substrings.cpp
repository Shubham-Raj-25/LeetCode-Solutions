class Solution {
public:
    long long countVowels(string word) {
     unordered_set<char> st;

     long long ans = 0;
     string vow = "aeiou";
     for(auto c: vow) st.insert(c);

     for(int i=0;i<word.size();i++){
         if(st.find(word[i])!=st.end())
            ans += (i+1) * (word.size()-i); // the main formula
     }   

     return ans;
    }
};