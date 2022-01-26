#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);

	// Process crab data
	vector<int> data;
	while (cin) {
		int fish;
		cin >> fish;
		data.push_back(fish);
		// Ignore next character (comma)
		getchar();
	}
	data.pop_back();

	int largest = *max_element(data.begin(),data.end());

	// Total cost of fuel for each possible position
	vector<int> fuel(largest+1);

	// Calculate fuel cost for each position, one crab at a time
	for (int crab_pos : data) {
		int cost;
		// Fill right
		cost = 1;
		for (int i=crab_pos+1;i<largest+1;i++) {
			fuel[i] += (cost*(cost+1))/2;
			++cost;
		}
		// Fill left
		cost = 1;
		for (int i=crab_pos-1;i>=0;i--) {
			fuel[i] += (cost*(cost+1))/2;
			++cost;
		}
	}

	int ans = *min_element(fuel.begin(),fuel.end());

	cout << "Result: " << ans << '\n';
}
