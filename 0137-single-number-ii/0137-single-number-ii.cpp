class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int bitIdx = 0; bitIdx < 32; bitIdx++){
            int count = 0;
            for(int num : nums){
                if(num & (1 << bitIdx)){
                    count++;
                }
            }
            if(count % 3 == 1){
                ans = ans | (1 << bitIdx);
            }
        }

        return ans;
    }
};