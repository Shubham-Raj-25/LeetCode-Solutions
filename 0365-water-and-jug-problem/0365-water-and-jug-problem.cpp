//Absurd Math's Solution using GCD, I prefer BFS more
class Solution {
public:
    int gcd(int a, int b){
    while(b != 0 ){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;}

    bool canMeasureWater(int j1, int j2, int t) {
        if(j1+j2<t) return false;
        if(j1==t||j2==t||j1+j2==t) return true;
        return t % gcd(j1,j2) == 0;
    }
};