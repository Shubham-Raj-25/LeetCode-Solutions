class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = sqrt(c)+1;
        while(left<=right){
            if((long long)pow(left,2) + (long long)pow(right,2)==c)
                return true;
            else if((long long)pow(left,2) + (long long)pow(right,2)>c)
                right--;
            else
                left++;
        }

        return false;
    }
};