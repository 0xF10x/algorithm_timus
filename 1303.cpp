#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct str {
    int left, right;
    str(int x = 0, int y = 0) {
        left = x;
        right = y;
    }

    bool operator < (str X)const {
        return right < X.right;
    }
}
S[100000], ans[100000];

bool pr_sort(str x, str y) {
    return x.left < y.left;
}

int main() {
    int m, i = 0;
    cin >> m;

    while (true) {
        cin >> S[i].left >> S[i].right;
        if (S[i].left == 0 && S[i].right == 0) { 
            break; 
        }
        ++i;
    }

    sort(S, S + i, pr_sort);

    int pokr = 0;
    int p = 0; 
    int t = 0;
    bool p = true;

    while (pokr < m && p) {
        priority_queue<str> queue1;

        while (p < i && S[p].left <= pokr) {
            if (S[p].right > pokr)
                queue1.push(S[p]);
            ++p;
        }

        if (queue1.empty()) p = false;
        else {
            str t_ans = queue1.top();
            ans[t] = t_ans;
            t++;
            pokr = t_ans.right;
        }
    }

    if (!p) cout << "No solution";
    else {
        cout << t << endl;
        for (int i = 0; i < t; ++i)
            cout << ans[i].left <<" "<< ans[i].right << endl;
    }

    return 0;
}