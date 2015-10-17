#include <string>

using namespace std;

class transaction
{
	string Date;
	string source;
	string destination;
	int summ;
	string note;

public:
	
	//*
	void Parse(string in) //конструктор принимает строку и на основании ее делате объект транзакция
	{
		size_t pos;
		pos=in.find_first_not_of(" \t", pos);
		size_t pos1 = in.find_first_of(" \t");

		Date = in.substr(pos, pos1-pos);
		pos = pos1;
		size_t pos1 = in.find_first_of(" \t", pos);
		source = in.substr(pos, pos1-pos);
		pos = pos1;
		size_t pos1 = in.find_first_of(" \t", pos);
		destination = in.substr(pos, pos1-pos);
		pos = pos1;
		size_t pos1 = in.find_first_of(" \t", pos);
		summ = stoi(in.substr(pos, pos1-pos));
		pos=pos1



		/*
		unsigned int i = 0;
		while (in[i] != ' ' && in[i] != '\n')
		{
			Date += in[i];
			++i;
		}
		++i;
		while (in[i] != ' ' && in[i] != '\n')
		{
			source += in[i];
			++i;
		}
		++i;
		while (in[i] != ' ' && in[i] != '\n')
		{
			destination += in[i];
			++i;

		}
		++i;
		char *tmp_toint = new char[250];

		for (unsigned int z = 0; in[i] != ' ' && in[i] != '\0'; ++i, ++z)
		{
			tmp_toint[z] = in[i];
		}
		summ = atoi(tmp_toint);

	}
	string getSource()
	{
		return source;
	}
	//*/
	}
};
