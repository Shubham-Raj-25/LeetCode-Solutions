class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> occur(26,{-1,-1});
        int n = s.length();

        for(int i=0;i<n;i++){
            if(occur[s[i]-'a'].first==-1) occur[s[i]-'a'].first=i; // will store the first occurance
            else occur[s[i]-'a'].second = i; // will end up storing the last occurance
        }

        int ans = 0;

        for(int i=0;i<26;i++){
            if(occur[i].second!=-1){ // means appear a second time
                unordered_set<char> st;
                    for(int j=occur[i].first+1;j<=occur[i].second-1;j++) st.insert(s[j]);
                    ans += st.size();                    
            }
        }

        return ans;
    }
};