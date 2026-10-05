#include <iostream>
using namespace std;

string PlayerName;
int Score;

enum Fields {WRD, HINT, NUM_FIELDS};
string wordsHints[3][NUM_FIELDS]
{
    {"Mouse","its a small animal that cats hunt."},
    {"Hipopotamus","its a big animal that lives in mud."},
    {"Skyline","its a car with the nickname godzilla"}
};

int main()
{
    std::cout << "Hello World!\n";
    cin >> PlayerName;
    cout << "Hi " << PlayerName << endl;
    string guess = "";
    while (guess != "end game")
    {
        srand(static_cast<unsigned int>(time(0)));
        int value = (rand() % 3);
        string wrd = wordsHints[value][WRD];
        string hint = wordsHints[value][HINT];

        string s = wrd;
        int length = (int)s.size();

        for (int i = 0; i < length; i++)
        {
            int a = (rand() % length);
            int b = (rand() % length);
            
            char tmp = s[a];
            s[a] = s[b];
            s[b] = tmp;
        }
        while (guess != wrd)
        {
            cout << s << endl;
            cin >> guess;
            if (guess == "hint")
            {
                cout << hint << endl;
            }
            else if (guess != wrd)
            {
                cout << "not the word" << endl;
            }
        }
        guess = "";
        Score++;
        cout << "You guessed it " << "Score: " << Score << endl;
    }
}