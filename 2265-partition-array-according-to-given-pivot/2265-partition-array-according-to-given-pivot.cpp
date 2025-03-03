class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left,mid, right,ans;
        for(auto it : nums){
            if(it < pivot)
                left.push_back(it);
            else if(it > pivot)
                right.push_back(it);
            else mid.push_back(it);
        }
        for(auto it : left) ans.push_back(it);
        for(auto it : mid) ans.push_back(it);
        for(auto it : right) ans.push_back(it);

        return ans;
    }
};