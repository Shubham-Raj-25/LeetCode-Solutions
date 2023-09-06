class Solution {
public:
    

    bool isValid(string s){
        stack<char> st;

        for(auto c:s){
            if(c!='(' && c!=')') continue;
            else if(c=='(') st.push('(');
            else{
                if(st.size()==0) return false;
                st.pop();
            }
        }

        return st.size()==0;
    }

    void func(int idx, string temp,unordered_set<string>& st,int max_len,map<pair<int,string>,int>& dp){

        if(dp.find({idx,temp})!=dp.end())
            return;

        if((int)temp.length()>=max_len && isValid(temp))
            {   max_len = temp.length();
                st.insert(temp);
                return;}

        if(idx==temp.length())
            return;
        
        // delete
        if((int)temp.length() > max_len && (temp[idx] == '(' || temp[idx] == ')'))
        {string og = temp;
        temp.erase(idx,1);
        func(idx,temp,st,max_len,dp);
        temp = og;}

        //skip
        func(idx+1,temp,st,max_len,dp);
        
        dp[{idx,temp}] = 1;

    }

    vector<string> removeInvalidParentheses(string s) {
        // naeive approach, in a set store all valid strings, then take the longest ones

        unordered_set<string> st;

        map<pair<int,string>,int> dp;

        func(0,s,st,0,dp);

        int len = -1;

        for(auto it:st)
            len = max(len,(int)it.length());
        
        vector<string> ans;

        for(auto it:st)
            if(it.length()==len)
                ans.push_back(it);
        
        if(ans.size()==0)
            ans.push_back("");
        return ans;
    }
};