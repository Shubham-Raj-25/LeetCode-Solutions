class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int j=0;j<=n;j++){
        int count = 0;
            for(int i = 31; i >= 0; i--) { // assuming 32-bit integers
                int k= (j >> i) & 1; // get the i-th bit
                if(k==1) count++;}
                ans.push_back(count);
            }
        return ans;
    }
};