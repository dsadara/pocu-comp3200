#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		unsigned int x = GetPassengersWeightSum();
		double result = 500.0 * log((150.0 + x) / 150.0) + 30;
		return static_cast<unsigned int>(result);
	}
	unsigned int UBoat::GetSailSpeed() const
	{
		unsigned int x = GetPassengersWeightSum();
		double result = 550.0 - static_cast<double>(x) / 200;
		if (result < 200)
		{
			return 200;
		}
		return static_cast<unsigned int>(result);
	}
	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int lhs = GetDiveSpeed();
		unsigned int rhs = GetSailSpeed();
		return lhs > rhs ? lhs : rhs;
	}
}