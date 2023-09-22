class Solution {
public:
    map<pair<int,int>,bool> mp;

    bool func(int i, int j, string s, string t){
        if(i==s.length())
            return true;

        if(j==t.length())
            return false;
        
        if(mp.find({i,j})!=mp.end())
            return mp[{i,j}];

        // take
        bool take = false, notTake = false;

        if(s[i]==t[j])
            take = func(i+1,j+1,s,t);

        // not Take
        notTake = func(i,j+1,s,t);

        return mp[{i,j}] = take||notTake;

    }

    bool isSubsequence(string s, string t) {
        return func(0,0,s,t);
    }
};