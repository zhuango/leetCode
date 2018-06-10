#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int rightest = 0;
        int bl = 0;
        int br = 0;
        int oldr = 0;
        int head = 0;
        if (seats[0] == 0)
        {
            while(seats[rightest] != 1) rightest ++;
        }
        head = rightest;
        int tail = seats.size()-1;
        if(seats[seats.size()-1] == 0)
        {
            while(seats[tail] != 1) tail--;
        }
        tail = seats.size() - 1 - tail;
        int distance =0;
        while(rightest < seats.size() - tail)
        {
            if(seats[rightest] == 1) {rightest++; continue;}
            int start = rightest-1;
            int end = 0;
            while(seats[rightest] != 1) rightest++;
            end = rightest;
            int temp = (end + start) / 2 - start;
            if(distance < temp)
            {
                distance = temp;
            }
        }
        return max(distance, max(head, tail));
    }
};


int main(void)
{
    vector<int> input = {0, 0, 0,  0, 0, 1};
    Solution sol;
    cout << sol.maxDistToClosest(input) << endl;
}