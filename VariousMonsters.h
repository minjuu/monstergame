#ifndef __VARIOUS_MONSTERS_H__
#define __VARIOUS_MONSTERS_H__

#include "Monster.h"

/*
 * 모든 몬스터는 이동 경로 사이에 존재하는 아이템은 획들 할 수 없다.
 * 오직 자신이 그 턴에 최종적으로 도착한 위치의 아이템만 획득 할 수 있다.
 */

// 몬스터의 기본 이동 동작을 따른다. (9가지 경우의 수 이동)
class Zombie : public Monster
{
public:
	Zombie(string n = "Zombie", string i = "Z", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie()
	{
		cout << " Zombie";
	}
};

// 가로 또는 세로로만 이동 한다 (4가지 경우의 수 이동)
class Vampire : public Monster
{
public:
	Vampire(string n = "Vampire", string i = "V", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(vector<vector<int> > &map, int maxx, int maxy)
	{
		if (nSleep == 0)
		{
			int random = rand() % 4;
			if (random == 0)//좌
			{
				p[0] -= 1;
				clip(32, 10);
				eat(map, true);
				q[0] = p[0];
				q[1] = p[1];
				
			}
			else if (random == 1)//우
			{
				p[0] += 1;
				clip(32, 10);
				eat(map, true);
				q[0] = p[0];
				q[1] = p[1];
				
			}
			else if (random == 2)//위
			{
				p[1] -= 1;
				clip(32, 10);
				eat(map, true);
				q[0] = p[0];
				q[1] = p[1];
				
			}
			else if (random == 3)//아래
			{
				p[1] += 1;
				clip(32, 10);
				eat(map, true);
				q[0] = p[0];
				q[1] = p[1];
				
			}
		}
		else
		{
			nSleep--;
			dist = 0;
		}
	}
	
};

// 순간이동을 할 수 있다. 매 이동턴 마다 화면 내의 랜덤한 한 지점으로 이동 한다. (제자리 포함)
class KGhost : public Monster
{
public:
	KGhost(string n = "KGhost", string i = "G", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(vector<vector<int> > &map, int maxx, int maxy)
	{
		if (nSleep == 0)
		{
			int xxx = rand() % 32;
			int yyy = rand() % 10;

			p[0] = xxx;
			p[1] = yyy;
			clip(32, 10);
			eat(map, true);
			q[0] = p[0];
			q[1] = p[1];
		}
		else
		{
			nSleep--;
			dist = 0;
		}
	}
};

// 가로 또는 세로 방향으로만 이동 할 수 있다.
// 한 칸 또는 두 칸을 이동 할 수 있다. (제자리에 머무를 수는 없다.)
class Jiangshi : public Monster
{
	bool bHori;

public:
	// bHori는 horizontal 이동 여부이다.
	// 이 값이 true 이면 가로방향으로만, false 이면 세로방향으로만 이동 할 수 있다.
	Jiangshi(string n = "Jiangshi", string i = "J", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(vector<vector<int> >& map, int maxx, int maxy)
	{
		if (nSleep == 0)
		{
			int rd = rand() % 2;
			int wh = rand() % 2;

			int rd1 = rand() % 2;
			int wh1 = rand() % 2;

			if (bHori == true)//가로방향
			{
				if (rd == 0)//1칸
				{
					if (wh == 0)//좌
					{
						p[0] -= 1;
						clip(32, 10);
						eat(map, true);
						q[0] = p[0];
						q[1] = p[1];
						
					}
					else//우
					{
						p[0] += 1;
						clip(32, 10);
						eat(map, true);
						q[0] = p[0];
						q[1] = p[1];
						
					}
				}
				else//2칸
				{
					if (wh == 0)//좌
					{
						p[0] -= 2;
						clip(32, 10);
						eat(map, true);
						q[0] = p[0];
						q[1] = p[1];
						
					}
					else//우
					{
						p[0] += 2;
						clip(32, 10);
						eat(map, true);
						q[0] = p[0];
						q[1] = p[1];
						
					}
				}

			}
			else if (bHori == false)//세로방향
			{
				if (rd1 == 0)//1칸
				{
					if (wh1 == 0)//위
					{
						p[1] -= 1;
						clip(32, 10);
						eat(map, true);
						q[0] = p[0];
						q[1] = p[1];
						
					}
					else//아래
					{
						p[1] += 1;
						clip(32, 10);
						eat(map, true);
						q[0] = p[0];
						q[1] = p[1];
						
					}
				}
				else//2칸
				{
					if (wh == 0)//위
					{
						p[1] -= 2;
						clip(32, 10);
						eat(map, true);
						q[0] = p[0];
						q[1] = p[1];
						
					}
					else//아래
					{
						p[1] += 2;
						clip(32, 10);
						eat(map, true);
						q[0] = p[0];
						q[1] = p[1];
						
					}
				}
			}
		}
		else
		{
			nSleep--;
			dist = 0;
		}
	}
};

#endif