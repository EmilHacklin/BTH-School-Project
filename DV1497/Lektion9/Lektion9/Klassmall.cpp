#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	vector<int> nrs;
	vector<string> names;

	nrs.push_back(10);
	cout << nrs.at(0) << endl;
	for (int i = 11; i < 100; i++)
	{
		nrs.push_back(i);
	}
}