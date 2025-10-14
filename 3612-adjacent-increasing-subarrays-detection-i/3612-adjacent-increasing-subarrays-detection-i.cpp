class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1)
            return true;
        
        for(int i=0; i <= nums.size() - 2 * k; i++){
            bool found = true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j] <= nums[j-1])
                    found =  false;
            }
            for(int j=i+k+1;j<i+2*k;j++){
                if(nums[j] <= nums[j-1])
                    found =  false;
            }

            if(found)
                return found;
        }
        
        return false;  
    }
};