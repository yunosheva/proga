#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <graphics.h>
#include <algorithm>
#include <random>
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
	/* тут создать 10 колод, из дека использовать колоду */
private:

};
/* нужно задать 10 стопок, в классе это просто переменная 
нужно сформировать один код игры, задаю ход, проверяю, можно ли его сделать, если да, то все обновляется
пока не думать о отрисовке */

struct Coords {
	int x, y;
};

enum Rangs {
	two, three, four, five, six, seven, eight, nine, ten,
	jack, queen, king, ace,
};

enum Suits {
	hearts,
	diamonds, // буби
	clubs, // крести
	spades, // пики
};

/* какие возможны карты (что-то я запуталась, зачем этот класс нужен?)*/
class Card {
public:
	Card(Rangs rang, Suits suit) {
		this->rang = rang;
		this->suit = suit; /* тут он присваивает переменной из конструктора значение из привата, лучше в привате писать suit_ */
	}

	virtual ~Card() = default;

	Rangs GetRang() const {
		return rang;
	}
	Suits GetSuit() const {
		return suit;
	}
private:
	Rangs rang;
	Suits suit;
};


class Deck {
public:
	Deck() {}
	virtual ~Deck() = default;

	void PutInDeck(Card card) {
		cards.push_back(card);
	}

	void Shuffle() {
		std::shuffle(std::begin(cards), std::end(cards), std::default_random_engine());
	}

	Card GetCard() {
		Card c = cards.front();
		cards.erase(cards.begin());
		return c;
	}

	bool IsEmpty () const {
		return cards.empty();
	}

	/* нужно еще метод взять карту из колоды и проверять, пустая ли колода */
	/* еще можно разделить на видимые и невидимые карты */

private:
	std::vector <Card> cards;
};

class DeckFactory {
public:
	std::vector<Deck> CreateSingleSuit(Suits suit = hearts) {
		Deck mega_deck; 
		for (int i = 0; i < 8; ++i) {
			for (int r = two; r <= ace; ++r) {
				Card c((Rangs)r, suit);
				mega_deck.PutInDeck(c);
			}
		}
		mega_deck.Shuffle();
		vector<Deck> result(15);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 6; j++) {
				result[i].PutInDeck(mega_deck.GetCard());
			}
		}

		return result;
	}

	std::vector<Deck> CreateDoubleSuit()
	{
		return {};
	}
	std::vector<Deck> CreateFourSuit()
	{
		return {};
	}
private:
};

class Table {
	virtual ~Table() = default;
	//vector <Deck*> decks(10);

};

/* for each (deck)
deck.render*/

/* тут правила движения карт, и что делать, когда собралась полная колода */
class Solitaire {
public:
	virtual ~Solitaire() = default;
	virtual bool CheckMove(
		const Card& source, const Card& dest /* source - это та карта, которую мы сейчас взяли; dest - та карта, на которую мы хотим положить source */
	) {
		if (source.rang + 1 = dest.rang)
			return true;
		return false;
	}
private:

};

/*
class Spider : public Solitaire {

};
/* если захочу сменить правила, то мне нужно будет изменить только чек мув, поэтому функция виртуальная */

// а как мне двигать мои карты? у меня же в любое место может двигаться карта за мышкой
/* drow (x,y и что рисовать)
по сути нужно в положение х,у положить карту и потом движать карту, короче это еще не скоро*/


int main() {
	return 0;
}