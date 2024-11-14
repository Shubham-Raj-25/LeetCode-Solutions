class Solution {
public:
    bool isPossible(int n, vector<int>& quantities, int maxi){
        int rooms_reqd = 0;
        for(int q : quantities){
            if(q > maxi){
                rooms_reqd += q % maxi == 0 ? q/maxi : q/maxi+1;
            }
            else
                rooms_reqd++;
        }
        return rooms_reqd <= n;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int low = 1, high = 100000;

        while(low < high){
            int mid = (low+high)/2;
            if(isPossible(n,quantities,mid))
                high = mid;
            else
                low = mid+1;   
        }

        return low;
    }
};