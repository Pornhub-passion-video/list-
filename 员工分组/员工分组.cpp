/*//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ��: ���� ���� �绰 ���ʵ����
//ͨ��Multimap������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

enum { yanfa ,shuxue ,xingyu };
class Worker
{
public:
	string mName;
	int salary;
	

};
void createWorker(vector<Worker> &v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "Ա��";
		name += nameseed[i];
		Worker w;
		w.mName = name;
		w.salary = rand() % 10000 + 10000;
		v.push_back(w);
		
	}

}
void setGroup(vector<Worker>& a, multimap<int, Worker>& m)
{ 

	for (vector<Worker>::iterator it = a.begin(); it != a.end(); it++)
	{
		//�������3�����ţ���Ա��������䵽����������
		int departmentID = rand() % 3;
		m.insert(make_pair(departmentID, *it)); 
		m, make_pair(departmentID, *it);
		
	}
}
void showGroup(multimap<int, Worker>& m)
{
	for (multimap<int, Worker>::iterator itMap = m.begin(); itMap != m.end(); itMap++)
	{
		cout << "deploment is  " << itMap->first << "   name is " << (itMap->second).mName << "    salary is " << (itMap->second).salary << endl;
	}
	
	//���Ǽ��� 0��CE 1��AB 2��D
	cout << "�з�������Ա����" << endl;
	multimap<int, Worker>::iterator itMap = m.find(yanfa);
	int index = 0;
	int num = m.count(0);
	for (; itMap != m.end(),index <num; itMap++,index++)
	{
		cout << "deploment is  " << itMap->first << "   name is " << (itMap->second).mName << "    salary is " << (itMap->second).salary << endl;
	}
	cout << "___________________________" << endl;
	multimap<int, Worker>::iterator itMap2 = m.find(shuxue);
	int index2 = 0;
	int num2 = m.count(1);
    for (; itMap2 != m.end(), index2 < num2; itMap2++, index2++)
{
	cout << "deploment is  " << itMap2->first << "   name is " << (itMap2->second).mName << "    salary is " << (itMap2->second).salary << endl;
	}
	cout << "___________________________" << endl;
	cout << endl;
	multimap<int, Worker>::iterator itMap3 = m.find(xingyu);
	int index3 = 0;
	int num3 = m.count(2);
	for (; itMap3 != m.end(), index3 < num3; itMap3++, index3++)
	{
		cout << "deploment is  " << itMap3->first << "   name is " << (itMap3->second).mName << "    salary is " << (itMap3->second).salary << endl;
	}

	
}
int main() {
	//���������
	srand((unsigned int)time(NULL));

	//����һ���������5��Ա��
	vector<Worker> a;

	//����5��Ա��
	createWorker(a);

	//����
	multimap<int, Worker> m;
	setGroup(a, m);

	//��ʾ����
	showGroup(m);
}