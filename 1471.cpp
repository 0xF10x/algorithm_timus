#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50000;
const int pow2 = 20;

int N;
vector<int> L[MAX], W[MAX];

int Q[MAX]; 
int start, down;
bool bpp[MAX] = {false};
int P[MAX][pow2];
int lvl[MAX];
int range[MAX][pow2];

void bfs();
void init();
int LCA(int p, int q);

int main() {
    cin >> N;
    for (int i = 1, u, v, w; i < N; ++i) {
        cin >>u >> v >> w;
        L[u].push_back(v);
        W[u].push_back(w);
        L[v].push_back(u);
        W[v].push_back(w);
    }
    int Q;
    cin >> Q;
    init();
    for (int q = 0, u, v; q < Q; ++q) {
        cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
    return 0;
}
void bfs() {
    start = 0; down = 0;
    P[0][0] = -1;
    lvl[0] = 0;
    range[0][0] = -1;
    Q[0] = 0; down = 1;
    bpp[0] = true;

    while (start < down) {
        int pos = Q[start];
        ++start;

        for (int i = L[pos].size() - 1; i >= 0; --i) {
            int next = L[pos][i];

            if (!bpp[next]) {
                P[next][0] = pos;
                lvl[next] = lvl[pos] + 1;
                range[next][0] = W[pos][i];
                Q[down] = next;
                ++down;
                bpp[next] = true;
            }
        }
    }
}
void init() {
    bfs();
    for (int j = 1; (1 << j) < N; ++j) {
        for (int i = 0; i < N; ++i) {
            if (P[i][j - 1] != -1) {
                P[i][j] = P[P[i][j - 1]][j - 1];
                range[i][j] = range[i][j - 1] + range[P[i][j - 1]][j - 1];
            }
        }
    }
}
int LCA(int p, int q) {
    if (lvl[p] < lvl[q]) swap(p, q);
    int log = 0;
    while ((1 << log) <= lvl[p]) ++log;
    --log;
    int ans = 0;
    for (int i = log; i >= 0; --i) {
        if (lvl[p] - (1 << i) >= lvl[q]) {
            ans += range[p][i];
            p = P[p][i];
        }
    }
    if (p == q) return ans;
    for (int i = log; i >= 0; --i) {
        if (P[p][i] != -1 && P[p][i] != P[q][i]) {
            ans += range[p][i] + range[q][i];
            p = P[p][i];
            q = P[q][i];
        }
    }
    ans += range[p][0] + range[q][0];
    return ans;
}
