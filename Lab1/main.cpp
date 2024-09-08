#include <fstream>                         
#include <iostream>

using namespace std;

class Patient {
private:
	char name[64];
	char address[64];
	char diagnosis[64];
	int number;

public:
	Patient(const char* name, const char* address, const char* diagnosis, int number) {
		strcpy_s(this->name, name);
		strcpy_s(this->address, address);
		strcpy_s(this->diagnosis, diagnosis);
		this->number = number;
	}

	Patient() {
		strcpy_s(this->name, "Name");
		strcpy_s(this->address, "Address");
		strcpy_s(this->diagnosis, "Diagnosis");
		this->number = 0;
	}

	void setName(const char* name) {
		strcpy_s(this->name, name);
	}

	void setAddress(const char* address) {
		strcpy_s(this->address, address);
	}

	void setDiagnosis(const char* diagnosis) {
		strcpy_s(this->diagnosis, diagnosis);
	}

	void setNumber(int number) {
		this->number = number;
	}

	char* getName() {
		return this->name;
	}

	char* getAddress() {
		return this->address;
	}

	char* getDiagnosis() {
		return this->diagnosis;
	}

	int getNumber() {
		return this->number;
	}

	void inStream(ostream& in) {
		in << "- - - - - - - - - - - - - - - - - - - - -" << endl;
		in << "���: " << this->name << endl;
		in << "�����: " << this->address << endl;
		in << "�������: " << this->diagnosis << endl;
		in << "����� ����������� �����: " << this->number << endl;
		in << "- - - - - - - - - - - - - - - - - - - - -" << endl;
	}

	void show() {
		inStream(cout);
	}
};

void getPatientsWithDiagnosis(string diagnosis, Patient patients[], int size, const int mode = ios::out) {
	ofstream output("output.txt");

	for (int index = 0; index < size; index++) {
		if (patients[index].getDiagnosis() == diagnosis) {
			patients[index].show();
			patients[index].inStream(output);
		}
	}
}

void getPatientsByNumberBetween(int a, int b, Patient patients[], int size, const int mode = ios::out) {
	ofstream output("output.txt");

	for (int index = 0; index < size; index++) {
		if (patients[index].getNumber() > a && patients[index].getNumber() < b) {
			patients[index].inStream(output);
			patients[index].show();
		}
	}
}


int main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	system("color 0A");

	const char* path = "start_list.txt";
	char* file = new char[1024];
	int size = 0;

	ifstream fin(path);

	while (!fin.eof()) {
		fin.getline(file, 1024, '\n');
		size++;
	}

	Patient* patients = new Patient[size];

	fin.seekg(0);
	int pos = 0;

	while (!fin.eof()) {
		if (pos > size - 1) break;

		char buffer[64];

		fin.getline(buffer, 63, ',');
		patients[pos].setName(buffer);
		fin.getline(buffer, 63, ',');
		patients[pos].setAddress(buffer);
		fin.getline(buffer, 63, ',');
		patients[pos].setDiagnosis(buffer);

		int num;
		fin >> num;
		patients[pos].setNumber(num);
		fin.getline(buffer, 63, ',');
		pos++;

		if (fin.eof()) break;
	}

	fin.close();

	int action;
	int a, b;
	char diagnosis[64];

	while (true) {
		cout << endl << "�������� ��������:" << endl;
		cout << "1 - ������ ���������" << endl;
		cout << "2 - ������ ���������, ������� ������ ������� (������������ � ��������)" << endl;
		cout << "3 - ������ ���������, ����� �������� ������� ��������� � �������� ��������� (a, b)" << endl;
		cout << "�� ��������� - �����" << endl;

		cout << "��� �����: ";
		cin >> action;


		switch (action) {
		case 1:
			cout << "������ ���������: " << endl;
			for (int index = 0; index < size; index++) {
				patients[index].show();
			}
			break;

		case 2:
			char diagnosis[32];
			cout << "������� �������: ";
			cin >> diagnosis;
			cout << "������ ��������� � ��������� " << diagnosis << ": " << endl;
			getPatientsWithDiagnosis(diagnosis, patients, size);
			break;

		case 3:
			cout << "������� a: ";
			cin >> a;
			cout << "������� b: ";
			cin >> b;
			cout << "������ ���������, ����� �������� ������� ��������� � ��������� (" << a << ", " << b << "): " << endl;
			getPatientsByNumberBetween(a, b, patients, size);
			break;

		default:
			delete[] file;
			delete[] patients;
			cout << "\n������ �������\n";
			return 0;
		}
	}

	return 0;
}