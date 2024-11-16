class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        //  nums.len = 500 -> O(n3) feasilbe bruh?
        //  Brute force
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<=n-k;i++){
            int prev = nums[i];
            bool is_valid = true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j] != prev+1){
                    is_valid = false;
                    break;
                }
                prev = nums[j];
            }
            if(is_valid)
                ans.push_back(prev);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};