class Solution {
public:
    int moves(vector<int>& nums, int i){
        int data = 0;
        if(i<0)
            return INT_MAX;
        for(auto it:nums)
            data += abs(it-nums[i]);
        return data;
    }

    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = INT_MAX;

        if(n%2){
            ans = min(ans,moves(nums,n/2));
        }
        else{
            ans = min(ans,moves(nums,n/2-1));
            ans = min(ans,moves(nums,n/2));
        }

        return ans;

    }
};