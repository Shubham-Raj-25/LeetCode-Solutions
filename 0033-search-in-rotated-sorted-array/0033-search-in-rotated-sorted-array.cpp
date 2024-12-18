class Solution {
public:
    int findPivot(vector<int>nums){
        // find min index for which nums[idx] < nums[0]
        int low = 0, high = nums.size();
        while(low+1<high){
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[0]){ // right branch 
                high = mid;
            }
            else{
                low = mid;
            }
        }
        if(high == nums.size()){ // meaning no pivot
            return 0;
        }
        return high;
    }

    int findTarget(int l, int r, int target, vector<int>& nums){
        int low = l, high = r+1;
        while(low+1<high){
            int mid = low + (high-low)/2;
            if(nums[mid] <= target){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        if(nums[low] != target){ // meaning no pivot
            return -1;
        }
        return low;
    }

    int search(vector<int>& nums, int target) {
        // first find the pivot
        // check in which part the target will lie
        // bs in that part
        int n = nums.size();
        int pivot = findPivot(nums);
        int l, r;
        
        if(nums[n-1] >= target){
            l = pivot;
            r = n-1;
        }
        else{
            l = 0;
            r = pivot-1;
        }

        return findTarget(l,r,target,nums);
    }
};