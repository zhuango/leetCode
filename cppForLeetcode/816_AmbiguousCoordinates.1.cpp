#include <string>
#include <vector>
using namespace std;

vector<string> cases(string &&s) {
    if (s.size() == 1) // single digit
        return {s};
    if (s.front() == '0') { // 0xxx
        if (s.back() == '0') // 0xxx0
            return {};
        return {"0." + s.substr(1)}; // 0xxx9
    }
    if (s.back() == '0') // 9xxx0
        return {s};
    vector<string> res{s}; // 9xxx9
    for (int i = 1; i < s.size(); i++)
        res.emplace_back(s.substr(0, i) + "." + s.substr(i));
    return res;
}

vector<string> ambiguousCoordinates(string S) {
    vector<string> res;
    for (int i = 2; i < S.size() - 1; i++) // position of comma
    for (auto &x : cases(S.substr(1, i - 1)))
    for (auto &y : cases(S.substr(i, S.size() - i - 1)))
        res.emplace_back("(" + x + ", " + y + ")");
    return res;
}