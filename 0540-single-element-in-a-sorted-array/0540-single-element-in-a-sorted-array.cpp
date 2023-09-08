class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // brute force first then logn
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            cout << nums[i] << endl;
            if(i==0 && nums[i]!=nums[i+1])
                 return nums[i];
            else if(i==nums.size()-1 && nums[i]!=nums[i-1])
                 return nums[i];
            else if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1])
                 return nums[i];
        }

        return 69;
    }
};