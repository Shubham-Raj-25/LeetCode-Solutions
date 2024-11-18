class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> data = code, ans;
        for(int i=0;i<2;i++)
            data.insert(data.end(),code.begin(),code.end());

        for(int i=code.size();i< 2 * code.size();i++){
            int temp = 0;
            for(int j=1; j<=abs(k) ; j++)
                if(k > 0)
                    temp += data[i+j];
                else if(k < 0)
                    temp += data[i-j];
            ans.push_back(temp);
            }

        return ans;
    }

};