class Solution {
private:
    bool func(string& s, int n, int& k){
        if(s.length() == n){
            k--;
            return k == 0;
        }

        for(char c = 'a'; c <= 'c'; c++){
            if(s != "" && s.back() == c){
                continue;
            }
            s.push_back(c);
            if(func(s,n,k)){
                return true;
            }
            s.pop_back();
        }
        return false;
    }
public:
    string getHappyString(int n, int k) {
        string s = "";
        func(s,n,k);
        return s;
    }
};

/*

['a', 'b', 'c']

*/ 