class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxi = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            unordered_set<int> vis;
            int len = 0;
            int idx = i;
            while(1){
                if(mp.find(idx)!=mp.end()){
                    len += mp[i];
                    break;
                }
                if(vis.find(nums[idx])!=vis.end())
                    break;
                vis.insert(nums[idx]);
                mp[idx] = len;
                idx  = nums[idx];
                len++;
            }

            maxi = max(maxi,len);

            mp[i] = len;
        }

        return maxi;
    }
};