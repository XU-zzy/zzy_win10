/*System.h ���ļ�ΪSystem��ͷ�ļ�*/
#pragma once
#include<list>
#include<fstream>
#include"UnderStudent.h"
#include"Administer.h"
class System
{
private:
	list<Understudent> underst;
	list<Administer> ad;
	static int underst_count;
	static int ad_count;
public:
	virtual void load_interface();			//��½����
	void exit_system();					    //�˳�ϵͳ
	void understudent_functionshow();		//ѧ���û����ܽ���
	void administer_functionshow();			//����Ա���ܽ���
	void set_ad_account();					//���ù���Ա�˻�
	void enter_ad_account();				//����Ա��ݵ�½
	void enter_underst_account();			//��������ݵ�½
	void save_undst();						//���汾��������
	void save_ad();							//�������Ա����
	void load_undst();						//��ȡ����������
	void load_ad();							//��ȡ����Ա����
	/*����Ա����*/
	void input_underst_info();				//¼�뱾������Ϣ
	void look_all_underst();				//�鿴���б�������Ϣ
	void look_underst_by_name(string name);			//���������鿴��������Ϣ
	void look_underst_by_id(string id);				//����ID�鿴��������Ϣ
	void delete_underst_by_id(string id);			//����IDɾ����������Ϣ
	/*����������*/
	void change_password(string id);			//�޸����� 
};

