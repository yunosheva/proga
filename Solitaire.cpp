#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <graphics.h>
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
private:

};

struct Coords {
	int x, y;
};

/* ����� �������� ����� (���-�� � ����������, ����� ���� ����� �����?)*/
class Card {
public:
	virtual ~Card() = default;
	
private:

};

enum Suits {
	hearts,
	diamonds, // ����
	clubs, // ������
    spades, // ����
};

enum Rangs {
	two, three, four, five, six, seven, eight, nine, ten,
	jack, queen, king, ace,
};

class Deck {
public:
	virtual ~Deck() = default; 
	std::vector <Card*> cards;
	/* ��� ����� ��������� �� ������� � ��������� ����� */
private:

};

/* ��� ������� �������� ����, � ��� ������, ����� ��������� ������ ������ */
class Solitaire {
public:
	virtual ~Solitaire() = default;
	virtual bool CheckMove(
		Card* source, Card* dest /* source - ��� �� �����, ������� �� ������ �����; dest - �� �����, �� ������� �� ����� �������� source */
	); 
	if (source.rang + 1 = dest.rang)
	    return true
	else false
	
private:

};


class Spider : public Solitaire {

};
/* ���� ������ ������� �������, �� ��� ����� ����� �������� ������ ��� ���, ������� ������� ����������� */

// � ��� ��� ������� ��� �����? � ���� �� � ����� ����� ����� ��������� ����� �� ������
/* drow (x,y � ��� ��������)
�� ���� ����� � ��������� �,� �������� ����� � ����� ������� �����, ������ ��� ��� �� �����*/


int main() {
	return 0;
}