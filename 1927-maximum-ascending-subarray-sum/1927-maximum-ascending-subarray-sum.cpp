class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0],c=0;
        int i=0,j=1;c=nums[0];
        while(j<n){
           if(nums[j]>nums[j-1])c+=nums[j];

           else{
            
            c=nums[j];
            i=j;
           }
           maxi=max(maxi,c);
           j++;
        }
        return maxi;
    }
};