class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, noOfGroups = 0;
        int r = s.length()-1;
        while(r>=0 && s[r] == '1'){
            r--;
        }
        while(r>=0){
            while(r>=0 && s[r]== '0'){
                r--;
            }
            while(r>=0 && s[r] == '1'){
                ans += (1 + noOfGroups);
                r--;
            }
            noOfGroups++;
        }

        return ans;
    }
};

/*
i + 1 < s.length
s[i] == '1' and s[i + 1] == '0'.

010010 -> 3

10010101 -> 
1 + 2 + 3 =  1 + noOfGroupInRight

110011001 1 + 1 + (1+1) + (1+1) = 

00111 -> 0

1 <= s.length <= 10^5

0 0 0 0 1 1 1 1 1 0 1 1 1

1 2 3 4 5 + 5 = 10

*/ 