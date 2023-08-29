class Solution {
public:
    int bestClosingTime(string customers) {
        // greedy type problem
        // Y Y N Y 
    // Ys->3 2 1 1 (close check)
    // Ns->F F T F (open  check)

    vector<int> yes;
    vector<int> no;

    int sum = 0;

    for(int i=customers.size()-1;i>=0;i--){
        if(customers[i]=='Y')
            sum++;
        yes.push_back(sum);

    }

    sum = 0;
    no.push_back(0);
    for(int i=1;i<customers.size();i++){
        if(customers[i-1]=='N')
            sum++;
        no.push_back(sum);
    }
    
    for(auto it:no)
        cout << it << " " ;

    reverse(yes.begin(),yes.end());

    if(customers.back()=='Y')
    {yes.push_back(yes[yes.size()-1]-1);
    no.push_back(sum);}

    int ans = 0;
    int mini = INT_MAX;


    for(int i=0;i<yes.size();i++){
        // if closing on ith hour
        if(mini > yes[i]+no[i]){
            ans = i;
            mini = yes[i]+no[i];
        }
    }
    return ans;

    }
};