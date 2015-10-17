#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "traction.h"


using namespace std;


void main()
{
	setlocale(LC_ALL, "ru-RU");
	unsigned int i; //Переменная для подстчета количества строк.
	string tmp;
	vector<transaction> massStr; // Массив строк прочитаных из фала
	transaction *t;
	transaction *t1;
	//massStr.resize(6);
	fstream fs("file.txt", ios::in);
	
	if (fs)
	{

		for (unsigned int k = 0; !fs.eof();++k)
		{
			t = new transaction[1];
			getline(fs, tmp);
			(*t).Parse(tmp);
			//cout << (*t).getSource()<<endl;
			massStr.push_back(*t);

		}
		fs.close();
	}
	else
	{
		cerr << "Error: cannot open file"<<endl;
	}

	
	for (unsigned int k = 0; k < i; ++k)
	{
		t1 = &massStr[k];
		cout << t1->getSource()<< endl;
		//cout << massStr[k].getSource()<<endl;
	}
	cout << massStr.size() << endl;
	system("pause");
}