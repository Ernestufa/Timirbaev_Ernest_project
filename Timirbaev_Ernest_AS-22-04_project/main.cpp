#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int number = 0;

	cout << "1 �������� �����" << endl
		<< "2 �������� ��" << endl
		<< "3 �������� ���� ��������" << endl
		<< "4 ������������� �����" << endl
		<< "5 ������������� ��" << endl
		<< "6 ���������" << endl
		<< "7 ���������" << endl
		<< "0 �����" << endl << endl
		<< "������� ����� �������: ";

	cin >> number;
	switch (number) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		cout << "������������ ������, ��������� �������!";
	}
	return 0;
}