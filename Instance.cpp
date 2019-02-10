#include <iostream>
#include <windows.h>
#include <sstream>
#include <cstdlib> 
#include <ctime> 
#include <conio.h>
#include <chrono>
#include <thread>
#include "Instance.h"
void Instance::Header()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "\t\t\t        _____ _   _______  _____ _   _______ _____ _   ___   _ \n" <<
		"\t\t\t       /  ___| | | | ___ \\/  ___| | | |  _  \\  _  | | / / | | | \n" <<
		"\t\t\t       \\ `--.| | | | |_/ /\\ `--.| | | | | | | | | | |/ /| | | | \n" <<
		"\t\t\t        `--. \\ | | |  __/  `--. \\ | | | | | | | | |    \\| | | | \n" <<
		"\t\t\t       /\\__/ / |_| | |    /\\__/ / |_| | |/ /\\ \\_/ / |\\  \\ |_| | \n" <<
		"\t\t\t       \\____/ \\___/\\_|    \\____/ \\___/|___/  \\___/\\_| \\_/\\___/ \n" <<
		"\t " << std::endl;

	SetConsoleTextAttribute(hConsole, 15);

}
void Instance::Menu()

{
	bool val = true;
	int Choice;

	while (val)
	{
		system("cls");
		Instance().Header();
		int f = 0;
		std::cout << "Select a Difficulty: \n\t0: Easy Level\n\t1: Medium Level\n\t2: Hard Level" << std::endl;
		std::cin >> Choice;
		switch (Choice)
		{
		case 0:
			val = false;
			Board().Generation(f = 1);

			break;

		case 1:
			val = false;
			Board().Generation(f = 2);

			break;

		case 2:
			val = false;
			Board().Generation(f = 3);

			break;

		default:
			std::cout << "Please enter a valid input.\nPress any key to continue." << std::endl;
			_getch();
			continue;
		}
	}
}

void Board::Generation(int f)
{
	system("cls");
	Instance().Header();
	srand(time(NULL));
	int t = 0;
	if (f == 1) {
		Board().Algo(t = 3);
	}
	else if (f == 2) {
		Board().Algo(t = 40);
	}
	else if (f == 3) {
		Board().Algo(t = 50);
	}

}

void Board::Algo(int t)
{
	int l;
	int n;
	int c;
	bool nul = false;
	bool x = false;
	bool r = false;
	int v = 0;
	int h = 0;
	int f = 0;
	int board[9][9];
	int verif[9];
	std::string verif2[50];
	std::string verif3[50];
	int trous = t;
	int o = 0;
	int g = 0;
	int complet = 0;
	std::string p;
	

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			x = false;
			for (int l = 0; l < 9; l++)
			{
				verif[l] = l + 1;
			}
			board[i][j] = (rand() % 9) + 1;
			while (x == false)
			{
				if (h == 9) {
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							board[i][j] = 0;
						}
					}
					i = 0;
					j = 0;
					x = true;
				}
				h = 0;

				r = false;
				
				for (int w = 0; w < 9; w++)
				{
					if (board[i][j] == board[i][w])
					{
						v++;
					}

					if (board[i][j] == board[w][j])
					{
						v++;
					}

					if (board[i][j] == board[(i / 3) * 3 + (w / 3)][(j / 3) * 3 + (w % 3)])
					{
						v++;
					}
				}

				if (v == 3)
				{
					x = true;
				}
				else
				{
					for (int n = 0; n < 9; n++)
					{
						if (board[i][j] == verif[n]) {
							verif[n] = 0;
						}
					}
					while (r == false) {
						board[i][j] = (rand() % 9) + 1;
						f = 0;
						for (int n = 0; n < 9; n++)
						{
							if (board[i][j] == verif[n]) {
								r = true;
							}
							else { f++; }
						}
						if (f == 9) {
							r = true;
						}
					}
				}
				for (int n = 0; n < 9; n++)
				{
					if (verif[n] == 0) {
						h++;
					}
				}
				v = 0;
			}

		}
	}
	for (int n = 0; n < 50; n++)
	{
		verif2[n] = "0";
		verif3[n] = "0";
	}

	for (int i = 0; i < trous; i++) {

		while (r == false) {
			f = 0;
			o = (rand() % 9);
			g = (rand() % 9);
			p = std::to_string(o) + std::to_string(g);
			for (int n = 0; n < 50; n++)
			{
				if (p == verif2[n]) {
					f=0;
				}
				else { f++; }

			}
			if (f == 50) {
				r = true;
			}
		}
		for (int n = 0; n < 50; n++)
		{
			if (verif3[n] == "0") {
				verif3[n] = std::to_string(board[o][g]) + p;
				break;
			}
		}
		board[o][g] = 0;
		for (int n = 0; n < trous; n++)
		{
			if (verif2[n] == "0") {
				verif2[n] = p;
				break;
			}
		}
		r = false;
	}

	v = 0;
	while (x == 1) {
		while (r == 0) {
			system("cls");
			complet = 0;
			Instance().Header();
			Board().Affichage(board);
			std::cout << "Choose a valid line in the box: " << std::endl;
			std::cin >> l;
			std::cout << "Choose a valid column in the box: " << std::endl;
			std::cin >> c;
			std::cout << "Choose a valid number to write: " << std::endl;
			std::cin >> n;
			if (board[l][c] == 0 &&  n <= 9) {
				board[l][c] = n;
				
				for (int o = 0; o < 50; o++)
				{
					if (verif3[o] == std::to_string(n)+ std::to_string(l)+ std::to_string(c)) {
					
						v++;
					}
				}
				r = 1;
			}
		}
		r = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != 0) {
					complet++;
				}
			}
		}
		if (complet == 81) {
			x = 0;
		}
	}
	system("cls");
	Instance().Header();
	Board().Affichage(board);
	if (v == trous) {
		std::cout << "### YOU WIN !" << std::endl;
	}
	else {
		std::cout << "Number of errors : " << trous - v << std::endl;
		std::cout << "### YOU LOOSE !" << std::endl;
	}
	std::cout << "Do you want to do another game?: \n\t0: Yes\n\t1: No" << std::endl;
	std::cin >> l;
	switch (l)
	{
	case 0:
		Instance().Menu();
		break;

	case 1:
		break;

	default:
		break;
	}

}
void Board::Affichage(int board[9][9])
{
	int indice[9];
	for (int l = 0; l < 9; l++)
	{
		indice[l] = l ;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == 8) {
			std::cout <<" "<< indice[i] << " "<< "\n";
		}
		else if (i == 2 || i == 5 ) {
			std::cout << " " << indice[i] << "  ";
		}
		else {
			std::cout << " " << indice[i] << " " ;
		}

	}
	for (int i = 0; i < 9; i++)
	{
		if (i == 3 || i == 6)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j == 0 && board[i][j] != 0) {
					std::cout << "\n[" << board[i][j] << "]";
				}
				else if (j == 2 && board[i][j] != 0  || j == 5 && board[i][j] != 0) {
					std::cout << "[" << board[i][j] << "] ";
				}
				else if (j == 8 && board[i][j] != 0) {
					std::cout << "[" << board[i][j] << "]\n";
				}
				else if (board[i][j] != 0) {
					std::cout << "[" << board[i][j] << "]";
				}
				else if (board[i][j] == 0) {
					if (j == 0) {
						std::cout << "\n[" << "." << "]";
					}
					else if (j == 2 || j == 5) {
						std::cout << "[" << "." << "] ";
					}
					else if (j == 8)
					{
						std::cout << "[" << "." << "]\n";
					}
					else {
						std::cout << "[" << "." << "]";
					}
				}
			}

		}
		else
		{
			for (int j = 0; j < 9; j++)
			{
				if (j == 2 && board[i][j] != 0  || j == 5 && board[i][j] != 0) {
					std::cout << "[" << board[i][j] << "] ";
				}
				else if (j == 8 && board[i][j] != 0)
				{
					std::cout << "[" << board[i][j] << "]\n";
				}
				else if (board[i][j] != 0) {
					std::cout << "[" << board[i][j] << "]";
				}
				else if (board[i][j] == 0) {
					if (j == 2 || j == 5) {
						std::cout << "[" << "." << "] ";
					}
					else if (j == 8)
					{
						std::cout << "[" << "." << "]\n";
					}
					else {
						std::cout << "[" << "." << "]";
					}
				}
			}
		}
	}

}




