#include <iostream>

using namespace std;

void merge_sort(int arr[], int min, int max) {
	if (max <= min) return;
	int middle = (min + max) / 2;
	merge_sort(arr, min, middle);
	merge_sort(arr, middle + 1, max);

	int* t_arr = new int[max - min + 1];
	int i = min, j = middle + 1;
	int index = 0;
	while (i <= middle && j <= max) {
		if (arr[i] < arr[j]) {
			t_arr[index] = arr[i];
			index++;
			i++;
		}
		else {
			t_arr[index] = arr[j];
			index++;
			j++;
		}
	}
	while (i <= middle) {
		t_arr[index] = arr[i];
		index++;
		i++;
	}
	while (j <= max) {
		t_arr[index] = arr[j];
		index++;
		j++;
	}

	for(int i=min; i<=max; i++) {
		arr[i] = t_arr[i-min];
	}

	delete[] t_arr;
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}