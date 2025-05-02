#include <iostream>
#include <fstream>

struct Order {
    double grossPrice;
    double vat;
    int customerID;
};

const char* ordersFile = "storeOrders.bin";
const char* topCustomersFile = "topCustomers.bin";

const int MAX_CUSTOMERS = 1000;

void addNewOrders() {
    std::ofstream out(ordersFile, std::ios::binary | std::ios::app);
    if (!out) {
        std::cerr << "Could not open file for writing.\n";
        return;
    }

    Order o;
    std::cout << "Enter customer ID: ";
    std::cin >> o.customerID;
    std::cout << "Enter gross price: ";
    std::cin >> o.grossPrice;
    std::cout << "Enter VAT: ";
    std::cin >> o.vat;

    out.write(reinterpret_cast<const char*>(&o), sizeof(Order));

    out.close();
}

int findMostOrdersCustomer() {
    std::ifstream in(ordersFile, std::ios::binary);
    if (!in) {
      return -1;
    }

    int mostOrdersCustomerID = -1;
    int maxOrders = 0;
    int currentCustomerID = 0;
    int currentOrderCount = 0;

    Order o;
    while (in.read(reinterpret_cast<char*>(&o), sizeof(Order))) {
        if (o.customerID == currentCustomerID) {
            currentOrderCount++;
        } else {
            if (currentOrderCount > maxOrders) {
                mostOrdersCustomerID = currentCustomerID;
                maxOrders = currentOrderCount;
            }
            currentCustomerID = o.customerID;
            currentOrderCount = 1;
        }
    }

    if (currentOrderCount > maxOrders) {
        mostOrdersCustomerID = currentCustomerID;
    }

    in.close();
    return mostOrdersCustomerID;
}

int findMostExpensiveOrderCustomer() {
    std::ifstream in(ordersFile, std::ios::binary);
    if (!in) {
      return -1;
    }

    int customer = -1;
    double maxTotal = -1;

    Order o;
    while (in.read(reinterpret_cast<char*>(&o), sizeof(Order))) {
        if ((o.grossPrice + o.vat) > maxTotal) {
            maxTotal = o.grossPrice + o.vat;
            customer = o.customerID;
        }
    }

    in.close();
    return customer;
}

int findMostPaidCustomer() {
    std::ifstream in(ordersFile, std::ios::binary);
    if (!in) {
      return -1;
    }

    int customer = -1;
    double maxPaid = -1;

    Order o;
    while (in.read(reinterpret_cast<char*>(&o), sizeof(Order))) {
        double total = o.grossPrice + o.vat;
        if (total > maxPaid) {
            maxPaid = total;
            customer = o.customerID;
        }
    }

    in.close();
    return customer;
}

void writeTopCustomers(int mostOrders, int mostExpensive, int mostPaid) {
    std::ofstream out(topCustomersFile, std::ios::binary);
    if (!out) {
        std::cerr << "Could not open result file.\n";
        return;
    }

    out.write(reinterpret_cast<const char*>(&mostOrders), sizeof(int));
    out.write(reinterpret_cast<const char*>(&mostExpensive), sizeof(int));
    out.write(reinterpret_cast<const char*>(&mostPaid), sizeof(int));

    out.close();
}

int main() {
    addNewOrders();

    int mostOrders = findMostOrdersCustomer();
    int mostExpensive = findMostExpensiveOrderCustomer();
    int mostPaid = findMostPaidCustomer();

    writeTopCustomers(mostOrders, mostExpensive, mostPaid);

    return 0;
}