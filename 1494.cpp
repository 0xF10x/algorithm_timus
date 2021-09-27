#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i, t;
    vector<int> v;
    cin >> n;
    cin >> i;
    t = i;
    if (t != 1) {
        for (int p = 1; p < t; p++) {
            v.push_back(p);
        }
    }
    else
        v.push_back(-1);
    for (; n - 1; n--) {
        cin >> i;
        if (v.empty() && (i > t)) {
            for (t = t + 1; t < i; ++t) {
                v.push_back(t);
            }
            t = i;
            continue;
        }
        if (i == v.back()) {
            v.erase(v.begin() + size(v) - 1, v.begin() + size(v));
        }
        else {
            if (i > v.back()) {
                for (t = t + 1; t < i; ++t) {
                    v.push_back(t);
                }
                t = i;
            }
            if (i < v.back()) {
                cout << "Cheater";
                return 0;
            }
        }

    }
    cout << "Not a proof";
    return 0;
}