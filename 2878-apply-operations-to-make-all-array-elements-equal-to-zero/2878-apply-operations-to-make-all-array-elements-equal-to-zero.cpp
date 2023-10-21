class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums[0] < nums[n-1])
            reverse(nums.begin(),nums.end()); // jugad to avoid TLE
        int i =0;
        while(i<n){
            while(i<n && nums[i]==0) i++;

            if(i==n) return true;

            int minus = nums[i];

            for(int j=0;j<k;j++){
                if(i+j>=n || nums[i+j] < minus)
                    return false;
                nums[i+j] -= minus;
            }
            i++;
        }

        return true;
    }
};