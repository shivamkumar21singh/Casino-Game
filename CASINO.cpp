#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct Player
{
    string name;
    double balance;
    int chosenNumber;
    double betAmount;
};

void casino()
{
    cout<<"---------------------------------------------------------------------------\n";
    cout<<"\n\t\t\tWelcome to the Casino!\n";
    cout<<"---------------------------------------------------------------------------\n";
    cout<<"\t********  ********  ********  *********  *      *  ********"<<"\n";
    cout<<"\t*         *      *  *             *      * *    *  *      *"<<"\n";
    cout<<"\t*         ********  ********      *      *   *  *  *      *"<<"\n";
    cout<<"\t*         *      *         *      *      *    * *  *      *"<<"\n";
    cout<<"\t********  *      *  ********  *********  *      *  ********"<<"\n";
    cout<<"---------------------------------------------------------------------------\n";
    cout<<"---------------------------------------------------------------------------\n";
}

void rules()
{
    cout << "\n\n";
    cout << "\t\tRULES OF THE GAME\n";
    cout << "\t\t-----------------\n";
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
}

int main()
{
    const int numPlayers=5;
    const int minNumber=1;
    const int maxNumber=10;
    const double multiplier=10.0;

    Player players[numPlayers];

    casino();

    rules();

    for(int i=0; i<numPlayers; i++)
    {
        cout << "\tEnter name for player " << i + 1 << ": ";
        cin >> players[i].name;
        cout << "\tEnter initial balance for " << players[i].name << ": ";
        cin >> players[i].balance;
        cout<<"\n";
    }

    char choice;
    do
    {
        for(int i=0; i<numPlayers; i++)
        {
            cout << "\n\t" << players[i].name << ", choose a number between " << minNumber << " and " << maxNumber << ": ";
            cin >> players[i].chosenNumber;

            if(players[i].chosenNumber<0 || players[i].chosenNumber>10)
            {
                cout << "\t" << "Please check the number you have choosen!! should be between 1 to 10\n" << endl;
                i--;
            }

            cout << "\tEnter the bet amount for " << players[i].name << ": ";
            cin >> players[i].betAmount;
            cout<<"\n";

            if(players[i].betAmount>players[i].balance)
            {
                cout << "\t" << "Invalid bet amount! Please enter a value less than or equal to the current balance." << endl;
                i--;
            }
            else
            {
                players[i].balance -= players[i].betAmount;
            }
        }
        
        srand(static_cast<unsigned int>(time(0)));
        int generatedNumber=minNumber+rand()%(maxNumber-minNumber+1);

        cout << "\n\tThe generated number is: " << generatedNumber << endl;

        int numWinners=0;
        double totalPayout=0.0;
        for(int i=0; i<numPlayers; i++)
        {
            if(players[i].chosenNumber==generatedNumber)
            {
                numWinners++;
                double winnings = players[i].betAmount * multiplier;
                totalPayout += winnings;
                players[i].balance += winnings;
            }
        }
        cout << "\n\tWinners:\n";
        if (numWinners == 0)
        {
            cout << "\tNo winners!" << std::endl;
        }
        else
        {
            for(int i=0; i<numPlayers; i++)
            {
                if(players[i].chosenNumber == generatedNumber) {
                    cout << "\t" <<players[i].name << " won " << players[i].betAmount * multiplier << " with a balance of " << players[i].balance << endl;
                }
            }
            cout << "\t" <<"Total payout: " << totalPayout << endl;
        }

        cout << "\n\tRemaining balances:\n";
        for(int i=0; i<numPlayers; i++)
        {
            cout << "\t" << players[i].name << ": " << players[i].balance << std::endl;
        }

        cout<<"\n\n\t-->Do ypu want to play again (y/n): ";
        cin>>choice;
    }
    while(choice=='y' || choice=='Y');
    return 0;
}