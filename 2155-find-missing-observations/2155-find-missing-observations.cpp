class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans(n);
        int m = rolls.size();
        
        int sum_have = 0;
        
        for(int roll : rolls)
            sum_have += roll;
        
        int sum_missed = (mean) * (n+m) - sum_have;

        if(sum_missed < n || sum_missed > 6*n)
            return {};
        
        cout << sum_missed << endl;

        int temp = sum_missed/n;

        for(int i=0;i<n;i++)
            ans[i] = temp;
        
        temp = sum_missed - temp * n;

        for(int i=0;i<temp;i++)
            ans[i] += 1;

        return ans;
    }
};