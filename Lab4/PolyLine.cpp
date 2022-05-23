#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCurrPointIndex(0)
		, mPoints()
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		// PolyLine의 복사생성자

		// 기존 Point 삭제
		for (size_t i = 0; i < mCurrPointIndex; i++)
		{
			delete mPoints[i];
		}
		mCurrPointIndex = 0;
		// Point 깊은 복사
		for (size_t i = 0; i < other.mCurrPointIndex; i++)
		{
			AddPoint(mPoints[i]);
		}
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mCurrPointIndex; i++)
		{
			delete mPoints[i];
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCurrPointIndex >= 10)
		{
			return false;
		}

		mPoints[mCurrPointIndex] = new Point(x, y);
		mCurrPointIndex++;
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCurrPointIndex >= 10)
		{
			return false;
		}
		mPoints[mCurrPointIndex] = new Point(point->GetX(), point->GetY());	// point의 복사 생성자를 이용하는게 좋을까?
		mCurrPointIndex++;
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCurrPointIndex)
		{
			return false;
		}

		delete mPoints[i];

		for (size_t j = i; j < mCurrPointIndex; j++)
		{
			mPoints[j] = mPoints[j + 1];
		}

		mCurrPointIndex--;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		// point가 두개 이상이여야 직사각형이 성립
		if (mCurrPointIndex < 2)
		{
			return false;
		}

		float minX = mPoints[0]->GetX();
		float minY = mPoints[0]->GetY();
		float maxX = mPoints[0]->GetX();
		float maxY = mPoints[0]->GetY();

		// find min x, y max x, y by one pass
		float currX;
		float currY;
		for (size_t i = 0; i < mCurrPointIndex; i++)
		{
			currX = mPoints[i]->GetX();
			currY = mPoints[i]->GetY();
			if (minX > currX)
			{
				minX = currX;
			}
			if (maxX < currX)
			{
				maxX = currX;
			}
			if (minY > currY)
			{
				minY = currY;
			}
			if (maxY < currY)
			{
				maxY = currY;
			}
		}

		outMin->SetX(minX);
		outMin->SetY(minY);
		outMax->SetX(maxX);
		outMax->SetY(maxY);

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mCurrPointIndex)
		{
			return nullptr;
		}

		return new Point(mPoints[i]->GetX(), mPoints[i]->GetY());
	}
}