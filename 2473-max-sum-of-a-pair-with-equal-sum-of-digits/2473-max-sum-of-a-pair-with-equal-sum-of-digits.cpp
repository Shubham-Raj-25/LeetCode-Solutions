class Solution {
private:
    int getDigitSum(int n){ // O(9) time => O(1)
        int sum = 0;
        while(n){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> sumToMaxNum;
        int ans = -1;
        
        for(int i=0;i<nums.size();i++){
            int sum = getDigitSum(nums[i]);
            if(sumToMaxNum.find(sum) != sumToMaxNum.end()){
                ans = max(ans, nums[i] + nums[sumToMaxNum[sum]]);
                if(nums[i] > nums[sumToMaxNum[sum]]){
                    sumToMaxNum[sum] = i;
                }
            }
            else{
                sumToMaxNum[sum] = i;
            }
        }

        return ans;
    }
};

/*

18,43,36,13,7

[10,12,19,14]

TC: O(N)
SC: O(N)

*/ 