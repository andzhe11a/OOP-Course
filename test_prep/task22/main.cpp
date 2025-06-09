#include <iostream>
#include "Constant.h"
#include "Sum.h"
#include "Prod.h"
#include "Max.h"
#include "Average.h"

int main() {
    using std::cout;
    using std::endl;

    MathExpression<int>* c1 = new Constant<int>(3);
    MathExpression<int>* c2 = new Constant<int>(7);
    MathExpression<int>* c3 = new Constant<int>(10);

    MathExpression<int>* sum = new Sum<int>(c1, c2);
    cout << "Sum: ";
    sum->print();
    cout << " = " << sum->value() << endl;

    MathExpression<int>* prod = new Prod<int>(sum, c3);
    cout << "Prod: ";
    prod->print();
    cout << " = " << prod->value() << endl;

    Max<int> maxExpr;
    maxExpr.add(new Constant<int>(2));
    maxExpr.add(new Constant<int>(8));
    maxExpr.add(new Constant<int>(6));
    cout << "Max: ";
    maxExpr.print();
    cout << " = " << maxExpr.value() << endl;

    Average<int> avgExpr;
    avgExpr.add(new Constant<int>(5));
    avgExpr.add(new Constant<int>(15));
    avgExpr.add(new Constant<int>(25));
    cout << "Average: ";
    avgExpr.print();
    cout << " = " << avgExpr.value() << endl;

    delete prod;
    delete sum;
    delete c3;

    return 0;
}
