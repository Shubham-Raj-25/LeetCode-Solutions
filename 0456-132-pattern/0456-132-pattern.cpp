class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;

        int thirdElement = INT_MIN; // third element

        for (int i = n - 1; i >= 0; i--) {
            
            if (nums[i] < thirdElement) return true;
            
            while (!stk.empty() && nums[i] > stk.top()) {
                thirdElement = stk.top(); 
                stk.pop();
                // last element to be popped will be the third element
            }

            stk.push(nums[i]);
            // the top most element of the stack will be the second element
        }
        return false;
    }
};