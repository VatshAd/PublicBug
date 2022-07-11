#include<iostream>
#include<stdlib.h>  
#include<time.h>

using namespace std;

int random(int n);
int check(int userin, int compin);

int main() {

    int userInput;
    int compInput;
    int userScore = 0;
    int compScore = 0;
    string value[] = {"Random", "Rock", "Paper", "Scissor", "\0"};

    cout<<"\n\n";
    cout<<"                                    __________________Welcome to Rock, Paper and Scissor Game_________________                                    ";
    cout<<"\n\n";

    for (int i = 0; i < 3; i++)
    {
        cout<<"\n_______User's Turn________"<<endl<<endl;
        cout<<"Enter 1 for Rock, 2 for Paper and 3 for Scissor"<<endl;
        cin>>userInput;
        cout<<"User Entered "<<value[userInput]<<endl;

        cout<<"\n_________Computer's Turn________"<<endl<<endl;
        cout<<"Enter 1 for Rock, 2 for Paper and 3 for Scissor"<<endl;
        compInput = random(3);
        cout<<compInput<<endl;
        cout<<"Computer Entered "<<value[compInput]<<endl;

        cout<<endl;

        if (check(userInput, compInput) == -1)
        {
            compScore;
            userScore;
            cout<<"Ooops....! Same Same...! None of you got score.!"<<endl;
        }
        else if(check(userInput, compInput) == 1){
            compScore;
            userScore++;
            cout<<"User got 1 point."<<endl;     
        }
        else{
            userScore;
            compScore++;
            cout<<"Computer got 1 point."<<endl;
        }

        cout<<"\nScore : "<<endl<<"User Score = "<<userScore<<endl<<"Comp Score = "<<compScore<<endl<<endl;

        if((userScore == 2) && (compScore == 0)) {               
            break;
        }
        else if((userScore == 0) && (compScore == 2)) {       
            break;
        }
        else {                                                
            continue;
        }
    }

    if (userScore > compScore)
    {
        cout<<endl<<"Yea....! USER WON...)"<<endl<<endl;
    }

    else if(userScore < compScore) {
        cout<<endl<<"Oh....! COMPUTER WON...)"<<endl<<endl;
    }
    
    else{
        cout<<endl<<"It's A draw.!"<<endl<<endl;
    }


    return 0;
}


int random(int n) {
    srand(time(NULL));
    return rand() % n + 1;
}

int check(int userin, int compin) {
    if (userin == compin)
    {
        return -1;
    }
    /*
        User win's in conditions only -
            Rock - Scissor            -----> UserInput(1) > CompInput(3)
            Paper - Rock              -----> UserInput(2) > CompInput(1)
            Scissor - Paper           -----> UserInput(3) > CompInput(2)
    */

    else if ((userin == 1) && (compin == 3))
    {
        return 1;
    }
    else if ((userin == 2) && (compin == 1))
    {
        return 1;     
    }
    else if ((userin == 3) && (compin == 2))
    {
        return 1;
    }
    else {
        return 0;
    }
}
