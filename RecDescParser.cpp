/*
 * Author: Aman Wardak
 *
 * This is a recursive descent parser for the following language:
 * S -> aABa
 * A -> aaA | b
 * B -> bB | epsilon
 *
 * It is assumed the input strings have a '$' marker at the end.
 *
 * Some strings in the language: aba, abba, aaaba, aaabba
 *
 */
#include <iostream>
#include <string>
using namespace std;

/* token is always the next token in the input buffer */
char match(char token, char tokenToMatch) {
    if ( token == tokenToMatch )
        return cin.get();
    else
        throw -1;
}
char A(char token) {
    switch(token) {
        case 'a':
            cout << "2 ";
            token = match(token, 'a');
            token = match(token, 'a');
            token = A(token);
            break;
        case 'b':
            cout << "3 ";
            token = match(token, 'b');
            break;
        default:;
            throw -1;
    }
    return token;
}
char B(char token) {
    switch(token) {
        case 'b':
            cout << "4 ";
            token = match(token, 'b');
            token = B(token);
            break;
        default:
            /* this is the epsilon case */
            cout << "5 ";
    }
    return token;
}
char S(char token) {
    switch(token) {
        case 'a':
            cout << "1 ";
            token = match(token, 'a');
            token = A(token);
            token = B(token);
            token = match(token, 'a');
            break;
        default:
            throw -1;
    }
    return token;
}

int main() {
    char token;

    cout << "Enter some strings in the language:\n\n";

    cout << "> ";
    token = cin.get();
    while (cin) {
        try {
            token = S(token);

            /* if we have extra unmatched tokens remaining
             * in the input buffer, reject string */
            if (token != '$')
                cout << "error";
            else
                cout << "success";
        
        } catch (int exc) {
            /* if there was matching problem, reject */
            cout << "error";
        }

        /* clear input buffer and prepare for new string */
        cin.ignore(80, '\n');
        cout << "\n\n> ";
        token = cin.get();
    }
}