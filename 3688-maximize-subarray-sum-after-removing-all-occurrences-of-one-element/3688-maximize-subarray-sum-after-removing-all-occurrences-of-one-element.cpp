class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        unordered_map<long, long> minPrefixSumSoFarAfterDel;
        long ans = nums[0];
        long prefixSum = 0; // no deletion simply prefix Summation
        long lowestPrefixSumSoFar = 0;
        minPrefixSumSoFarAfterDel[0] = 0; // [0] means no deletion of any element

        for(int num : nums){
            prefixSum += num;
            ans = max(ans, prefixSum - lowestPrefixSumSoFar);

            if(num < 0){ // we can either delete it or keep it
                if(minPrefixSumSoFarAfterDel.count(num)){ // we have already deleted it once in past
                    minPrefixSumSoFarAfterDel[num] = min(minPrefixSumSoFarAfterDel[num],minPrefixSumSoFarAfterDel[0]) + num; // what if previous deletion wasn't useful
                }else{
                    minPrefixSumSoFarAfterDel[num] = minPrefixSumSoFarAfterDel[0] + num;
                }
                lowestPrefixSumSoFar = min(lowestPrefixSumSoFar,minPrefixSumSoFarAfterDel[num]);
            }

            minPrefixSumSoFarAfterDel[0] = min(minPrefixSumSoFarAfterDel[0],prefixSum);
            lowestPrefixSumSoFar = min(lowestPrefixSumSoFar, minPrefixSumSoFarAfterDel[0]);
        }

        return ans;
    }
};

/*

EqualKirby's solution


at every index, we have to see if the ans subarray's sum will end at this index of not

we can delete all occurance of only one element

prefixSum simply keeps tracks of the prefix sum till index i

minPrefixSumSoFarAfterDel[k] keeps tracks of the minimum prefix sum till i after deleting atleast one k
minPrefixSumSoFarAfterDel[0] keeps tracks of the minimum prefix sum till i without any deletion of any element

lowestPrefixSumSoFar keeps tracks of the global lowest prefix sum, with or without deletion till index i,
so we will get our answer as 
ans = max(ans, prefixSum - lowestPrefixSumSoFar);

we delete negative numbers only
minPrefixSumSoFarAfterDel[k] will be increase by |num| (as num is negative) once num is removed
we may need to reset minPrefixSumSoFarAfterDel[k] to minPrefixSumSoFarAfterDel[0] in case we see it's lesser
*/ 