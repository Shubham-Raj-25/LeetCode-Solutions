class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int count = 0;
        for (char x : s) {
            if (x == 'b') {
                count += 1;
            } else if (count) {
                ans += 1;
                count -= 1;
            }
        }
        return ans;
    }
};