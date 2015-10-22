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
		vector<string> massData; //Массив дат транзакций
		fstream fs("file.txt", ios::in);
		if (fs)
		{

			for (unsigned int k = 0; !fs.eof(); ++k)
			{
				getline(fs, tmp);
				if ((tmp[4] != tmp[7]) || (tmp[7] != '.'))
				{
					cerr << "Error: uncorrected string (" << tmp << ").\n";
					cout << tmp[4] << " " << tmp[7] << endl;
				}
				else
				{
					massTransact.push_back(*new transaction(tmp));
					if (massSchetr.size() == 0 && massTransact.size() == 1)
					{
						massSchetr.push_back(massTransact[0].getSource());
						if (massTransact[0].getSource() != massTransact[0].getDestinon())
						{
							massTransact[0].getDestinon();
						}
					}
					else
					{
						bool schetSource = false;
						bool schetDestination = false;
						for (unsigned int i = 0; i < massSchetr.size(); ++i)
						{
							if (massTransact[massTransact.size() - 1].getSource() == massSchetr[i])
							{
								schetSource = true;
							}
							if (massTransact[massTransact.size() - 1].getDestinon() == massSchetr[i])
							{
								schetDestination = true;
							}
						}
						if (!schetSource)
						{
							massSchetr.push_back(massTransact[massTransact.size() - 1].getSource());
						}
						if (!schetDestination)
						{
							massSchetr.push_back(massTransact[massTransact.size() - 1].getDestinon());
						}

						if (massData.size() == 0 && massTransact.size() == 1)
						{
							massData.push_back(massTransact[0].getDate());
						}
						else
						{
							bool dataNotExist=true;
							for (unsigned int i = 0; i < massData.size(); ++i)
							{
								if(massData[massData.size()-1]== massTransact[massTransact.size() - 1].getDate())
								{
									dataNotExist = false;
									break;
								}
							}
							if(dataNotExist)
							{
								massData.push_back(massTransact[massTransact.size() - 1].getDate());
							}
						}

					}
					
				}
			}
		
			fs.close();
			unsigned int y = 0;
			while (y != 9)
			{

				cout << "Enter number menu:\n1. Out all account.\n" << "2. Report time.\n9. Out program.\n";
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
					if (true)
					{
						unsigned int numberSchet = 0;
						unsigned int numberDataBegin = 0;
						unsigned int numberDateEnd = 0;
						double begin = 0;
						double in = 0;
						double out = 0;
						double Prihod = 0;
						double Rashod = 0;
						cout << "------------------------------------------------------------\n";
						for (unsigned int i = 0; i < massSchetr.size(); ++i)
						{
							cout << i + 1 << ". " << massSchetr[i] << endl;

						}
						cout << "Enter number schet (no more " << massSchetr.size() << "): ";
						while(true)
						{
							cin >> numberSchet;
							if(numberSchet<1||numberSchet>massSchetr.size())
							{
								cerr << "Error: incorrect number, reenter: ";
							}
							else
							{
								break;
							}
						}
						cout << "------------------------------------------------------------\n";
						for (unsigned int i = 0; i < massData.size(); ++i)
						{
							cout << i + 1 << ". " << massData[i] << endl;
						}
						cout << "Enter number date begin: ";
						
						while(true)
						{
							cin >> numberDataBegin;
							if(numberDataBegin<1 || numberDataBegin>massData.size())
							{
								cerr << "Error: incorrect number, reenter: ";
							}
							else
							{
								break;
							}
						}
						cout << "------------------------------------------------------------\n";
						for (unsigned int i = numberDataBegin - 1; i < massData.size(); ++i)
						{
							cout << i + 1 << ". " << massData[i] << endl;
						}
						cout <<"Enter number date end: ";
						
						while (true)
						{
							cin >> numberDateEnd;
							if (numberDateEnd<numberDataBegin || numberDateEnd>massData.size())
							{
								cerr << "Error: incorrect number, reenter: ";
							}
							else
							{
								break;
							}
						}
						// Счетаем баланс по транзакциям на начало периода
						unsigned int i = 0;
						for (; i!= numberDataBegin-1; ++i)
						{
							if (massSchetr[numberSchet - 1] == massTransact[i].getSource())
							{
								in -= massTransact[i].getSumm();
							}
							else if (massSchetr[numberSchet - 1] == massTransact[i].getDestinon())
							{
								in += massTransact[i].getSumm();
							}

						}
						// Счетем расход/приход за пераод
						for (; i != numberDateEnd; ++i)
						{
							if (massSchetr[numberSchet - 1] == massTransact[i].getSource()) // Если движение денег происходит со счета это расход
							{
								Rashod += massTransact[i].getSumm();
							}
							else if (massSchetr[numberSchet - 1] == massTransact[i].getDestinon()) // Если движение денег происходит на счет это приход
							{
								Prihod += massTransact[i].getSumm();
							}
						}
						cout << "Begin: " << in << endl;
						cout << "Rashod: " << Rashod << endl;
						cout << "Prihod: " << Prihod << endl;
						cout << "Result: " << in - Rashod + Prihod << endl; 
					}
					break;
			
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