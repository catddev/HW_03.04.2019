#include"Bus.h"

int cur_size = 0, buf_size = 0;
void add(Bus*&bs, Bus el) {
	if (buf_size == 0)
	{
		buf_size = 4;
		bs = new Bus[buf_size];
	}
	else
	{
		if (cur_size == buf_size)
		{
			buf_size *= 2;
			Bus*tmp1 = new Bus[buf_size];
			for (int i = 0; i < cur_size; i++)
				tmp1[i] = bs[i];
			delete[] bs;
			bs = tmp1;
		}
	}
	bs[cur_size++] = el;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream in_file("in.txt");
	Bus *bs = 0;
	Bus tmp;
	char str[30];
	int y, p;
	double r;
	if (!in_file)
		cerr << "File open error" << endl;
	else
	{
		while (!in_file.eof())
		{
			in_file.getline(str, 30, '#');
			tmp.setDriver(str);

			in_file.getline(str, 10, '#');
			tmp.setBus(str);

			in_file >> p;
			tmp.setRoute(p);
			in_file.ignore();

			in_file.getline(str, 30, '#');
			tmp.setModel(str);

			in_file >> y >> r;
			tmp.setYear(y);
			tmp.setRun(r);

			add(bs, tmp);
		}
		
		cout << "Enter needed route number" << endl;
		cin >> p;
		for (int i = 0; i < cur_size; i++)
			if (bs[i].by_route(p))
				bs[i].print();
		cout << endl << endl;

		cout << endl << "Buses by run more than 10 years:" << endl;
		for (int i = 0; i < cur_size; i++)
			if (bs[i].years10())
				bs[i].print();
		cout << endl;

		cout << endl << "Buses by run more than 10 000 km:" << endl;
		for (int i = 0; i < cur_size; i++)
			if (bs[i].by_run())
				bs[i].print();
		cout << endl << endl;
	}

	delete[] bs;

	system("pause");
	return 0;
}