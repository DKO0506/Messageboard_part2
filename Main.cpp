#include "Board.hpp"
#include <stdlib.h>
#include <time.h>

using namespace ariel;

int main() {

    cout << "Hello, This is my project" << endl;

    Board board;


    board.post(0, 0, Direction::Horizontal, "Hello  This is my project");

    board.show();

    board.post(2, 4, Direction::Vertical, "Hello, This is my project");

    board.show();


    board.post(5, 5, Direction::Horizontal, "Good Bye!");

    board.show();

    return 0;
}