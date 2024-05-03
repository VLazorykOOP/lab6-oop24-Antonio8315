// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>

// Ваші файли загловки 
//
class Base
{
protected:
    int dat;
    // double A[5] = { 1,1,1,1,1 };
public:
    Base() : dat(1) {}
    Base(int d) : dat(d) {}
};

//успадкування з елементами даних класів
class D1 : protected Base
{
protected:
    int d1;
public:
    D1() : d1(1) {}
    D1(int d) : d1(d) {}
    D1(int d, int dt) : Base(dt), d1(d) {}
};
class D2 : protected Base
{
protected:
    double d2;
public:
    D2() : d2(1) {}
    D2(int d) : d2(d) {}
    D2(int d, double dt) : Base(d), d2(dt) {}
};
class E1 : protected D1
{
protected:
    double e1;
public:
    E1() : e1(1) {}
    E1(int e) : e1(e) {}
    E1(int e, int dt, int et) : D1(e, dt), e1(et) {}
};
class E2 : protected D2
{
protected:
    double e2;
public:
    E2() : e2(1) {}
    E2(int e) : e2(e) {}
    E2(int e, double dt, double et) : D2(et, dt), e2(e) {}
};
class R : protected E1, protected E2, protected Base
{
protected:
    double dt;
public:
    R() : dt(1) {}
    R(int d) : dt(d) {}
    R(int a, int b, int c, double d, double e, int f) : E1(a, b, c), E2(d, e, f), Base::Base(a), dt(f + 1.) {}
    void showDat()
    {   
        //попередження про помилку, що не впливає на компіляцію коду
        std::cout << "dat =? Error C2385 ambiguous access level dat " << std::endl;

        /// << dat << std::endl;
        std::cout << "E1VV::D1V::Base::dat = " << E1::D1::Base::dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "E2VV::D2V::Base::dat = " << E2::D2::Base::dat << std::endl;
    }
};







//віртуальне успадкування з елементами даних класів
class D1V : virtual protected Base
{
protected:
    int d1;
public:
    D1V() : d1(1) {}
    D1V(int d) : d1(d) {}
    D1V(int d, int dt) : Base(dt), d1(d) {}
};
class D2V : virtual protected Base
{
protected:
    double d2;
public:
    D2V() : d2(1) {}
    D2V(int d) : d2(d) {}
    D2V(int d, double dt) : Base(d), d2(dt) {}
};
class E1V : virtual protected D1V
{
protected:
    double e1;
public:
    E1V() : e1(1) {}
    E1V(int e) : e1(e) {}
    E1V(int e, int dt, int et) : D1V(e, dt), e1(et) {}
};
class E2V : virtual protected D2V
{
protected:
    double e2;
public:
    E2V() : e2(1) {}
    E2V(int e) : e2(e) {}
    E2V(int e, double dt, double et) : D2V(et, dt), e2(e) {}
};
class RV : virtual protected E1V, virtual public E2V, public Base
{
protected:
    double dt;
public:
    RV() : dt(1) {}
    RV(int d) : dt(d) {}
    RV(int a, int b, int c, double d, double e, int f) : E1V(a, b, c), E2V(d, e, f), Base::Base(a + 1), dt(f + 1.0) {}
    void showDat()
    {
        //попередження про помилку, що не впливає на компіляцію коду
        std::cout << "dat =? Error C2385 ambiguous access level dat " << std::endl;

        /// << dat << std::endl;
        std::cout << "E1VV::D1V::Base::dat = " << E1V::D1V::Base::dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "E2VV::D2V::Base::dat = " << E2V::D2V::Base::dat << std::endl;
    }
};




//абстрактний базовий клас
class Figure {
public:
    //віртуальна функція для обчислення площі
    virtual double area() const = 0;

    //віртуальний деструктор
    virtual ~Figure() {}
};

//клас "Прямокутник", що успадковує "Фігура"
class Rectangle : public Figure {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    //реалізація віртуальної функції для прямокутника
    double area() const override {
        return width * height;
    }
};

//клас "Коло", що успадковує "Фігура"
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    //реалізація віртуальної функції для кола
    double area() const override {
        return 3.14 * radius * radius;
    }
};

//клас "Прямокутний трикутник", що успадковує "Фігура"
class RightTriangle : public Figure {
private:
    double base;
    double height;
public:
    RightTriangle(double b, double h) : base(b), height(h) {}

    //реалізація віртуальної функції для прямокутного трикутника
    double area() const override {
        return 0.5 * base * height;
    }
};

//клас "Трапеція", що успадковує "Фігура"
class Trapezoid : public Figure {
private:
    double base1;
    double base2;
    double height;
public:
    Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}

    //реалізація віртуальної функції для трапеції
    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }
};




class Person {
protected:
    std::string name;
    int age;
public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
protected:
    std::string university;
public:
    Student(const std::string& n, int a, const std::string& uni) : Person(n, a), university(uni) {}

    void display() const override {
        std::cout << "Student - ";
        Person::display();
        std::cout << "University: " << university << std::endl;
    }
};

class FamilyParent : public Person {
protected:
    int numberOfChildren;
public:
    FamilyParent(const std::string& n, int a, int children) : Person(n, a), numberOfChildren(children) {}

    void display() const override {
        std::cout << "Family Parent - ";
        Person::display();
        std::cout << "Number of Children: " << numberOfChildren << std::endl;
    }
};

class StudentFamilyParent : public Student, public FamilyParent {
public:
    StudentFamilyParent(const std::string& n, int a, const std::string& uni, int children)
        : Student(n, a, uni), FamilyParent(n, a, children) {}

    void display() const override {
        std::cout << "Student Family Parent - ";
        Person::display();
        std::cout << "University: " << university << ", Number of Children: " << numberOfChildren << std::endl;
    }
};
int main()
{
    //завдання 1
    std::cout << " Lab #6  !\n";
    R a, b(1, 2, 3, 4.5, 5.5, 6);
    RV av, bv(1, 2, 3, 4.5, 5.5, 6);
    std::cout << "Test !\n";
    std::cout << "Size for Base " << sizeof(Base) << std::endl;
    std::cout << "Size for D1 " << sizeof(D1) << std::endl;
    std::cout << "Size for D2 " << sizeof(D2) << std::endl;
    std::cout << "Size for E1 " << sizeof(E1) << std::endl;
    std::cout << "Size for E2 " << sizeof(E2) << std::endl;
    std::cout << "Size for R " << sizeof(R) << std::endl;
     std::cout << "Size for Base " << sizeof(Base) << std::endl;
     std::cout << "Size for D1V " << sizeof(D1V) << std::endl;
     std::cout << "Size for D2V " << sizeof(D2V) << std::endl;
     std::cout << "Size for E1V " << sizeof(E1V) << std::endl;
     std::cout << "Size for E2V " << sizeof(E2V) << std::endl;
     std::cout << "Size for RV " << sizeof(RV) << std::endl;
    std::cout << "Size for object class R " << sizeof(R) << " or "
        << sizeof(a) << " or " << sizeof(b) << std::endl;
    std::cout << "Size for object class RV " << sizeof(RV) << " or "
        << sizeof(av) << " or " << sizeof(bv) << std::endl;
    b.showDat();
     bv.showDat();
     //  Код виконання завдань
     //  Головне меню завдань
     //  Функції та класи можуть знаходитись в інших файлах проекту

     //завдання 2
     Rectangle rect(5, 10);
     Circle circle(7);
     RightTriangle triangle(3, 4);
     Trapezoid trapezoid(6, 8, 5);
     std::cout << "\n\n\nTask 2\n";
     //виклик функції "area" для кожної фігури
     std::cout << "Area of Rectangle: " << rect.area() << std::endl;
     std::cout << "Area of Circle: " << circle.area() << std::endl;
     std::cout << "Area of Right Triangle: " << triangle.area() << std::endl;
     std::cout << "Area of Trapezoid: " << trapezoid.area() << std::endl;

     //завдання 3
     std::cout << "\n\n\nTask 3\n";
     Student s1("Alice", 20, "University A");
     FamilyParent fp1("Bob", 40, 2);
     StudentFamilyParent sfp1("Charlie", 30, "University B", 1);

     std::cout << "Displaying Student:" << std::endl;
     s1.display();
     std::cout << std::endl;

     std::cout << "Displaying Family Parent:" << std::endl;
     fp1.display();
     std::cout << std::endl;

     std::cout << "Displaying Student Family Parent:" << std::endl;
     sfp1.display();

     return 0;
}