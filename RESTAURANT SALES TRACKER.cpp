#include <iostream>
using namespace std;


void inputSales(float sales[][7], int items, int days) {
    for (int i = 0; i < items; i++) {
        cout << "Enter sales for Item " << i + 1 << ":\n";
        for (int j = 0; j < days; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> sales[i][j];
        }
    }
}


void totalSalesPerItem(float sales[][7], int items, int days, float totals[]) {
    for (int i = 0; i < items; i++) {
        totals[i] = 0;
        for (int j = 0; j < days; j++) {
            totals[i] += sales[i][j];
        }
    }
}


void totalSalesPerDay(float sales[][7], int items, int days, float totals[]) {
    for (int j = 0; j < days; j++) {
        totals[j] = 0;
        for (int i = 0; i < items; i++) {
            totals[j] += sales[i][j];
        }
    }
}


int highestSalesDay(float dailyTotals[], int days) {
    int maxDay = 0;
    for (int i = 1; i < days; i++) {
        if (dailyTotals[i] > dailyTotals[maxDay]) {
            maxDay = i;
        }
    }
    return maxDay;
}


int mostSoldItem(float itemTotals[], int items) {
    int maxItem = 0;
    for (int i = 1; i < items; i++) {
        if (itemTotals[i] > itemTotals[maxItem]) {
            maxItem = i;
        }
    }
    return maxItem;
}

int main() {
    int items = 4;
    int days = 7;
    float sales[4][7];
    float itemTotals[4];
    float dayTotals[7];

    inputSales(sales, items, days);

    totalSalesPerItem(sales, items, days, itemTotals);
    totalSalesPerDay(sales, items, days, dayTotals);

    cout << "\n--- Total Sales Per Item ---\n";
    for (int i = 0; i < items; i++) {
        cout << "Item " << i + 1 << ": " << itemTotals[i] << "\n";
    }

    cout << "\n--- Total Sales Per Day ---\n";
    for (int j = 0; j < days; j++) {
        cout << "Day " << j + 1 << ": " << dayTotals[j] << "\n";
    }

    int bestDay = highestSalesDay(dayTotals, days);
    int topItem = mostSoldItem(itemTotals, items);

    cout << "\nHighest Sales Day: Day " << bestDay + 1 << "\n";
    cout << "Most Sold Item: Item " << topItem + 1 << "\n";

    return 0;
}
