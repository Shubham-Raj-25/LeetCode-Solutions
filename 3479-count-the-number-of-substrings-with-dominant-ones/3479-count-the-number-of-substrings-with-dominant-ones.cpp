class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> OneCount;
        int oneSum = 0;
        for(char c : s){
            oneSum += c == '1';
            OneCount.push_back(oneSum);
        } 

        for(int i=0;i<n;i++){ // substr starting from i
            int ones = 0, zeros = 0;
            for(int j=i;j<n;j++){ // substr ending at j
                ones = OneCount[j] - (i == 0 ? 0 : OneCount[i-1]);
                zeros = j-i+1-ones;
                if(zeros*zeros > ones){ // not a dominate string till nextJ
                    int nextJ = j + zeros*zeros-ones-1;
                    j = nextJ;
                }
                else if(zeros*zeros == ones){
                    ans++;
                }
                else{ // ones are dominating
                    ans++;
                    int subplusOne = sqrt(ones) - zeros;
                    int nextJ = j + subplusOne; // till here 1 will dominate so no need to recalculate

                    if(nextJ >= n){
                        ans += (n - j - 1); // whatever lengtg is left
                    }
                    else{
                        ans += subplusOne;
                    }

                    j = nextJ;
                }
            }
        }

        return ans;
    }
};

/*
binary string s
number of substrings
number of ones in the string is greater than or equal to
the square of the number of zeros in the string.

freq[1] >= freq[0]^2
l - f0 >= f0^2
f0(f0-1) <= l
1 <= s.length <= 4 * 10^4

all 1 will be counted 

in a substr:
    freq(0) = len - freq(1)
    freq(1) >= freq(0)^2
    f1 >= l^2 + f1^2 - 2*l*f1
    0 >= l^2 + f1^2 - f1(2l+1)

    f1(2l + 1 - f1) >= l^2

    f0(f0-1) <= l // is this sw?
    
    * * * * * * * * * * * * * * * * 
    1 0 0 0 1 0 0 1 0 0 0 0 1 0 0 1

    0 0 0 1 1
    
    101101

    
    010111


*/ 