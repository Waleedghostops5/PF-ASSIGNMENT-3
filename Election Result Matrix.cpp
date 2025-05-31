#include <iostream>
using namespace std;

void inputVotes(int votes[4][6]) {
    cout << "Enter votes for 4 candidates from 6 polling stations:\n";
    for (int c = 0; c < 4; c++) {
        cout << "Candidate " << c + 1 << ":\n";
        for (int p = 0; p < 6; p++) {
            cout << "  Polling Station " << p + 1 << ": ";
            cin >> votes[c][p];
        }
    }
}

void totalVotesPerCandidate(int votes[4][6], int totals[4]) {
    for (int c = 0; c < 4; c++) {
        int sum = 0;
        for (int p = 0; p < 6; p++)
            sum += votes[c][p];
        totals[c] = sum;
    }
}

void totalVotesPerStation(int votes[4][6], int totals[6]) {
    for (int p = 0; p < 6; p++) {
        int sum = 0;
        for (int c = 0; c < 4; c++)
            sum += votes[c][p];
        totals[p] = sum;
    }
}

void findWinner(int totals[4]) {
    int maxVotes = totals[0];
    for (int i = 1; i < 4; i++) {
        if (totals[i] > maxVotes)
            maxVotes = totals[i];
    }
    cout << "\nWinner(s): ";
    for (int i = 0; i < 4; i++) {
        if (totals[i] == maxVotes)
            cout << "Candidate " << i + 1 << " ";
    }
    cout << "with " << maxVotes << " votes.\n";
}

void checkLowTurnout(int totals[6]) {
    cout << "\nPolling stations with voter turnout less than 100:\n";
    bool found = false;
    for (int i = 0; i < 6; i++) {
        if (totals[i] < 100) {
            cout << "Polling Station " << i + 1 << " (Turnout: " << totals[i] << ")\n";
            found = true;
        }
    }
    if (!found)
        cout << "None.\n";
}

int main() {
    int votes[4][6], candidateTotals[4], stationTotals[6];

    inputVotes(votes);
    totalVotesPerCandidate(votes, candidateTotals);
    totalVotesPerStation(votes, stationTotals);

    cout << "\nTotal votes per candidate:\n";
    for (int i = 0; i < 4; i++)
        cout << "Candidate " << i + 1 << ": " << candidateTotals[i] << endl;

    cout << "\nTotal votes per polling station:\n";
    for (int i = 0; i < 6; i++)
        cout << "Polling Station " << i + 1 << ": " << stationTotals[i] << endl;

    findWinner(candidateTotals);
    checkLowTurnout(stationTotals);

    return 0;
}
