class MyCalendar {
public:
    vector<pair<int, int>> eventTime;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& [s, e] : eventTime){
            if (max(start, s) < min(end, e)){
                return false;
            }
        }
        eventTime.push_back({start, end});
        return true;
    }
};