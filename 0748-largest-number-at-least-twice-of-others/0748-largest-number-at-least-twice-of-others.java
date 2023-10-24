class Solution {
    public int dominantIndex(int[] nums) {
        int maxi = -1;
        int idx = 69;
        for(int i=0;i<nums.length;i++)
            {
                if(nums[i] > maxi){
                    idx = i;
                    maxi = nums[i];
                }
            }

        for(Integer num:nums)
            if(maxi != num && maxi < 2* num)
                return -1;
        return idx;
    }
}