class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        int n = exp.length();
        vector<bool> res;
        for (int i = n - 1; i > 0; i--) {
            char c = exp[i];

            if (c == ')' || c == 't' || c == 'f') {
                st.push(c);
            } else if (c == '(') {
                char sign = exp[i - 1];
                while (st.top() != ')') {
                    if (st.top() == 't') {
                        res.push_back(1);
                    } else if (st.top() == 'f') {
                        res.push_back(0);
                    }
                    st.pop();
                }
                st.pop();
                if (sign == '|') {
                    bool output = res[0];
                    for (int i = 1; i < res.size(); i++) {
                        output |= res[i];
                    }
                    output ? st.push('t') : st.push('f');
                } else if (sign == '&') {
                    bool output = res[0];
                    for (int i = 1; i < res.size(); i++) {
                        output &= res[i];
                    }
                    output ? st.push('t') : st.push('f');
                } else {
                    bool output = !res[0];
                    output ? st.push('t') : st.push('f');
                }
                res = {};
            } else
                continue;
        }
        return st.top() == 't';
    }
};