class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);

        while(q.size() > 1){
            int temp = k;
            while(1){
                int curr = q.front();
                q.pop();
                temp --;
                if(!temp){
                    break;
                }else{
                    q.push(curr);
                }
            }
        }

        return q.front();
    }
};