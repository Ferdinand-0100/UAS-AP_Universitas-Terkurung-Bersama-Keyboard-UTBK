#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class lotreGosok {
    private:
        int step = 0;
        char board[4][5] = {
            {'*', '*', '*', '*', '*'},
            {'*', '*', '*', '*', '*'},
            {'*', '*', '*', '*', '*'},
            {'*', '*', '*', '*', '*'}
        };
        
        int data[4][5] = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
        };
        
        bool revealed[4][5] = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
        };
        
    public:
        void generateBoard() {
            srand(time(0));
            int r1 = rand() % 4, c1 = rand() % 5;
            int r2 = rand() % 4, c2 = rand() % 5;
            while (r1 == r2 && c1 == c2) {
                r2 = rand() % 4;
                c2 = rand() % 5;
            }
            data[r1][c1] = 1;
            data[r2][c2] = 1;
        }
        
        void displayBoard() {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 5; j++) cout << board[i][j] << " ";
                cout << endl;
            }
        }
        
        int guess(int row, int col) {
            if (data[row][col] == 1) {
                cout << "BOOM! Anda menemukan bom! Permainan berakhir." << endl;
                board[row][col] = 'X';
                displayBoard();
                return -1;
            }
            else {
                if (revealed[row][col]) cout << "Kotak telah dibuka sebelumnya!" << endl;
                else {
                    revealed[row][col] = true;
                    board[row][col] = '0';
                    step++;
                }
                cout << "Kotak Aman" << endl;
                return 0;
            }
        }
        
        bool isGameOver() {
            if (step == 18) {
                cout << "Selamat anda menang" << endl;
                displayBoard();
                return true;
            } return false;
        }
};

int main() {
    lotreGosok game;
    cout << "Welcome to E-Lottery Gosok" << endl;
    game.generateBoard();
    while (true) {
        game.displayBoard();
        cout << "Masukkan tebakan anda (baris dan kolom) : ";
        int r, c; cin >> r >> c;
        if (r >= 0 && c >= 0 && r <= 3 && c <= 4) {
            if (game.guess(r, c) == -1 || game.isGameOver()) break;
        }
        else cout << "Mohon input baris 0-3 dan kolom 0-4" << endl;
    }
}