class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        // key idea
        // if 1 -> 4 is patched, adding 5 in num will patch upto 1 -> 9
        
        int idx = 0, ans = 0;
        long long patched_upto = 0;
        
        while(patched_upto < n){
            if(idx < nums.size() && nums[idx] <= patched_upto + 1)
                patched_upto += nums[idx++];
            else{
                ans++;
                patched_upto += patched_upto + 1;
            }
        }

        return ans;
    }
};