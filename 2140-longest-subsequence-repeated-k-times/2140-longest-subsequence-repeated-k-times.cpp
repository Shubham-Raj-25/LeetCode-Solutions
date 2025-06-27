class Solution {
public:
    bool issubseq(const string& s, const string& curr, int k) {
        int i = 0, j = 0;
        int total = curr.size() * k;
        while (i < s.size() && j < total) {
            if (s[i] == curr[j % curr.size()])
                j++;
            i++;
        }
        return j == total;
    }

  
    bool generate(const string& s, string& curr,
                  vector<pair<char, int>>& candidate, string& res, int k,
                  int maxlen) {
        if (curr.size() > maxlen)
            return false;

        bool found = false;

        if (!curr.empty() && issubseq(s, curr, k)) {
            if ((curr.size() > res.size()) ||
                (curr.size() == res.size() && curr > res)) {
                res = curr;
                found = true;
            }
        }

        for (int i = candidate.size() - 1; i >= 0; i--) {
            if (candidate[i].second > 0) {
                curr.push_back(candidate[i].first);
                candidate[i].second--;
                found |= generate(s, curr, candidate, res, k, maxlen);
                curr.pop_back();
                candidate[i].second++;
            }
        }

        return found;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<pair<char, int>> candidate;
        for (int i = 25; i >= 0; --i) {
            if (freq[i] >= k) {
                candidate.emplace_back('a' + i, freq[i] / k);
            }
        }

        string res = "", curr = "";
        int maxlen = s.size() / k;

        

        // Try lengths from max down to 1 (early pruning)
        for (int len = maxlen; len >= 1; len--) {
            vector<pair<char, int>> temp = candidate;
            if (generate(s, curr, temp, res, k, len)) {
                break;  
            }
        }

        return res;
    }
};