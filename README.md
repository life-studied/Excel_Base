# Excel_Base

​	xlnt快速读取类

## usage

```C++
#include <iostream>
#include "Excel_Base.h"
using Excel::Excel_Base;
using std::vector;

// 定义你的类
class A : public Excel_Base<A>
{
public:
    // 构造函数输入excel名
    A() : Excel_Base("test-data.xlsx") {};
    
    // 必须指定想要输出的类型的构造
    A(int _a, double _b) : Excel_Base("test-data.xlsx"), a(_a), b(_b) {}
    
    // 通过read_from_excel传入excel中，一行的数据类型
    // 返回类型： vector<A>
    auto getExcelData()
    {
        return read_from_excel(a, b);
    }

public:
    // 测试函数
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
```

