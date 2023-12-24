#include<iostream>
using namespace std;

char matrix[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int coloumn;
char token = 'X';
bool tie = false;
string n1;
string n2;

void board(void) {
    cout << "       |       |      " << endl;
    cout << "   " << matrix[0][0] << "   |" << "   " << matrix[0][1] << "   |" << "   " << matrix[0][2] << endl;
    cout << "       |       |      " << endl;
    cout << "-----------------------" << endl;
    cout << "       |       |      " << endl;
    cout << "   " << matrix[1][0] << "   |" << "   " << matrix[1][1] << "   |" << "   " << matrix[1][2] << endl;
    cout << "       |       |      " << endl;
    cout << "-----------------------" << endl;
    cout << "       |       |      " << endl;
    cout << "   " << matrix[2][0] << "   |" << "   " << matrix[2][1] << "   |" << "   " << matrix[2][2] << endl;
    cout << "       |       |      " << endl;
}

void placement(void) {
    int digit;
    cout << (token == 'X' ? n1 : n2) << ", please enter position : ";
    cin >> digit;
    cin.ignore();  // Consume the newline character

    if (digit == 1) {
        row = 0;
        coloumn = 0;
    } else if (digit == 2) {
        row = 0;
        coloumn = 1;
    } else if (digit == 3) {
        row = 0;
        coloumn = 2;
    } else if (digit == 4) {
        row = 1;
        coloumn = 0;
    } else if (digit == 5) {
        row = 1;
        coloumn = 1;
    } else if (digit == 6) {
        row = 1;
        coloumn = 2;
    } else if (digit == 7) {
        row = 2;
        coloumn = 0;
    } else if (digit == 8) {
        row = 2;
        coloumn = 1;
    } else if (digit == 9) {
        row = 2;
        coloumn = 2;
    } else {
        cout << "INVALID POSITION " << endl;
        return;
    }

    if (matrix[row][coloumn] != 'X' && matrix[row][coloumn] != 'O') {
        matrix[row][coloumn] = token;
        token = (token == 'X' ? 'O' : 'X');
    } else {
        cout << "Position already occupied. Choose another position." << endl;
        placement();
    }
}

bool win(void) {
    for (int i = 0; i < 3; i++) {
        if ((matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) || (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])) {
            return true;
        }
    }

    if ((matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) || (matrix[0][2] == matrix[1][1] && matrix[2][0] == matrix[1][1])) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O') {
                return false;
            }
        }
    }

    tie = true;
    return true;
}

int main() {
    cout << "Enter name of First Player : ";
    getline(cin, n1);
    cout << endl;

    cout << "Enter name of Second Player : ";
    getline(cin, n2);
    cout << endl;

    cout << n1 << " is 1st Player So he/she will play first. " << endl;
    cout << n2 << " is 2nd Player So he/she will play second. " << endl << endl << endl;

    while (true) {
        board();
        placement();
        if (win()) {
            break;
        }
    }

    if (token == 'X' && !tie) {
        cout << n2 << " WINS!!" << endl;
    } else if (token == 'O' && !tie) {
        cout << n1 << " WINS!!" << endl;
    } else {
        cout << "IT IS A DRAW " << endl;
    }

    return 0;
}
