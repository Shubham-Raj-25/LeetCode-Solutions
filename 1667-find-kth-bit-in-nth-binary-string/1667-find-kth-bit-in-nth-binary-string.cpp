class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1 || k==1) return '0'; 
        int length = (1 << n) -1; 
        int mid = length/2 +1; 
        if(k==mid) return '1'; 
        if(k<mid){
            return findKthBit(n-1, k); 
        }
        else{
            int mirrored_k = length - k+1 ; 
            char mirrored_bit = findKthBit(n-1, mirrored_k); 
            return mirrored_bit == '0' ? '1' : '0'; 
        }
    }
};