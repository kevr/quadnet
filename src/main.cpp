#include <iostream>
#include <string>

static const std::string PROJECT_NAME("quadnet");
static const std::string PROJECT_DESC("a graph quadrant neural network");

int main(int argc, char **argv)
{
    if (argc != 1) {
        std::cout << argv[0] << "takes no arguments.\n";
        return 1;
    }
    std::cout << PROJECT_NAME << " - " << PROJECT_DESC << std::endl;

    return 0;
}
