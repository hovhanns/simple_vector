#include <iostream>
#include "Vector.h"
//#include "Vector.cpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Vector <int> myvec;	
	int a = 3;
	myvec.push_back(a);
	myvec.push_back(12);
	myvec.push_back(13);
	myvec.push_back(15);

	cout<<myvec.size()<<endl;
	cout<<myvec.capacity()<<endl;

	for (int i = 0; i < myvec.size(); ++i)
	{
		cout<<myvec[i]<<" ";
	}
	
	

	cout<<endl;
	Vector <int> other_vec(myvec);

	for (int i = 0; i < other_vec.size(); ++i)
	{
		cout<<other_vec[i]<<" ";
	}

	cout << endl;
	return 0;
}