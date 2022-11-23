#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <graphics.h>
#include <algorithm>
#include <random>
using namespace std;
/* ������� ���� Solitaire*/


class Field {
public: 
	/* ���������� �����, ����� �����, ��� ������� �������; ����� ���������� ���, ��� ���� ����������;
	default ����� ������ �� ����� �����������*/
	virtual ~Field() = default; 

	/* size of field */
	Field(int Sx, int Sy) {

	}
	/* ��� ������� 10 �����, �� ���� ������������ ������ */
private:

};
/* ����� ������ 10 ������, � ������ ��� ������ ���������� 
����� ������������ ���� ��� ����, ����� ���, ��������, ����� �� ��� �������, ���� ��, �� ��� �����������
���� �� ������ � ��������� */

struct Coords {
	int x, y;
};

enum Rangs {
	two, three, four, five, six, seven, eight, nine, ten,
	jack, queen, king, ace,
};

enum Suits {
	hearts,
	diamonds, // ����
	clubs, // ������
	spades, // ����
};

/* ����� �������� ����� (���-�� � ����������, ����� ���� ����� �����?)*/
class Card {
public:
	Card(Rangs rang, Suits suit) {
		this->rang = rang;
		this->suit = suit; /* ��� �� ����������� ���������� �� ������������ �������� �� �������, ����� � ������� ������ suit_ */
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

	/* ����� ��� ����� ����� ����� �� ������ � ���������, ������ �� ������ */
	/* ��� ����� ��������� �� ������� � ��������� ����� */

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

/* ��� ������� �������� ����, � ��� ������, ����� ��������� ������ ������ */
class Solitaire {
public:
	virtual ~Solitaire() = default;
	virtual bool CheckMove(
		const Card& source, const Card& dest /* source - ��� �� �����, ������� �� ������ �����; dest - �� �����, �� ������� �� ����� �������� source */
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
/* ���� ������ ������� �������, �� ��� ����� ����� �������� ������ ��� ���, ������� ������� ����������� */

// � ��� ��� ������� ��� �����? � ���� �� � ����� ����� ����� ��������� ����� �� ������
/* drow (x,y � ��� ��������)
�� ���� ����� � ��������� �,� �������� ����� � ����� ������� �����, ������ ��� ��� �� �����*/


int main() {
	return 0;
}