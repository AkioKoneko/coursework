#include <iostream>
#include "phone.hpp"

int main()
{
	char c;

	do
	{
		std::cout << '\n';

		std::cout << "L: Загрузить данные из файла\n"
		          << "P: Вывести данные на экран\n"
		          << "E: Отредактировть данные\n"
		          << "S: Сохранить данные в файл\n"
		          << "Q: Выход\n\n";

		std::cin >> c;

		if (c == 'L')
		{
			std::cout << "Загрузка...\n";
			std::cin.ignore();
		}

		else if (c == 'P')
		{
			std::cout << "Печать...\n";
			std::cin.ignore();
		}

		if (c == 'E')
		{
			std::cout << "Редактирование...\n";
			std::cin.ignore();
		}

		else if (c == 'S')
		{
			std::cout << "Сохранение...\n";
			std::cin.ignore();
		}
	}
	while (c != 'Q');
}
