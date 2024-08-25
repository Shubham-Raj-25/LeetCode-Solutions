class Solution {
public:
    void func(int idx, string& temp, string& digits, vector<string>& data, vector<string>& ans){
        if(idx == digits.length()){
            if(temp.length()>0)
                ans.push_back(temp);
            return;
        }

        for(char c: data[int(digits[idx]) - 49]){
            temp.push_back(c);
            func(idx+1,temp,digits,data,ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> data = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s;
        func(0,s,digits,data,ans);
        return ans;
    }
};