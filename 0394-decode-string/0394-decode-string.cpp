class Solution {
private:
    bool is_number(const std::string& s)
    {
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
    }
public:
    string decodeString(string s) {
        stack<string> st;
        string ans = "";

        for(int curr = 0; curr<s.length(); curr++){
            char c = s[curr];
            if(c != ']'){
                if(isdigit(c)){
                    string to_add = "";
                    to_add += c;
                    while(isdigit(s[curr+1])){
                        curr++;
                        to_add += s[curr];
                    }
                    st.push(to_add);
                }
                else{
                    string to_add = "";
                    to_add += c;
                    st.push(to_add);
                }
            }
            else{
                string data = "";
                string res = "";
                int multplier = 1;
                while(st.size()){
                    string top = st.top();
                    st.pop();
                    if(top != "["){
                        data += top;
                    }
                    else{
                        if(st.size() && is_number(st.top())){
                            multplier = stoi(st.top());
                            st.pop();
                        }
                        for(int i=0;i<multplier;i++){
                            res += data;
                        }
                        st.push(res);
                        break;
                    }
                }
            }
        }

        while(st.size()){
            string curr = st.top();
            ans += curr;
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};