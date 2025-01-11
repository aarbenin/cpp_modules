#include "Replace.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    Replace replacer(argv[1], argv[2], argv[3]);
    replacer.processFile();

    return 0;
}
