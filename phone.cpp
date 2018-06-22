#include "phone.hpp"

void Phone::Print(std::ostream &out)
{
	out << "Год производства: " << prod_year << '\n';
	out << "Цвет: " << color << '\n';
	out << "Тип связи: " << comm_type << '\n';
}

void MobilePhone::Print(std::ostream &out)
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

void Smartphone::Print(std::ostream &out)
{
	MobilePhone::Print(out);

	out << "Камера: " << btos(HasCamera()) << '\n';
	if (HasCamera())
		out << "Разрешение матрицы: " << camera_mp << " MP\n";
}
