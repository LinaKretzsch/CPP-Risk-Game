#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H 1

#pragma once

#include "../GameObservers/GameObservers.h"
#include "../Cards/Cards.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"
#include "../Orders/Orders.h"
#include "../PlayerStrategies/PlayerStrategies.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
#include <windows.h>

class Player;

using namespace std;

class GameEngine : public Subject
{
public:

	//******     Constructor & Destructor    *****//
	GameEngine();
	GameEngine(const GameEngine&);//All functions for Gamestart here with parameters
	~GameEngine();
	GameEngine& operator=(const GameEngine&);
	friend ostream& operator<<(ostream& strm, GameEngine& gameEngine);
	string to_string();

	//******     PART I    *****//
	void gameStart();


	//******     Map Methods    *****//
	void loadMap();
	string selectMap();
	bool isMapInDirectory(string fileName);
	shared_ptr<Map> getMap();
	vector<string> findMapNames();

	//******     Oberserver Methods    *****//
	void Observers();
	bool getObserverStatus(int);
	void setObserverStatus(int, bool);
	bool equals(const string& a, const string& b);


	//******     Deck Method    *****//
	Deck* getDeck();


	//******     Player Methods    *****//
	void addPlayers(shared_ptr<Player> player);
	vector<shared_ptr <Player>> getPlayers();
	shared_ptr<Player> getPlayer(unsigned int id);
	string getPlayersInfo();
	string getPlayersNames();
	

	//******     PART II    *****//
	void startupPhase();

	//shared_ptr<GameEngine> createEngine();

	void mainGameLoop();
	void reinforcementsPhase();
	int findContinentBonusTotal(shared_ptr<Player> player);
	void issueOrdersPhase();
	bool atleastOneOfType(string type);
	void executeOrdersPhase();
	void checkForEliminatedPlayers();
	shared_ptr<Player> checkForWinner();
	shared_ptr<Player> checkForLeader();
	void reassignTerritories();


	//******     Private Members    *****//
private:
	int numOfPlayers;
	Deck* deck;
	shared_ptr<Map> map;
	vector<shared_ptr<Player>> players;
	string mapFilePath;

	bool phaseObserver;
	bool mapObserver;
};

#endif