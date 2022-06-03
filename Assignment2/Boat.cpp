#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetSailSpeed() const
	{
		unsigned int x = GetPassengersWeightSum();
		int lhs = (800 - 10 * static_cast<int>(x));
		int rhs = 20;
		return  lhs > rhs ? static_cast<unsigned int>(lhs) : static_cast<unsigned int>(rhs);
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		unsigned int maxPassengerCountSum = GetMaxPassengersCount() + plane.GetMaxPassengersCount();
		unsigned int passengerCountSum = GetPassengersCount() + plane.GetPassengersCount();

		Boatplane bp(maxPassengerCountSum);

		unsigned int planePassengersCount = plane.GetPassengersCount();
		// ºñÇà±â ½Â°´ Ãß°¡
		for (unsigned int i = 0; i < planePassengersCount; i++)
		{
			bp.AddPassenger(new Person(*plane.GetPassenger(i)));
		}
		// ºñÇà±â ½Â°´ »èÁ¦
		for (int i = planePassengersCount - 1; i >= 0; i--)
		{
			plane.RemovePassenger(i);
		}

		unsigned int boatPassengersCount = GetPassengersCount();
		// º¸Æ® ½Â°´ Ãß°¡
		for (unsigned int i = 0; i < boatPassengersCount; i++)
		{
			bp.AddPassenger(new Person(*GetPassenger(i)));
		}
		// º¸Æ® ½Â°´ »èÁ¦
		for (int i = boatPassengersCount - 1; i >= 0; i--)
		{
			RemovePassenger(i);
		}

		return bp;
	}

	char Boat::GetVehicleType() const
	{
		return 'B';
	}

	bool Boat::IsTrailerConnected() const
	{
		return false;
	}
}