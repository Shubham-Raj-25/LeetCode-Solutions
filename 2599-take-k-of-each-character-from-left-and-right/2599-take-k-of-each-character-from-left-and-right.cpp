class Solution {
public:
    bool is_valid(vector<int>& freq, int k) {
        for (auto it : freq) {
            if (it < k) {
                return false;
            }
        }
        return true;
    }

    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int> freq(3, 0); 

        for (char c : s) {
            freq[c - 'a']++;
        }

        if (freq[0] < k || freq[1] < k || freq[2] < k) {
            return -1;
        }

        int required = k;
        vector<int> windowFreq(3, 0);
        int maxWindow = 0; 
        int l = 0;          

        for (int r = 0; r < n; ++r) {
            windowFreq[s[r] - 'a']++;

            while (windowFreq[0] > freq[0] - k ||
                   windowFreq[1] > freq[1] - k ||
                   windowFreq[2] > freq[2] - k) {
                windowFreq[s[l] - 'a']--;
                l++;
            }

            maxWindow = max(maxWindow, r - l + 1);
        }

        return n - maxWindow;
    }
};
