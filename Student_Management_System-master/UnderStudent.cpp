/*UnderStudent.cpp ���ļ�ΪUnderStudent���ʵ��*/
#include"UnderStudent.h"
Understudent::Understudent(string na, string id, string passw, float gra, string s):name(na),ID(id),password(passw),grade(gra), sex(s)
{}
void Understudent::display()
{
	cout << "******************"<< endl;
	cout << "* ����:" << name   << endl;
	cout << "* ѧ��:" << ID     <<endl ;
	cout << "* �Ա�:"  << sex   <<endl ;
	cout << "* ����:"  << grade << endl;
	cout << "******************"<< endl;
}
