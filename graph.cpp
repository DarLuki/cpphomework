#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector<int>> v(n);
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (x > n || y > n) continue;
		else v[x].push_back(y);
	}int ver;
	cin >> ver;
	cout << v[ver].size() << endl;
}
