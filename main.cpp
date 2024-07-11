#include <iostream>
#include <fstream>


int main() {
    std::ifstream png_file;
    std::string path;

    std::cout << "Enter file path:" << std::endl;
    std::cin >> path;
    png_file.open(path, std::ios::binary);

    if (!png_file.is_open()) {
        std::cout << "Error! File isn't open" << std::endl;
        return 0;
    }

    if (path.find(".png") == std::string::npos) {
        std::cout << "This is not PNG extension" << std::endl;
        return 0;
    } else {
        std::cout << "This is PNG extension!" << std::endl;
    }

    char buffer[4];
    png_file.read(buffer, sizeof(buffer));

    if (buffer[0] == '\x89' &&
        buffer[1] == 'P' &&
        buffer[2] == 'N' &&
        buffer[3] == 'G') {
        std::cout << "This is real PNG!" << std::endl;
    } else {
        std::cout << "This is not PNG";
    }

    png_file.close();

    return 0;
}
