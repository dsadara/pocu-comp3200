#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();
		unsigned int GetMaxSpeed() const = 0;
		unsigned int GetDriveSpeed() const = 0;
	};
}