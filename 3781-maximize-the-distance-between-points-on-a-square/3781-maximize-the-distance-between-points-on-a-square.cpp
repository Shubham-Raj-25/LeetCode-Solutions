class Solution {
private:
    bool isMinDistPossible(int dist, int side, vector<long long>& pts, int k){
        int n = pts.size() / 2; // Only original points, not extended
        
        for(int i = 0; i < n; i++){ // try with every point because k can be up to 25
            int ptsCollected = 1;
            long long currPos = pts[i];
            int currIdx = i;
            
            // try to select k points with min dist as dist
            for(int j = 1; j < k; j++){
                long long nextPos = currPos + dist;
                // select up to n next points so that it doesn't select already selected points
                auto it = lower_bound(pts.begin() + currIdx + 1, pts.begin() + i + n, nextPos);
                
                if(it == pts.begin() + i + n){ // it means end, no point found after this
                    break;
                }

                currIdx = it - pts.begin();
                currPos = pts[currIdx];
                ptsCollected++;
            }

            if(ptsCollected == k && (pts[i] + 4LL * side - currPos) >= dist){ // wrap-around check
                return true;
            }
        }
        return false;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        // anti-clockwise
        vector<long long> pts;

        for(auto point : points){
            if(point[1] == 0){ // x-axis
                pts.push_back(point[0]);
            }
            else if(point[0] == side){ // x = side
                pts.push_back(side + point[1]);
            }
            else if(point[1] == side){ // y = side line
                pts.push_back(3LL * side - point[0]);
            }
            else{ // y-axis
                pts.push_back(4LL * side - point[1]);  
            }
        }

        sort(pts.begin(), pts.end());

        // to handle circularity
        int n = pts.size();
        for(int i = 0; i < n; i++){
            pts.push_back(pts[i] + 4LL * side);
        }

        int low = 0, high = 2 * side + 1; 

        while(low <= high){ 
            int mid = low + (high - low) / 2;
            if(isMinDistPossible(mid, side, pts, k)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};
