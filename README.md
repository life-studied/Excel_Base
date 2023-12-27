# Excel_Base

​	xlnt快速读取类

## usage

* 定义构造函数：必须与`read_from_excel`传入的参数列表一致
* `read_from_excel`：传入需要读取的数据成员

```C++
#include <iostream>
#include "Excel_Base.h"
using Excel::Excel_Base;
using std::vector;
class A : public Excel_Base<A>
{
public:
    A() : Excel_Base("test-data.xlsx") {};
    A(std::string s, int _a, double _b) : Excel_Base("test-data.xlsx"), s(s), a(_a), b(_b) {}
    auto getExcelData()
    {
        return read_from_excel(s, a, b);
    }

public:
    void print_title() { std::cout << titles[0] << " " << titles[1] << " " << titles[2] << std::endl; }
    void print()
    {
        std::cout << s << " " << a << ' ' << b << std::endl;
    }
private:
    std::string s;
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
}
```

