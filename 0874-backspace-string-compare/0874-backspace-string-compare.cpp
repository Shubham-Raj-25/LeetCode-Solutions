class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1,st2;
        for(auto it:s){
            if(it!='#')
                st1.push(it);
            else if(!st1.empty())
                st1.pop();
        }

        string news;

        while(!st1.empty()){
            news.push_back(st1.top());
            st1.pop();
        }

        for(auto it:t){
            if(it!='#')
                st2.push(it);
            else if(!st2.empty())
                st2.pop();
        }

        string newt;

        while(!st2.empty()){
            newt.push_back(st2.top());
            st2.pop();
        }

        return news == newt;
    }
};