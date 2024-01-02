#include "gold.h"

USING_NS_CC;



CGold::CGold(int coins) {
    golds = coins;
}

CGold::~CGold() {

}

void CGold::addGolds(int amount) {

    golds += amount;
}

bool CGold::spendGolds(int amount) {
    if (golds >= amount) {

        golds -= amount;
    }
    return false;
}

int CGold::getGolds() const {
    return golds;
}

void CGold::setGolds(int coins) {
    golds = coins;
}


