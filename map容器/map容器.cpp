#include<iostream>
#include<map>
using namespace std;

void test01()
{
	map<int, int> a;
	//第一种
	a.insert(pair<int, int>(1, 10));
	//第二种
	a.insert(make_pair(2, 30));
	//第三种
	a.insert(map<int, int>::value_type(3, 40));
	//第4种
	a[4] = 40;
	for (map<int, int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << "key=   " << it->first << "   value=   " << (it->second) << endl;
	}
}

int main() {

	test01();
}


