class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> numsAsDoubles;
        for (int num : nums) {
            numsAsDoubles.push_back(static_cast<double>(num));
        }
        return checkCombination(numsAsDoubles);
    }

private:
    bool checkCombination(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                
                vector<double> remaining;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) remaining.push_back(nums[k]);
                }
                
                for (char op : {'+', '-', '*', '/'}) {
                    if (op == '/' && nums[j] == 0) continue;
                    vector<double> nextSet = remaining;
                    
                    if (op == '+') nextSet.push_back(nums[i] + nums[j]);
                    else if (op == '-') nextSet.push_back(nums[i] - nums[j]);
                    else if (op == '*') nextSet.push_back(nums[i] * nums[j]);
                    else if (op == '/') nextSet.push_back(nums[i] / nums[j]);
                    
                    if (checkCombination(nextSet)) return true;
                }
            }
        }
        
        return false;
    }
};