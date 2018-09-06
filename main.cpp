#include <list>
#include <memory>
#include <iostream>
#include "phone.hpp"

int main()
{
	char c;
	std::list<std::unique_ptr<Phone>> phones;

	do
	{
		std::cout << '\n';

		std::cout << "L: Загрузить данные из файла\n"
		          << "P: Вывести данные на экран\n"
		          << "S: Сохранить данные в файл\n"
		          << "Q: Выход\n\n";

		std::cin >> c;

		if (c == 'L')
		{
			for (auto &&p : PhoneLoader("input.txt"))
				phones.emplace_back(p);
			std::cout << "Данные успешно загружены" << '\n';
		}

		else if (c == 'P')
		{
			for (auto &p : phones)
			{
				p->Print();
				std::cout << '\n';
			}
		}

		else if (c == 'S')
		{
			for (auto &p : phones)
				p->Save("output.txt");
			std::cout << "Данные сохранены в файл" << '\n';
		}
	}
	while (c != 'Q');
}
