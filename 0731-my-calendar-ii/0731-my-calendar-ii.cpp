class MyCalendarTwo {
public:
    map<int,int> bookings;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        bookings[start]++;
        bookings[end]--;
        int no_of_bookings = 0;

        for(auto it = bookings.begin(); it != bookings.end(); it++){
            no_of_bookings += it->second;
            if(no_of_bookings > 2){
                bookings[start]--;
                bookings[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */