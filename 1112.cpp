#include <iostream>
#include <vector>
#include <algorithm>
#define N 100
using namespace std;

struct struc
{
	int x, y;
};
bool sravnenie(struc l, struc r);
struc ar[N];

vector<struc> res;

int main(){
	int n,s,f;
	cin >> n;
	for (int i = 0; i < n; i++){	
		cin >> s >> f;
		ar[i].x = s < f ? s : f;
		ar[i].y = s > f ? s : f;
	}
	sort(ar, ar + n, sravnenie);
	res.push_back(ar[0]);
	int k = 0;
	for (int i = 1; i < n; i++){
		if (ar[i].x >= ar[k].y){
			res.push_back(ar[i]);
			k = i;
		}
	}
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
		cout << res[i].x << " " << res[i].y <<"\n";
}
bool sravnenie(struc l, struc r){
	if (l.y != r.y)
		return l.y < r.y;
	return l.x < r.x;
}