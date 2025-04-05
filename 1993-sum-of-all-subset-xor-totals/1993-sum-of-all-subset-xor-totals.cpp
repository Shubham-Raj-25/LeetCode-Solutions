class Solution {
public:
    void func(int i, vector<int>& nums, int& sum, vector<int>& temp){
        if(i == nums.size()){
            int data = 0;
            for(auto it: temp)
                data = data ^ it;
                sum += data;
                return;
        }
        // take
        temp.push_back(nums[i]);
        func(i+1,nums,sum,temp);
        temp.pop_back();

        // skip
        func(i+1,nums,sum,temp);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        vector<int> temp;
        func(0,nums,sum,temp);
        return sum;
    }
};