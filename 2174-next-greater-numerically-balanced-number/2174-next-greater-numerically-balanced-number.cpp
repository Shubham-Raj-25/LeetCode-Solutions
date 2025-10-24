class Solution {
public:
    bool isBalanced(int n){
        vector<int> data(10,0);
        while(n){
            data[n%10]++;
            n /= 10;
        }
        if(data[0] != 0){
            return false;
        }
        for(int i=1;i<10;i++){
            if(data[i] != 0 && data[i] != i){
                return false;
            }
        }
        return true;
    }
    int helper(int n){
        if(isBalanced(n)){
            return n;
        }
        return helper(n+1);
    }
    int nextBeautifulNumber(int n) {
        return helper(n+1);
    }
};

/*
why not just loop through all?
*/ 