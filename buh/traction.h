#include <string>

using namespace std;

class transaction
{
	string date;
	string source;
	string destination;
	double summ;
	string note;

public:

	//*
	void Parse(string in) //
	{


		size_t pos, pos1;
		pos1 = in.find_first_of(" \t", pos);
		date = in.substr(pos, pos1 - pos);

		pos = in.find_first_not_of(" \t", pos1);
		pos1 = in.find_first_of(" \t", pos);
		source = in.substr(pos, pos1 - pos);

		pos = in.find_first_not_of(" \t", pos1);
		pos1 = in.find_first_of(" \t", pos);
		destination = in.substr(pos, pos1 - pos);


		pos = in.find_first_not_of(" \t", pos1);
		pos1 = in.find_first_of(" \t", pos);
		summ = atof((in.substr(pos, pos1 - pos)).c_str()); // Почему- то не работает перевод из строки в float, нужно спросить.

		pos = in.find_first_not_of(" \t", pos1);
		note = in.substr(pos, 1000);
	}
	string getSource()
	{
		return source;
	}
	string getDestinon()
	{
		return destination;
	}

	double getSumm()
	{
		return summ;
	}

	string getDate()
	{
		return date;
	}
	//*/
};
