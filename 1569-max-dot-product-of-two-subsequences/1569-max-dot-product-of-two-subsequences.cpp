class Solution {
public:
    map<pair<int,int>,int> mp;

    int func(int i, int j,vector<int>& nums1, vector<int>& nums2){
        if(i==nums1.size() || j==nums2.size())
            return 0;
        
        if(mp.find({i,j})!=mp.end())
            return mp[{i,j}];

        int ans = INT_MIN;        

        ans = max(0,func(i+1,j+1,nums1,nums2)) + nums1[i]*nums2[j];
        
        if(i<nums1.size()-1)
        ans = max(ans, func(i+1,j,nums1,nums2));

        if(j<nums2.size()-1)
        ans = max(ans, func(i,j+1,nums1,nums2));
        
        return mp[{i,j}] = ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return func(0,0,nums1,nums2);
    }
};