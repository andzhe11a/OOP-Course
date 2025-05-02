#include <iostream>
#include <fstream>

int main() {
  std::ifstream file("numbers.bin", std::ios::binary);

  int currNumber;
  int maxNumber;

  file.read(reinterpret_cast<char*>(&maxNumber), sizeof(int));

  while (file.read(reinterpret_cast<char*>(&currNumber), sizeof(int))) {
    if (currNumber > maxNumber) {
      maxNumber = currNumber;
    }
  }

  std::cout << "Max number: " << maxNumber << std::endl;

  return 0;
}