#include "Constant.h"
#include "Sum.h"
#include "Prod.h"
#include "Max.h"
#include "Average.h"

int main() {
    MathExpression<int>* c1 = new Constant<int>(3);
    MathExpression<int>* c2 = new Constant<int>(7);
    MathExpression<int>* c3 = new Constant<int>(10);

    Max<int> maxExpr;
    maxExpr.add(new Constant<int>(2));
    maxExpr.add(new Constant<int>(8));
    maxExpr.add(new Constant<int>(6));
    std::cout << "Max: ";
    maxExpr.print();
    std::cout << " = " << maxExpr.value() << std::endl;

    Average<int> avgExpr;
    avgExpr.add(new Constant<int>(5));
    avgExpr.add(new Constant<int>(15));
    avgExpr.add(new Constant<int>(25));
    std::cout << "Average: ";
    avgExpr.print();
    std::cout << " = " << avgExpr.value() << std::endl;

    MathExpression<int>* sum = new Sum<int>(c1, c2);
    std::cout << "Sum: ";
    sum->print();
    std::cout << " = " << sum->value() << std::endl;

    MathExpression<int>* prod = new Prod<int>(c1, c3);
    std::cout << "Prod: ";
    prod->print();
    std::cout << " = " << prod->value() << std::endl;

    delete prod;
    delete sum;
    delete c1;
    delete c2;
    delete c3;

    return 0;
}
