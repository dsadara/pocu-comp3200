#pragma once
#include <cmath>
#include "Vehicle.h"
#include "IDivable.h"
#include "ISailable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		~UBoat();
		unsigned int GetDiveSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;
	};
}