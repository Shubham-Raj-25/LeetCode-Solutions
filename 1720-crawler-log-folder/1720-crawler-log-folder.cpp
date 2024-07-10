class Solution {
public:
    int minOperations(vector<string>& logs) {
        int i = 0;
        for(string log : logs){
            if(log == "../")
                i = max(0,i-1);
            else if(log == "./")
                continue;
            else
                i++;
        }

        return i;
    }
};