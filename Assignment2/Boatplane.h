#pragma once

#include "Vehicle.h"
#include "ISailable.h"
#include "IFlyable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public ISailable, public IFlyable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();
		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetFlySpeed() const;
		const char* GetVehicleType() const = 0;
	};
}