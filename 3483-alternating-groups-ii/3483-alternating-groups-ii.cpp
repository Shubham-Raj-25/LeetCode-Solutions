class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int l = 0, r = 0;
        int ans = 0;

        for(int l=0;l<n;l++){
            // try to form the window
            int last = colors[r%n];
            while(r-l+1 < k && colors[(r+1)%n] != last){
                r++;
                last = colors[r%n];
            }
             // if window formed
            if(r-l+1 == k){
                ans++;
            }
            else{ // jump l
                l = r;
                r = r+1;
            }
        }
        return ans;
    }
};

/*

0->red
1->blue
alternating group 
:every k contiguous tiles in the circle with alternating colors 

k->size

3 <= colors.length <= 105 O(N)
SW of size k approach

[0,1,0,1,0], k = 3

0 1 0 1 0
_ _ _
  _ _ _
    _ _ _
    
if not alternating -> break the window ?

i-> 0 to n-1
j-> k to (n-1+k)%n


0 1 0 0 1 0 1    :: k = 6
_ _   _ _ _ _

handle only the starting point and make sure it makes only 1 circle.

*/ 