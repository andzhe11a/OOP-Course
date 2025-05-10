#include <iostream>
#include <cstring>

const int MAX_TEAMS = 10;

struct Engineer {
    char name[64];
    char position[64];
    int salary;

    void read() {
        std::cout << "Name: ";
        std::cin.getline(name, 64);
        std::cout << "Position: ";
        std::cin.getline(position, 64);
        std::cout << "Salary: ";
        std::cin >> salary;
        std::cin.ignore();
    }
};

struct Team {
    Engineer player1;
    Engineer player2;
    int totalPoints;

    void read() {
        std::cout << "Enter player 1:\n";
        player1.read();
        std::cout << "Enter player 2:\n";
        player2.read();
        totalPoints = 0;
    }

    void resetPoints() {
        totalPoints = 0;
    }

    bool isValid() const {
        return player1.salary > 0 && player2.salary > 0;
    }

    int donateFromLosers() const {
        return (player1.salary + player2.salary) * 2 / 100;
    }

    int bonusToWinners() const {
        return (player1.salary + player2.salary) * 1 / 100;
    }

    void printNames() const {
        std::cout << player1.name << " & " << player2.name;
    }
};

class BelotTournament {
    Team teams[MAX_TEAMS];
    int teamCount;

public:
    BelotTournament() : teamCount(0) {}

    void addTeam(const Team& t) {
        if (teamCount < MAX_TEAMS)
            teams[teamCount++] = t;
    }

    void startTournament() {
        if (teamCount <= 2 || teamCount % 2 != 0) {
            std::cout << "Invalid team count. Removing last team because it is odd.\n";
            if (teamCount % 2 != 0)
                teamCount--;
        }

        int donationPool = 0;
        int currentSize = teamCount;

        while (currentSize > 1) {
            int winnersCount = 0;
            Team nextRound[MAX_TEAMS];

            for (int i = 0; i < currentSize; i += 2) {
                Team& t1 = teams[i];
                Team& t2 = teams[i + 1];

                std::cout << "\nMatch: ";
                t1.printNames();
                std::cout << " vs ";
                t2.printNames();
                std::cout << "\n";

                int score1 = 0, score2 = 0;
                int round = 1;

                while (score1 < 2 && score2 < 2 && round <= 3) {
                    std::cout << "Round " << round << ":\n";
                    t1.resetPoints();
                    t2.resetPoints();

                    while (t1.totalPoints < 151 && t2.totalPoints < 151) {
                        int p1, p2;
                        std::cout << "Points for team 1: ";
                        std::cin >> p1;
                        std::cout << "Points for team 2: ";
                        std::cin >> p2;
                        t1.totalPoints += p1;
                        t2.totalPoints += p2;
                    }

                    if (t1.totalPoints >= 151)
                        ++score1;
                    else
                        ++score2;

                    ++round;
                }

                if (score1 == 2) {
                    nextRound[winnersCount++] = t1;
                    donationPool += t2.donateFromLosers();
                    donationPool -= t1.bonusToWinners();
                } else {
                    nextRound[winnersCount++] = t2;
                    donationPool += t1.donateFromLosers();
                    donationPool -= t2.bonusToWinners();
                }

                std::cin.ignore();
            }

            for (int i = 0; i < winnersCount; ++i)
                teams[i] = nextRound[i];

            currentSize = winnersCount;
        }

        std::cout << "\nWinner: ";
        teams[0].printNames();
        std::cout << "\nTotal donation: " << donationPool << " BGN\n";
    }
};

int main() {
    BelotTournament tournament;

    int teamNum;
    std::cout << "Enter number of teams (even, >2, max 10): ";
    std::cin >> teamNum;
    std::cin.ignore();

    if (teamNum > MAX_TEAMS)
        teamNum = MAX_TEAMS;

    for (int i = 0; i < teamNum; ++i) {
        std::cout << "\nTeam " << i + 1 << ":\n";
        Team t;
        t.read();
        tournament.addTeam(t);
    }

    tournament.startTournament();
    return 0;
}