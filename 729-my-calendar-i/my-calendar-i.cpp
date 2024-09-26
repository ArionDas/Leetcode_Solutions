class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    multiset<pair<int,int>> ms;
    
    bool book(int start, int end) {
        auto it = ms.lower_bound({end, 0});

        if(it != ms.begin()) {
            auto prev = it;
            prev--;
            if(prev->first > start)
                return false;
        }

        if(it != ms.end() && it->second < end)
            return false;

        ms.insert({end, start});
        return true;    
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */