#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0) {
        this->radius = radius;
    }
    int getRadius() {
        return radius;
    }
    void setRadius(int radius) {
        this->radius = radius;
    }
    double getArea() {
        return 3.14 * radius * radius;
    }
};


class NamedCircle : public Circle {
    string name;
public:
    NamedCircle(int radius = 0, string name = "") : Circle(radius) {
        this->name = name;
    }
    void setRN(int radius, string name) {
        setRadius(radius);
        this->name = name;
    }
    string getName() {
        return name;
    }
};

int main() {
    NamedCircle pizza[3];
    int radius;
    string name;

    cout << "3개의 정수 반지름과 원의 이름을 입력하세요" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ">> ";
        cin >> radius >> name;
        pizza[i].setRN(radius, name);
    }

    NamedCircle* largestPizza = &pizza[0];
    for (int i = 1; i < 3; i++) {
        if (pizza[i].getArea() > largestPizza->getArea()) {
            largestPizza = &pizza[i];
        }
    }

    cout << "가장 면적이 큰 피자는 " << largestPizza->getName() << "입니다." << endl;

    return 0;
}
