class Solution {
public:
    int less_or_equal(int a, vector<int>& nums){    
        int ans = 0;
        for(auto it:nums)
            if(it<=a)
                ans++;
        return ans;
    }

    int findDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size();    
        int duplicate = -1;

        while(low <= high){
            int mid = (low+high)/2;
            if(less_or_equal(mid,nums) > mid){
                duplicate = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return duplicate;
    }
};