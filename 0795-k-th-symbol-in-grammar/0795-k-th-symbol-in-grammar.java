class Solution {
    public int kthGrammar(int n, int k) {
        if(n==1 && k==1)
            return 0;
        
        int mid = (int)Math.pow(2,n-1)/2;

        int ans = 1;

        if(k<=mid){
            ans = kthGrammar(n-1,k);
        }
        else
            ans = 1^kthGrammar(n-1,k-mid);
        
        return ans;
    }
}