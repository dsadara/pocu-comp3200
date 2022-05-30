#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		:Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
	unsigned int Motorcycle::GetDriveSpeed() const
	{
		int x = static_cast<int>(GetPassengersWeightSum());
		double result = (-pow((static_cast<double>(x) / 15), 3) + 2.0 * x + 400.0);
		if (result < 0)
		{
			return 0;
		}
		return static_cast<unsigned int>(result + 0.5);
	}
}