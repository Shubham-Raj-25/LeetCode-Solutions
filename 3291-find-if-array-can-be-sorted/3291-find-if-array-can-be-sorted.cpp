class Solution {
public:
    static bool check(const pair<int,int>&a, const pair<int,int>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }else{
            return false;
        }
    }
    int count(int x){
        int c = 0;
        while(x>0){
            int num = x%2;
            if(num==1){
                c++;
            }
            x = x/2;
        }
        return c;
    }
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i= 0; i<nums.size(); i++){
            int x = count(nums[i]);
            v.push_back({nums[i],x});
        }
        stable_sort(v.begin(),v.end(),check);
        int num = v[0].first;
        for(int i = 1; i<v.size(); i++){
            if(v[i].first<num){
                return false;
            }
            num = v[i].first;
        }
        return true;
    }
};
