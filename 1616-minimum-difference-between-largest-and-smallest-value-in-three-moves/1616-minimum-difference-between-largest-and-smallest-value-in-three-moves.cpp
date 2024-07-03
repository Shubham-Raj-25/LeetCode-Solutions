class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)
            return 0;
        // either eliminate left exterme or right extreme of sorted nums (draw diagram to realise)
        // also take cases of 2 left and 2 right dels
        // but always delete from extermes
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left_del = nums[n-1]-nums[3];
        int right_del = nums[n-4]-nums[0];
        int two_left_one_right_del = nums[n-2] - nums[2];
        int two_right_one_left_del = nums[n-3] - nums[1];

        return min(min(left_del,right_del),min(two_left_one_right_del,two_right_one_left_del));

    }
};