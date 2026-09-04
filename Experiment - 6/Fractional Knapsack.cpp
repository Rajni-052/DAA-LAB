//Name -> Rajni
//Roll No. -> 25/DA/052
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter profit and weight of each item:\n";

    for (int i=0; i<n; i++) {
        cin>>items[i].profit>>items[i].weight;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    double maxProfit = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight){
            capacity -= items[i].weight;
            maxProfit += items[i].profit;
        }
        else {
            maxProfit += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }
    cout << "\nMaximum Profit = " << maxProfit << endl;

    return 0;
}
