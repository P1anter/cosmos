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
        cout << "재료가 모두 소진되어 음료를 만들 수 없습니다." << endl;
    }

    void drinkEspresso() {
            coffee -= 4;
            water -= 6;
            cout << "에스프레소를 만들었습니다." << endl;
    }

    void drinkAmericano() {
            coffee -= 2;
            water -= 7;
            cout << "아메리카노를 만들었습니다." << endl;
    }

    void drinkSugerCoffee() {
            coffee -= 3;
            water -= 5;
            sugar -= 3;
            cout << "설탕커피를 만들었습니다." << endl;
    }

    void Refill() {
        if (coffee < 10) {
            int coffee_re = max - coffee;
            coffee += coffee_re;
            cout << "커피를 " << coffee_re << " 추가했습니다." << endl;
        }
        if (water < 10) {
            int water_re = max - water;
            water += water_re;
            cout << "물을 " << water_re << " 추가했습니다." << endl;
        }
        if (sugar < 10) {
            int sugar_re = max - sugar;
            sugar += sugar_re;
            cout << "설탕을 " << sugar_re << " 추가했습니다." << endl;
        }

    }

    void show() {
        cout << "커피: " << coffee << ", 물: " << water << ", 설탕: " << sugar << endl;
    }
};

int main() {
    CoffeeMachine java(5, 10, 3);
    int select;

    while (true) {
        cout << "1. 에스프레소 2. 아메리카노 3. 설탕커피 0. 종료" << endl;
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



