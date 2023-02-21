#include <iostream>
#include <list>
#include <string>
#include <random>
#include <algorithm>
#include <conio.h>

int main(){
    // Rock Paper scissor game: 
    std::vector<std::string> choices{"rock", "paper", "scissors"};
    std::string computer_choice;
    std::string user_choice;
    std::string result;
    std::string playagain;

    std::cout << "Press any key to proceed... " << '\n';
    getch();

    while (true) {
        std::cout << "Please enter a choice: 'Rock', 'Paper' or 'Scissors' ";

        std::getline(std::cin, user_choice);
        std::transform(user_choice.begin(), user_choice.end(), user_choice.begin(), [](unsigned char c) { return std::tolower(c); });

        if (std::find(choices.begin(), choices.end(),user_choice) != choices.end()) {
            break;
        }

        std::cout << "Invalid choice. Please try again" << '\n';
    }
    //generate random choice for use

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,choices.size() - 1);
    auto random_int = dis(gen);

    auto computer = choices.begin();
    std::advance(computer,random_int);

    computer_choice = *computer;

    if (user_choice == "rock"){

        if (computer_choice == "paper"){
            result = "Lose";
        } else{
            result = "Win";
        }
    }
    if (user_choice == "paper"){

        if (computer_choice == "rock"){
            result = "Win";
        } else{
            result = "Lose";
        }
    }
    if(user_choice == "scissors"){

        if (computer_choice == "rock"){
            result = "Lose";
        } else{
            result = "Win";
        }
    }

    if (user_choice == computer_choice){
        result = "Draw";
    }

    std::cout << "A match begins." << '\n';
    std::cout << "User uses: " << user_choice << '\n' << "Computer uses: " << computer_choice << '\n' << "Match result: You " << result << '!' << '\n';

    std::cout << "Would you like to play again? Yes or No: ";
    std::getline(std::cin, playagain);
    std::transform(playagain.begin(), playagain.end(), playagain.begin(), [](unsigned char c) { return std::tolower(c); });

    if (playagain == "yes"){
        main();
    }else{
            std::cout << "Goodbye!";
    }
    return 0;
}
