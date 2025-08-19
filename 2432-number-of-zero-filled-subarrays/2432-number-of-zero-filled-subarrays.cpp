class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;

        for(int i=0;i<nums.size();i++){
            int count = 0;
            while(i<nums.size() && nums[i]==0) i++,count++;
            if(count>0){
                ans += (1ll*count*1ll*(count+1))/2;
                // i--;
            }
            
        }
        return ans;
    }
};