class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int newElement = 0;

        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                newElement ++;
                ans += newElement;
            }
            else
                newElement = 0;
        }

        return ans;

    }
};