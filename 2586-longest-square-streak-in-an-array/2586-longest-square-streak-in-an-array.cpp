class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st;
        int ans = -1;

        for(int num : nums) st.insert(num);
        for (int num : nums) {
            int len = 1;
            int candidate = num;
            while (true) {
                int root = int(sqrt(candidate));
                if (root * root == candidate && st.count(root)) {
                    candidate = root;
                    len++;
                } else {
                    break;
                }
            }
            ans = max(ans, len);
        }


        return ans <= 1 ? -1 : ans;
    }
};