#include <iostream>
using namespace std;

void inputRatings(int ratings[5][10]) {
    for (int i = 0; i < 5; i++) {
        cout << "Enter ratings for product " << i + 1 << " (10 users, 1-5):\n";
        for (int j = 0; j < 10; j++) {
            int r;
            do {
                cout << "User " << j + 1 << ": ";
                cin >> r;
                if (r < 1 || r > 5)
                    cout << "Invalid rating, enter 1 to 5.\n";
            } while (r < 1 || r > 5);
            ratings[i][j] = r;
        }
    }
}

void calculateAverage(int ratings[5][10], float avg[5]) {
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += ratings[i][j];
        }
        avg[i] = sum / 10.0f;
    }
}

void countPerfect(int ratings[5][10], int perfectCount[5]) {
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (ratings[i][j] == 5) count++;
        }
        perfectCount[i] = count;
    }
}

void displayWorstProducts(float avg[5]) {
    float minAvg = avg[0];
    for (int i = 1; i < 5; i++) {
        if (avg[i] < minAvg)
            minAvg = avg[i];
    }
    cout << "\nProduct(s) with worst average rating (" << minAvg << "): ";
    for (int i = 0; i < 5; i++) {
        if (avg[i] == minAvg)
            cout << "Product " << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    int ratings[5][10];
    float averages[5];
    int perfectRatings[5];

    inputRatings(ratings);
    calculateAverage(ratings, averages);
    countPerfect(ratings, perfectRatings);

    cout << "\nAverage Ratings per Product:\n";
    for (int i = 0; i < 5; i++)
        cout << "Product " << i + 1 << ": " << averages[i] << endl;

    cout << "\nPerfect Ratings (5) per Product:\n";
    for (int i = 0; i < 5; i++)
        cout << "Product " << i + 1 << ": " << perfectRatings[i] << endl;

    displayWorstProducts(averages);

    return 0;
}
