#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int number = 0;

	cout << "1 Добавить трубу" << endl
		<< "2 Добавить КС" << endl
		<< "3 Просмотр всех объектов" << endl
		<< "4 Редактировать трубу" << endl
		<< "5 Редактировать КС" << endl
		<< "6 Сохранить" << endl
		<< "7 Загрузить" << endl
		<< "0 Выход" << endl << endl
		<< "Введите номер команды: ";

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
		cout << "Неправильные данные, повторите попытку!";
	}
	return 0;
}