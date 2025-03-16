class Solution {
public:
    bool check(long long mid, vector<int>& ranks, int cars){
        long long k = 0;
        for(auto rank : ranks){
            k += sqrt((long long)mid/(long long)rank); 
            if(k >= cars){
                return true;
            }
        }
        return k >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long high = 1e14;
        long long low  = 1;
        long long ans = 0;
        while(low <= high){
            long long mid = high - (high - low)/2;
            if(check(mid,ranks,cars)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        } 
        return ans;
    }
};