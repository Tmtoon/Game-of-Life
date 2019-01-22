//
// Created by tmtoon on 22.01.19.
//

#ifndef GAME_OF_LIFE_GAME_HPP
#define GAME_OF_LIFE_GAME_HPP

#include "Grid.hpp"

template<size_t ROW, size_t COL>
class Game {
private:
    unsigned int it;
    std::function<bool(bool, int)> test_life;
    Grid<ROW, COL> grid;

public:
    Game(unsigned int iterations, std::function<bool(bool, int)> f);

    void operator()(unsigned int x, unsigned int y);

    void evolve();
};

template<size_t ROW, size_t COL>
Game<ROW, COL>::Game(unsigned int iterations, std::function<bool(bool, int)> f) : it(iterations),
                                                                                  test_life(std::move(f)) {}

template<size_t ROW, size_t COL>
void Game<ROW, COL>::operator()(unsigned int x, unsigned int y) {
    grid(x, y, true);
}

template<size_t ROW, size_t COL>
void Game<ROW, COL>::evolve() {
    for (unsigned int i = 0; i < it; ++i) {
        std::cout << "Iteration: " << i << std::endl;
        grid.print();
        grid.evolve(test_life);
    }
    std::cout << "Iteration: " << it << std::endl;
    grid.print();
}

#endif //GAME_OF_LIFE_GAME_HPP
