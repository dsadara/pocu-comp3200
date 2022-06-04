#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		double result = 3.14 * static_cast<double>(mRadius) * static_cast<double>(mRadius);
		return static_cast<unsigned int>(result + 0.5);
	}

}