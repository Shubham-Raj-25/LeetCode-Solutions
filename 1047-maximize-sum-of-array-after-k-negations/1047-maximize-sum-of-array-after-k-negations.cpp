class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini= 1e3;
        for(auto it:nums) mini = min(mini,abs(it));
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            if(k>0){
                if(nums[i]==0)
                    break;
                else if(nums[i]<0)
                    nums[i] = - nums[i];
                else{
                    if(k & 1!=0)
                        flag = true;
                    break;
                }
                k--;
            }
        }
        if(k%2!=0){
            flag = true;
        }

        int ans = 0;
        for(auto it:nums)
            ans += it;

        if(flag) ans -= 2*mini;
        return ans;
    }
};