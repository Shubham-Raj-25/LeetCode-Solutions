class Solution {
public:
    long long atleastK(string word, int k) {
        int n = word.size();
        int left = 0;
        int consonantCount = 0;
        long long maxCount = 0;
        unordered_set<char> vowels = {'a','e','i','o','u'};
        unordered_map<char,int> mpp;
        for(int right = 0; right < n; right++) {
            if(vowels.count(word[right])) mpp[word[right]]++;
            else consonantCount++;
            while(mpp.size() == 5 && consonantCount >= k) {
                maxCount += (n - right);
                if(vowels.count(word[left])) {
                    mpp[word[left]]--;
                    if(mpp[word[left]] == 0) mpp.erase(word[left]);
                }
                else consonantCount--;
                left++;
            }
        }
        return maxCount;
    }

    long long countOfSubstrings(string word, int k) {
        return atleastK(word, k) - atleastK(word,k + 1);
    }
};