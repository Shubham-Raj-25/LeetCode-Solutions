class Solution {
public:
    int isValid(int curr, vector<int> nums, bool is_left){
        while(curr >= 0 && curr < nums.size()){
            if(is_left){
                curr--;
            }
            else{
                curr++;
            }
            if(curr >= 0 && curr < nums.size()){
                if(nums[curr] != 0){
                    nums[curr]--;
                    is_left = !is_left;
                }
            }
        }
        for(auto it: nums)
            if(it)
                return 0;
        return 1;
    }
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0)
                ans += isValid(i,nums,true) + isValid(i, nums,false);
        }
        
        return ans;
    }
};