#include "solver.h"
#include <iostream>

using namespace std;

int main() {
    double a, b, eps;
    
    cout << "=========================================" << endl;
    cout << "          ПОШУК КОРЕНІВ РІВНЯННЯ         " << endl;
    cout << "=========================================" << endl;
    cout << "Введіть параметри:" << endl;
    cout << "  a   : ";
    cin >> a;
    cout << "  b   : ";
    cin >> b;
    cout << "  eps : ";
    cin >> eps;
    
    Math obj;
    obj.setinterval(a, b);
    obj.setEPS(eps);

    double x1 = obj.dichotomy();
    double x2 = obj.newton();

    cout << "\n=========================================" << endl;
    cout << "               РЕЗУЛЬТАТИ                " << endl;
    cout << "=========================================" << endl;
    
    cout << " [ Метод дихотомії ]" << endl;
    cout << "   Знайдений корінь x : " << x1 << endl;
    cout << "   Значення f(x)      : " << obj.f(x1) << endl;
    
    cout << "-----------------------------------------" << endl;

    cout << " [ Метод Ньютона ]" << endl;
    cout << "   Знайдений корінь x : " << x2 << endl;
    cout << "   Значення f(x)      : " << obj.f(x2) << endl;
    
    cout << "=========================================" << endl;
    
    return 0;
}
