class Solution {
public:
    int check(unordered_set<char>& st, string temp){
        for(auto it:temp)
            if(st.find(it)==st.end())
                return 0;
        return 1;;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(auto it:allowed)
            st.insert(it);
        int ans = 0;

        for(auto it: words)
            ans += check(st,it);
        
        return ans;
    }
};