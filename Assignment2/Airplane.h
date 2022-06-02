#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();
		unsigned int GetFlySpeed() const;
		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;
		bool IsTrailerConnected() const;
		char GetVehicleType() const;
		Boatplane operator+(Boat& boat);
	};
}