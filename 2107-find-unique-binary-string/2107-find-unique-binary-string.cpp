class Solution {
public:
    bool generate(string &s, vector<string>& nums){
        if(s.length() == nums.size()){
            auto it = find(nums.begin(),nums.end(),s);
            if(it == nums.end()){
                return true;
            }
            return false;
        }

        for(char c = '0'; c <= '1'; c++){
            s.push_back(c);
            if(generate(s,nums)){
                return true;
            }
            s.pop_back();
        }
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string s = "";
        generate(s,nums);
        return s;
    }
};