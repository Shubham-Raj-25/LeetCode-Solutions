class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> tk;
        int n = digits.size();
        for(int a=0; a<n; a++)
        {
            if(digits[a]!=0)
            {
                for(int b=0; b<n; b++)
                {
                    for(int c=0; c<n; c++)
                    {
                        if(a==b || b==c || a==c)
                            continue;

                        int cal = (digits[a]*100)+(digits[b]*10)+digits[c];
                        if(cal%2==0)
                            tk.insert(cal);
                    }
                }
            }
        }
        vector<int> re(tk.begin(), tk.end());
        return re;
    }
};