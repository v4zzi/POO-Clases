//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//std::string PlayerName;
//int Score = 0;
//
//int main()
//{
//    std::vector<std::string> words;
//    words.push_back("COMPUTER");
//    words.push_back("MOUSE");
//    words.push_back("KEYBOARD");
//    words.push_back("WOMAN");
//    words.push_back("PISTOL");
//    words.push_back("PEPPER");
//
//    std::cout << "Hello Player, what is your name?" << std::endl;
//    std::cin >> PlayerName;
//    std::cout << "Hello " << PlayerName << ", welcome to the Hangman game!" << std::endl;
//
//    srand(static_cast<unsigned int>(time(0)));
//    std::random_shuffle(words.begin(), words.end());
//
//    size_t currentWordIndex = 0;
//    bool keepPlaying = true;
//
//    while (keepPlaying && currentWordIndex < words.size())
//    {
//        const std::string theWord = words[currentWordIndex];
//        std::string wordToGuess(theWord.size(), '_');
//        std::string used = "";
//
//        std::cout << "\n--- NEXT WORD ---" << std::endl;
//        std::cout << wordToGuess << "\n";
//
//        while (wordToGuess != theWord)
//        {
//            std::cout << "Guess a letter: ";
//            char letterToGuess;
//            std::cin >> letterToGuess;
//            letterToGuess = std::toupper(letterToGuess);
//
//            if (theWord.find(letterToGuess) != std::string::npos)
//            {
//                for (size_t i = 0; i < theWord.size(); ++i)
//                {
//                    if (theWord[i] == letterToGuess)
//                    {
//                        wordToGuess[i] = letterToGuess;
//                    }
//                }
//                std::cout << "Current word: " << wordToGuess << std::endl;
//            }
//            else
//            {
//                if (used.find(letterToGuess) == std::string::npos)
//                {
//                    used += letterToGuess;
//                }
//                else
//                {
//                    std::cout << "You already used that letter. Try again." << std::endl;
//                }
//                std::cout << "Used letters: " << used << std::endl;
//            }
//        }
//
//        std::cout << "\nCongratulations " << PlayerName << ", you guessed the word!" << std::endl;
//        std::cout << "The word was: " << theWord << std::endl;
//        Score++;
//        std::cout << "Your score is: " << Score << std::endl;
//
//        currentWordIndex++;
//
//        if (currentWordIndex < words.size())
//        {
//            std::cout << "Do you want to play the next word? (y/n): ";
//            char response;
//            std::cin >> response;
//            if (std::tolower(response) != 'y')
//            {
//                keepPlaying = false;
//            }
//        }
//        else
//        {
//            std::cout << "Wow! You have guessed all the available words!" << std::endl;
//        }
//    }
//
//    std::cout << "\nThanks for playing, " << PlayerName << "! Your final score is: " << Score << std::endl;
//    return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>

void Instructions();
void DisplayBoard(const std::vector<char>* board);

char PlayerPiece();
char CPUPiece(char piece);

int MovePlayer(std::vector<char> board);
int MoveCPU(std::vector<char>& board, char piece);

char Winner(std::vector<char> board);

bool IsEmpty(int pos, const std::vector<char>* board);

const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const char TIE = 'T';
const char NOTIE = 'N';
const char NUM_SPACE = 9;


int main()
{
	Instructions();
	std::vector<char> board(NUM_SPACE, EMPTY);
	DisplayBoard(&board);
	char human = PlayerPiece();
	char CPU = CPUPiece(human);
	char turn = X;

	std::cout << "You are " << human << " and the CPU is " << CPU << std::endl;
	DisplayBoard(&board);

	while (Winner(board) == NOTIE)
	{
		if (turn == human)
		{
			std::cout << "Your turn." << std::endl;
			board[MovePlayer(board)] = human;
			DisplayBoard(&board);
		}
		else
		{
			std::cout << "CPU's turn." << std::endl;
			board[MoveCPU(board, CPU)] = CPU;
			DisplayBoard(&board);
		}
		if (turn == X)
		{
			turn = O;
		}
		else
		{
			turn = X;
		}
	}
	
	

}

void Instructions()
{
	std::cout << "Welcome to Tic Tac Toe!" << std::endl;
}

void DisplayBoard(const std::vector<char>* board)
{
	std::cout << std::endl;
	std::cout << "-------"<< std::endl;
	std::cout << "|" << (*board)[0] << "|" << (*board)[1] << "|" << (*board)[2] << "|" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "|" << (*board)[3] << "|" << (*board)[4] << "|" << (*board)[5] << "|" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "|" << (*board)[6] << "|" << (*board)[7] << "|" << (*board)[8] << "|" << std::endl;
	std::cout << "-------" << std::endl;

}

char PlayerPiece()
{
	char answer;
	std::cout << "Do you want to go first? (y/n): " << std::endl;
	std::cin >> answer;

	if(answer == 'y' || answer == 'Y')
	{
		std::cout << "You are X and will go first." << std::endl;
		return X;
	}
	else
	{
		std::cout << "You are O and will go second." << std::endl;
		return O;
	}
}

char CPUPiece(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

int MovePlayer(std::vector<char> board)
{
	int move;
	std::cout << "Enter your move (0-8): " << std::endl;
	std::cin >> move;
	while (IsEmpty(move, &board) == false)
	{
		std::cout << "That space is already taken. Try again: " << std::endl;
		std::cin >> move;
	}

	return move;
}

int MoveCPU(std::vector<char>& board, char piece)
{
	std::vector<char> tempBoard = board;
	const char opponentPiece = (piece == 'X') ? 'O' : 'X';

	static const int bestMoves[9] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
	int i = 0;
	int move = 0;
	bool foundMove = false;

	while(foundMove == false && move < board.size())
	{
		if (IsEmpty(move, &board))
		{
			board[move] = opponentPiece;
			foundMove = (Winner(board) == opponentPiece);
			board[move] = EMPTY;
		}
		if (!foundMove)
		move++;
	}

	while (!foundMove && move < board.size())
	{
		if (IsEmpty(move, &board))
		{
			board[move] = piece;
			foundMove = (Winner(board) == piece);
			board[move] = EMPTY;
		}
		if (!foundMove)
		move++;
	}
	if (!foundMove)
	{
		move = 0;

		while (i < board.size())
		{
			int move = bestMoves[i];
			if (IsEmpty(move, &board))
			{
				return move;
			}
			i++;
		}
	}
		return move;
}

char Winner(std::vector<char> board)
{
	const int WINNING_COMBOS[8][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6}
	};
	for(int i = 0; i < 8; i++)
	{
		if ((board)[WINNING_COMBOS[i][0]] != EMPTY &&
			(board)[WINNING_COMBOS[i][0]] == (board)[WINNING_COMBOS[i][1]] &&
			(board)[WINNING_COMBOS[i][1]] == (board)[WINNING_COMBOS[i][2]])
			return (board)[WINNING_COMBOS[i][0]];
	}
	if(std::count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	else
		return NOTIE;
}

bool IsEmpty(int pos, const std::vector<char>* board)
{
	return ((*board)[pos] == EMPTY);
}