#include <list>
#include <iostream>
#include "phone.hpp"

int main()
{
	char c;
	std::list<Phone> phones;

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
			std::cout << "Загрузка...\n"; // TODO
			std::cin.ignore();
		}

		else if (c == 'P')
		{
			for (auto &p : phones)
			{
				p.Print();
				std::cout << '\n';
			}
		}

		if (c == 'E')
		{
			std::cout << "Редактирование...\n"; // TODO
			std::cin.ignore();
		}

		else if (c == 'S')
		{
			for (auto &p : phones)
				p.Save("output.txt");
		}
	}
	while (c != 'Q');
}
