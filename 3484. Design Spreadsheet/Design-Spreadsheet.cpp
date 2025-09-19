class Spreadsheet {
public:
    unordered_map<string, int> sheet;
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) { sheet[cell] = value; }

    void resetCell(string cell) { sheet[cell] = 0; }

    int getValue(string formula) {
        int plus = formula.find('+');
        string first = formula.substr(1, plus - 1);
        string second = formula.substr(plus + 1);

        int val1 = 0;
        int val2 = 0;

        if (isalpha(first[0]))
            val1 = sheet[first];
        else
            val1 = stoi(first);
        if (isalpha(second[0]))
            val2 = sheet[second];
        else
            val2 = stoi(second);

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */