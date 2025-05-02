#include <iostream>
#include <fstream>

int main() {
  std::ifstream file("numbers.txt");

  if (!file.is_open())
  {
    std::cout << "Could not open the file! " << std::endl;
    return 1;
  }

  int N;
  file >> N;

  int* numbers = new int[N];

  for (int i = 0; i < N; ++i)
  {
    file >> numbers[i];
  }

  std::cout << "The read numbers are: ";
  for (int i = 0; i < N; ++i)
  {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  delete[] numbers;
  file.close();

  return 0;
}