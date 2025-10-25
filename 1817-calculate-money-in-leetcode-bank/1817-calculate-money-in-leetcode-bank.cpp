class Solution {
public:
    int totalMoney(int n) {
        // iterative
        int sum = 1;
        int prev = 1;
        int last = prev;
        for(int i=1;i<n;i++){
            if(i%7 == 0){
                prev ++;
                sum += prev;
                last = prev;
                continue;
            }
            sum += last+1;
            last++;
        }

        return sum;
    }
};