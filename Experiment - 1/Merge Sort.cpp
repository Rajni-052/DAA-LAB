//Name -> Rajni
//Roll No. -> 25/DA/052
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Recursive Merge Sort
void recursiveMergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left+(right-left)/2;

    recursiveMergeSort(arr, left, mid);
    recursiveMergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

// Iterative Merge Sort
void iterativeMergeSort(vector<int>& arr) {
    int n = arr.size();
    for (int size=1; size<n; size*=2) {
        for (int left=0; left<n-1; left+=2*size) {
            int mid = min(left+size-1, n-1);
            int right = min(left+2*size-1, n-1);

            if (mid < right)  merge(arr, left, mid, right);
        }
    }
}


int main() {
    vector<int> arr = {90,45,21,23.53,78,9,4,68};
	int n = arr.size();
    vector<int> recursiveArr = arr;
    vector<int> iterativeArr = arr;

    recursiveMergeSort(recursiveArr, 0, n-1);

    iterativeMergeSort(iterativeArr);

    cout << "\nSorted array using Recursive Merge Sort: ";
    for(int i=0;i<recursiveArr.size();i++) cout<<recursiveArr[i]<<" ";

    cout <<endl<< "Sorted array using Iterative Merge Sort: ";
    for(int i=0; i<iterativeArr.size(); i++) cout<<iterativeArr[i]<<" ";

    return 0;
}
