class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // till i what is the len of consecutive increasing array
        int consecutive = 0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i >0 && nums[i] == nums[i-1] + 1)
                consecutive++;
            else
                consecutive = 1;
            if(i + 1 >= k) 
                ans.push_back(consecutive >= k ? nums[i] : -1);
        }

        return ans;
    }
};