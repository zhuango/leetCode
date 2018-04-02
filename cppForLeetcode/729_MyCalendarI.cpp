#include <tuple>
#include <vector>
using namespace std;

class MyCalendar {
    typedef tuple<int, int> Interval;
    private:
    vector<Interval> single;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int overstart = 0;
        int overend = 0;
        for (Interval & interval: single)
        {
            overstart = max(start, get<0>(interval));
            overend = min(end, get<1>(interval));
            if (overstart < overend)
            {
                return false;
            }
        }
        single.push_back(make_tuple(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */