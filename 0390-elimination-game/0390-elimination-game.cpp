class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int jump = 1;
        bool right = true;

        while(n>1){
            if(right)
                head += jump;
            else
                head += n%2 == 0 ? 0:jump;
            
            jump *= 2;
            n /= 2;
            right = !right;
        }

        return head;
    }
};