#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <graphics.h>
using namespace std;
/* ������� ���� */


class Field {
public: 
	virtual ~Field() = default; /* ��� ����� ����������, �� �� ������? ����� �� �����, �����
								� ����������� ��������� ���� ����������?*/

private:

};

class Cards {
public:
	virtual ~Cards() = default;

private:

};

class Deck {
public:
	virtual ~Deck() = default; 

private:

};

/* ��� ������� �������� ����, � ��� ������, ����� ��������� ������ ������ */
class MoveCards {
public:
	virtual ~MoveCards() = default;

private:

};




int main() {
	return 0;
}