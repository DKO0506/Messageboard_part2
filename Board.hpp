#include <iostream>
#include <vector>
#include <string>
#include "Direction.hpp"

using namespace std;




namespace ariel {

    class Board {
    private:
        const char ch = '_';
        unsigned int min_row, min_col;
        unsigned int max_row, max_col;
        vector <vector<char>> slots_vec;
    public:
        Board(){
            slots_vec = vector < vector < char >> (1, vector<char>(1, '_'));
            min_row = min_col = UINT32_MAX;
            max_row = max_col = 0;
        }

        ~Board(){}

        void post(unsigned int row, unsigned int col, Direction d, const string &input);

        string read(unsigned int row, unsigned int col, Direction d, unsigned int size);

        void show();

    };
}