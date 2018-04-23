#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int index = 0;
        for(Employee *e : employees)
        {
            mapping[e->id] = index;
            index += 1;
        }
        return getImportanceEntry(employees, id);
    }
    int getImportanceEntry(vector<Employee*> &employees, int id)
    {
        int count = 0;
        for(int &e : employees[mapping[id]]->subordinates)
        {
            count += getImportanceEntry(employees, e);
        }
        return count + employees[mapping[id]]->importance;
    }
    private:
        unordered_map<int, int> mapping;
};
