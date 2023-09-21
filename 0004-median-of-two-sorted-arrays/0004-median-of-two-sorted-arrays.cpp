class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // O(m+n) soliution
        vector<int> nums;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] <= nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while(i<nums1.size()){
            nums.push_back(nums1[i]);
            i++;
        }

        while(j<nums2.size()){
            nums.push_back(nums2[j]);
            j++;
        }

        int n = nums.size();

        if(n%2!=0){
            return (double)nums[n/2]/1.00;
        }

        return (double)(nums[n/2]+nums[n/2-1])/2.00;
    }
};