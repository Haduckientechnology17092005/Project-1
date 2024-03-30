#include <iostream>
#include <vector>
using namespace std;

const int N = 8; // Kích thu?c bàn c?

// Bi?u di?n bàn c?
vector<vector<int>> board(N, vector<int>(N, 0));

// Hàm ki?m tra xem quân h?u t?i v? trí (row, col) có ki?m soát ô (x, y) hay không
bool controlsSquare(int row, int col, int x, int y) {
    // Ki?m tra hàng ngang
    if (x == row) return true;
    
    // Ki?m tra c?t d?c
    if (y == col) return true;
    
    // Ki?m tra du?ng chéo
    if (abs(row - x) == abs(col - y)) return true;
    
    return false;
}

// Hàm quay lui d? d?t 5 quân h?u
bool solveNQueens(int col, vector<pair<int, int>> &positions) {
    // N?u dã d?t xong 5 quân h?u, ki?m tra xem chúng có ki?m soát t?t c? các ô không
    if (col == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bool controlled = false;
                for (const auto &pos : positions) {
                    if (controlsSquare(pos.first, pos.second, i, j)) {
                        controlled = true;
                        break;
                    }
                }
                if (!controlled) return false; // N?u có ô không du?c ki?m soát, tr? v? false
            }
        }
        return true; // N?u t?t c? các ô d?u du?c ki?m soát, tr? v? true
    }

    // Th? d?t quân h?u t?i các hàng c?a c?t hi?n t?i
    for (int row = 0; row < N; row++) {
        bool safe = true;
        // Ki?m tra xem có th? d?t quân h?u t?i v? trí (row, col) hay không
        for (const auto &pos : positions) {
            if (controlsSquare(row, col, pos.first, pos.second)) {
                safe = false;
                break;
            }
        }
        if (safe) {
            positions.emplace_back(row, col); // Ð?t quân h?u
            if (solveNQueens(col + 1, positions)) return true; // N?u có th? d?t xong 5 quân h?u, tr? v? true
            positions.pop_back(); // Backtrack
        }
    }
    return false; // Không tìm du?c l?i gi?i
}

int main() {
    vector<pair<int, int>> positions;
    if (solveNQueens(0, positions)) {
        cout << "Mot loi giai voi 5 quan hau: " << endl;
        for (const auto &pos : positions) {
            board[pos.first][pos.second] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Khong tim duoc loi giai voi 5 quan hau." << endl;
    }
    return 0;
}
