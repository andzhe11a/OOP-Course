#include "Game.h"
#include <fstream>

class GamePlatform {
    Game games[64];
    int gameCount = 0;

public:
    void addGame(const Game& game) {
        if (gameCount < 64) {
            games[gameCount++] = game;
        }
    }

    void printGame(int index) const {
        if (index >= 0 && index < gameCount) {
            std::cout << index << '\n';
            games[index].print();
        }
    }

    void printAllGames() const {
        for (int i = 0; i < gameCount; ++i) {
            std::cout << i << ". ";
            games[i].print();
        }
    }

    void printFreeGames() const {
        for (int i = 0; i < gameCount; ++i) {
            if (games[i].isFree()) {
                games[i].print();
            }
        }
    }

    Game getMostExpensiveGame() const {
        Game maxGame = games[0];
        for (int i = 1; i < gameCount; ++i) {
            if (games[i].getPrice() > maxGame.getPrice()) {
                maxGame = games[i];
            }
        }
        return maxGame;
    }

    Game getCheapestGame() const {
        Game minGame = games[0];
        for (int i = 1; i < gameCount; ++i) {
            if (games[i].getPrice() < minGame.getPrice()) {
                minGame = games[i];
            }
        }
        return minGame;
    }

    void removeGame(int index) {
        if (index >= 0 && index < gameCount) {
            for (int i = index; i < gameCount - 1; ++i) {
                games[i] = games[i + 1];
            }
            --gameCount;
        }
    }

    void saveToTextFile(const char* filename) const {
        std::ofstream outFile(filename);
        if (!outFile) return;

        outFile << gameCount << "\n";
        for (int i = 0; i < gameCount; ++i) {
            outFile << games[i].getTitle() << "\n"
                    << games[i].getPrice() << "\n"
                    << games[i].getAvailability() << "\n";
        }
        outFile.close();
    }

    void loadFromTextFile(const char* filename) {
        std::ifstream inFile(filename);
        if (!inFile) return;

        inFile >> gameCount;
        inFile.ignore(); // skip newline
        for (int i = 0; i < gameCount; ++i) {
            char title[65];
            float price;
            int avail;

            inFile.getline(title, 65);
            inFile >> price >> avail;
            inFile.ignore(); // skip newline

            games[i] = Game(title, price, avail);
        }
        inFile.close();
    }

    void saveToBinaryFile(const char* filename) const {
        std::ofstream outFile(filename, std::ios::binary);
        if (!outFile) return;

        outFile.write((const char*)&gameCount, sizeof(gameCount));
        outFile.write((const char*)games, sizeof(Game) * gameCount);
        outFile.close();
    }

    void loadFromBinaryFile(const char* filename) {
        std::ifstream inFile(filename, std::ios::binary);
        if (!inFile) return;

        inFile.read((char*)&gameCount, sizeof(gameCount));
        inFile.read((char*)games, sizeof(Game) * gameCount);
        inFile.close();
    }
};