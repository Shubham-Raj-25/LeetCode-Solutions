class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int kCount = 0, maxConversionCount = 0;
        for(int num : nums){
            kCount += num == k;
        }
        for(int candidate = 1; candidate <= 50; candidate++){
            if(candidate == k){
                continue;
            }
            int curr = 0, maxSoFar = 0;
            for(int num : nums){
                if(num == candidate){
                    curr++;
                }
                else if(num == k){
                    curr--;
                }
                curr = max(curr,0);
                maxSoFar = max(maxSoFar,curr);
            }
            maxConversionCount = max(maxConversionCount,maxSoFar);
        }

        return kCount + maxConversionCount;
    }
};