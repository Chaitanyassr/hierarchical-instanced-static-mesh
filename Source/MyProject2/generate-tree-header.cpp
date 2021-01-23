#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <random>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << argv[0] << " <number of trees> <output filename>" << std::endl;
        return 1;
    }

    int32_t trees = std::stol(argv[1]);
    std::string filename = argv[2];

    std::cout << "Generating " << trees << " trees in " << filename << "." << std::endl;

    std::ofstream out(filename);
    out << "#pragma once" << std::endl;
    out << std::endl;
    out << "#include <vector>" << std::endl;
    out << std::endl;
    out << "struct Tree {" << std::endl;
    out << "    // Values are in standard Unreal Engine coordinates (centimeters)" << std::endl;
    out << "    float positionX;" << std::endl;
    out << "    float positionY;" << std::endl;
    out << "    float positionZ;" << std::endl;
    out << "    float height;" << std::endl;
    out << "    float canopyRadius;" << std::endl;
    out << "};" << std::endl;
    out << std::endl;
    out << "std::vector<Tree> trees {" << std::endl;

    std::default_random_engine generator;
    std::uniform_real_distribution<float> positionDistribution(0.0, 100000.0);
    std::uniform_real_distribution<float> heightDistribution(2.0, 10000.0);
    std::uniform_real_distribution<float> canopyRadiusDistribution(1.0, 5000.0);

    out << std::fixed << std::setprecision(1);

    for (int32_t i = 0; i < trees; ++i) {
        out << "    { ";
        out << positionDistribution(generator) << "f, " << positionDistribution(generator) << "f, " << positionDistribution(generator) << "f, " << heightDistribution(generator) << "f, " << canopyRadiusDistribution(generator) << "f";
        out << " }," << std::endl;
    }

    out << "};" << std::endl;

    return 0;
}
