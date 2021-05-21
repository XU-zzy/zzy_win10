/*System.cpp ���ļ�ΪSystem���ʵ��*/
#include"System.h"

int System::underst_count = 0;
int System::ad_count = 0;

//��½����
void System::load_interface()
{
	int i;
	do
	{
		system("cls");
		load_ad();
		load_undst();
		cout << "********************" << endl;
		cout << "1)��ͨ����Ա�˻�!" << endl;
		cout << "2)����Ա��ݵ�½!" << endl;
		cout << "3)��������ݵ�½!" << endl;
		cout << "4)�˳�ϵͳ!" << endl;
		cout << "********************" << endl;
		cout << "���������:";
		cin >> i;
		while (i < 1 || i>4)
		{
			cout << "��������ȷ�����!" << endl;
			cout << "����������:";
			cin >> i;
		}
		switch (i)
		{
		case 1:
			set_ad_account();
			break;
		case 2:
			enter_ad_account();
			break;
		case 3:
			enter_underst_account();
			break;
		case 4:
			exit_system();
			break;
		default:
			break;
		}
		//cin.get();
	} while (true);
}

//�˳�ϵͳ
void System::exit_system()
{
	cout << "****************��лʹ��!******************" << endl;
	exit(0);
}


//���������ܽ���
void System::understudent_functionshow()
{
	cout << "***************************" << endl;
	cout << "1)�鿴������Ϣ" << endl;
	cout << "2)�޸�����" << endl;
	cout << "3)������һ���˵�!" << endl;
	cout << "*****************************" << endl;
	cout << "��ѡ����Ҫ���еĲ���:";
}


//����Ա���ܽ���
void System::administer_functionshow()
{
	cout << "***************************" << endl;	
	cout << "1)�鿴����ѧ����Ϣ!" << endl;
	cout << "2)����������ѧ����Ϣ!" << endl;
	cout << "3)��ѧ�Ų���ѧ����Ϣ!" << endl;
	cout << "4)¼��ѧ����Ϣ" << endl;
	cout << "5)��ѧ��ɾ��ѧ����Ϣ" << endl;
	cout << "6)������һ���˵�!" << endl;
	cout << "*****************************" << endl;
	cout << "��ѡ����Ҫ���еĲ���:";
}


//���ù���Ա�˻�
void System::set_ad_account()
{
	string name;
	string id;
	string password;
	string password2;
	cout << endl<<"����������:";
	cin >> name;
	cout << endl << "������ID:";
	cin >> id;
	cout << endl << "����������:";
	cin >> password;
	cout << endl << "���ٴ���������:";
	cin >> password2;
	while (password != password2)
	{
		cout << "�������벻һ�£����ٴ�ȷ��:";
		cin >> password2;
	}
	Administer adm(name, id, password);
	ad.push_back(adm);
	cout << "�����ɹ�!" << endl;
	cin.get();
	ad_count++;
	save_ad();
}


//����Ա��ݵ�½
void System::enter_ad_account()
{
	string udst_name;	//Ҫ��ѯ��ѧ��������
	string udst_id;		//Ҫ��ѯѧ����ID
	string id;
	string passw;
	list<Administer>::iterator iter;
	cout << "�������˻�:";
	cin >> id;
	int flag = 1;
	for (iter = ad.begin(); iter != ad.end(); iter++)
	{
		if (id == iter->get_id())
		{
			flag = 0;
			break;
		}	
	}
	if (flag)
	{
		cout << endl<<"�˻�������!" << endl;
		return;
	}
	cout << endl << "����������:";
	cin >> passw;
	while (passw != iter->get_password())
	{
		cout << endl<<"�����������������:";
		cin >> passw;
	}
	cin.get();
	int n;
	do 
	{
		system("cls");
		administer_functionshow();
		cin >> n;
		while (n < 1 || n>6)
		{
			cout << "��������ȷ��ѡ��:";
			cin >> n;
		}
		switch (n)
		{
		case 1:
			look_all_underst();
			break;
		case 2:
			cout << "������Ҫ��ѯѧ��������:";
			cin >> udst_name;
			look_underst_by_name(udst_name);
			break;
		case 3:
			cout << "������Ҫ��ѯѧ����ID:";
			cin >> udst_id;
			look_underst_by_id(udst_id);
			break;
		case 4:
			input_underst_info();
			break;
		case 5:
			cout << "������Ҫɾ��ѧ����ID:";
			cin >> udst_id;
			delete_underst_by_id(udst_id);
			break;
		case 6:
			return;
			break;
		default:
			break;
		}
	} while (1);
}

//��������ݵ�½
void System::enter_underst_account()
{
	list<Understudent>::iterator iter;
	string id;
	string passw;
	cout << "�������˻�:";
	cin >> id;
	int flag = 1;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (id == iter->get_id())
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << endl << "�˻�������!" << endl;
		return;
	}
	cout << endl << "����������:";
	cin >> passw;
	while (passw != iter->get_password())
	{
		cout << endl << "�����������������:";
		cin >> passw;
	}
	int n;
	do
	{
		system("cls");
		understudent_functionshow();
		cin >> n;
		while (n < 1 || n>3)
		{
			cout << endl << "��������ȷ�Ĳ���:";
			cin >> n;
		}
		system("cls");
		switch (n)
		{
		case 1:
			iter->display();
			break;
		case 2:

			change_password(id);
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
		system("pause");

	} while (true);
}

//�������Ա����
void System::save_ad()
{
	ofstream outfile("administer.dat",ios::out);
	list<Administer>::iterator iter;
	outfile << ad_count << endl;
	for (iter = ad.begin(); iter != ad.end(); iter++)
	{
		outfile << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_password() << endl;
	}
	outfile.close();
}

//���汾��������
void System::save_undst()
{
	ofstream outfile("understudent.dat",ios::out);
	list<Understudent>::iterator iter;
	outfile << underst_count << endl;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		outfile << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_password() << "\t" << iter->get_grade() << "\t"
			<< iter->get_sex() << endl;
	}
	outfile.close();
}

//��ȡ����������
void System::load_undst()
{
	ifstream infile("understudent.dat");
	if (!infile)
	{
		cout << "�ޱ��������ϣ�" << endl;
		return;
	}
	string name;
	string ID;
	string password;
	float grade;
	string sex;
	infile >> underst_count;//��ȡ������������
	infile.get();
	if (!underst.empty())
		underst.clear();
	while (!infile.eof() && infile.peek() != EOF)
	{
		infile >> name >> ID >> password >> grade >> sex;
		Understudent undst(name, ID, password, grade, sex);
		underst.push_back(undst);
		infile.get();
	}
	infile.close();
	cout << "��ȡ����������������" << endl;
	
}

//��ȡ����Ա����
void System::load_ad()
{
	ifstream infile("administer.dat");
	if (!infile)
	{
		cout << "�޹���Ա����!" << endl;
		return;
	}
	string name;
	string ID;
	string password;
	infile >> ad_count;//��ȡ����Ա������
	infile.get();
	if (!ad.empty())
		ad.clear();
	while (!infile.eof()||infile.peek()!=EOF)
	{
		infile >> name >> ID >> password;
		Administer adm(name, ID, password);
		ad.push_back(adm);
		infile.get();
	}
	infile.close();
	cout << "��ȡ����Ա����������" << endl;
}

/*
����ԱȨ�ޣ�
*/

//1)�鿴���б�������Ϣ
void System::look_all_underst()
{
	system("cls");
	if (underst.empty())
	{
		cout << "�ޱ���������!" << endl;
		system("pause");
		return;
	}
	list<Understudent>::iterator iter;
	cout << "����" << "\t" << "ID" << "\t" << "\t" <<"�Ա�"  << "\t" << "����" << endl;
	for (iter = underst.begin(); iter != underst.end(); iter++)
		cout << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_sex() << "\t" << iter->get_grade() << endl;
	cout << endl << "ѧ��������:" << underst_count << endl;
	system("pause");
}

//2)�������鿴����������
void System::look_underst_by_name(string udst_name)
{
	system("cls");
	if (underst.empty())
	{
		cout << "�ޱ���������!" << endl;
		system("pause");
		return;
	}
	list<Understudent>::iterator iter;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (iter->get_name() == udst_name)
		{
			cout << "����" << "\t" << "ID" << "\t" << "\t" << "�Ա�" << "\t" << "����" << endl;
			cout << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_sex() << "\t" << iter->get_grade() << endl;
			//���������ظ�����˱�������
		}
		if (iter == --underst.end())
		{
			system("pause");
			return;
		}
	}	
	cout << "�޸�������!" << endl;
	system("pause");
	return;
}

//3����ID�鿴����������
void System::look_underst_by_id(string udst_id)
{
	system("cls");
	if (underst.empty())
	{
		cout << "�ޱ���������!" << endl;
		system("pause");
		return;
	}
	list<Understudent>::iterator iter;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (iter->get_id()==udst_id)
		{
			cout << "����" << "\t" << "ID" << "\t" << "\t" << "�Ա�" << "\t" << "����" << endl;
			cout << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_sex() << "\t" << iter->get_grade() << endl;
			system("pause");
			return;	//ID�������ظ�
		}
	}
	cout << "�޸�������!" << endl;
	system("pause");
	return;
}

//4)¼�뱾������Ϣ
void System::input_underst_info()
{

	string name;
	string ID;
	string password;
	float grade;
	string sex;
	char s;	//�Ƿ����¼��flag
	do
	{
		system("cls");
		cout << endl << "������ѧ������:";
		cin >> name;
		cout << endl << "������ѧ��ID:";
		cin >> ID;
		cout << endl << "������ѧ����ʼ����:";
		cin >> password;
		cout << endl << "������ѧ������:";
		cin >> grade;
		cout <<endl<< "������ѧ���Ա�:";
		cin >> sex;
		Understudent undst(name, ID, password, grade, sex);
		underst.push_back(undst);
		underst_count++;
		cout << endl << "�Ƿ����¼��?(Y/N)";
		cin >> s;
		while (s != 'Y'&&s != 'N'&&s != 'y'&&s != 'n')
		{
			cout << endl << "��������ȷ����(Y/N):";
			cin >> s;
		}
	} while (s == 'Y'||s=='y');
	save_undst();
}

//5)��IDɾ��ѧ����Ϣ
void System::delete_underst_by_id(string udst_id)
{
	system("cls");
	if (underst.empty())
	{
		cout << "�ޱ���������!" << endl;
		system("pause");
		return;
	}
	list<Understudent>::iterator iter;
	string name;
	string ID;
	string password;
	float grade;
	string sex;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (iter->get_id() == udst_id)
		{
			name = iter->get_name(); 
			ID = iter->get_id(); 
			password = iter->get_password();
			grade = iter->get_grade(); 
			sex = iter->get_sex();
			Understudent undst(name, ID, password, grade, sex);
			underst.remove(undst);
			underst_count--;
			cout << "ɾ���ɹ�!" << endl;
			system("pause");
			save_undst();
			return;	//ID�������ظ�
		}
	}
	cout << "�޸�������!" << endl;
	system("pause");
	return;
}


/*
������Ȩ��
*/
//2)�޸�����
void System::change_password(string id)
{
	string password, passw;
	cout << "������������:";
	cin >> password;
	cout <<endl<<"���ٴ�����:";
	cin >> passw;
	while (password != passw)
	{
		cout << endl<<"�������벻һ�£�����������:";
		cin >> passw;
	}
	list<Understudent>::iterator iter;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (iter->get_id() == id)
			break;
	}
	iter->set_password(password);
	cout << "�޸�����ɹ�!" << endl;
	save_undst();
}

