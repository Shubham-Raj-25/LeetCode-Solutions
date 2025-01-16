class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xr = 0;
        int n = nums1.size(), m = nums2.size();
        
        if(m%2){// odd, ignore even case as it'll be 0
            for(int num : nums1){
                    xr ^= num;
            }
        }

        if(n%2){
            for(int num : nums2){
                    xr ^= num;
            }
        }

        return xr;
    }
};