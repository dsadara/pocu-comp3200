#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina::DeusExMachina()
		: mCurrVehiclesIndex(0)
		, mRemainRestTimes{-1, }
		, mTravelDistance{-1, }
	{
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina* deus = new DeusExMachina();

		//deus->mCurrVehiclesIndex = 0;
		return deus;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mCurrVehiclesIndex; i++)
		{

		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mCurrVehiclesIndex >= 10)
		{
			return false;
		}
		mVehicles[mCurrVehiclesIndex] = vehicle;
		mRemainRestTimes[mCurrVehiclesIndex] = 0;
		mTravelDistance[mCurrVehiclesIndex] = 0;
		mCurrVehiclesIndex++;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mCurrVehiclesIndex)
		{
			return false;
		}

		delete mVehicles[i];
		for (unsigned int j = i; j < mCurrVehiclesIndex - 1; j++)
		{
			mVehicles[j] = mVehicles[j + 1];
		}
		for (unsigned int j = i; j < mCurrVehiclesIndex - 1; j++)
		{
			mRemainRestTimes[j] = mRemainRestTimes[j + 1];
		}
		for (unsigned int j = i; j < mCurrVehiclesIndex - 1; j++)
		{
			mTravelDistance[j] = mTravelDistance[j + 1];
		}

		mCurrVehiclesIndex--;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}
}