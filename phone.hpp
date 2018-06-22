#ifndef PHONE_HPP
#define PHONE_HPP

#include <string>
#include <fstream>
#include <iostream>

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
	      inline auto ProductionYear() const { return prod_year; }
	const inline auto & CommType()     const { return comm_type; }
	const inline auto & Color()        const { return color;     }

	virtual void Print(std::ostream &out = std::cout);
	void Save(std::string filename);
};

class LandlinePhone : public Phone
{

};

class MobilePhone : public Phone
{
	bool has_gps, has_glonass, has_wifi, has_4g;
	mm screen_diagonal;
	MHz cpu_frequency;
	MB memory_size;

public:
	inline bool HasGPS()         const { return has_gps;              }
	inline bool HasGLONASS()     const { return has_glonass;          }
	inline bool HasWiFi()        const { return has_wifi;             }
	inline bool Has4G()          const { return has_4g;               }
	inline bool HasScreen()      const { return screen_diagonal != 0; }
	inline mm   ScreenDiagonal() const { return screen_diagonal;      }
	inline MHz  CPUFreqency()    const { return cpu_frequency;        }
	inline MB   MemorySize()     const { return memory_size;          }

	virtual void Print(std::ostream &out = std::cout);
};

class Smartphone : public MobilePhone
{
	float camera_mp;

public:
	inline bool HasCamera() const { return camera_mp != 0; }
	inline auto CameraMP()  const { return camera_mp;      }

	virtual void Print(std::ostream &out = std::cout);
};

class SatellitePhone : public MobilePhone
{

};

#endif
