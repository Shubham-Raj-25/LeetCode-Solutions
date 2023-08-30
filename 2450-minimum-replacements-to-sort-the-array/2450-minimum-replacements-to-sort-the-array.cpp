class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long ans = 0, steps = 0;
        
        int n = nums.size();
        int last = nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            if(nums[i] <= last)
                {   
                    last = nums[i];
                }
            else{
                steps = (nums[i]-1)/last+1;
                last = nums[i]/steps;
                ans += steps-1;
            }
        }

        return ans;
    
    }

};