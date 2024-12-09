class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // store in a sorted ds all the false and for each query check
        set<int> falses;
        vector<bool> ans;

        for(int i=0;i<nums.size()-1;i++)
            if((nums[i]+nums[i+1]) % 2 == 0) // means same parity
                falses.insert(i); // store parity for lefter element
    

        for(auto query : queries){
            int from = query[0];
            int to = query[1];
            auto it = falses.lower_bound(from);
            if(it != falses.end() && *it <= to-1)
                ans.push_back(false);
            else
                ans.push_back(true);   
        }

        return ans;
    }
};