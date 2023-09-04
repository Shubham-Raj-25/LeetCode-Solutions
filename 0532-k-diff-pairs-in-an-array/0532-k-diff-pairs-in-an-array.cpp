class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> vals;

        set<pair<int,int>> pairs;

        for(auto it:nums) vals.insert(it);

        if(k){
        for(auto it:nums){
            if(vals.find(it+k)!=vals.end()){
                if(pairs.find({it,it+k})==pairs.end() && pairs.find({it+k,it})==pairs.end())
                    pairs.insert({it,it+k});
            }
            if(vals.find(it-k)!=vals.end()){
                if(pairs.find({it,it-k})==pairs.end() && pairs.find({it-k,it})==pairs.end())
                    pairs.insert({it,it-k});
            }
        }}
        else{
            unordered_map<int,int> mp;
            int sum = 0;
            for(auto it:nums){
                mp[it]++;
            }
            for(auto it:mp)
                if(it.second>1)
                sum++;
            
            return sum;
        }

        return pairs.size();
    }
};