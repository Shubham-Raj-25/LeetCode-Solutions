class Solution {
public:
    int getSum(string s, int k){
        if(k == 0)
            return stoi(s);
        int sum = 0;
        for(char c : s)
            sum += c - '0';
        if(sum >= 10)
            return getSum(to_string(sum),k-1);
        return sum;
    }
    int getLucky(string s, int k) {
        string s_new = "";
        for(char c : s){
            int data = c - 'a' + 1;
            string temp = to_string(data);
            s_new  += temp; 
        }
        cout << s_new << endl;
        return getSum(s_new,k);
    }
};