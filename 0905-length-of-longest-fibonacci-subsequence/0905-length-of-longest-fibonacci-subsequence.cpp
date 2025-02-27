class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int len = 2;
                int a = arr[i];
                int b = arr[j];
                while(true){
                    auto it = lower_bound(arr.begin(),arr.end(),a+b);
                    if(it == arr.end() || *it != a+b){
                        break;
                    }
                    len++;
                    int temp = b;
                    b = a+b;
                    a = temp;
                }
                ans = max(ans,len);
            }
        }

        return ans == 2 ? 0 : ans;
    }
};

/*

[1,2,3,4,5,6,7,8]
1 2 3 5 8
1 5 6

Given a strictly increasing array arr 

3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 10^9

    1000 , 10^9 :-> MLE
    1e3
func(idx, prevIdx, preIdx-1)

xi + xi+1 == xi+2

jump? might not be O(N^3)

1 2 4 7 11 12 23 35
// including i idx what's the longest?
dp[i][sum] = dp[i-1][sum-nums[i]]

*/ 