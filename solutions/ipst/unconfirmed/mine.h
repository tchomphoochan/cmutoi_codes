#ifndef __MINE_H_
#define __MINE_H_

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

namespace TOI_Mine
{
	using namespace std;
	typedef pair<int,int> Point;
	vector<Point> mines;
	int A;

	bool init = false;
	int numCalls = 0;

	void report(bool correct)
	{
		if(correct)
		{
			cout << "Mines cleared!" << endl;
			cout << "#calls to probe() : " << numCalls << endl;
		}
		else
			cout << "Incorrect interaction!" << endl;

		exit(0);
	}

#define TOI_assertBetween(x, lo, hi) assert((lo) <= (x) && (x) <= (hi))
};

int initialize()
{
	using namespace std;
	if(TOI_Mine::init) // already initialized
		TOI_Mine::report(false);

	int numMines;
	cin >> TOI_Mine::A >> numMines;
	TOI_Mine::mines.resize(numMines);

	TOI_assertBetween(TOI_Mine::A, 1, 1000000);
	TOI_assertBetween(numMines, 1, 1000);

	for(int i = 0; i < numMines; i++)
	{
		int x, y;
		cin >> x >> y;
		TOI_assertBetween(x, 1, TOI_Mine::A);
		TOI_assertBetween(y, 1, TOI_Mine::A);
		TOI_Mine::mines[i] = TOI_Mine::Point(x,y);
	}
	TOI_Mine::init = true;

	return TOI_Mine::A;
}

int probe(int x, int y)
{
	using namespace std;
	if(!TOI_Mine::init) // not yet initialized
		TOI_Mine::report(false);

	if(x < 1 || x > TOI_Mine::A || y < 1 || y > TOI_Mine::A)
		TOI_Mine::report(false);

	TOI_Mine::numCalls++;

	int pos = -1;
	int dist = 1e9; // inf
	int sz = TOI_Mine::mines.size();

	for(int i = 0; i < sz; i++)
	{
		TOI_Mine::Point p = TOI_Mine::mines[i];
		int dist1 = max(abs(p.first - x), abs(p.second - y));
		dist = min(dist, dist1);
		if(dist1 == 0)
			pos = i;
	}

	if(dist == 0)
	{
		--sz;
		if(pos < sz)
			swap(TOI_Mine::mines[pos], TOI_Mine::mines[sz]);
		TOI_Mine::mines.pop_back();

		if(sz == 0)
			TOI_Mine::report(true);
	}
	return dist;
}


#undef TOI_assertBetween

#endif //__MINE_H_