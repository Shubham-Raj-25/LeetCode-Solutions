class Solution {
public:
    bool containsZero(int a){
        string temp = to_string(a);
        if(temp.find('0')!=string::npos)
            return true;
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n-1;

        while(1){
            if(containsZero(a) || containsZero(b)){
                a++;
                b--;
            }
            else
                return {a,b};
        }

        return {6,9};
    }
};