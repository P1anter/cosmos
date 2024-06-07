#include <iostream>
using namespace std;

class CoffeeMachine {
private:
    const int max = 100;
    const int min = 0;
public:
    int coffee;
    int water;
    int sugar;

    CoffeeMachine(int c, int w, int s) {
        coffee = c;
        water = w;
        sugar = s;

    };

    void cant() {
        cout << "��ᰡ ��� �����Ǿ� ���Ḧ ���� �� �����ϴ�." << endl;
    }

    void drinkEspresso() {
            coffee -= 4;
            water -= 6;
            cout << "���������Ҹ� ��������ϴ�." << endl;
    }

    void drinkAmericano() {
            coffee -= 2;
            water -= 7;
            cout << "�Ƹ޸�ī�븦 ��������ϴ�." << endl;
    }

    void drinkSugerCoffee() {
            coffee -= 3;
            water -= 5;
            sugar -= 3;
            cout << "����Ŀ�Ǹ� ��������ϴ�." << endl;
    }

    void Refill() {
        if (coffee < 10) {
            int coffee_re = max - coffee;
            coffee += coffee_re;
            cout << "Ŀ�Ǹ� " << coffee_re << " �߰��߽��ϴ�." << endl;
        }
        if (water < 10) {
            int water_re = max - water;
            water += water_re;
            cout << "���� " << water_re << " �߰��߽��ϴ�." << endl;
        }
        if (sugar < 10) {
            int sugar_re = max - sugar;
            sugar += sugar_re;
            cout << "������ " << sugar_re << " �߰��߽��ϴ�." << endl;
        }

    }

    void show() {
        cout << "Ŀ��: " << coffee << ", ��: " << water << ", ����: " << sugar << endl;
    }
};

int main() {
    CoffeeMachine java(5, 10, 3);
    int select;

    while (true) {
        cout << "1. ���������� 2. �Ƹ޸�ī�� 3. ����Ŀ�� 0. ����" << endl;
        cin >> select;

        if (select == 1) {
            
            if (java.coffee < 4 || java.water < 6) {
                java.cant();
                java.Refill();
            }
            else {
                java.drinkEspresso();
                java.show();
            }
        }
        else if (select == 2) {
            
            if (java.coffee < 2 || java.water < 7) {
                java.cant();
                java.Refill();
            }
            else {
                java.drinkAmericano();
                java.show();
            }
        }
        else if (select == 3) {
            
            if (java.coffee < 3 || java.water < 5 || java.sugar < 3) {
                java.cant();
                java.Refill();
            }
            else {
                java.drinkSugerCoffee();
                java.show();
            }
        }
        else if (select == 0) {
            break;
        }
    }
    return 0;
}



