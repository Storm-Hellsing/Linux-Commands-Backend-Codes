#include <iostream>
#include <filesystem>
#include <string>

int main(int argc, char* argv[]) {
    if(argc < 2){

        std::cerr << "Usage: " <<argv[0] << "<directory1> [directory2] ..."<<std::endl;
        return 1;

    }

    for(int i = 1; i < argc; ++i){

        std::filesystem::path dirPath(argv[i]);

        if(std::filesystem::create_directory(dirPath)){

            std::cout<<"Directory created: "<<argv[i]<< std::endl;

        }
        else{

            std::cerr<<"Failed to create directory (it might already exist): "<<argv[i]<< std::endl;

        }
    }
    
    return 0;
}
