#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-5;
double a[10010];
int k, n;
double check(double mid) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (int)(a[i] / mid);
	}
	return sum;
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
	double l = 0, r = 0x7fffffff;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (check(mid) >= k) l = mid;
		else r = mid;
	}
	printf("%.2lf\n", floor(r * 100) / 100);  
	return 0;
} 