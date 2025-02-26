class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        for(auto num : nums){
            sum += num;
            if(sum < 0){
                sum = 0;
            }
            ans = max(ans,sum);
        }
        sum = 0;
        for(auto num : nums){
            sum += num;
            if(sum > 0){
                sum = 0;
            }
            ans = max(ans, abs(sum));
        }

        return ans;
    }
};

// kadane for -ve and +ve