#define foru(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        foru(i, 0, n-1){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int j=0;
        foru(i, 0, n){
            if(nums[i]){
                nums[j++]=nums[i];
            }
        }
        while(j<n){
            nums[j++]=0;
        }
        return nums;
    }
};