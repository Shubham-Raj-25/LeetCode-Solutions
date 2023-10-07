class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = minutes*6;
        double n;
        if(hour == 12)
            n = (30*(m/360));
        else
            n = (hour*30)+(30*(m/360));
        
        return min(abs(m-n),360-abs(m-n));
    }
};