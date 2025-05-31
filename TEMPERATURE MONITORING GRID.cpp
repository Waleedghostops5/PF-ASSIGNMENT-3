#include <iostream>
using namespace std;

void inputTemperature(float temp[5][5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Enter temperatures for Zone " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cout << "  Location " << j + 1 << ": ";
            cin >> temp[i][j];
        }
    }
}

void averagePerZone(float temp[5][5], float avg[5]) {
    for (int i = 0; i < 5; i++) {
        float sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += temp[i][j];
        }
        avg[i] = sum / 5;
    }
}

void findExtremes(float temp[5][5], float& hottest, float& coldest) {
    hottest = temp[0][0];
    coldest = temp[0][0];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (temp[i][j] > hottest)
                hottest = temp[i][j];
            if (temp[i][j] < coldest)
                coldest = temp[i][j];
        }
    }
}

int main() {
    float temp[5][5];
    float avg[5];
    float hottest, coldest;

    inputTemperature(temp);
    averagePerZone(temp, avg);
    findExtremes(temp, hottest, coldest);

    cout << "\n--- Average Temperature per Zone ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "Zone " << i + 1 << ": " << avg[i] << "\n";
    }

    cout << "\n--- Extreme Temperatures ---\n";
    cout << "Hottest Spot: " << hottest << "\n";
    cout << "Coldest Spot: " << coldest << "\n";

    return 0;
}
