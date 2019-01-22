//
// Created by tmtoon on 22.01.19.
//

#ifndef GAME_OF_LIFE_GRID_HPP
#define GAME_OF_LIFE_GRID_HPP

#include <glob.h>
#include <array>
#include <memory>
#include <iostream>
#include "Cell.h"
#include <vector>

template<size_t ROW, size_t COL>
class Grid {
private:
    std::array<std::array<std::shared_ptr<Cell>, COL>, ROW> grid;

    unsigned int neighbours(size_t x, size_t y) const;

public:
    Grid();

    void operator()(size_t row_index, size_t col_index, bool a);

    void print() const;

    void evolve(const std::function<bool(bool, int)> &f);

};

template<size_t ROW, size_t COL>
void Grid<ROW, COL>::print() const {
    for (auto &row : grid) {
        for (auto &elem : row)
            std::cout << *elem;
        std::cout << std::endl;
    }
}

template<size_t ROW, size_t COL>
void Grid<ROW, COL>::operator()(size_t row_index, size_t col_index, bool a) {
    if (row_index >= ROW or col_index >+ COL) {
        throw std::out_of_range("Invalid position in grid(row, col, bool).");
    }

    if (a) {
        grid[row_index][col_index] = std::make_unique<AliveCell>();
    } else {
        grid[row_index][col_index] = std::make_unique<DeadCell>();
    }
}

template<size_t ROW, size_t COL>
Grid<ROW, COL>::Grid() {
    for (size_t i = 0; i < ROW; ++i) {
        for (size_t j = 0; j < COL; ++j) {
            grid[i][j] = std::make_unique<DeadCell>();
        }
    }
}

template<size_t ROW, size_t COL>
void Grid<ROW, COL>::evolve(const std::function<bool(bool, int)> &f) {
    std::vector<std::tuple<size_t, size_t, unsigned int>> vec;
    for (size_t i = 0; i < ROW; ++i) {
        for (size_t j = 0; j < COL; ++j) {
            vec.emplace_back(i, j, neighbours(i, j));
        }
    }
    for (const auto& e : vec) {
        using std::get;
        operator()(get<0>(e), get<1>(e), f(grid[get<0>(e)][get<1>(e)]->alive(), get<2>(e)));
    }
}

template<size_t ROW, size_t COL>
unsigned int Grid<ROW, COL>::neighbours(size_t x, size_t y) const {
    unsigned int rval = 0;
    if (x > 0) {
        rval += grid[x - 1][y]->alive();
        if (y > 0) {
            rval += grid[x-1][y-1]->alive();
        }
        if (y < COL - 1) {
            rval += grid[x-1][y+1]->alive();
        }
    }
    if (x < ROW - 1) {
        rval += grid[x + 1][y]->alive();
        if (y > 0) {
            rval += grid[x+1][y-1]->alive();
        }
        if (y < COL - 1) {
            rval += grid[x+1][y+1]->alive();
        }
    }
    if (y > 0) { rval += grid[x][y - 1]->alive(); }
    if (y < COL - 1) { rval += grid[x][y + 1]->alive(); }

    return rval;
}

#endif //GAME_OF_LIFE_GRID_HPP
