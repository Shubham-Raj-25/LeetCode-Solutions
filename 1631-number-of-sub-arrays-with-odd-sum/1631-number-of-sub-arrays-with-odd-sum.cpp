class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> evenCount(n,0), oddCount(n,0);
        int ans = 0;

        for(int i=0;i<n;i++){
            oddCount[i] += arr[i] % 2 != 0;
            evenCount[i] += arr[i] % 2 == 0;
            if(i!=0){
                oddCount[i] += evenCount[i-1] * (arr[i] % 2 != 0) + oddCount[i-1] * (arr[i] % 2 == 0);
                evenCount[i] += evenCount[i-1] * (arr[i] % 2 == 0) + oddCount[i-1] * (arr[i] % 2 != 0);
            }
            ans = (ans + oddCount[i]) % mod;
        }

        return ans % mod;
    }
};


/*

1 <= arr.length <= 10^5
1 <= arr[i] <= 100

sum < 10^7

[1 3 5]

dp[0] = 1
dp[1] = 

dp[i] = dp[i-1]  + nums

count even and odd sum ending at i

evenCount[0] = 0;
oddCount[0] = 1;

oddCount[1] = 1 + 0
evenCount[1] = 2

oddCount[2] = 1 + 2
evenCount[2] = 2

*/ 