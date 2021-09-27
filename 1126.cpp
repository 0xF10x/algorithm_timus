#include <iostream>
#include <queue>

using namespace std;

struct strct
{
    int zn;
    int k;
}n;

deque<strct> q;

int main()
{
    int m, i, a; 
    i = 0;
    cin >> m;
    while (1){
        cin >> a;
        if (a != -1) {
            n.zn = a;
            n.k = i++;
            while (!q.empty() && q.front().k < i - m) q.pop_front(); // проверка на промежуток и удаление лишнего с левого края
            while (!q.empty() && q.back().zn < a) q.pop_back(); // замена меньшего жлемента на больший с правого края
            q.push_back(n); // внесение в очередь
            if (i >= m) cout << q.front().zn << "\n"; // после выполнения двух предыдущих циклов, когда индекс элемента будет равен или больше m, в первом элементе лежит наибольший элемент промежута
        }
        else return 0;
    }
    return 0;
}