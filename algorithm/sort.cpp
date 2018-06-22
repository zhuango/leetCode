#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &num, int start, int end)
{
    int pivot = num[start];
    int i = start + 1;
    int j = end;

    while(true)
    {
        while(num[i] < pivot) { if(i == end) break; i++; }
        while(num[j] > pivot) { if(j == start) break; j--;}
        if(i >= j) break;
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
    swap(num[start], num[j]);
    return j;
}

void quickSort(vector<int> &num, int start, int end)
{
    if(start >= end) return;
    int middle = partition(num, start, end);
    quickSort(num, start, middle - 1);
    quickSort(num, middle + 1, end);
}

void adjustHeap(vector<int> &num, int i, int n)
{
    while((i+1)*2 < n)
    {
        int left = i * 2 + 1;
        int right = left + 1;
        int maxlr = left;
        if(right < n && num[right] > num[left]) maxlr = right;
        if (num[i] < num[maxlr]) swap(num[i], num[maxlr]);
        else break;
        i = maxlr;
    }
}
void buildHeap(vector<int> &num)
{
    int n = num.size();
    for(int i = n / 2 - 1; i >= 0; --i)
    {
        adjustHeap(num, i, num.size());
    }
}


void heapSort(vector<int> &num)
{
    buildHeap(num);
    for(int i = num.size() - 1; i >= 0; --i)
    {
        swap(num[i], num[0]);
        adjustHeap(num, 0, i);
    }
}

int main(void)
{
    vector<int> input = {23, 12, 4, 312, 4, 12, 65,2, 23};
    //quickSort(input, 0, input.size());
    heapSort(input);
    for(int i : input)
    {
        cout << i << " ";
    }
    cout << endl;
}