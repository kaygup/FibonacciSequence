#include <iostream>
#include <vector>
#include <fstream>

int calculate(int numbers) {
    std::vector< int > sequence;

    sequence.push_back(0);
    sequence.push_back(1);

    int lastNum = 0;
    int thisNum = 1;

    for (int i = 0; i < numbers; i++) {
        int CalcedNum = lastNum + thisNum;
        if (CalcedNum < 0) {
            CalcedNum *= -1;
        }

        lastNum = thisNum;
        thisNum = CalcedNum;

        sequence.push_back(CalcedNum);
    }

    for (auto & element : sequence) {
        if (element != 0) {
            std::cout << ",";
        }
        std::cout << element;
    }
    std::cout << std::endl;
    std::cout << "Would you like to save the result? (y/n) ";

    std::string seqRes;
    std::cin >> seqRes;
    if (seqRes == "y") {
        std::string fileName;
        std::cout << "File name: ";
        std::cin >> fileName;

        std::ofstream resFile(fileName + ".txt");
        for (auto& seqNum : sequence) {
            if (seqNum != 0) {
                resFile << "," << seqNum;
            } else {
                resFile << seqNum;
            }
        }
        resFile.close();

        std::cout << std::endl << "Write to file: " << fileName << ".txt";

    }
    std::cout << std::endl << "Press any key to continue";
    return 0;
}

void mainloop() {
    int numberstogen;
    std::cout << "How many numbers would you like to calculate: ";
    std::cin >> numberstogen;

    calculate(numberstogen);

    system("pause >nul");
}

int main() {
    system("title Fibonacci Sequence Calculator");
    while (true) {
        system("cls"); 
        mainloop();
    }
    return 0;
}
