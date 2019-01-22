//
// Created by tmtoon on 22.01.19.
//

#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H


#include <string>

class Cell {
private:
    virtual std::string str() const = 0;

public:
    virtual bool alive() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Cell& c);
};

class AliveCell : public Cell {
private:
    std::string str() const override;

public:
    bool alive() const override;
};

class DeadCell : public Cell {
private:
    std::string str() const override;

public:
    bool alive() const override;
};

#endif //GAME_OF_LIFE_CELL_H
