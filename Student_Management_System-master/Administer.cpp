/*Administer.cpp ���ļ�ΪAdminister���ʵ��*/
#include"Administer.h"
Administer::Administer(string na, string id, string passw) :name(na), ID(id), password(passw)
{}
void Administer::display()
{
	cout << endl << "******************" << endl;
	cout << endl << "* ����:" << name;
	cout << endl << "* �˺�:" << ID;
	cout << endl << "******************" << endl;
}

