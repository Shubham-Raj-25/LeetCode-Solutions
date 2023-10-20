class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size() && nums[j] == nums[i] +(j-i)%2;j++)
                ans = max(ans,j-i+1);
        }

        return ans > 1 ? ans: -1;
    }
};