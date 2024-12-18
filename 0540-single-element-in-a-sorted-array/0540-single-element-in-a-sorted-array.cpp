class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size();

        while(low+1<high){
            int mid = low + (high-low)/2;
            int smaller_elements = mid;
            if(mid>0 && nums[mid]==nums[mid-1]){
                smaller_elements--;
            }
            if(smaller_elements % 2 == 0){
                low=mid;
            }
            else{
                high = mid;
            }
        }

        return nums[low];

    }
};