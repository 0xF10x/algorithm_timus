#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,m;
	int ans[10001];
	int a[51];
	cin >> n >> m;
	memset(ans, 0, sizeof(ans));
	ans[0] = 1;
	for (int i = 0;i < m;i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < m; j++){
			if (i - a[j] >= 0 && ans[i - a[j]] == 0){
				ans[i] = 1;
				break;
			}
		}
	}
	if (ans[n] == 1){
		cout << 1;
	}
	else cout << 2;
	return 0;
}