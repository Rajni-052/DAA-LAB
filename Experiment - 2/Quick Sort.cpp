//Name -> Rajni
//Roll No. -> 25/A07/052
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j=low; j<high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {21,23,43,12,1,32,17,86};
	int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";

    return 0;
}
