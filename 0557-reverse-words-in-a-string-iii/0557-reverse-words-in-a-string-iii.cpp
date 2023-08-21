class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string ans = "";
        while(i<s.length()){
            string temp;
            while(i<s.length() && s[i]!=' '){
                temp.push_back(s[i++]);
            }
            reverse(temp.begin(),temp.end());
            ans+=temp;
            ans.push_back(' ');
            i++;
        }

        return ans.substr(0,ans.length()-1);
    }

};