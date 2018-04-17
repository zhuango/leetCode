#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        vector<int> buckets (n+1,0);
        for(int citation: citations) {
            if(citation>=n)
                buckets[n]++;
            else
                buckets[citation]++;
        }
        
        int h_index=0;
        for(int i=n; i>=0; i--) {
            h_index += buckets[i];
            if(h_index>=i) return i;
        }
        return h_index;
    }
};