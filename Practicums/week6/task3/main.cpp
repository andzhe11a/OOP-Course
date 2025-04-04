#include "GamePlatform.h"

int main() {
    GamePlatform platform;

    platform.addGame(Game("CS:GO", 0, true));
    platform.addGame(Game("League Of Legends", 59.99, true));
    platform.addGame(Game("Minecraft", 14.99, true));

    std::cout << "All games:\n";
    platform.printAllGames();

    std::cout << "\nFree games:\n";
    platform.printFreeGames();

    std::cout << "\nMost expensive game:\n";
    platform.getMostExpensiveGame().print();

    std::cout << "\nCheapest game:\n";
    platform.getCheapestGame().print();

    platform.saveToBinaryFile("games.dat");

    GamePlatform platform2;
    platform2.loadFromBinaryFile("games.dat");

    std::cout << "\nLoaded games from binary:\n";
    platform2.printAllGames();

    return 0;
}