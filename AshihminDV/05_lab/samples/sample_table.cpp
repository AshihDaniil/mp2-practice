//#include "Other.h"
//
//
//int main()
//{
//	mainMenu();
//
//	return 0;
//}

#include "viewable_table.h"
#include "polinom.h"

int main()
{
    VTable<Polinomial, double> polyTable(10);

    Polinomial p1("2x + 3y");
    Polinomial p2("x^2 + 5");

    TabNode<Polinomial, double> tn1(p1, 10.5);
    TabNode<Polinomial, double> tn1(p2, 20.3);

    // Добавление элементов
    polyTable.Insert(tn1);
    polyTable.Insert(tn2);

    // Вывод таблицы
    polyTable.Print();

    // Поиск элемента
    double* val = polyTable.Find(p1);
    if (val) {
        std::cout << "Found value: " << *val << std::endl;
    }

    // Итерация по таблице
    polyTable.Reset();
    while (!polyTable.IsEnd()) {
        auto node = polyTable.GetCurr();
        std::cout << "Current: " << node->key << " -> " << node->data << std::endl;
        polyTable.Next();
    }

    return 0;
}