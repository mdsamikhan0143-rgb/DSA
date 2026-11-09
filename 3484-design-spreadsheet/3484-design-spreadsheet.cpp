class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.resize(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        sheet[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        sheet[row][col] = 0;
    }

    int getValue(string formula) {
        formula = formula.substr(1);

        int pos = formula.find('+');

        string x = formula.substr(0, pos);
        string y = formula.substr(pos + 1);

        return getNumber(x) + getNumber(y);
    }

    int getNumber(string s) {
        if (isdigit(s[0])) {
            return stoi(s);
        }

        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;

        return sheet[row][col];
    }
};