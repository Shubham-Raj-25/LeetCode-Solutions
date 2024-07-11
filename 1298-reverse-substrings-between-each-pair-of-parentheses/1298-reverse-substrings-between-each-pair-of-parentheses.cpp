class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        string ans = "";
        int cnt = 0;
        for (int i = 0;i<n;i++){
            if (s[i] == '('){
                st.push(cnt);
            }
            else if (s[i] == ')'){
                reverse(ans.begin()+st.top() , ans.begin() + cnt);
                st.pop();
            }
            else {
                ans += s[i];
                ++cnt;
            }
        }

        return ans;
    }
};