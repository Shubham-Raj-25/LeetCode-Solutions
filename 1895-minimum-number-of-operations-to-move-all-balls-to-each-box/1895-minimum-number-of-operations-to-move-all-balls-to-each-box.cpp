class Solution {
public:
    vector<int> minOperations(string boxes) {
        // O(N)
        int n = boxes.size();
        vector<int> leftBalls(n,0), rightBalls(n,0), ans(n,0);
        int left = 0;
        for(int i=1;i<n;i++){
            left += boxes[i-1] == '1';
            leftBalls[i] = left;
        }
        int right = 0;
        for(int i=n-1;i>=0;i--){
            right += boxes[i] == '1';
            rightBalls[i] = right;
        }
        
        // figure out answer for the first index
        for(int i=1;i<n;i++){
            if(boxes[i] == '1'){
                ans[0] += i;
            }
        }
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] + leftBalls[i] - rightBalls[i];
        }

        return ans;
    }
};