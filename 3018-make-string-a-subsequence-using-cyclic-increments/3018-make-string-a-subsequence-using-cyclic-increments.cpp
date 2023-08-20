class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
     // can't do dp because too much space.
     // greedy will work, should have thought about it earlier

    int i =0, j = 0;

    while(i<str1.size()){
        if(j==str2.size())
            return true;
        if(str1[i]==str2[j] || str2[j]-str1[i]==1 || str1[i]-str2[j]==25)
            j++;
        
        i++;
    }
    if(j==str2.size()) return true;
    return false;
    }
};