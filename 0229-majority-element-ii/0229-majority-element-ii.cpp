class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // TC = O(n)
        // SC = O(1)
        unordered_map<int,int> mp;

        for(auto it:nums){
            mp[it]++;
            if(mp.size()>2){
                unordered_map<int,int> new_mp;
                for(auto itr:mp){
                    if(itr.second>1)
                        new_mp[itr.first] = itr.second-1;
                }
                mp = new_mp;
            }
        }

        vector<int> ans;

        for(auto it:mp){
            int check = it.first;
            int count = 0;
            for(auto itr:nums)
                if(check==itr) count++;
            
            if(count > nums.size()/3) ans.push_back(check);
        }

        return ans;

    }
};