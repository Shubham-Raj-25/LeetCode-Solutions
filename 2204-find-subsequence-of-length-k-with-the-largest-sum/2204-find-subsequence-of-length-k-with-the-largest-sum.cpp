class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<pair<int,int>> temp;

        for(int i = 0; i < n; i++){
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        //selecting the largest k elements of the array
        vector<pair<int,int>> res(temp.begin() + (n-k), temp.begin() + n);
        //sorting the k elements based on their position(indices) in the array
        sort(res.begin(), res.end(), cmp);
        vector<int> ans;
        for(int i = 0; i < res.size(); i++){
            ans.push_back(res[i].first);
        }

        return ans;
    }
};