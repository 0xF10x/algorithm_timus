#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct otr
{
    int l;
    int num;
    int f;
    otr(int l = 0, int num = 0, int f = 0) {
        this->l = l;
        this->num = num;
        this->f = f;
    }
};
bool sr(otr o1, otr o2);
int main() {
    int n, l, k, a, j;
    otr t;
    vector<otr> o;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> l;
        o.push_back(otr(l, (int)(i / 2 + 1), pow(-1, i)));
    }

    sort(o.begin(), o.end(), sr);

    /*for (auto i = o.begin(); i != o.end(); i++) {
        cout << i->l << " " << i->num << " " << i->f << endl;
    }*/
    cin >> k;
    t.num = INT32_MAX;
    for (int i = 0; i < k; i++) {
        cin >> t.l;
        if ((t.l > o[o.size() - 1].l) || (t.l < o[0].l)) {
            cout << -1 << "\n";
            continue;
        }
        a = upper_bound(o.begin(), o.end(), t, sr) - o.begin();
        if (o[a - 1].l == t.l) {
            cout << o[a - 1].num << "\n";
            continue;
        }
        j = 0;
        for (; a < o.size(); a++) {
            j += o[a].f;
            if (j == -1) {
                cout << o[a].num << "\n";
                break;
            }
        }
    }

}
bool sr(otr o1, otr o2) {
    if (o1.l != o2.l) return o1.l < o2.l;
    else return o1.num < o2.num;
}