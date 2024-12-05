class Solution {
public:
    bool canChange(string start, string target) {
        // order of elements should remain same
        // Ls can only go left and Rs can only go right
        string a, b;
        for(char c : start)
            if(c != '_') a.push_back(c);
        for(char c : target)
            if(c != '_') b.push_back(c);
        if(a != b)
            return false;

        // compare Ls
        int j = 0;
        for(int i=0;i<start.length();i++){
            if(start[i] == 'L'){
                while(target[j] != 'L')
                    j++;
                if(j > i)
                    return false;
                j++;
            }
        }
        
        // Compare Rs
        j = 0;
        for(int i=0;i<start.length();i++){
            if(start[i] == 'R'){
                while(target[j] != 'R')
                    j++;
                if(i > j)
                    return false;
                j++;
            }
        }

        return true;
    }
};