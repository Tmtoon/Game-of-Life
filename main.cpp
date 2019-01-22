#include <iostream>
#include <stdexcept>
#include <functional>
#include "Game.hpp"

int main() {
    try {
        /*
         *
         * @param bool: cell is alive in current iteration
         * @param int: number of alive neighbors
         * @return: cell will be alive or not in next iteration
         */
        std::function<bool (bool, int)> ruleLambda = [](bool alive, int i) {
            if (alive) {
                return (i == 2 or i == 3);
            } else {
                return i == 3;
            }
        };


        Game<15, 30> game(1000, ruleLambda);

        game(7, 14);
        game(7, 15);
        game(7, 16);
        game(7, 17);
        game(7, 18);

        game.evolve();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

