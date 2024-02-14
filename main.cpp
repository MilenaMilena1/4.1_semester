#include "iostream"
#include "dispenserType.h"
#include "cashRegister.h"
using namespace std;

void showSelection() {
    cout << "Выберите продукт: " << endl;
    cout << "1. Конфеты" << endl;
    cout << "2. Чипсы" << endl;
    cout << "3. Жвачка" << endl;
    cout << "4. Печенье" << endl;
}

void sellProduct(dispenserType& dispenser, cashRegister& cashReg) {
    int choice;
    cout << "Введите номер продукта: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Стоимость конфет: " << dispenser.getCost() << " рублей" << endl;
            break;
        case 2:
            cout << "Стоимость чипсов: " << dispenser.getCost() << " рублей" << endl;
            break;
        case 3:
            cout << "Стоимость жвачки: " << dispenser.getCost() << " рублей" << endl;
            break;
        case 4:
            cout << "Стоимость печенья: " << dispenser.getCost() << " рублей" << endl;
            break;
        default:
            cout << "Некорректный выбор" << endl;
            return;
    }

    int amount;
    cout << "Введите сумму: ";
    cin >> amount;

    if (amount >= dispenser.getCost()) {
        dispenser.makeSale();
        cashReg.acceptAmount(dispenser.getCost());
        cout << "Спасибо за покупку! Возьмите свой товар." << endl;
    } else {
        cout << "Внесенная сумма недостаточна. Пожалуйста, внесите большую сумму." << endl;
    }
}

int main() {
    dispenserType candyDispenser;
    cashRegister cashRegister;

    showSelection();
    sellProduct(candyDispenser, cashRegister);

    return 0;
}