//Name -> Rajni
//Roll No. -> 25/DA/052
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    int start[100], finish[100];

    cout << "Enter starting times:\n";
    for(int i = 0; i < n; i++){
        cin >> start[i];
    }

    cout << "Enter finishing times:\n";
    for(int i = 0; i < n; i++){
        cin >> finish[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(finish[i] > finish[j]){
                swap(finish[i], finish[j]);
                swap(start[i], start[j]);
            }
        }
    }

    cout << "Selected activities are:\n";

    cout << "(" << start[0] << ", " << finish[0] << ") ";

    int lastFinish = finish[0];

    for(int i = 1; i < n; i++){
        if(start[i] >= lastFinish){
            cout << "(" << start[i] << ", " << finish[i] << ") ";
            lastFinish = finish[i];
        }
    }

    return 0;
}
