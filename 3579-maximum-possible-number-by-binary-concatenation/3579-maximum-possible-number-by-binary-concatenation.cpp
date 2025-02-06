class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<vector<int>> permutations = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
        int maxi = -1;

        for(int i=0;i<permutations.size(); i++){
            vector<int> permutation = permutations[i];
            int ans = 0;
            for(int j=0;j<3;j++){
                int num = nums[permutation[j]];
                while(num){
                    num = num >> 1;
                    ans = ans << 1;
                }
                ans = ans | nums[permutation[j]];
            }
            maxi = max(maxi,ans);
        }

        return maxi;
    }
};