#ifndef PHONE_HPP
#define PHONE_HPP

#include <fstream>

using mm = short;
using MHz = short;
using MB = short;

class Phone
{
	short prod_year;
	std::string color;
	std::string comm_type;

public:
	      auto ProductionYear() const { return prod_year; }
	const auto & CommType()     const { return comm_type; }
	const auto & Color()        const { return color;     }
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
	bool HasGPS()         const { return has_gps;              }
	bool HasGLONASS()     const { return has_glonass;          }
	bool HasWiFi()        const { return has_wifi;             }
	bool Has4G()          const { return has_4g;               }
	bool HasCamera()      const { return camera_mp != 0;       }
	bool HasScreen()      const { return screen_diagonal != 0; }
	auto CameraMP()       const { return camera_mp;            }
	mm   ScreenDiagonal() const { return screen_diagonal;      }
	MHz  CPUFreqency()    const { return cpu_frequency;        }
	MB   MemorySize()     const { return memory_size;          }
};

class Smartphone : public MobilePhone
{
	float camera_mp;

public:
	auto CameraMP() const { return camera_mp; }
};

class SatellitePhone : public MobilePhone
{

};

#endif
