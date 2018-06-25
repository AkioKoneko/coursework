#ifndef PHONE_HPP
#define PHONE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <functional>
#include <cctype>

using mm = short;
using MHz = short;
using MB = short;

constexpr const char * btos(bool arg) { return arg ? "Есть" : "Нет"; }

class Phone
{
	short prod_year;
	std::string color;
	std::string comm_type;

public:
	Phone(std::ifstream &in);

	      inline auto ProductionYear() const { return prod_year; }
	const inline auto & CommType()     const { return comm_type; }
	const inline auto & Color()        const { return color;     }

	virtual const char * ClassName() const { return ""; }
	virtual void Print(std::ostream &out = std::cout) const;
	void Save(const std::string filename) const;
};

class LandlinePhone : public Phone
{
	virtual const char * ClassName() const { return "LandlinePhone"; }

public:
	LandlinePhone(std::ifstream &in) : Phone(in) {}
};

class MobilePhone : public Phone
{
	bool has_gps, has_glonass, has_wifi, has_4g;
	mm screen_diagonal;
	MHz cpu_frequency;
	MB memory_size;

public:
	MobilePhone(std::ifstream &in);

	inline bool HasGPS()         const { return has_gps;              }
	inline bool HasGLONASS()     const { return has_glonass;          }
	inline bool HasWiFi()        const { return has_wifi;             }
	inline bool Has4G()          const { return has_4g;               }
	inline bool HasScreen()      const { return screen_diagonal != 0; }
	inline mm   ScreenDiagonal() const { return screen_diagonal;      }
	inline MHz  CPUFreqency()    const { return cpu_frequency;        }
	inline MB   MemorySize()     const { return memory_size;          }

	virtual void Print(std::ostream &out = std::cout) const;
};

class Smartphone : public MobilePhone
{
	float camera_mp;

public:
	Smartphone(std::ifstream &in);

	inline bool HasCamera() const { return camera_mp != 0; }
	inline auto CameraMP()  const { return camera_mp;      }

	virtual const char * ClassName() { return "Smartphone"; }
	virtual void Print(std::ostream &out = std::cout) const;
};

class SatellitePhone : public MobilePhone
{
	virtual const char * ClassName() const { return "SatellitePhone"; }

public:
	SatellitePhone(std::ifstream &in) : MobilePhone(in) {}
};

template <typename T>
inline Phone * PhoneFactory(std::ifstream &in) { return new T(in); }

static std::map<std::string, std::function<Phone*(std::ifstream &)>> NewPhone =
{
	{ "Smartphone"    , PhoneFactory<Smartphone>     },
	{ "LandlinePhone" , PhoneFactory<LandlinePhone>  },
	{ "SatellitePhone", PhoneFactory<SatellitePhone> }
};

bool nws_left(std::istream &in);

inline void skip_colon(std::ifstream &in)
{
	do in.get(); while (in.peek() != ':');
}

class PhoneIterator
{
	std::ifstream &file;
	std::string type;
	bool is_end;

public:
	inline PhoneIterator(std::ifstream &f, bool e = false)
		: file(f), is_end(e) {}

	using value_type = Phone *;
	using difference_type = int;
	using pointer = Phone **;
	using reference = Phone *&;
	using iterator_category	= std::input_iterator_tag;

	inline bool operator!=(const PhoneIterator &other) const
	{
		return (is_end ^ other.is_end);
	}

	inline bool operator==(const PhoneIterator &other) const
	{
		return !(*this != other);
	}

	inline PhoneIterator operator++()
	{
		is_end = !nws_left(file);
		if (!is_end)
			file >> type;
		return *this;
	}

	inline PhoneIterator operator++(int)
	{
		PhoneIterator old = *this;
		++(*this);
		return old;
	}

	inline value_type operator*() { return NewPhone[type](file); }
};

class PhoneLoader
{
	std::ifstream file;

public:
	inline PhoneLoader(const std::string filename) : file(filename) {}
	inline auto begin() { return PhoneIterator(file); };
	inline auto end() { return PhoneIterator(file, true); };
};

#endif
