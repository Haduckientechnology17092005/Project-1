#include <iostream>
#include <vector>
using namespace std;

const int N = 8; // K�ch thu?c b�n c?

// Bi?u di?n b�n c?
vector<vector<int>> board(N, vector<int>(N, 0));

// H�m ki?m tra xem qu�n h?u t?i v? tr� (row, col) c� ki?m so�t � (x, y) hay kh�ng
bool controlsSquare(int row, int col, int x, int y) {
    // Ki?m tra h�ng ngang
    if (x == row) return true;
    
    // Ki?m tra c?t d?c
    if (y == col) return true;
    
    // Ki?m tra du?ng ch�o
    if (abs(row - x) == abs(col - y)) return true;
    
    return false;
}

// H�m quay lui d? d?t 5 qu�n h?u
bool solveNQueens(int col, vector<pair<int, int>> &positions) {
    // N?u d� d?t xong 5 qu�n h?u, ki?m tra xem ch�ng c� ki?m so�t t?t c? c�c � kh�ng
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
                if (!controlled) return false; // N?u c� � kh�ng du?c ki?m so�t, tr? v? false
            }
        }
        return true; // N?u t?t c? c�c � d?u du?c ki?m so�t, tr? v? true
    }

    // Th? d?t qu�n h?u t?i c�c h�ng c?a c?t hi?n t?i
    for (int row = 0; row < N; row++) {
        bool safe = true;
        // Ki?m tra xem c� th? d?t qu�n h?u t?i v? tr� (row, col) hay kh�ng
        for (const auto &pos : positions) {
            if (controlsSquare(row, col, pos.first, pos.second)) {
                safe = false;
                break;
            }
        }
        if (safe) {
            positions.emplace_back(row, col); // �?t qu�n h?u
            if (solveNQueens(col + 1, positions)) return true; // N?u c� th? d?t xong 5 qu�n h?u, tr? v? true
            positions.pop_back(); // Backtrack
        }
    }
    return false; // Kh�ng t�m du?c l?i gi?i
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
