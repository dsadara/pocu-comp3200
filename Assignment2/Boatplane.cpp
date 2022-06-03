#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int lhs = GetSailSpeed();
		unsigned int rhs = GetFlySpeed();
		return lhs > rhs ? lhs : rhs;
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int x = GetPassengersWeightSum();
		double lhs = 800.0 - 1.7 * static_cast<double>(x);
		double rhs = 20.0;
		return lhs > rhs ? static_cast<unsigned int>(lhs + 0.5) : static_cast<unsigned int>(rhs);
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int x = GetPassengersWeightSum();
		double result = 150.0 * exp(static_cast<double>(500 - static_cast<int>(x)) / 300.0);
		return static_cast<unsigned int>(result + 0.5);
	}

	char Boatplane::GetVehicleType() const
	{
		return 'P';
	}

	bool Boatplane::IsTrailerConnected() const
	{
		return false;
	}
}