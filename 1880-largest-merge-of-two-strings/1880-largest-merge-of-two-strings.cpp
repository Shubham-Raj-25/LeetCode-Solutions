class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0;
        int len1 = word1.length(), len2 = word2.length();

        while (i < len1 && j < len2) {
            if (word1.compare(i, len1, word2, j, len2) >= 0) {
                ans += word1[i];
                i++;
            } else {
                ans += word2[j];
                j++;
            }
        }

        while (i < len1) {
            ans += word1[i];
            i++;
        }

        while (j < len2) {
            ans += word2[j];
            j++;
        }

        return ans;
    }
};