#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

enum Masts
{
    MAST_TREFI,
    MAST_BUBNI,
    MAST_WORMS,
    MAST_PIKI,
    MAST_MAX
};

enum Types
{
    TYPES_2,
    TYPES_3,
    TYPES_4,
    TYPES_5,
    TYPES_6,
    TYPES_7,
    TYPES_8,
    TYPES_9,
    TYPES_10,
    TYPES_VALET,
    TYPES_DAMA,
    TYPES_KING,
    TYPES_TUZ,
    TYPES_MAX
};

struct Card
{
    Types Type;
    Masts Mast;
};

void printCard(const Card &card)
{
      switch(card.Type)
      {
          case TYPES_2:       std::cout << "2"; break;
          case TYPES_3:       std::cout << "3"; break;
          case TYPES_4:       std::cout << "4"; break;
          case TYPES_5:       std::cout << "5"; break;
          case TYPES_6:       std::cout << "6"; break;
          case TYPES_7:       std::cout << "7"; break;
          case TYPES_8:       std::cout << "8"; break;
          case TYPES_9:       std::cout << "9"; break;
          case TYPES_10:      std::cout << "t"; break;
          case TYPES_VALET:   std::cout << "V"; break;
          case TYPES_DAMA:    std::cout << "D"; break;
          case TYPES_KING:    std::cout << "K"; break;
          case TYPES_TUZ:     std::cout << "T"; break;
      }

      switch(card.Mast)
      {
          case MAST_TREFI:    std::cout << "TR"; break;
          case MAST_BUBNI:    std::cout << "B"; break;
          case MAST_WORMS:    std::cout << "CH"; break;
          case MAST_PIKI:     std::cout << "P"; break;
      }
}

void printDeck(const std::array<Card, 52> &deck)
{
    for(const auto &card: deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

Card swapCard(Card &card1, Card &card2)
{
    Card newcard;
    newcard = card1;
    card1 = card2;
    card2 = newcard;
}

int getRandomNumber(int min, int max);

void shufleDeck(std::array<Card, 52> &deck)
{
    for(int count = 0; count < 52; ++count)
    {
        int min = 0;
        int max = 51;
        swapCard(deck[count], deck[getRandomNumber(min, max)]);
    }
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int getCardValue(Card &card)
{
    switch(card.Type)
    {
        case TYPES_2: return 2;
        case TYPES_3: return 3;
        case TYPES_4: return 4;
        case TYPES_5: return 5;
        case TYPES_6: return 6;
        case TYPES_7: return 7;
        case TYPES_8: return 8;
        case TYPES_9: return 9;
        case TYPES_10: return 10;
        case TYPES_VALET: return 10;
        case TYPES_DAMA: return 10;
        case TYPES_KING: return 10;
        case TYPES_TUZ: return 10;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    std::array<Card, 52> deck;
    int card = 0;
        for(int count2 = 0; count2 < MAST_MAX; ++count2)
        {

            for(int count3 = 0; count3 < TYPES_MAX; ++count3)
            {
                deck[card].Mast = static_cast<Masts>(count2);
                deck[card].Type = static_cast<Types>(count3);
                ++card;
            }
        }

        printDeck(deck);

        shufleDeck(deck);

        printDeck(deck);

        std::cout << getCardValue(deck[11]) << '\n';

        return 0;
}