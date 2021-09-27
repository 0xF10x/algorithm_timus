#include <iostream>
#include <algorithm>
#define n 70000 
#include <vector>
#include <stdlib.h>

using namespace std;



struct dima {
	int num;
	int kolvo;
	dima(int num = 0, int kolvo = 0) {
		this->num = num;
		this->kolvo = kolvo;
	}
};

int sr(const dima* x, const dima* y);
int sr1(const dima x, const dima y);
int main() {
	vector<int> vec;
	int m,l ,b, x, p,k;
	dima a[n];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].kolvo;
		a[i].num = i + 1;
	}
	dima t;
	qsort(a, m, sizeof(dima), (int(*)(const void*, const void*)) sr);

	dima o, y;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> b >> x;
		o.kolvo = x;
		y.kolvo = x;
		o.num = l;
		y.num = b;
		p = lower_bound(a, a + m, o, sr1)-a;
		k = upper_bound(a, a + m, y, sr1)-a;
		if (p != k) cout << 1;
		else cout << 0;
	}
}

int sr(const dima* x, const dima* y) {
	if ((*x).kolvo == (*y).kolvo) return (*x).num - (*y).num;
	return (*x).kolvo - (*y).kolvo;
}
int sr1(const dima x, const dima y) {
	if (x.kolvo == y.kolvo) return x.num < y.num;
	return x.kolvo < y.kolvo;
}