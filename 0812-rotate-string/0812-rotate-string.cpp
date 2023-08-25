class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        goal += goal;

        size_t found = goal.find(s);

        return found != std::string::npos;

    }
};