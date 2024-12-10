class Solution {
public:
    int maximumLength(string s) {
        int i = 0, len = s.length(), ans = -1;
        vector<vector<int>> charToFreq(27, vector<int> (51, 0));

        while(i < len) {
            char ch = s[i];
            int cnt = 0;

            while (i < len and ch == s[i]) {
                i += 1;
                cnt += 1;
            }

            charToFreq[ch - 'a'][cnt] += 1;

            if(cnt > 1) {
                charToFreq[ch - 'a'][cnt - 1] += 2;
            }

            if(cnt > 2) {
                charToFreq[ch - 'a'][cnt - 2] += 3;
            }
        }

        for (int i=0; i<27; i++) {
            for(int j=0; j<51; j++) {
                if(charToFreq[i][j] >= 3) {
                    ans = max(ans, j);
                }
            }
        }

        return ans;
    }
};