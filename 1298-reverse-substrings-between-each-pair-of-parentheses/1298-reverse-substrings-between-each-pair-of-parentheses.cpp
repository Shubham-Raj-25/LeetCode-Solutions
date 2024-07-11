class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";
        int idx = 0;

        for(int i=0;i<s.length();i++){
            if(s[i] == '(')
                st.push(idx);
            else if(s[i] == ')'){
                reverse(ans.begin()+st.top(),ans.begin()+idx);
                st.pop();
            }
            else{
                ans += s[i];
                idx++;
            }
        }

        return ans;
    }
};