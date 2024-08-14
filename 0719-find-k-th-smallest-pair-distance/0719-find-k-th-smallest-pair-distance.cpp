class Solution {
public:
    int func(int mid, vector<int>& nums){
        int count = 0, r = 0;

        for(int l=0; l<nums.size(); l++){
            while(r < nums.size() && nums[r] - nums[l] <= mid)
                r++;
            count += r-l-1;
        }

        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums[0];
        
        while(low < high){
            int mid = (high + low) / 2;
            int smaller_diff = func(mid, nums);
            
            if(smaller_diff >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
