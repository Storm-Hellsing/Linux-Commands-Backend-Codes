#include <iostream>
#include <fstream>
#include <filesystem>

int main(int argc, char* argv[]){
    if(argc < 2){

        std::cout<<"Usage: "<< argv[0]<<" <file_name-1> <file_name-2> ..."<<std::endl;
        return 1;
    }
    else{
        
        for(int i = 1; i < argc; i++){

        std::filesystem::path filePath = argv[i]; // Create a filesystem path object

        // Check if the file already exists using std::filesystem
        if(std::filesystem::exists(filePath)){
            
            std::cerr<<"Failed to create file: "<<filePath<<" (File already exists)"<<std::endl;
            
        } 
        else{
            // Create and immediately close the file to indicate it was created
            std::ofstream file(filePath);

            // Optionally, check if the file was successfully created
            if(!file){

                    std::cerr<< "Failed to create file: "<<filePath <<std::endl;

            }
            else{

                std::cout<< "File created: "<<filePath<<std::endl;
                file.close();

                }
            }
        }
    }

    return 0;
}
