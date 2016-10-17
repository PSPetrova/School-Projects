#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <StringUtils.h>


using namespace std;

// Used as property separator for the dat files
static const char DELIMER = '&';

// The colors
enum Color { Red, Black, Blue, White, Green, Empty };

// File paths for the dat files
static const char* PROFILES_PATH = "players.dat";
static const char* CARDS_PATH = "cards.dat";
static const char* DECKS_PATH = "decks.dat";


// Converts Color to string. Red -> "Red"
const char* colorToString(Color color)
{
    switch (color)
    {
    case Red:
        return "Red";
    case Black:
        return "Black";
    case Blue:
        return "Blue";
    case White:
        return "White";
    case Green:
        return "Green";
    default:
        return "Empty";
    }
};

// Converts String to color. "Red" -> Red
Color stringToColor(const char* colorStr)
{
    if (equal(colorStr, "Red"))
    {
        return Red;
    }
    else if (equal(colorStr, "Black"))
    {
        return Black;
    }
    else if (equal(colorStr,"Blue"))
    {
        return Blue;
    }
    else if (equal(colorStr, "White"))
    {
        return White;
    }
    else if (equal(colorStr, "Green"))
    {
        return Green;
    }
    else
    {
        return Empty;
    }
};



// Class to represent player
class Player
{
private:
    const char* id;
    const char* name;

public:
    Player()
    {
        id = "";
        name = "";
    };
    Player(const char* id, const char* name)
    {
        this->id = id;
        this->name = name;
    };

    // Creates the player form data string
    Player(const char* dataString)
    {
        char** dataSplit=split(dataString,DELIMER);
        this->id = dataSplit[0];
        this->name = dataSplit[1];
    };

    const char* getName()
    {
        return name;
    };
    const char* getId()
    {
        return id;
    };
    void setId(const char* id)
    {
        this->id = id;
    }
    void setName(const char* name)
    {
        this->name = name;
    }
    void printInfo()
    {
        cout << "Name " << name << " ID " << id << endl;
    }

    void save()
    {
        ofstream outfile;
        outfile.open(PROFILES_PATH, ios_base::app);
        outfile<<id<<DELIMER<<name<<endl;
        outfile.close();
    }

};

// Class to represent Card
class Card
{
private:
    const char* id;
    const char* name;
    Color color;

public:
    Card()
    {
        id = "";
        name = "";
        color = Empty;
    }
    Card(const char* id, const char* name, Color color)
    {
        this->color = color;
        this->id = id;
        this->name = name;
    }
    Card(const char* dataString)
    {
        //1467565025&BlueDragon&Red
        char** dataSplit=split(dataString,DELIMER);
        this->id = dataSplit[0];
        this->name = dataSplit[1];
        this->color = stringToColor(dataSplit[2]);
    }

    void save()
    {
        ofstream outfile;
        outfile.open(CARDS_PATH, ios_base::app);
        outfile<<id<<DELIMER<<name<<DELIMER<<colorToString(color)<<endl;
        outfile.close();
    }
    const char* getId()
    {
        return id;
    }
    const char* getName()
    {
        return name;
    }
    Color getColor()
    {
        return color;
    }
};

// Class to represent Deck
class Deck
{
private:
    const char* cardNames;
    const char* ownerId;
    Color color;

public:
    Deck()
    {
        cardNames = "";
        ownerId = "";
        color = Empty;
    }
    Deck(const char* ownerId, const char* cardNames, Color color)
    {
        this->ownerId = ownerId;
        this->cardNames = cardNames;
        this->color = color;
    }
    Deck(const char* dataString)
    {
        char** dataSplit=split(dataString,DELIMER);
        this->ownerId = dataSplit[0];
        this->cardNames = dataSplit[1];
        this->color = stringToColor(dataSplit[2]);
    }
    void save()
    {
        ofstream outfile;
        outfile.open(DECKS_PATH, ios_base::app);
        outfile<<cardNames<<DELIMER<<ownerId<<DELIMER<<colorToString(color)<<endl;
        outfile.close();
    }

    const char* getOwnerId()
    {
        return ownerId;
    }
    const char* getCardNames()
    {
        return cardNames;
    }
    const char* getColorStr()
    {
        return colorToString(color);
    }
};

// This is the actual logic we provide
class Game
{
private:
    // Reads the card from file by id
    Card getCard(const char* id)
    {
        const char* cardsText = readFileToString(CARDS_PATH);
        char** lines = split(cardsText,'\n');
        int linesCount=countChars(cardsText,'\n')+1;

        for(int i=0; i<linesCount; i++)
        {
            Card card(lines[i]);
            if (equal(card.getId(),id))
            {
                return card;
            }
        }
        Card defaultResult;
        return defaultResult;
    }
    //Reads the card from file by name
    Card getCardByName(const char* name)
    {
        const char* cardsText = readFileToString(CARDS_PATH);
        char** lines = split(cardsText,'\n');
        int linesCount=countChars(cardsText,'\n')+1;

        for(int i=0; i<linesCount; i++)
        {
            if(lines[i]=='\0')
            {
                cout<<"End "<<endl;
            }
            else
            {
                Card card(lines[i]);
                if (equal(card.getName(),name))
                {
                    return card;
                }
            }
        }

        Card defaultResult;
        return defaultResult;
    }
    // Reads the Player from file by id
    Player getPlayer(const char* id)
    {
        Player defaultResult;

        const char* profilesText = readFileToString(PROFILES_PATH);
        char** lines = split(profilesText,'\n');
        int linesCount=countChars(profilesText,'\n')+1;
        for(int i=0; i<linesCount; i++)
        {
            Player player(lines[i]);
            if (equal(player.getId(),id))
            {
                defaultResult= player;
                break;
            }
        }

        return defaultResult;
    }

    //Reads the Player from file by name
    Player getPlayerByName(const char* name)
    {
        Player defaultResult;
        const char* profilesText = readFileToString(PROFILES_PATH);
        char** lines = split(profilesText,'\n');
        int linesCount=countChars(profilesText,'\n')+1;
        for(int i=0; i<linesCount; i++)
        {
            Player player(lines[i]);
            if (equal(player.getName(),name))
            {
                defaultResult= player;
                break;
            }
        }

        return defaultResult;
    }
    // Reads the Deck from file by id
    Deck getDeck(const char* ownerId)
    {
        Deck defaultResult;
        const char* decksText = readFileToString(DECKS_PATH);
        char** lines = split(decksText,'\n');
        int linesCount=countChars(decksText,'\n')+1;
        for(int i=0; i<linesCount; i++)
        {
            Deck deck(lines[i]);
            if (equal(deck.getOwnerId(),ownerId))
            {
                defaultResult=deck;
                break;
            }
        }

        return defaultResult;
    }


    // Prints the deck with the ids of data replaced by their names
    void printDeck(Deck deck)
    {
        Player owner = getPlayerByName(deck.getOwnerId());
        cout << "Owner: " << owner.getName() << " Cards: "<<deck.getCardNames();
        cout<< "   Deck's color: "<< deck.getColorStr()<<endl;;
    }

public:
    // Creates deck
    void createDeck(const char* ownerName, const char* cardNames)
    {
        Color color = Empty; // Find most common color TODO

        Deck deck(ownerName, cardNames, color);
        deck.save();
    }
    // Creates a player with ID current timestamp and saves it to file
    void createPlayer(const char* playerName)
    {
        Player player(convertIntToString(time(0)), playerName);
        player.save();
    }
    // Creates a Card with ID current timestamp and saves it to file
    void createCard(const char* name, const char* color)
    {
        Card card(convertIntToString(time(0)), name, stringToColor(color));
        card.save();
    }
    // Prints all defined deck using 'printDeck()'
    void printAllDecks()
    {
        const char* decks=readFileToString(DECKS_PATH);
        cout<<decks<<endl;

    }
};

int main1(int argc, char* argv[])
{
    Game game;
    // Parse input args
    if (argc <= 0)
    {
        return -1;
    }
    else
    {
        if (equal(argv[1] ,"cc"))
        {
            game.createCard(argv[2], argv[3]);                // program.exe cc Name_of_Card Color_of_Card
            cout << "Created Card" << endl;
        }
        else if (equal(argv[1], "cd"))
        {
            game.createDeck(argv[2], argv[3]);               //program.exe cd Name_of_Owner card1,card2,card3...
            cout << "Created Deck" << endl;
        }
        else if (equal(argv[1],"cp"))
        {
            game.createPlayer(argv[2]);                     //program.exe cp Name_of_Player
            cout << "Created player" << endl;
        }
        else if (equal(argv[1], "report"))
        {
            game.printAllDecks();                          //program.exe report
        }
        else
        {
            cout << "Unsuported command " <<argv[1]<< endl;
            return -1;
        }
    }

    return 0;
}

