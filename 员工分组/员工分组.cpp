/*//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过Multimap进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
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
		string name = "员工";
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
		//随机产生3个部门，将员工随机分配到三个部门中
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
	
	//我们假设 0：CE 1：AB 2：D
	cout << "研发部分人员如下" << endl;
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
	//随机数种子
	srand((unsigned int)time(NULL));

	//创建一个容器存放5个员工
	vector<Worker> a;

	//创建5个员工
	createWorker(a);

	//分组
	multimap<int, Worker> m;
	setGroup(a, m);

	//显示分组
	showGroup(m);
}