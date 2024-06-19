class Solution {
public:
    bool isPossible(int day, vector<int>& bloomDay, int m, int k){
        int count = 0;
        
        for(int i=0;i<bloomDay.size();i++){
            int adj = 0;
            while(i < bloomDay.size() && bloomDay[i] <= day){
                adj++;
                if(adj == k){
                    count++;
                    break;
                }
                i++;
            }
        }
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // BS on answer space might work
        int n = bloomDay.size();
        
        if((long long)m*k > n)
            return -1;


        int low = 0, high = 1e9, ans;

        while(low <= high){
            int mid = (low+high)/2;
            if(isPossible(mid,bloomDay,m,k)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return ans;
    }
};