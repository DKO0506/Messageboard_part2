

#include "Board.hpp"


namespace ariel {
    void Board::post(unsigned int row, unsigned int col, Direction d, const string &input) {
        if (row < min_row) { min_row = row; }
        if (col < max_col) { min_col = col; }
        unsigned int len = input.size();

        if (d == Direction::Vertical) {
            if ((row + input.size()) >= max_row) {
                max_row = row + len + 1;
            }
            if (col >= max_col) {
                max_col = col + 1;
            }
        } else {
            if ((col + input.size()) >= max_col) {
                max_col = col + len + 1;
            }
            if (row >= max_row) {
                max_row = row + 1;
            }
        }
        slots_vec.resize(max_row);
        for (unsigned int i = 0; i < max_row; i++) {
            slots_vec.at(i).resize(max_col, '_');
        }

        unsigned int k = 0;
        if (d == Direction::Horizontal) {
            for (unsigned int c = col; k < input.size() && c < max_col - 1; c++) {
                slots_vec.at(row).at(c) = input.at(k++);
            }
        } else {
            for (unsigned int r = row; k < input.size() && r < max_row - 1; r++) {
                slots_vec.at(r).at(col) = input.at(k++);
            }
        }
    }


    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int size) {
        string answer;

        bool check = row < 0 || col < 0 || row >= UINT32_MAX || col >= UINT32_MAX;

        if (check) {
            throw "Out of bounds!";
            return "";
        }


        if (d == Direction::Horizontal) {

            for (unsigned int c = col; c < col + size; c++) {
                if (c >= max_col) {
                    answer += "_";
                } else {
                    answer += slots_vec.at(row).at(c);
                }
            }

        } else {
            for (unsigned int r = row; r < row + size; r++) {
                if (r >= max_row) {
                    answer += "_";
                } else {
                    answer += slots_vec.at(r).at(col);
                }
            }
        }
        return answer;
    }

    void Board::show() {
        string sh;

        for (unsigned int r = min_row; r < max_row; r++) {
            for (unsigned int c = min_col; c < max_col; c++) {
                sh += slots_vec.at(r).at(c);
            }
            sh += "\n";
        }

    }
};