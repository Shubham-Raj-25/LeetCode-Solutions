class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<double> pq;

        for(int i=0;i<piles.size();i++)
            pq.push(piles[i]);
        
        for(int i=0;i<k;i++){
            double a = pq.top();
            pq.pop();
            a = ceil(a/2);
            pq.push(a);
        }

        int ans = 0;

        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};