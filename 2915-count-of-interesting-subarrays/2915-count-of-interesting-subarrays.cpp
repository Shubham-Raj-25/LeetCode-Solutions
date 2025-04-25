class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        map<long long, long long> mpp;
        mpp[0] = 1;
        long long  count = 0;
        long long result = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k) count++; 
            int rem = (count - k) % modulo;

            if(rem < 0) rem += modulo;
            result += mpp[rem];
            mpp[count % modulo]++;
        }

        return result;
    }
};