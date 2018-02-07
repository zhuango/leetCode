#include <list>
#include <tuple>
using namespace std;

class MyCalendarTwo 
{
    typedef tuple<int, int> Interval;
private:
    list<Interval> singleBook;
    list<Interval> doubleBook;
public:
    MyCalendarTwo() 
    {
        
    }
    bool book(int start, int end) 
    {
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */