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
		unsigned int rhs = GetSailSpeed();
		return lhs > rhs ? lhs : rhs;
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int x = GetPassengersWeightSum();
		double lhs = 800.0 - 1.7 * x;
		double rhs = 20;
		return lhs > rhs ? static_cast<unsigned int>(lhs) : static_cast<unsigned int>(rhs);
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		int x = static_cast<int>(GetPassengersWeightSum());
		double result = 150.0 * exp(static_cast<double>(-x + 500) / 300.0);
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