#include<iostream>
#include<set>
using namespace std;
//�º���
class myCompare
{
public:
	bool operator()(int v1,int v2) const
	{
		return v1 > v2;
	}
};
void PrintSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << endl;
	}
}	

void test01()
{
	set<int> s1;//����ʽ������С��������
	s1.insert(5);
	s1.insert(1);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);
	PrintSet(s1);
}

void test02()
{
	set<int> s1;//����ʽ������С��������
	s1.insert(5);
	s1.insert(1);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);
	//û��key��value����key
	set<int>::iterator pos=s1.find(3);//find()����һ��iterator��Ҳ����һ����ַ
	int i = *(s1.find(1));
	if (pos != s1.end())
	{
		cout << "have found" << endl;
	}
	cout << i << endl;
	set<int>::iterator it1 = s1.lower_bound(3);                       //���ص�һ��key��=keyElement�ĵ�����
	pair<set<int>::iterator, set<int>::iterator>p1= s1.equal_range(5);//����������key��keyelement��ȵ������޵�������������
	                                                                //�����޾���lower_bound��upper_bound,���ڵ���������
	if (p1.first != s1.end())
	{
		cout << "lower_bound is		" << *(p1.first) << endl;

	}
	else
	{
		cout << "not find lower_bound " << endl;
	}

	if (p1.second != s1.end())
	{
		cout << "upper_bound is		" << *(p1.second) << endl;
	}
	else
	{
		cout << "notupperlower_bound" << endl;
	}
}

void test03()
{
	//���ܲ�����ͬ��ֵ
	set<int> s3; 
	s3.insert(10);
	pair<set<int>::iterator,bool> ret = s3.insert(10);
	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else if (!ret.second)
	{
		cout << "����ʧ��" << endl;
	}
	s3.insert(10);
	pair<set<int>::iterator, bool> ret2 = s3.insert(10);
	if (ret2.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else if (!ret2.second)
	{
		cout << "�ڶ��β���ʧ��" << endl;
	}
	
}

//�º�����set����Ӵ�С
void test04()
{
	set<int,myCompare> s4;
	s4.insert(5);
	s4.insert(1);
	s4.insert(9);
	s4.insert(3);
	s4.insert(7);
	for (set<int, myCompare>::iterator it4 = s4.begin(); it4 != s4.end(); it4++)
	{
		cout << *it4 << endl;
	}

}

int main() {

	//test01();
	//test02();
	//test03();
	test04();
}