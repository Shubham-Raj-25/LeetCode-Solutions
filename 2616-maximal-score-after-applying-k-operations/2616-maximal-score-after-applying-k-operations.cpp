class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // greedy with max heap?
        long long ans = 0;
        priority_queue<int> pq;
        for(int num:nums) pq.push(num);
        
        for(int i=0;i<k;i++){
            int curr = pq.top();
            pq.pop();
            ans += (long long)curr;
            if(curr % 3 == 0)
                pq.push(curr/3);
            else
                pq.push(curr/3+1);
        }

        return ans;
    }
};