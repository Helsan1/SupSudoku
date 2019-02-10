#pragma once

class Instance {
public:
	void Header();
	void Menu();
};

class Board {
public:
	void Generation(int f);
	void Algo(int t);
	void Affichage(int board[9][9]);
};
