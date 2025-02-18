class Solution {
private:
    bool func(string &s, vector<bool>& vis,string &pattern){
        if(s.length() == pattern.length()+1){
            return true;
        }

        int l = s.length();
        
        for(char c='1'; c<='9'; c++){
            if(!vis[c-'1']){
                if(l != 0){
                    if(pattern[l-1] == 'I' && c <= s.back() || pattern[l-1] == 'D' && c >= s.back()){
                        continue;
                    }
                }
                s.push_back(c);
                vis[c-'1'] = true;
                if(func(s,vis,pattern)){
                    return true;
                }
                s.pop_back();
                vis[c-'1'] = false;
            }
        }

        return false;
    }
public:
    string smallestNumber(string pattern) {
        vector<bool> vis(9,false);
        string s = "";
        func(s,vis,pattern);
        return s;
    }
};

/*

pattern

IIIDIDDD
123549876
*/ 