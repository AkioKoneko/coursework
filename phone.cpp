#include "phone.hpp"

Phone::Phone(std::ifstream &in)
{
	skip_colon(in);
	in >> prod_year;
	skip_colon(in);
	std::getline(in, color);
	skip_colon(in);
	std::getline(in, comm_type);
}

MobilePhone::MobilePhone(std::ifstream &in) : Phone(in)
{
	std::string buff;
	skip_colon(in);
	in >> buff;
	has_gps = (buff == "Есть");

	skip_colon(in);
	in >> buff;
	has_glonass = (buff == "Есть");

	skip_colon(in);
	in >> buff;
	has_wifi = (buff == "Есть");

	skip_colon(in);
	in >> buff;
	has_4g = (buff == "Есть");

	skip_colon(in);
	in >> buff;

	if (buff == "Есть")
	{
		skip_colon(in);
		in >> screen_diagonal;
	}

	skip_colon(in);
	in >> cpu_frequency;
	skip_colon(in);
	in >> memory_size;
}

Smartphone::Smartphone(std::ifstream &in) : MobilePhone(in)
{
	std::string has_camera;
	skip_colon(in);
	in >> has_camera;

	if (has_camera == "Есть")
	{
		skip_colon(in);
		in >> camera_mp;
	}
}

void Phone::Print(std::ostream &out) const
{
	out << "Год производства: " << prod_year << '\n';
	out << "Цвет: " << color << '\n';
	out << "Тип связи: " << comm_type << '\n';
}

void MobilePhone::Print(std::ostream &out) const
{
	Phone::Print(out);

	out << "GPS: " << btos(has_gps) << '\n';
	out << "ГЛОНАСС: " << btos(has_glonass) << '\n';
	out << "Wi-Fi: " << btos(has_wifi) << '\n';
	out << "4G: " << btos(has_4g) << '\n';
	out << "Экран: " << btos(HasScreen()) << '\n';
	if (HasScreen())
		out << "Диагональ экрана: " << screen_diagonal << " mm\n";
	out << "Частота процессора: " << cpu_frequency << " MHz\n";
	out << "Объем памяти: " << memory_size << " MB\n";
}

void Smartphone::Print(std::ostream &out) const
{
	MobilePhone::Print(out);

	out << "Камера: " << btos(HasCamera()) << '\n';
	if (HasCamera())
		out << "Разрешение матрицы: " << camera_mp << " MP\n";
}

void Phone::Save(const std::string filename) const
{
	std::ofstream file(filename, std::ios_base::app);
	file << ClassName() << '\n';
	Print(file);
}

bool nws_left(std::istream &in)
{
	for (char c; (c = in.peek()) != '\n' && c != EOF; in.get())
		if (!std::isspace(c))
			return true;
	return false;
}
