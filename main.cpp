/*
 Program designed by Diego Acuna
 This program will allow a local store to keep up with inventory.
 It will allow you to add, remove, clear, display, count, sort, search and exit the program.
 It will utilize structs, vectors, templates and algorithms.
 */
 
/*
 CSCI 4100 Dr. Casimir-Patton, AUM
 HW 4
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

//create the struct template
struct Games {
    std::string title;
    std::string system;
    std::string rating;
    std::string genre;
    std::string year;
};


// main function will run the program
int main(){
    //declare your variables
    int choice = 0; //user choice
    Games tempGames; //place holder for games
    std::string tempStr; //place holder for string data types
    std::vector<Games> inventory; //will hold the inventory
    bool found; // will find or not find games

    
    //open file for READING
    std::ifstream invFile("inventory.txt");
    //import data into vector
    while (std::getline(invFile, tempStr)) {
        tempGames.title = tempStr;
        std::getline(invFile, tempStr);
        tempGames.system = tempStr;
        std::getline(invFile, tempStr);
        tempGames.rating = tempStr;
        std::getline(invFile, tempStr);
        tempGames.genre = tempStr;
        std::getline(invFile, tempStr);
        tempGames.year = tempStr;
        std::getline(invFile, tempStr);
        //add to vector
        inventory.push_back(tempGames);
    }
    invFile.close(); //close file
    
    
    //display menu
    while (true){
        std::cout << "Welcome to your games inventory program. Please choose from the following menu\n\n";
        std::cout << "1. Add a new game" << std::endl;
        std::cout << "2. Remove a game" << std::endl;
        std::cout << "3. Clear inventory" << std::endl;
        std::cout << "4. Display inventory" << std::endl;
        std::cout << "5. Number of games in the inventory" << std::endl;
        std::cout << "6. Search by system" << std::endl;
        std::cout << "7. Search by title" << std::endl;
        std::cout << "8. Exit program" << std::endl;
        std::cout << std::endl;
        std::cout << "Plese enter your choice: ";
        std::cin >> choice;
        
        //check input and perform menu
        while (choice < 1 || choice > 8) {
            std::cout << "Please enter valid menu option (1-8): ";
            std::cin >> choice;
        }
        
        switch (choice) {
            case 1:
                std::cout << "Please enter title of game: ";
                std::cin.ignore();
                std::getline(std::cin,tempGames.title);
                std::cout << "Please enter the system (PlayStation 4/5, Xbox One, Xbox Series X/S, Nintendo Switch): ";
                std::getline(std::cin, tempGames.system);
                std::cout << "Please enter the rating (EC, E, E10+, T, M, AO): ";
                std::cin >> tempGames.rating;
                std::cout << "Please enter the genre: ";
                std::cin >> tempGames.genre;
                std::cout << "Please enter the year: ";
                std::cin >> tempGames.year;
                std::cout << "The following game has been added: " << tempGames.title;
                std::cout << std::endl;
                std::cout << std::endl;
                //add the game to the library
                inventory.push_back(tempGames);;
                break;
                
            case 2:
                std::cout << "What is the title of the game you want to remove: ";
                std::cin.ignore();
                std::getline(std::cin, tempStr);
                //search the vector
                for (int i = 0; i < inventory.size(); i++){
                    if (inventory[i].title == tempStr){
                        inventory.erase(inventory.begin()+i);
                        found = true;
                    }
                }
                std::cout << "Game has been deleted";
                std::cout << std::endl;
                std::cout << std::endl;
                if (!found){
                    std::cout << "The game is not in the list\n";
                    std::cout << std::endl;
                }
                break;
                
            case 3:
                inventory.clear(); //clears everything
                std::cout << "Your list has been cleared.";
                std::cout << std::endl;
                break;
                
            case 4:
                //prints the whole vector and text file
                for (int i = 0; i < inventory.size(); i++){
                    std::cout << "-Game Title: " << inventory[i].title << ", ";
                    std::cout << "Gaming System: " << inventory[i].system << ", ";
                    std::cout << "Game Rating: " <<  inventory[i].rating << ", ";
                    std::cout << "Game Genre: " << inventory[i].genre << ", ";
                    std::cout << "Game Year: " << inventory[i].year;
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                break;
                
            case 5:
                //show how many games there are in the inventory
                std::cout << "There are " << inventory.size() << " games in the store.";
                std::cout << std::endl;
                             
                break;
                
            case 6:
                std::cout << "Please input the system (PlayStation 4/5, Xbox One, Xbox Series X/S, Nintendo Switch): ";
                std::cin.ignore();
                std::getline(std::cin, tempStr);
                for (int i = 0; i < inventory.size(); i++){
                    if (inventory[i].system == tempStr){
                        std::cout << "Game Title: " << inventory[i].title << ", Game System: " << inventory[i].system;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        found = true;
                    }
                }
                if (!found){
                    std::cout << "There are no games for that system.";
                    std::cout << std::endl;
                }
                break;
                
            case 7:
                std::cout << "Please input the game title: ";
                std::cin.ignore();
                std::getline(std::cin, tempStr);
                for (int i = 0; i < inventory.size(); i++){
                    if (inventory[i].title == tempStr){
                        std::cout << "Game Title: " << inventory[i].title << ", ";
                        std::cout << "Gaming System: " << inventory[i].system << ", ";
                        std::cout << "Game Rating: " <<  inventory[i].rating << ", ";
                        std::cout << "Game Genre: " << inventory[i].genre << ", ";
                        std::cout << "Game Year: " << inventory[i].year;
                        std::cout << std::endl;
                        std::cout << std::endl;
                        found = true;
                    }
                }
                if (!found){
                    std::cout << "Game is not in the inventory.";
                    std::cout << std::endl;
                }
                break;
                
            case 8:
                std::cout << "Thanks for using the program. Goodbye!";
                std::cout << std::endl;
                exit(0);
                
            default:
                break;
        }
        
    }
    
    return 0;
}
