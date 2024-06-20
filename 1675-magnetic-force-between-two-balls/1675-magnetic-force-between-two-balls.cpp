class Solution {
public:
    bool isPossible(int dist, vector<int>& position, int m){
        int last = -1;
        for(auto it: position){
            if(last == -1 || it - last >= dist){
                m--;
                last = it;
            }
        }
        
        return m <= 0;
    }

    int maxDistance(vector<int>& position, int m) {
        // BS on answer space
        sort(position.begin(),position.end());
        int low = 1, high = 1e9, ans;
        
        while(low <= high){
            int mid = (high+low)/2;
            if(isPossible(mid,position,m)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return ans;
    }
};