#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;

	int run_sum = 0;
	int idx = 0;

	vector<int> h(n - k);

	for (int i = 0; i < k; i++) {
		int b;
		cin >> b;
		run_sum += b;
		if (i < n - k) h[i] = b;
	}

	int min_sum = run_sum;

	for (int i = k; i < n; i++) {
		int b;
		cin >> b;
		if (i < n - k) h[i] = b; 
		run_sum += b - h[i - k]; 
		if (run_sum < min_sum) {
			min_sum = run_sum;
			idx = i - k + 1;
		}
	}

	cout << idx + 1;

	return 0;
}
