class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1, v2;
        string s = "";

        // Split sentence1 into words
        for (char c : sentence1) {
            if (c != ' ') {
                s += c;
            } else {
                v1.push_back(s);
                s = "";
            }
        }
        v1.push_back(s); // Push the last word
        
        s = "";
        for (char c : sentence2) {
            if (c != ' ') {
                s += c;
            } else {
                v2.push_back(s);
                s = "";
            }
        }
        v2.push_back(s); 
        
        
        if (v1.size() > v2.size()) {
            swap(v1, v2);
        }

        
        int i = 0;
        while (i < v1.size() && v1[i] == v2[i]) {
            i++;
        }

        
        int j = v1.size() - 1, l = v2.size() - 1;
        while (j >= i && v1[j] == v2[l]) {
            j--;
            l--;
        }

        
        return i > j;
    }
};