class MyCalendar {
public:
        unordered_map<int,int>map;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& pointer : map) {
            int a = pointer.first;  // start time of the existing booking
            int b = pointer.second; // end time of the existing booking

            
            if (start < b && end > a) {
                return false; // There is an overlap
            }
        }
         map[start]=end;
            return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */