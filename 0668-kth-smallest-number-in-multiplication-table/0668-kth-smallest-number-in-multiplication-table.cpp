class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 0, r = m*n, count, ans;
        
        while(l <= r){
            count = 0;
            int mid = (l+r)/2;
            
            for(int i=1;i<=m;i++)
                count += min(mid/i,n);  // num of element in ith row <= mid
            
            if(count < k)
                l = mid+1;
            else{
                r = mid-1;
                ans = mid;
            }
        }

        return ans;
    }
};