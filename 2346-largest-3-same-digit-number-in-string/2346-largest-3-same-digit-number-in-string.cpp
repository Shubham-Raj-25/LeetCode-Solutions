class Solution {
public:
    string largestGoodInteger(string num) {
        
        string ans = "";
        int maxi = 0;
        
        for(int i=0;i<num.length()-2;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                int data = stoi(num.substr(i,3));
                if(data >= maxi)
                    {   
                        maxi = data;
                        ans = num.substr(i,3);
                    }
            }    
        }

        return ans;
    }
};