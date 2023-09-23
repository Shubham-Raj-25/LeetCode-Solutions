class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int duration;
        int maxi = 0;
        char ans;
        //64111136 -> o
        // 38650756
        for(int i=0;i<releaseTimes.size();i++){
            if(i==0)
                duration = releaseTimes[i];
            else
                duration = releaseTimes[i] - releaseTimes[i-1];
            
            if(duration > maxi){
                maxi = duration;
                ans = keysPressed[i];
            }
            else if(duration == maxi){
                ans = max(ans,keysPressed[i]);
            }
        }

        return ans;
    }
};