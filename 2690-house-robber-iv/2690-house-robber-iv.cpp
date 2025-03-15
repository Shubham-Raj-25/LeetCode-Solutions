// Binary Search on answer
class Solution {
public:
    bool func(vector<int>& nums,int k,int mid){
        int i = 0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                k--;
                i+=2;
            }else
                i++;
            if(k==0) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = INT_MAX;
        int ans = INT_MAX;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(func(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else
                low = mid+1;
        }

        return ans;
    }
};