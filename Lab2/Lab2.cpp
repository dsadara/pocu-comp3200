#include "Lab2.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        int number;
        string str;
        bool bFirstInput = true;

        while (true)
        {
            in >> number;
            if (in.fail())
            {
                in.clear();
                in >> str;
                continue;
            }
            if (bFirstInput)
            {
                out << setfill(' ') << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
                out << setfill('-') << setw(12) << " " << setw(11) << " " << setw(9) << "" << endl;
                bFirstInput = false;
            }
            if (in.eof())
            {
                // eof전 출력하지 못한 number 출력
                out << setfill(' ') << setw(12) << oct << number
                    << setw(11) << dec << number << setw(9) << uppercase << hex << number << endl;
                break;
            }
            out << setfill(' ') << setw(12) << oct << number
                << setw(11) << dec << number << setw(9) << uppercase << hex << number << endl;
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {

    }
}