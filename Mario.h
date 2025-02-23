#ifndef MARIO_H
#define MARIO_H

#include <cstdlib>  // for rand(), srand() if needed

class Mario {
public:
    // Constructor: Initialize Mario with a certain number of lives
    Mario(int startLives);
    
    // Destructor (likely empty)
    ~Mario();

    // Position methods
    void setPosition(int newRow, int newCol);
    int getRow() const;
    int getCol() const;

    // Level methods
    void setCurrentLevel(int level);
    int getCurrentLevel() const;

    // Coin methods
    void addCoins(int numCoins);
    int getCoins() const;

    // Life methods
    void loseLife();
    void gainLife();
    int getLives() const;

    // Power level methods
    void powerUp();
    void powerDown();
    int getPowerLevel() const;

    // Movement
    // Moves Mario one step in a random direction (0=UP,1=DOWN,2=LEFT,3=RIGHT) on an NxN grid
    void moveRandom(int N);

    // Encounters
    // Returns true if Mario survives the encounter, false if he dies
    bool encounterEnemy(char enemyType);
    // Returns true if Mario defeats the boss, false otherwise
    bool encounterBoss();

private:
    int row;    // Mario's current row on the grid
    int col;    // Mario's current column on the grid
    int currentLevel;      // Which level Mario is on
    int lives;             // Number of lives remaining
    int coins;             // Coins collected (earns extra life at 20)
    int powerLevel;        // 0 = PL0, 1 = PL1, 2 = PL2
    int enemiesDefeatedThisLife; // Count enemies defeated without losing a life
};

#endif
