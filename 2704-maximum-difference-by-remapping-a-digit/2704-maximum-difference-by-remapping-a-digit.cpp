class Solution {
public:
    int minMaxDifference(int num) {
        string curr = to_string(num);
        string maxi, mini;
        char to_change_maxi = '9', to_change_mini = curr[0];
        for(int i=0;i<curr.length();i++){
            if(curr[i] != '9'){
                to_change_maxi = curr[i];
                break;
            }
        }
        for(int i=0;i<curr.length();i++){
            if(curr[i] == to_change_maxi){
                maxi.push_back('9');
            }
            else{
                maxi.push_back(curr[i]);
            }
            if(curr[i] == to_change_mini){
                mini.push_back('0');
            }
            else{
                mini.push_back(curr[i]);
            }
        }

        return stoi(maxi)-stoi(mini);
    }
};

/*
for max - pick first non 9 from the left, and map it to 9
for min - map first one to 0
*/