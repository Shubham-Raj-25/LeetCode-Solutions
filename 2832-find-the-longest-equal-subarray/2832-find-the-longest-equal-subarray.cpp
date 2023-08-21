class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int ans = 1;
        unordered_map<int,vector<int>> indices;
        
        for(int i=0;i<nums.size();i++)
            indices[nums[i]].push_back(i);
        
        for(auto it : indices){
            vector<int> ids = it.second;
            int left = 0, right = 1;

            for(int bal = k;right<ids.size();right++){
                bal -= ids[right] - ids[right-1]-1;
                if(bal < 0)
                    bal += ids[++left] - ids[left-1]-1;
            }
            ans = max(ans,right-left);
        }

        return ans;
    }
};