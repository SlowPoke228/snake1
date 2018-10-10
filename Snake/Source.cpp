#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;
int xf = 5, yf = 5, px = 5, py = 5, tl = 3, vel[2] = { 0 }, tails[14][2] = { 0 };
char symbol;
bool GameOver = false;
void Lodgic() {
	if (xf == px && yf == py) { 
		yf = rand() % 16 + 1; 
		xf = rand() % 22 + 1;
		tl++;
	}
	px += vel[0];
	py -= vel[1];

	for (int m = 1; m <= tl; m++) {
		tails[m - 1][0] = tails[m + 1][0]; //В буффер из 2 ячеек вносим значения первого тейла
		tails[m - 1][1] = tails[m + 1][1];
		tails[m +1][0] = tails[m][0]; //Так же значение предыдущего
		tails[m +1][1] = tails[m][1];
		tails[m][0] = tails[m - 1][0];
		tails[m][1] = tails[m - 1][1];
	}
}
void Drow() {
	system("cls");
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 24; j++) {
			if (i==0||i==17||j==0||j==23) { cout << '#'; }			
			else if (i == py && j == px) { cout << 'O'; }
			else if (i == yf && j == xf) { cout << 'F'; }
			else {
				for (int z = 2; z < tl+2; z++) { if (tails[z][0] == j && tails[z][1] == i) { cout << 'o'; } }
				cout << " "; }
		}
		cout<< ' '<< endl;
	}

}
void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'w': {  vel[0] = { 0 }; vel[1] = { 1 }; break; }
		case 's': { vel[0] = { 0 }; vel[1] = { -1 }; break; }
		case 'a': { vel[0] = { -1 }; vel[1] = { 0 }; break; }
		case 'd': { vel[0] = { 1 }; vel[1] = { 0 }; break; }
		}
	}
}

int main() {
	tails[2][0] = px; tails[2][1] = py;
	while (GameOver != true)
	{
		Input();
		Lodgic();
		Drow();
		Sleep(1000);
	}
	return 0;
}