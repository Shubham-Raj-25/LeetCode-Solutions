class Solution {
public:
   
   vector<int> executeInstructions(int n, vector<int> &st, string s)
{
    vector<int> res;
    int i1 = st[0], j1 = st[1];
    int a=i1,b=j1;

    for (int j = 0; j < s.size(); j++)
    {
        int c = 0;
        for (int i = j; i < s.size(); i++)
        {
            if (s[i] == 'U')
            {
                if (i1 - 1 >= 0)
                   i1--, c++;
                 else
                    break;
            }
            else if (s[i] == 'R')
            {
                if (j1 + 1 < n)
                    j1++,c++;
                else
                    break;
            }
            else if (s[i] == 'D')
            {
                if (i1 + 1 <n)
                  i1++, c++;
                 else
                    break;
            }
            else if (s[i] == 'L')
            {
                if (j1 - 1 >= 0)
                   j1--, c++;
                 else
                    break;
            }
            else
                break;
        }
        res.push_back(c);
        i1=a,j1=b;
    }
    return res;
}
};