#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int k = 3;
        vector<int> heap;
        unordered_map<int, bool> has;
        for(int i = 0; heap.size() < k && i < nums.size(); ++i)
        {
            if(!has[nums[i]]) 
            {   
                cout << nums[i] << endl;
                heap.push_back(nums[i]);
                has[nums[i]] = true;
            }
        }
        if(heap.size() < 3) return *max_element(heap.begin(), heap.end());
        buildHeap(heap);
        cout << heap[0] << endl;
        for(int i = k; i < nums.size(); ++i)
        {
            if(nums[i] > heap[0] && !has[nums[i]])
            {
                has[heap[0]] = false;
                has[nums[i]] = true;
                heap[0] = nums[i];
                adjustHeap(heap, 0);
            }
        }
        return heap[0];
    }
    void buildHeap(vector<int> &heap)
    {
        for(int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            adjustHeap(heap, i);
        }
    }
    void adjustHeap(vector<int> &heap, int i)
    {
        while((i+1)*2 <= heap.size())
        {
            int left = i * 2 + 1;
            int right = left + 1;
            int maxlr = left;
            if(right < heap.size() && heap[right] < heap[left]) maxlr = right;
            if(heap[i] > heap[maxlr])
            {
                int temp = heap[i];
                heap[i] = heap[maxlr];
                heap[maxlr] = temp;
                i = maxlr;
            }
            else break;
        }
    }
};

int main(void)
{
    //vector<int> input = {12, 123, 5, 3,12, 54, 123, 3, 76, 4};
    vector<int> input = {2, 2, 3, 1};
    Solution sol;
    cout << sol.thirdMax(input) << endl;
}