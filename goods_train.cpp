#include <iostream>
#include <string>
using namespace std;

/*
 * A goods train is a string of cars that must begin with one or two
 * engines (E).  These are followed by one or more trucks (T), which
 * are followed by one Guard Van (G).
 */
bool isGoodsTrain(string input) {
    int state = 0;
    int i;

    for (i = 0; i < input.size(); i++) {

        // skip over spaces
        if (input[i] == ' ') continue;

        switch(state) {
            case 0:
                // must start with E, otherwise not a goods train
                if (input[i] == 'E')
                    state = 1;
                else
                    return false;
                break;
            case 1:
                // may have another E or move to T's
                if (input[i] == 'E')
                    state = 2;
                else if (input[i] == 'T')
                    state = 3;
                else
                    return false;
                break;
            case 2:
                // now we start seeing sequence of T's
                if (input[i] == 'T')
                    state = 3;
                else
                    return false;
                break;
            case 3:
                // we either see T's or one final G
                if (input[i] == 'T')
                    ;
                else if (input[i] == 'G')
                    state = 4;
                else
                    return false;
                break;
            case 4:
                // we've seen a G and should not see anything else
                return false;
        }
    }
    
    // we accept if we're in state 4 and no characters remain in the input
    if (state == 4 && i == input.size())
        return true;
    else
        return false;
}

/*
 * Here's the output after testing the above function:
 *
 * Enter your goods trains: 
 *
 * > E E T T T T G
 * OK
 *
 * > E T G
 * OK
 *
 * > E G
 * not OK
 *
 * > E E E T G
 * not OK
 *
 * > E T T T
 * not OK
 *
 * > E E
 * not OK
 *
 * > T G
 * not OK
 *
 */
int main() {
    string input;
    cout << "Enter your goods trains: " << endl << endl << "> ";

    while (getline(cin, input)) {
        if (isGoodsTrain(input))
            cout << "OK";
        else 
            cout << "not OK";

        cout << endl << endl << "> ";
    }
}