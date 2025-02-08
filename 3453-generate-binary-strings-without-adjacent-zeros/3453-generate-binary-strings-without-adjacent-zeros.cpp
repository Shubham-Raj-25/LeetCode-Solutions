class Solution {
public:
    void func(string& s, int curr, int n, unordered_set<string>& st){
        if(curr == n){
            st.insert(s);
            return;
        }
        if(s[curr-1] == '1'){
            s.push_back('0');
            func(s,curr+1,n,st);
            s.pop_back();
        }
        s.push_back('1');
        func(s,curr+1,n,st);
        s.pop_back();
    }
    vector<string> validStrings(int n) {
        string s = "0";
        vector<string> ans;
        unordered_set<string> st; 
        
        func(s,1,n,st);
        s = "1";
        func(s,1,n,st);
        
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};