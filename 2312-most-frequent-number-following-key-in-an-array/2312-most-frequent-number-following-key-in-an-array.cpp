class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> data;
        int ans = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){

            if(i<nums.size()-1 && nums[i]==key)
                data[nums[i+1]]++;
            if(i<nums.size()-1 && data[nums[i+1]] > maxi){
                maxi = data[nums[i+1]];
                ans = nums[i+1];
            }
        }

        return ans;
    }
};