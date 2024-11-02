#include <iostream>
#include <string>

int main() {
    int numCandidates;
    
    // number of candidates
    std::cout << "Enter the number of candidates: ";
    std::cin >> numCandidates;

    std::string *candidates = new std::string[numCandidates];
    int *votes = new int[numCandidates];

    //  names and vote counts
    for (int i = 0; i < numCandidates; ++i) {
        std::cout << "Enter the name of candidate " << (i + 1) << ": ";
        std::cin >> candidates[i];
        
        std::cout << "Enter the number of votes for " << candidates[i] << ": ";
        std::cin >> votes[i];
    }

    // Calculates the winner 
    int totalVotes = 0;
    int maxVotes = votes[0];
    int winnerIndex = 0;
    
    for (int i = 0; i < numCandidates; ++i) {
        totalVotes += votes[i];
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    std::cout << "\nElection Results:\n";
    for (int i = 0; i < numCandidates; ++i) {
        std::cout << candidates[i] << ": " << votes[i] << " votes\n";
    }
    std::cout << "Total votes: " << totalVotes << "\n";
    std::cout << "Winner: " << candidates[winnerIndex] << " with " << maxVotes << " votes.\n";
    
    delete[] candidates;
    delete[] votes;

    return 0;
}