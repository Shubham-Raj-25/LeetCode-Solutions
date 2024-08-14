class Solution {
public:
    vector<vector<int>> ans;

    void func(int idx, int target, vector<int>& candidates, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break; 
            temp.push_back(candidates[i]);
            func(i + 1, target - candidates[i], candidates, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        func(0, target, candidates, temp);
        return ans;
    }
};
