class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,int> mp;
        int l=0;
        int pairs=0;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            pairs += mp[nums[i]]-1;
            
            if(pairs>=k){
                while(l<=i && pairs>=k){
                    ans += nums.size()-i;
                    mp[nums[l]]--;
                    pairs -= mp[nums[l]];
                    l++;
                }  
            }
        }
        return ans;
    }
};