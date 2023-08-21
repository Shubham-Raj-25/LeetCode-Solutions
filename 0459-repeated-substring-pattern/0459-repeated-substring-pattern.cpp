class Solution {
public:
    bool repeatedSubstringPattern(string temp) {
        // use trick for O(n) solution
        string s = temp;
        s += s;
        s = s.substr(1,2*temp.length()-2);
        size_t foundPos = s.find(temp);
        return foundPos != std::string::npos;
    }
};