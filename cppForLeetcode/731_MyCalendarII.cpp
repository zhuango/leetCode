#include <iostream>

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
        for (auto head : singleBook)
        {
            int tempStart = get<0>(head);
            int tempEnddd = get<1>(head);
            int singleOverlapStart = max(start, tempStart);
            int singleOverlapEnddd = min(end, tempEnddd);
            if ( singleOverlapStart < singleOverlapEnddd )
            {
                for (auto doubleHead : doubleBook)
                {
                    int doubleStart = get<0>(doubleHead);
                    int doubleEnddd = get<1>(doubleHead);
                    int doubleOverlapStart = max(singleOverlapStart, doubleStart);
                    int doubleOverlapEnddd = min(singleOverlapEnddd, doubleEnddd);
                    if ( doubleOverlapStart < doubleOverlapEnddd )
                    {
                        doubleBook.clear();
                        return false;
                    }
                }
                doubleBook.push_back(make_tuple(singleOverlapStart, singleOverlapEnddd));
            }
        }
        singleBook.push_back(make_tuple(start, end));
        return true;
    }
};

int main(void)
{
    MyCalendarTwo *obj = new MyCalendarTwo();
    bool param_1 = obj->book(10,20); 
    cout << param_1 << endl; 
    param_1 = obj->book(50,60); 
    cout << param_1 << endl; 
    param_1 = obj->book(10,40); 
    cout << param_1 << endl; 
    param_1 = obj->book(5,15); 
    cout << param_1 << endl; 
    param_1 = obj->book(5,10); 
    cout << param_1 << endl; 
    param_1 = obj->book(25,55); 
    cout << param_1 << endl; 
    // param_1 = obj->book(5,15); 
    // cout << param_1 << endl; 
}
