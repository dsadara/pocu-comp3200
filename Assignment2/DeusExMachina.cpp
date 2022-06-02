#include "DeusExMachina.h"

namespace assignment2
{
	int DeusExMachina::mRemainRestTimes[10] = { 0 };
	int DeusExMachina::mRemainTravelTime[10] = { 0 };
	unsigned int DeusExMachina::mTravelDistance[10] = { 0 };

	DeusExMachina::DeusExMachina()
		: mCurrVehiclesIndex(0)
		, mVehicles{ nullptr, }
	{
		/*for (int i = 0; i < 10; i++)
		{
			mRemainRestTimes[i] = -1;
		}
		for (int i = 0; i < 10; i++)
		{
			mRemainTravelTime[i] = -1;
		}
		for (int i = 0; i < 10; i++)
		{
			mTravelDistance[i] = -1;
		}*/
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina* deus = new DeusExMachina();
		//deus->mCurrVehiclesIndex = 0;
		return deus;
	}

	void DeusExMachina::Travel() const
	{
		char vehicleType = 0;
		for (unsigned int i = 0; i < mCurrVehiclesIndex; i++)
		{
			vehicleType = mVehicles[i]->GetVehicleType();
			switch (vehicleType)
			{
			case 'A':
				if (mRemainRestTimes[i] == 0)
				{
					mTravelDistance[i] += mVehicles[i]->GetMaxSpeed();
					mRemainRestTimes[i] += 3;
				}
				else
				{
					mRemainRestTimes[i]--;
				}
				break;
			case 'B':
				if (mRemainTravelTime[i] == 0)
				{
					mRemainTravelTime[i] += 2;
				}
				else
				{
					mRemainTravelTime[i]--;
					mTravelDistance[i] += mVehicles[i]->GetMaxSpeed();
				}
				break;
			case 'P':
				if (mRemainRestTimes[i] == 0)
				{
					mTravelDistance[i] += mVehicles[i]->GetMaxSpeed();
					mRemainRestTimes[i] += 3;
				}
				else
				{
					mRemainRestTimes[i]--;
				}
				break;
			case 'M':
				if (mRemainTravelTime[i] == 0)
				{
					mRemainTravelTime[i] += 5;
				}
				else
				{
					mRemainTravelTime[i]--;
					mTravelDistance[i] += mVehicles[i]->GetMaxSpeed();
				}
				break;
			case 'S':
				// 세단이 연결되어 있는지 어케 알지
				if (mVehicles[i]->IsTrailerConnected())
				{
					if (mRemainTravelTime[i] == 0)
					{
						mRemainTravelTime[i] += 5;
						//mRemainRestTimes[i] += 2;
						mRemainRestTimes[i] += 1;
					}
					else
					{
						if (mRemainRestTimes[i] == 0)
						{
							mRemainTravelTime[i]--;
							mTravelDistance[i] += mVehicles[i]->GetMaxSpeed();
						}
						else
						{
							mRemainRestTimes[i]--;
						}
					}
				}
				else
				{
					if (mRemainTravelTime[i] == 0)
					{
						mRemainTravelTime[i] += 5;
					}
					else
					{
						mRemainTravelTime[i]--;
						mTravelDistance[i] += mVehicles[i]->GetMaxSpeed();
					}
				}
				break;
			case 'U':
				if (mRemainTravelTime[i] == 0)
				{
					mRemainTravelTime[i] += 2;
					/*mRemainRestTimes[i] += 4;*/
					mRemainRestTimes[i] += 3;
				}
				else
				{
					if (mRemainRestTimes[i] == 0)
					{
						mRemainTravelTime[i]--;
						mTravelDistance[i] += mVehicles[i]->GetMaxSpeed();
					}
					else
					{
						mRemainRestTimes[i]--;
					}
				}
				break;
			default:
				break;
			}
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
		/*mRemainTravelTime[mCurrVehiclesIndex] = 0;*/
		mTravelDistance[mCurrVehiclesIndex] = 0;

		char vehicleType = mVehicles[mCurrVehiclesIndex]->GetVehicleType();
		switch (vehicleType)
		{
		case 'A':
			mRemainTravelTime[mCurrVehiclesIndex] = 0;
			break;
		case 'B':
			mRemainTravelTime[mCurrVehiclesIndex] = 2;
			break;
		case 'P':
			mRemainTravelTime[mCurrVehiclesIndex] = 0;
			break;
		case 'M':
			mRemainTravelTime[mCurrVehiclesIndex] = 5;
			break;
		case 'S':
			mRemainTravelTime[mCurrVehiclesIndex] = 5;
			break;
		case 'U':
			mRemainTravelTime[mCurrVehiclesIndex] = 2;
			break;
		default:
			break;
		}

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
			mRemainTravelTime[j] = mRemainTravelTime[j + 1];
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
		if (mCurrVehiclesIndex == 0)
		{
			return NULL;
		}

		int maxTravelledIndex = 0;

		for (int i = 0; i < mCurrVehiclesIndex; i++)
		{
			if (mTravelDistance[i] > mTravelDistance[maxTravelledIndex])
			{
				maxTravelledIndex = i;
			}
		}

		return mVehicles[maxTravelledIndex];
	}

	void DeusExMachina::PrintTravelTimes()
	{
		for (int i = 0; i < mCurrVehiclesIndex; i++)
		{
			std::cout << i << ": " << mVehicles[i]->GetVehicleType() << ": " << mTravelDistance[i] << std::endl;
		}

		std::cout << "===Print END===" << std::endl;
	}
}