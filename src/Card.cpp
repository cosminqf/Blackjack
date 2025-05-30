#include "Card.h"

Card::Card(int s, int val) : suit(s), value(val) {

}

Card::~Card() {

}

int Card::getSuit() const {
	return suit;
}

int Card::getValue() const {
	return value;
}

int Card::getBlackjackValue() const {
	if (value >= 10) {
    	return 10;
	}
	else if (value == 1) {
		return 11;
	}
	else {
		return value;
	}
}

std::string Card::suitToString() const {
	switch (suit) {
		case 0: return "Inima rosie";
        case 1: return "Romb";
        case 2: return "Trefla";
 		case 3: return "Frunza";
	}
}

std::string Card::valueToString() const {
	switch (value) {
		case 1:  return "As";
        case 2:  return "Doi";
        case 3:  return "Trei";
        case 4:  return "Patru";
        case 5:  return "Cinci";
        case 6:  return "Sase";
        case 7:  return "Sapte";
        case 8:  return "Opt";
        case 9:  return "Noua";
        case 10: return "Zece";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
	}
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
	os << card.valueToString() << " de " << card.suitToString();
	return os;
}