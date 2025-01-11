#include "Replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1,
                 const std::string& s2)
    : m_filename(filename), m_s1(s1), m_s2(s2)
{
    if (m_s1.empty() || m_s2.empty())
    {
        std::cerr << "Error: Strings s1 and s2 cannot be empty.\n";
    }
}

Replace::~Replace() {}

void Replace::processFile()
{
    std::ifstream inputFile(m_filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << m_filename << ".\n";
        return;
    }

    std::ofstream outputFile(m_filename + ".replace");
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create output file "
                  << m_filename + ".replace" << ".\n";
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << replaceLine(line) << "\n";
    }

    inputFile.close();
    outputFile.close();
}

std::string Replace::replaceLine(const std::string& line) const
{
    std::string result;
    size_t      pos = 0;
    size_t      foundPos;

    while ((foundPos = line.find(m_s1, pos)) != std::string::npos)
    {
        result += line.substr(pos, foundPos - pos);
        result += m_s2;
        pos = foundPos + m_s1.length();
    }

    result += line.substr(pos);
    return result;
}
