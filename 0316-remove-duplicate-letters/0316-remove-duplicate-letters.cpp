class Solution {
public:
    string removeDuplicateLetters(string s) {
    // dp problem?
    stack<char> st;
    unordered_set<char> dic;
    unordered_map<char,int> mp;

    for(auto it:s){
        mp[it]++;
    }

    for(auto it:s){
        if(dic.find(it)!=dic.end()) {
            mp[it]--;
            continue;}

        while(!st.empty() && st.top()>it && mp[st.top()]>1){
            mp[st.top()]--;
            dic.erase(st.top());
            st.pop();
        }
        dic.insert(it);
        st.push(it);
    }

    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
    }
};