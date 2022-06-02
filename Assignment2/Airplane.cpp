#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		unsigned int maxPassengerCountSum = GetMaxPassengersCount() + boat.GetMaxPassengersCount();
		unsigned int passengerCountSum = GetPassengersCount() + boat.GetPassengersCount();

		Boatplane bp(maxPassengerCountSum);

		unsigned int planePassengersCount = GetPassengersCount();
		// ºñÇà±â ½Â°´ Ãß°¡
		for (unsigned int i = 0; i < planePassengersCount; i++)
		{
			bp.AddPassenger(new Person(*GetPassenger(i)));
		}
		// ºñÇà±â ½Â°´ »èÁ¦
		for (int i = planePassengersCount - 1; i >= 0; i--)
		{
			RemovePassenger(i);
		}

		unsigned int boatPassengersCount = boat.GetPassengersCount();
		// º¸Æ® ½Â°´ Ãß°¡
		for (unsigned int i = 0; i < boatPassengersCount; i++)
		{
			bp.AddPassenger(new Person(*boat.GetPassenger(i)));
		}
		// º¸Æ® ½Â°´ »èÁ¦
		for (int i = boatPassengersCount - 1; i >= 0; i--)
		{
			boat.RemovePassenger(i);
		}

		return bp;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		int x = static_cast<int>(GetPassengersWeightSum());
		double result = 200.0 * exp(static_cast<double>(-x + 800) / 500.0);
		return static_cast<unsigned int>(result + 0.5);	// ¹Ý¿Ã¸² ÇÏ±â À§ÇÏ¿© 0.5 ´õÇÔ
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		int x = static_cast<int>(GetPassengersWeightSum());
		double result = 4.0 * exp(static_cast<double>(-x + 400) / 70.0);
		return static_cast<unsigned int>(result + 0.5);
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetDriveSpeed();
		return flySpeed > driveSpeed ? flySpeed : driveSpeed;
	}

	char Airplane::GetVehicleType() const
	{
		return 'A';
	}

	bool Airplane::IsTrailerConnected() const
	{
		return false;
	}
}