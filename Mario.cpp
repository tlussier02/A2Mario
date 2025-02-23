#include "Mario.h"
#include <cstdlib>
using namespace std;

Mario::Mario(int startLives) {
    lives = startLives;
    coins = 0;
    powerLevel = 0;
    row = 0;
    col = 0;
    currentLevel = 1;
    enemiesDefeatedThisLife = 0;
}

Mario::~Mario() {
}

void Mario::setPosition(int newRow, int newCol) {
    row = newRow;
    col = newCol;
}

int Mario::getRow() const {
    return row;
}

int Mario::getCol() const {
    return col;
}

void Mario::setCurrentLevel(int level) {
    currentLevel = level;
}

int Mario::getCurrentLevel() const {
    return currentLevel;
}

void Mario::addCoins(int numCoins) {
    coins += numCoins;
    if (coins >= 20) {
        gainLife();
        coins -= 20;
    }
}

int Mario::getCoins() const {
    return coins;
}

void Mario::loseLife() {
    lives--;
    enemiesDefeatedThisLife = 0;
}

void Mario::gainLife() {
    lives++;
}

int Mario::getLives() const {
    return lives;
}

void Mario::powerUp() {
    if (powerLevel < 2) {
        powerLevel++;
    }
}

void Mario::powerDown() {
    if (powerLevel > 0) {
        powerLevel--;
    } else {
        loseLife();
        powerLevel = 0;
    }
}

int Mario::getPowerLevel() const {
    return powerLevel;
}

void Mario::moveRandom(int N) {
    // 0=UP, 1=DOWN, 2=LEFT, 3=RIGHT
    int dir = rand() % 4;

    switch (dir) {
        case 0: // UP
            row = (row - 1 + N) % N;
            break;
        case 1: // DOWN
            row = (row + 1) % N;
            break;
        case 2: // LEFT
            col = (col - 1 + N) % N;
            break;
        case 3: // RIGHT
            col = (col + 1) % N;
            break;
    }
}

bool Mario::encounterEnemy(char enemyType) {
    int chance = rand() % 100;
    int winThreshold = 0;
    if (enemyType == 'g') {
        winThreshold = 80;
    } else if (enemyType == 'k') {
        winThreshold = 65;
    } else {
        return true;
    }
    if (chance < winThreshold) {
        enemiesDefeatedThisLife++;
        if (enemiesDefeatedThisLife == 7) {
            gainLife();
            enemiesDefeatedThisLife = 0;
        }
    } else {
        powerDown();
        if (lives <= 0) {
            return false;
        }
    }
    return true;
}

bool Mario::encounterBoss() {
    while (true) {
        int chance = rand() % 100;
        if (chance < 50) {
            return true;
        } else {
            if (powerLevel == 2) {
                powerLevel = 0;
            } else {
                loseLife();
                powerLevel = 0;
            }
            if (lives <= 0) {
                return false;
            }
        }
    }
}
