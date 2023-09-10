class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> data = nums;
        sort(data.begin(),data.end());
        int ans = 0;
        int left = -1, right = -1;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=data[i] && left == -1) left = i;
            else if(nums[i]!=data[i]) right = i;
        
        if(left==right) return 0;

        return right-left+1;
    }
};