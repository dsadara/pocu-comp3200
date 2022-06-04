#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		unsigned int area = GetArea();
		double result = 0.0;
		switch (grassType)
		{
		case BERMUDA:
			result = (static_cast<double>(area) * 800.0) / 100.0;
			break;
		case BAHIA:
			result = (static_cast<double>(area) * 500.0) / 100.0;
			break;
		case BENTGRASS:
			result = (static_cast<double>(area) * 300.0) / 100.0;
			break;
		case PERENNIAL_RYEGRASS:
			result = (static_cast<double>(area) * 250.0) / 100.0;
			break;
		case ST_AUGUSTINE:
			result = (static_cast<double>(area) * 450.0) / 100.0;
			break;
		default:
			break;
		}
		return static_cast<unsigned int>(result + 0.5);		// 반올림 or 내림? 
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int area = GetArea();
		double result = static_cast<double>(area) / 0.3;
		return static_cast<unsigned int>(result + 0.99);
	}
}