class Solution {
    int check_sum(int num){
        int sum=0;
        while(num>0){
            int l=num%10;
            sum+=l;
            num/=10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        if(n<10)return n;int current_largest=0;
        vector<int>check(37,0);
        for(int i=1;i<=n;i++){
            int sum=check_sum(i);
            check[sum]++;
            if(check[sum]>current_largest){
                current_largest=check[sum];

            }  

        }
        int ans=0;
        for(auto it:check){
            if(it==current_largest)ans++;
        }
        return ans;


        
    }
};