class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0)
            return -1;
        
        int pivot = rand()%(nums.size());

        vector<int> left, mid, right;

        for(auto it:nums){
            if(it>nums[pivot])
                left.push_back(it);
            else if(it==nums[pivot])
                mid.push_back(it);
            else
                right.push_back(it);
        }

        int L = left.size();
        int M = mid.size();

        if(k<=L)
            return findKthLargest(left,k);
        else if (k> L+M)
            return findKthLargest(right, k-L-M);
        else
            return mid[0];
    }
};