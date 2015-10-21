#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "traction.h"


using namespace std;


void main()
{
	setlocale(LC_ALL, "ru-RU");
	string tmp;
	vector<transaction> massTransact; // Массив транзакций
	vector<string> massSchetr; // Массив счетов
	transaction *t;
	fstream fs("file.txt", ios::in);
	if (fs)
	{

		for (unsigned int k = 0; !fs.eof(); ++k)
		{
			getline(fs, tmp);
			t = new transaction[1];
			(*t).Parse(tmp);
			massTransact.push_back((*t));
			if (massSchetr.size() == 0)
			{
				massSchetr.push_back((*t).getSource());
				if ((*t).getSource() != (*t).getDestinon())
				{
					massSchetr.push_back((*t).getDestinon());
				}
			}
			else
			{
				bool schetSource = false;
				bool schetDestination = false;
				for (unsigned int i = 0; i < massSchetr.size(); ++i)
				{
					if ((*t).getSource() == massSchetr[i])
					{
						schetSource = true;
					}
					if ((*t).getDestinon() == massSchetr[i])
					{
						schetDestination = true;
					}
				}
				if (!schetSource)
				{
					massSchetr.push_back((*t).getSource());
				}
				if (!schetDestination)
				{
					massSchetr.push_back((*t).getDestinon());
				}
			}
		}
		fs.close();


		unsigned int y = 0;
		while (y != 10)
		{

			cout << "Enter number menu:\n 1. Out all account.\n"
				<< "10. Out program.\n";
			cin >> y;
			switch (y)
			{
			case 1:
				for (unsigned int i = 0 ; i < massSchetr.size(); ++i)
				{
					double sm = 0;
					for (unsigned int j = 0; j<massTransact.size(); ++j)
					{
						if (massSchetr[i] == massTransact[j].getSource())
						{
							sm -= massTransact[j].getSumm();
						}
						else if (massSchetr[i] == massTransact[j].getDestinon())
						{
							sm += massTransact[j].getSumm();
						}
					}
					cout << massSchetr[i] << " = " << sm << endl;
				}
				break;
			case 2:
			
			default:
				break;
			}
		}
	}
	else
	{
		cerr << "Error: cannot open file"<<endl;
	}

	


	system("pause");
}