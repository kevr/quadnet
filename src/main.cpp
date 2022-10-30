#include <iostream>
#include <string>
using std::endl;

static const std::string PROJECT_NAME("quadnet");
static const std::string PROJECT_DESC("a graph quadrant neural network");

int main(int argc, const char **argv)
{
    if (argc != 1) {
        std::cerr << "error: " << argv[0] << " takes no arguments" << endl;
        return 1;
    }
    std::cout << PROJECT_NAME << " - " << PROJECT_DESC << endl;

    return 0;
}
