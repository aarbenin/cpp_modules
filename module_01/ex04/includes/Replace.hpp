#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>

class Replace
{
public:
    Replace(const std::string& filename, const std::string& s1,
            const std::string& s2);
    ~Replace();

    void processFile();

private:
    std::string m_filename;
    std::string m_s1;
    std::string m_s2;

    std::string replaceLine(const std::string& line) const;
};

#endif