#include <iostream>

void fillArray(int* arr, int size)
{
  std::cout << "Enter the elements of the array: ";
  for (int i = 0; i < size; i++)
  {
    std::cin >> arr[i];
  }
}

void printArray(int* arr, int size)
{
  std::cout << "[ ";
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << " ]" << std::endl;
}

void filter(int* arr, int size, int*& result, int*& resultArr, int& resultSize, bool (*predicate)(int))
{
  for (int i = 0; i < size; i++)
  {
    if (predicate(arr[i]))
    {
      resultSize++;
    }
  }

  result = new int[resultSize];

  int index = 0;
  for (int i = 0; i < size; i++)
  {
    if (predicate(arr[i]))
    {
      result[index] = arr[i];
      index++;
    }
  }
}

bool isEven(int num)
{
  return num % 2 == 0;
}

int main()
{
  int size;
  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  int* arr = new int[size];  // Use dynamic allocation for flexibility

  fillArray(arr, size);

  int* resultArr = nullptr;
  int resultSize = 0;

  filter(arr, size, resultArr, resultSize, isEven);

  std::cout << "Filtered array (only even numbers): ";
  printArray(resultArr, resultSize);

  delete[] arr;
  delete[] resultArr;

  return 0;
}
