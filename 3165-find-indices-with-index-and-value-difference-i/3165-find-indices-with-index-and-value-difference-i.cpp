class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
      int min_j = 0;
        int max_j = 0;

        for(int i=indexDifference, j = 0; i<nums.size(); i++, j++){
            min_j = nums[j] <= nums[min_j] ? j : min_j;
            max_j = nums[j] >= nums[max_j] ? j : max_j;
            if(abs(nums[i] - nums[min_j]) >= valueDifference)
                return {i,min_j};
            if(abs(nums[i] - nums[max_j]) >= valueDifference)
                return {i,max_j};
        }

        return {-1,-1};
}};