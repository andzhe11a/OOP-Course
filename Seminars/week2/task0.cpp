#include <iostream>

struct Item
{
  double price;
  int quantity;
};

void inputItems(Item items[], int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << "Enter the price of item " << i + 1 << ": ";
    std::cin >> items[i].price;

    std::cout << "Enter the quantity of the item " << i + 1 << ": ";
    std::cin >> items[i].quantity;
  }
}

double calculateSum(const Item items[], int size)
{
  double sum = 0;
  for (int i = 0; i < size; i++)
  {
    double itemPrice = items[i].price * items[i].quantity;
    sum += itemPrice;
  }

  return sum;
}

int findQuantity(const Item items[], int size)
{
  double highestPrice = 0;
  int quantity = 0;

  for (int i = 0; i < size; i++)
  {
    if (items[i].price > highestPrice)
    {
      highestPrice = items[i].price;
      quantity = items[i].quantity;
    }
  }

  return quantity;
}

int main() {
  int size;

  std::cout << "Enter the number of items: ";
  std::cin >> size;
  std::cout << std::endl;

  Item* items = new Item[size];

  inputItems(items, size);

  double sum = calculateSum(items, size);
  int quantity = findQuantity(items, size);

  std::cout << "\nSum of all items: " << sum << std::endl;
  std::cout << "Quantity of the most expensive item: " << quantity << std::endl;

  delete[] items;

  return 0;
}
