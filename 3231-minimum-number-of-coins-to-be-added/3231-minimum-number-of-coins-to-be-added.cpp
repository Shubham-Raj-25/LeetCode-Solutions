class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int ans = 0, obtainable_upto = 0, idx = 0;

        while(obtainable_upto < target){
            if(idx < coins.size() && coins[idx] <= obtainable_upto+1)
                obtainable_upto += coins[idx++];
            else{
                ans++;
                obtainable_upto += obtainable_upto+1;
            }
        }
        return ans;
    }
};