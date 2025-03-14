class Solution {
public:
    bool check(int mid, vector<int>& candies,long long k){
        long long count = 0;
        for(auto it:candies)
            count += it/mid;
        
        return count>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(),candies.end());
        int left = 0, right = candies[candies.size()-1];

        while(left<right){
            int mid = right - (right-left)/2;
            if(check(mid,candies,k))
                left = mid;
            else
                right = mid-1;
        }

        return left;
    }
};