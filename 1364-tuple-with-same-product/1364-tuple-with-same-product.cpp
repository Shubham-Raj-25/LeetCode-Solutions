class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mp[nums[i]*nums[j]] += 1;
            }
        }

        for(auto it : mp){
            ans += it.second * (it.second-1) / 2 * 8;
        }

        return ans;
    }
};

/*

a/c = d/b

[2,3,4,6]
{6} => {2,3},{3,2}
{8} => {2,4},{4,2}
{12} => {2,6},{6,2},{3,4},{4,3}
{18} => {3,6}, {6,3}
{24} => {4,6}, {6,4}

x -> 2 pairs -> 8 possibilities
x -> 3 pairs -> (3C2 * 8 possibilities)


n!/2!(n-2)!
n*(n-1)/2

* * *


*/ 