#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <graphics.h>
using namespace std;
/* пасьянс паук */


class Field {
public: 
	virtual ~Field() = default; /* это вроде деструктор, че за дефолт? вроде же нужен, чтобы
								у наследников вызывался свой деструктор?*/

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

/* тут правила движения карт, и что делать, когда собралась полная колода */
class MoveCards {
public:
	virtual ~MoveCards() = default;

private:

};




int main() {
	return 0;
}