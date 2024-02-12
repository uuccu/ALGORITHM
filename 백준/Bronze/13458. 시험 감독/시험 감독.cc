#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int room, main, sub;
	long int result = 0;
	cin >> room;
	vector<int> v(room);

	for (int i = 0; i < room; i++) {
		cin >> v[i];
	}

	cin >> main >> sub;
	
	for (int i = 0; i < room; i++) {

		if (v[i] - main < 1) result += 1;
		else if (v[i] - main > 0 && (v[i] - main) % sub == 0) result += (1 + (v[i] - main) / sub);
		else result += (2 + (v[i]-main) / sub);
	}

	cout << result;
	return 0;

}