#include <iostream>
#include <iomanip>  
using namespace std;

int main() {
    const int numCandidates = 5;
    string candidates[numCandidates];
    int votes[numCandidates];
    int totalVotes = 0;
    int winnerIndex = 0;

    for (int i = 0; i < numCandidates; i++) {
        cout << "Enter the last name of candidate " << i + 1 << ": ";
        cin >> candidates[i];
        cout << "Enter the number of votes received by " << candidates[i] << ": ";
        cin >> votes[i];
        totalVotes += votes[i];
    }

    cout << "\nCandidate" << setw(15) << "Votes Received" << setw(15) << "Percentage\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < numCandidates; i++) {
        double percentage = static_cast<double>(votes[i]) / totalVotes * 100;
        cout << left << setw(10) << candidates[i]
             << setw(15) << votes[i]
             << fixed << setprecision(2) << percentage << "%\n";

        if (votes[i] > votes[winnerIndex]) {
            winnerIndex = i;
        }
    }

    cout << "\nThe winner of the election is " << candidates[winnerIndex] << " with " 
         << votes[winnerIndex] << " votes.\n";

    return 0;
}