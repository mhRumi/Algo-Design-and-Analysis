#include <iostream>
#include <string>
#include <stdlib.h>
#include <new>

using namespace std;

int main()
{
    string *states, *final, *trap, **transition,input, tmp;

    char *alf, temp;
    int nos, nots, nofs, noa, i, j, current, flag;

    cout << "This is a program to simulate a DFA" << endl;
    cout << "Enter the number of states, number of final states and"
         << " the number of trap states.\n";

    cin >> nos >> nofs >> nots;
    cout << "Enter the number of symbols in the alphabet:\n";
    cin >> noa;

    states = new string[nos];
    final = new string[nofs];
    trap = new string[nots];
    alf = new char[noa+1];

    for (i = 'a'; i <'a'+nos; i++)
          states[i] = char(i);

    final[0] = 'd'

    cout << "Enter the trap states:\n";

    for (i = 0; i < nots; i++)
        cin >> trap[i];

    cout << "Enter the alphabet for the DFA:\n";

    for (i = 0; i < noa; i++)
        cin >> alf[i];
    //allocating space for the transition table

    transition = new string *[nos];

    for (i = 0; i < nos; i++)
        transition[i] = new string[noa];
    //getting the values for the transition table

    cout << "Enter the transition for the given states:";

    for (i = 0; i < nos; i++)
    {
        cout << "\nFor state " << states[i] << endl;
        for (j = 0; j < noa; j++)
        {
            cout << "On input " << alf[j] << " to state : ";
            cin >> transition[i][j];
        }
    }

    cout << "The transition table you entered is :\n";
    cout << "state\t";

    for (i = 0; i < noa; i++)
        cout << alf[i] << "\t";

    for (i = 0; i < nos; i++)
    {
        cout << endl << states[i] << "\t";
        for (j = 0; j < noa; j++)
            cout << transition[i][j] << "\t";
    }

    while (true)
    {
        current = 0, flag = 0;// current will keep track of the current state
        cout << "\nEnter the input string( enter exit to terminate) : ";
        cin >> input;
        if (input.compare("exit") == 0)
            exit(0);

        for (i = 0; i < input.length(); i++)
        {
            // process the string and change the state accordingly
            temp = input.at(i);
            // getting the index of the input from the alphabet set
            for (j = 0; j < noa; j++)
            {
                if (alf[j] == temp)
                {
                    break;
                }
            }
            // storing the value of transition state
            tmp = transition[current][j];
            // changing the current state to the next state
            for (int k = 0; k < nos; k++)
                if (states[k].compare(tmp) == 0)
                {
                    current = k;
                    break;
                }
            // loop for checking if a the dfa is in a trap state
            for (j = 0; j < nots; j++)

                if (states[current].compare(trap[j]) == 0)
                {
                    cout << "The input string has been rejected";
                    flag = 1;
                    break;
                }

            if (flag == 1)
                break;
        }

        if (flag == 1)
            continue;

        for (i = 0; i < nofs; i++)
            if (states[current].compare(final[i]) == 0)
            {
                cout << "The input has been accepted by the DFA";
                flag = 1;
                break;
            }

        if (flag == 1)
            cout << "The input has been rejected by the DFA";

    }

    return 0;

}
