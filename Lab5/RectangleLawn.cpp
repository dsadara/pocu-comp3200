#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		unsigned int perimeter = GetPerimeter();
		double result = static_cast<double>(perimeter) / 0.25;
		return static_cast<unsigned int>(result + 0.99);
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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

	unsigned int RectangleLawn::GetPerimeter() const
	{
		return 2u * mWidth + 2u * mHeight;
	}
}