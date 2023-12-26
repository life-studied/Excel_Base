#include <iostream>
#include "Excel_Base.h"
using Excel::Excel_Base;
using std::vector;
class A : public Excel_Base<A>
{
public:
    A() : Excel_Base("test-data.xlsx") {};
    A(int _a, double _b) : Excel_Base("test-data.xlsx"), a(_a), b(_b) {}
    auto getExcelData()
    {
        return read_from_excel(a, b);
    }

public:
    void print_title() { std::cout << titles[0] << " " << titles[1] << std::endl; }
    void print()
    {
        std::cout << a << ' ' << b << std::endl;
    }
private:
    int a;
    double b;
};

int main()
{
    A a;
    auto res = a.getExcelData();
    a.print_title();
    for (auto& i : res)
    {
        i.print();
    }
    std::cout << "Hello World!\n";
}