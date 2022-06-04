#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int width)
		: RectangleLawn(width, width)
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		return RectangleLawn::GetArea();
	}

	SquareLawn::~SquareLawn()
	{
		// delete 넣어야 되나?
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return RectangleLawn::GetMinimumFencesCount();
	}
	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return RectangleLawn::GetFencePrice(fenceType);
	}

	unsigned int SquareLawn::GetPerimeter() const
	{
		return RectangleLawn::GetPerimeter();
	}

}