class Solution {
public:
    map<pair<int,int>,int> mp;
    int fn(int ind,int num,string &s)
    {
        if(ind==s.size())
        {
             if(num%25==0)return 0;
            return 1e9;
        }
        if(mp.find({ind,num})!=mp.end())return mp[{ind,num}];
        
        int digit=s[ind]-'0';
        int non_pick=1+fn(ind+1,num,s);
        int pick=fn(ind+1,(num*10+digit)%25,s);
        
        return mp[{ind,num}]=min(pick,non_pick);
    }
    int minimumOperations(string num) {
        return fn(0,0,num);
    }
};