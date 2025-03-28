#include <iostream>

const char* Suits[] = { "Hearts", "Spades", "Diamonds", "Clubs" };
enum class Suit
{
  Hearts,
  Spades,
  Diamonds,
  Clubs
};

const char* Ranks[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
enum class Rank
{
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace
};

int main()
{
  Rank rank;
  Suit suit;

  int input;

  std::cout << "Enter rank (1-13): ";
  std::cin >> input;
  rank = (Rank)(input - 1);

  std::cout << "Enter suit (1-4): ";
  std::cin >> input;
  suit = (Suit)(input - 1);

  std::cout << Ranks[(int)rank] << " of " << Suits[(int)suit] << std::endl;

  return 0;
}
