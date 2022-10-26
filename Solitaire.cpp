#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <graphics.h>
using namespace std;
/* пасьянс паук Solitaire*/


class Field {
public: 
	/* деструктор нужен, чтобы знать, как удалять объекты; нужно определять там, где есть наследники;
	default пушто ничего не нужно присваивать*/
	virtual ~Field() = default; 

	/* size of field */
	Field(int Sx, int Sy) {

	}
private:

};

struct Coords {
	int x, y;
};

/* какие возможны карты (что-то я запуталась, зачем этот класс нужен?)*/
class Card {
public:
	virtual ~Card() = default;
	
private:

};

enum Suits {
	hearts,
	diamonds, // буби
	clubs, // крести
    spades, // пики
};

enum Rangs {
	two, three, four, five, six, seven, eight, nine, ten,
	jack, queen, king, ace,
};

class Deck {
public:
	virtual ~Deck() = default; 
	std::vector <Card*> cards;
	/* еще можно разделить на видимые и невидимые карты */
private:

};

/* тут правила движения карт, и что делать, когда собралась полная колода */
class Solitaire {
public:
	virtual ~Solitaire() = default;
	virtual bool CheckMove(
		Card* source, Card* dest /* source - это та карта, которую мы сейчас взяли; dest - та карта, на которую мы хотим положить source */
	); 
	if (source.rang + 1 = dest.rang)
	    return true
	else false
	
private:

};


class Spider : public Solitaire {

};
/* если захочу сменить правила, то мне нужно будет изменить только чек мув, поэтому функция виртуальная */

// а как мне двигать мои карты? у меня же в любое место может двигаться карта за мышкой
/* drow (x,y и что рисовать)
по сути нужно в положение х,у положить карту и потом движать карту, короче это еще не скоро*/


int main() {
	return 0;
}