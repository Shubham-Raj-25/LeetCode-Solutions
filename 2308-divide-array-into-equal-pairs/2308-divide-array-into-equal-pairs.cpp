class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) == mp.end()) mp[nums[i]]++;
            else{
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
            }
        }
        return mp.size() == 0 ;
    }
};