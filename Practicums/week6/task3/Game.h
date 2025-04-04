#include <iostream>
#include <cstring>

class Game {
  char title[65];
  float price;
  bool isAvailable;

public:
  Game() {
    strcpy(title, "Untitled");
    this->price = 0.0f;
    this->isAvailable = false;
  }

  Game(const char* title, float price, bool isAvailable) {
    setTitle(title);
    setPrice(price);
    setAvailability(isAvailable);
  }

  void setTitle(const char* newTitle) {
    strncpy(title, newTitle, 64);
    title[64] = '\0';
  }

  void setPrice(float newPrice) {
    if (newPrice >= 0) {
      this->price = newPrice;
    }
  }

  void setAvailability(bool available) {
    this->isAvailable = available;
  }

  const char* getTitle() const {
    return title;
  }

  float getPrice() const {
    return price;
  }

  bool getAvailability() const {
    return isAvailable;
  }

  bool isFree() const {
    return this->price == 0.0f;
  }

  void print() const {
    std::cout << "Title: " << title << "\n";
    std::cout << "Price: " << price << "\n";
    std::cout << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
    std::cout << '\n';
  }
};

