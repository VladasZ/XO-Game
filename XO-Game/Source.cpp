//Крестики нолики

#include <iostream>
using namespace std;
#define HUMAN_MOVE 'X'
#define BOT_MOVE 'O'
#define EMPTY '-'
#define GO_ON 1
#define DRAW 2
#define WINNER_HUMAN 3
#define WINNER_BOT 4
char YN = ' ';
int xCount = 0;
int oCount = 0;
int drawCount = 0;
int moveCount = 0;
char currentMove = HUMAN_MOVE;
char a[3][3] = { EMPTY, EMPTY, EMPTY,
EMPTY, EMPTY, EMPTY,
EMPTY, EMPTY, EMPTY };
char *p_a = &a[0][0];
int gameStat = GO_ON;


void main();
void newGame();

void startGame(){


	cout << "First move? +/-" << endl;


	while (YN != '+' && YN != '-'){

		cin >> YN;

		if (YN == '+')
			currentMove = HUMAN_MOVE;
		if (YN == '-')
			currentMove = BOT_MOVE;
		else
			cout << "only + or - !" << endl;
	}

	YN = ' ';

}

void display(){
	system("cls");
	for (int line = 2; line > -1; line--){
		for (int column = 0; column < 3; column++){
			cout << a[line][column];
		}
		cout << endl;
	}
}

void newGame(){
	cout << endl;
	cout << "Play again?? +/-" << endl;

	while (YN != '+' && YN != '-'){

		cin >> YN;

		if (YN == '+'){

			for (int line = 0; line < 3; line++){
				for (int column = 0; column < 3; column++){
					a[line][column] = '-';
				}
			}

			system("cls"); YN = ' '; gameStat = GO_ON; moveCount = 0;

			main();

		}


		if (YN == '-')
			exit(0);

		else
			cout << "only Y or N!" << endl;

	}
}

void humanMove(){

	int x, y;

	do{
		cout << endl << "You turn" << endl;
		cin >> x;
		//cin >> y;

		// Начать новую игру не закончив текущую игру
		/*
		if (x == 'n'){
		for (int line = 0; line < 3; line++){
		for (int column = 0; column < 3; column++){
		a[line][column] = '-';
		}
		}

		system("cls");
		YN = ' ';
		gameStat = GO_ON;
		main();
		}
		*/

	} while (*(p_a + x - 1) != EMPTY);

	*(p_a + x - 1) = HUMAN_MOVE;

	moveCount++;

}

int botMove(){

	moveCount++;

	///////////////////////Победный ход в очевидных ситуациях/////////////////////////


	// Победа по линиям
	for (int line = 0; line < 3; line++){

		for (int i = 0; i < 3; i++){
			if (a[line][i] == BOT_MOVE)
				xCount++;
		}

		if (xCount == 2){
			for (int j = 0; j < 3; j++){
				if (a[line][j] == EMPTY){
					a[line][j] = BOT_MOVE;
					xCount = 0;
					return 0;
				}
			}
		}

		xCount = 0;
	}

	// Победа по колонкам
	for (int column = 0; column < 3; column++){

		for (int i = 0; i < 3; i++){
			if (a[i][column] == BOT_MOVE)
				xCount++;


			if (xCount == 2){
				for (int j = 0; j < 3; j++){
					if (a[j][column] == EMPTY){
						a[j][column] = BOT_MOVE;
						xCount = 0;
						return 0;
					}
				}
			}
		}
		xCount = 0;
	}

	//Победа по \ диагонали


	for (int i = 0; i < 3; i++){
		if (a[i][i] == BOT_MOVE)
			xCount++;
	}


	if (xCount == 2){
		for (int i = 0; i < 3; i++){
			if (a[i][i] == EMPTY){
				a[i][i] = BOT_MOVE;
				xCount = 0;
				return 0;
			}

		}
	}
	xCount = 0;

	//Победа по / диагонали
	for (int i = 0; i < 3; i++){
		if (a[2 - i][i] == BOT_MOVE)
			xCount++;
	}


	if (xCount == 2){
		for (int i = 0; i < 3; i++){
			if (a[i][2 - i] == EMPTY){
				a[i][2 - i] = BOT_MOVE;
				xCount = 0;
				return 0;
			}
		}
	}
	xCount = 0;

	///////////////////////Контр ходы против игрока/////////////////////////

	// Контрит х по линиям
	for (int line = 0; line < 3; line++){

		for (int i = 0; i < 3; i++){
			if (a[line][i] == HUMAN_MOVE)
				xCount++;
		}

		if (xCount == 2){
			for (int j = 0; j < 3; j++){
				if (a[line][j] == EMPTY){
					a[line][j] = BOT_MOVE;
					xCount = 0;
					return 0;
				}
			}
		}

		xCount = 0;
	}


	// Контрит х по колонкам
	for (int column = 0; column < 3; column++){

		for (int i = 0; i < 3; i++){
			if (a[i][column] == HUMAN_MOVE)
				xCount++;


			if (xCount == 2){
				for (int j = 0; j < 3; j++){
					if (a[j][column] == EMPTY){
						a[j][column] = BOT_MOVE;
						xCount = 0;
						return 0;
					}
				}
			}
		}
		xCount = 0;
	}


	//Контрит х по \ диагонали

	// НЕ НУЖНО

	/*
	for (int i = 0; i < 3; i++){
	if (a[i][i] == HUMAN_MOVE)
	xCount++;
	}


	if (xCount == 2){
	for (int i = 0; i < 3; i++){
	if (a[i][i] == EMPTY){
	a[i][i] = BOT_MOVE;
	xCount = 0;
	return 0;
	}

	}
	}
	xCount = 0;
	*/


	//Контрит х по / диагонали
	for (int i = 0; i < 3; i++){
		if (a[2 - i][i] == HUMAN_MOVE)
			xCount++;
	}


	if (xCount == 2){
		for (int i = 0; i < 3; i++){
			if (a[i][2 - i] == EMPTY){
				a[i][2 - i] = BOT_MOVE;
				xCount = 0;
				return 0;
			}
		}
	}
	xCount = 0;




	///////////////////////Ходы в наиболее выгодные свободные клетки в остальных случаях/////////////////////////

	// Ходит в центр если он свободен

	if (a[1][1] == '-'){
		a[1][1] = BOT_MOVE;
		return 0;
	}

	// Ходит по углам если они свободны

	if (a[0][0] == '-'){
		a[0][0] = BOT_MOVE;
		return 0;
	}
	if (a[2][2] == '-'){
		a[2][2] = BOT_MOVE;
		return 0;
	}
	if (a[2][0] == '-'){
		a[2][0] = BOT_MOVE;
		return 0;
	}
	if (a[0][2] == '-'){
		a[0][2] = BOT_MOVE;
		return 0;
	}

	// Ходит в остальные клетки

	if (a[0][1] == '-'){
		a[0][1] = BOT_MOVE;
		return 0;
	}
	if (a[1][2] == '-'){
		a[1][2] = BOT_MOVE;
		return 0;
	}
	if (a[1][0] == '-'){
		a[1][0] = BOT_MOVE;
		return 0;
	}
	if (a[2][1] == '-'){
		a[2][1] = BOT_MOVE;
		return 0;
	}

	return 0;

}

void drawCheck(){

	// Проверяем возможность выйграть по линиям

	for (int line = 0; line < 3; line++){
		for (int column = 0; column < 3; column++){

			if (a[line][column] == HUMAN_MOVE)
				xCount++;
			if (a[line][column] == BOT_MOVE)
				oCount++;
		}
		if (xCount != 0 && oCount != 0){
			drawCount++;
			xCount = 0;
			oCount = 0;
		}
	}

	//Проверяем возможность выйграть по колонкам

	for (int line = 0; line < 3; line++){
		for (int column = 0; column < 3; column++){

			if (a[column][line] == HUMAN_MOVE)
				xCount++;
			if (a[column][line] == BOT_MOVE)
				oCount++;
		}

		if (xCount != 0 && oCount != 0){
			drawCount++;
			xCount = 0;
			oCount = 0;

		}
	}

	//Проверяет возможность выйграть по \ диагонали

	for (int line = 0; line < 3; line++){

		if (a[line][line] == HUMAN_MOVE)
			xCount++;
		if (a[line][line] == BOT_MOVE)
			oCount++;
	}

	if (xCount != 0 && oCount != 0){
		drawCount++;
		xCount = 0;
		oCount = 0;
	}

	//Проверяет возможность выйграть по / диагонали

	for (int line = 0; line < 3; line++){

		if (a[line][2 - line] == HUMAN_MOVE)
			xCount++;
		if (a[line][2 - line] == BOT_MOVE)
			oCount++;
	}

	if (xCount != 0 && oCount != 0){
		drawCount++;
		xCount = 0;
		oCount = 0;
	}

	//Если все 8 возможных выйгрышных линии имеют одновременно и Х и О то возвращает ничью

	if (drawCount == 8)
		gameStat = DRAW;

	// Очистка переменных

	drawCount = 0;

	xCount = 0;
}

int winLoseDrawCheck(){

	//проверяем строки
	for (int i = 0; i < 3; i++){
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2]){
			if (a[i][0] == HUMAN_MOVE)
				return WINNER_HUMAN;
			else if (a[i][0] == BOT_MOVE)
				return WINNER_BOT;
		}
	}

	// проверяем столбцы
	for (int i = 0; i < 3; i++){
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i]){
			if (a[0][i] == HUMAN_MOVE)
				return WINNER_HUMAN;
			else if (a[0][i] == BOT_MOVE)
				return WINNER_BOT;
		}
	}

	// проверяем диагонали
	if ((a[0][0] == a[1][1] && a[1][1] == a[2][2]) || (
		a[0][2] == a[1][1] && a[1][1] == a[2][0])){
		if (a[1][1] == HUMAN_MOVE)
			return WINNER_HUMAN;
		else if (a[1][1] == BOT_MOVE)
			return WINNER_BOT;
	}

	// ничья
	drawCheck();
	if (gameStat == DRAW)
		return DRAW;

	// продолжаем играть
	return GO_ON;
}

void movesControl(){

	// Смена ходов между игроками
	do{

		display();

		if (currentMove == HUMAN_MOVE){
			humanMove();
			currentMove = BOT_MOVE;
		}

		else{
			botMove();
			currentMove = HUMAN_MOVE;
		}

		gameStat = winLoseDrawCheck();
		display();



		// Возвращяет ничью в ситуация непонятных для drawCheck()

		// на 8мом ходе
		if (moveCount == 8 && currentMove == HUMAN_MOVE){

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					if (a[i][j] == EMPTY)
						a[i][j] = HUMAN_MOVE;
				}
			}
			//gameStat = DRAW;
			gameStat = winLoseDrawCheck();
		}

		// на 7мом ходе
		if (moveCount == 7 && currentMove == HUMAN_MOVE && a[1][1] == BOT_MOVE){

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					if (a[i][j] == EMPTY)
						a[i][j] = HUMAN_MOVE;
				}
			}
			//gameStat = DRAW;
			gameStat = winLoseDrawCheck();
		}

		// Отображение результатов игры

		switch (gameStat)
		{
		case DRAW: cout << "Draw" << endl; break;
		case WINNER_HUMAN: cout << endl << "You win!" << endl; break;
		case WINNER_BOT: cout << endl << "Bot win" << endl; break;
		}
	} while (gameStat == GO_ON);



}





void main(){

	startGame();

	movesControl();

	newGame();

}
