#include<iostream>
using namespace std;
class Base {
public:
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
};

typedef void(*Fun)(void);

int main()
{
	Base b;
	Fun pFun = NULL;
	cout << "虚函数表的地址为:" << (int*)(&b) << endl;
	cout << "虚函数表的第一个函数地址为:" << (int*)*(int*)(&b) << endl;

	pFun = (Fun)*((int*)*(int*)(&b));
	pFun();
	system("pause");
	return 0;
}