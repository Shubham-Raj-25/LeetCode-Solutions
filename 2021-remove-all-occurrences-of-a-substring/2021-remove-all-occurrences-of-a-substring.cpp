class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st, temp;
        string ans;
        reverse(part.begin(),part.end());
        int i = 0;
        for(char c : s){
            st.push(c);
            while(st.size() && i < part.length() && st.top() == part[i]){
                temp.push(st.top());
                st.pop();
                i++;
            }
            i = 0;
            bool shouldRefill = false;
            if(temp.size() != part.length()){
                shouldRefill = true;
            }
            while(temp.size()){
                char curr = temp.top();
                temp.pop();
                if(shouldRefill){
                    st.push(curr);
                }
            }
        }

        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};

/*

1 <= s.length <= 1000
1 <= part.length <= 1000

dab abc
  ___  ___

 ----
|daabcbaabcbc
 ----
dababc

asdfasdfxbcde part = abcde

axxyyb

ab 

*/ 