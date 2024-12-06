class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> data(banned.begin(),banned.end());
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(data.count(i))
                continue;
            if(maxSum - i >= 0){
                ans ++;
                maxSum -= i;
            }
            else{
                return ans;
            }
        }

        return ans;
    }
};