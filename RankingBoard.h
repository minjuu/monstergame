#ifndef __RANKING_BOARD_H__
#define __RANKING_BOARD_H__

#include <iostream>
#include <fstream>
#include "FileException.h"
using namespace std;
#define NUM_MVP 5 // 최대 랭킹 기록 수

struct PlayInfo
{						// 게임 정보 클래스
	string name;		// 게이머의 이름
	int nItem;			// 획득한 아이템의 수
	double itemPerMove; // 이동 거리당 아이템 수
	PlayInfo(string na = "NewPlayer", int ni = 0, double ipm = 0.0) // 등록 기록이 없을 경우의 초기 값을 입력
		: name(na), nItem(ni), itemPerMove(ipm) {}
};

class RankingBoard
{ // 랭킹 관리 클래스
	string filename;
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;

public:
	RankingBoard(string filename) : filename(filename) {}

	// 주어진 파일의 데이터를 읽어온다. 파일이 없는 경우 예외 처리를 한다.
	void load()
	{
		string str;
		string s[15];
		int cnt = 0;

		ifstream is;//파일 데이터 읽어오기
		is.open(filename);

		if (is.is_open() == false)// 파일 없는 경우 예외 처리
		{
			FileException e(filename, false);
			throw e;
		}
		else
		{
			while (!is.eof() && cnt < 15)
			{
				getline(is, s[cnt]);
				cnt++;
			}
			for (int i = 0; i < nMVP; i++)//파일 이름 전달
			{
				MVP[i].name = s[3 * i];
			}

			for (int i = 0; i < nMVP; i++)//파일 아이템수 전달
			{
				MVP[i].nItem = atoi(s[3 * i + 1].c_str());
			}
			for (int i = 0; i < nMVP; i++)//파일 이동거리당아이템수 전달
			{
				MVP[i].itemPerMove = stod(s[3 * i + 2]);
			}
		}
	}

	// 랭킹 리스트를 저장한다.
	void store()
	{
		ofstream os;
		os.open(filename);
		for (int i = 0; i < nMVP; i++)
		{
			os << MVP[i].name << endl;
			os << MVP[i].nItem << endl;
			os << MVP[i].itemPerMove << endl;
		}
		os.close();

	}

	// 랭킹 리스트를 1위부터 순서대로 출력한다.
	void print(string title = "Game Ranking")
	{		
		cout <<endl<< title << endl;
		cout << endl;
		for (int i = 0; i < nMVP; i++)
		{
			cout << "[Rank " << i + 1 << "] " << MVP[i].name << "            " << MVP[i].nItem << "     " << MVP[i].itemPerMove << endl;
				
		}
		cerr << endl
			<< " Press [ENTER] key..."<<endl;
		getchar();

	}

	// 게임이 끝난 후 플레이어의 기록을 입력한다.
	// nItem : 아이템 획득 수, ipm : 이동거리당 아이템 획득 비율 (아이템 획득 수 / 총 이동 거리)
	// 입력시 현재 기록과 비교하여 5위 이내인 경우 기록을 위한 이름을 받는다.
	void add(int nItem, double ipm)
	{
		string name;
		int temp1;
		string temp2;		
		double temp3;
				
		if (nItem > MVP[0].nItem)//1등
		{
			cout <<endl<< "[Rank 1] Insert name: ";
			cin >> name;
			cout << endl;
			for (int j = nMVP - 2; j >= 0; j--) {
						MVP[j + 1].nItem = MVP[j].nItem;
						MVP[j + 1].name = MVP[j].name;
						MVP[j + 1].itemPerMove = MVP[j].itemPerMove;
			}
			MVP[0].name = name;
			MVP[0].nItem = nItem;
			MVP[0].itemPerMove = ipm;
			
		}
		else if (nItem > MVP[1].nItem)//2등
		{
			cout << endl << "[Rank 2] Insert name: ";
			cin >> name;
			cout << endl;
			for (int j = nMVP - 2; j >= 1; j--) {
				MVP[j + 1].nItem = MVP[j].nItem;
				MVP[j + 1].name = MVP[j].name;
				MVP[j + 1].itemPerMove = MVP[j].itemPerMove;
			}
			MVP[1].name = name;
			MVP[1].nItem = nItem;
			MVP[1].itemPerMove = ipm;
		}
		else if (nItem > MVP[2].nItem)//3등
		{
			cout << endl << "[Rank 3] Insert name: ";
			cin >> name;
			cout << endl;
			for (int j = nMVP - 2; j >= 2; j--) {
				MVP[j + 1].nItem = MVP[j].nItem;
				MVP[j + 1].name = MVP[j].name;
				MVP[j + 1].itemPerMove = MVP[j].itemPerMove;
			}
			MVP[2].name = name;
			MVP[2].nItem = nItem;
			MVP[2].itemPerMove = ipm;
		}
		else if (nItem > MVP[3].nItem)//4등
		{
			cout << endl << "[Rank 4] Insert name: ";
			cin >> name;
			cout << endl;
			for (int j = nMVP - 2; j >= 3; j--) {
				MVP[j + 1].nItem = MVP[j].nItem;
				MVP[j + 1].name = MVP[j].name;
				MVP[j + 1].itemPerMove = MVP[j].itemPerMove;
			}
			MVP[3].name = name;
			MVP[3].nItem = nItem;
			MVP[3].itemPerMove = ipm;
		
		}
		else if (nItem > MVP[4].nItem)//5등
		{
			cout << endl << "[Rank 5] Insert name: ";
			cin >> name;
			cout << endl;

			MVP[4].name = name;
			MVP[4].nItem = nItem;
			MVP[4].itemPerMove = ipm;
		}
	}
};

#endif