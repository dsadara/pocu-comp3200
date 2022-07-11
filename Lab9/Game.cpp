#include "Game.h"

namespace lab9
{
	Game::Game(unsigned int seed, unsigned int poolSize)
		: mObjectPool(poolSize)
	{
		srand(seed);
	}

	Game::~Game()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end(); ++it)
		{
			//delete (*it);
			mObjectPool.Return(*it);	// mObject�� �˾Ƽ� ��ü�� ������ �������ִϱ� �� �Ѱܹ��� 
		}

		mActiveGameObjects.clear();
	}

	void Game::Spawn()
	{
		/*IceCube* iceCube = new IceCube();
		iceCube->Initialize(rand() % MAX_FRAME_COUNT_TO_LIVE + 1);
		mActiveGameObjects.push_back(iceCube);*/

		IceCube* iceCube = mObjectPool.Get();
		iceCube->Initialize(rand() % MAX_FRAME_COUNT_TO_LIVE + 1);
		mActiveGameObjects.push_back(iceCube);

	}

	void Game::Update()
	{
		//for (int i = 0; i < mObjectPool.GetFreeObjectCount(); i++)
		//{
		//	IceCube* iceCube = mObjectPool.Get();
		//	iceCube->Animate();

		//	if (!iceCube->IsActive())
		//	{
		//		delete iceCube;
		//		continue;
		//	}

		//	mObjectPool.Return(iceCube);
		//}

		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end();)
		{
			IceCube* iceCube = *it;
			iceCube->Animate();

			if (!iceCube->IsActive())
			{
				mObjectPool.Return(iceCube);
				it = mActiveGameObjects.erase(it);
				continue;
			}
			++it;
		}
	}

	const std::vector<IceCube*>& Game::GetActiveGameObjects() const
	{
		return mActiveGameObjects;
	}

	ObjectPool<IceCube>& Game::GetObjectPool()
	{
		return mObjectPool;
	}
}
