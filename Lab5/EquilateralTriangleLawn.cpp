#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int side)
		: mSide(side)
	{

	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{

	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		double result = sqrt(3.0) / 4.0 * static_cast<double>(mSide) * static_cast<double>(mSide);
		return static_cast<unsigned int>(result + 0.5);
	}
	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		unsigned int perimeter = GetPerimeter();
		double result = static_cast<double>(perimeter) / 0.25;
		return static_cast<unsigned int>(result + 0.99);
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int perimeter = GetPerimeter();
		double result = 0.0;
		switch (fenceType)
		{
		case RED_CEDAR:
			result = static_cast<double>(perimeter) * 6.0;
			break;
		case SPRUCE:
			result = static_cast<double>(perimeter) * 7.0;
			break;
		default:
			break;
		}
		return static_cast<unsigned int>(result);
	}

	unsigned int EquilateralTriangleLawn::GetPerimeter() const
	{
		return 3 * mSide;
	}
}