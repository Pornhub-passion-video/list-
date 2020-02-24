#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<string>
//#include<>
using namespace std;

/*
set���캯��
set<T> st;//setĬ�Ϲ��캯����
mulitset<T> mst; //multisetĬ�Ϲ��캯��:
set(const set &st);//�������캯��
3.7.2.2 set��ֵ����
set& operator=(const set &st);//���صȺŲ�����
swap(st);//����������������
3.7.2.3 set��С����
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

3.7.2.4 set�����ɾ������
insert(elem);//�������в���Ԫ�ء�
clear();//�������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�

*/



//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
//������ ����lower_bound   upper_bound

//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//
//	string m_name;
//	int m_age;
//};
//
//void printperson(const set<Person> &L)
//{
//	for (set<Person>::iterator it = L.begin(); it != L.end(); ++it)
//	{
//		cout << it->m_name << it->m_age << endl;
//	}
//}
//
//
//
//void test01()
//{
//
//	set<Person>L;
//	Person p1("��  ��", 45);
//	Person p2("����", 47);
//	Person p3("�ܺ�ΰ", 43);
//	Person p4("�����", 39);
//	Person p5("������", 45);
//	Person p6("������", 45);
//	L.insert(p1);
//
//	L.insert(p2);
//	L.insert(p3);
//	L.insert(p4);
//	L.insert(p5);
//	printperson(L);
//
//}
//
//
//



//void test()
//{
//	set<int> S;
//	S.insert(10);
//	S.insert(50);
//	S.insert(20);
//	S.insert(30);
//	S.insert(40);
//
//
//
//	for (set<int>::iterator it = S.begin(); it != S.end(); ++it)
//	{
//		cout << (*it) << endl;
//	}
//
//	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
//	//�õ���������
//	S.lower_bound(3);
//
//}
//
//ָ��set�������
//�º�������һ����
class myCompare//ָ���������ʱҪ��const
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

void print(set<int, myCompare>& s1)
{
	for (set<int, myCompare>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}




void test02()
{
	set<int, myCompare>s1;

	s1.insert(5);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(6);

	print(s1);

}

class Person
{
public:
	Person(string name, int age) :m_name(name), m_age(age)
	{}

	string m_name;
	int m_age;

};


//�Զ�����������ָ���������ʱ���г�Ա������const��Ա
class compare01
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_age > p2.m_age;
	}
};


void printperson(set<Person, compare01>& s)
{
	for (set<Person, compare01>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "����:" << it->m_name << " ����:" << it->m_age << endl;
	}
}



void test03()
{
	set<Person, compare01> s;

	Person p1("��  ��", 35);
	Person p2("����", 36);
	Person p3("������", 37);
	Person p4("�����", 38);
	Person p5("�ܺ�ΰ", 39);


	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	printperson(s);
}





int main()
{


	//test();
	//test01();
	test02();
	//test03();
	system("pause");
	return EXIT_SUCCESS;
}