#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
public:
    vector<vector<int>> grid;

    Spreadsheet(int rows) { 
        grid.resize(rows, vector<int>(26, 0));  // respect rows argument
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getCellValue(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return grid[row][col];
    }

    int parseToken(const string& token) {
        if (isalpha(token[0])) { 
            return getCellValue(token);
        }
        return stoi(token);
    }

    int getValue(string formula) {
        // remove '=' if formula starts with it
        if (formula[0] == '=') formula = formula.substr(1);

        int ans = 0;
        stringstream ss(formula);
        string token;
        while (getline(ss, token, '+')) {
            ans += parseToken(token);
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
