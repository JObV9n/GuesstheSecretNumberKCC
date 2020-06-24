#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
//#include<string.h>
#include<ctime>
#include<process.h>
//#include<windows.h>
#include<conio.h>
//#include<stdio.h>
//#include<SFML/Graphics.hpp>

using namespace std;


class game{ //Main CLASS

private:
    int choice;
    //int y;
    int random_number;
   // int hrs=0,mins=0,sec=0;
    int secret_number;
    int chance=1;

public:
int login();
int registr();
//int display_Clock();
//int timer();
int random_num();
int startgame();
int about();
int start();
//bool ghadi=true;
int hints();

}x;

//Random Number Generation
 int game::random_num() 
{
	srand(time(0));

    random_number=rand()%1000+1;
    cout<< "\t" << random_number<<"\t";
    return EXIT_SUCCESS;

}

 /* int game::timer()
{

    hrs=0;
    mins=0;
    sec=0;
    while (ghadi)
        {
        display_Clock();
        Sleep(100);
        sec++;
        if (sec==60)
            {
                mins++;
                if (mins==60)
                    {
                        hrs++;
                        mins=0;
                    }
                sec=0;
            }

        }
}

int game::display_Clock()
{
    system("cls");
     cout<<"   STOP-WATCH      "<<endl;
     cout<<"****************"<<endl;
     cout<<hrs<<"hours!"<<"  ";
     cout<<mins<<"minutes!"<<"  ";
     cout<<sec<<" Seconds!"<<"  ";

     return EXIT_SUCCESS;
}
*/

//Hints Function
int game:: hints(){ 

    switch(chance) // Switch conditions of hints for the player
    {
    case (1):
        if (x.random_number%2==0)
        {
            cout<<"Your Secret Number is an EVEN NUMBER"<<endl;
            getch();
            chance++;
            break;
        }

        else {
            cout<<"Your Secret Number is an ODD NUMBER!!!"<<endl;
            getch();
            x.chance++;
            break;
        }
       /*f (x.chance=='4')
            {
                cout<<"Your Secret Number is Divisible by a PRIME Number from 0-9!"<<endl;
                getch();
            }
       */
  case (2):
        if (x.random_number < 1000 && x.random_number > 500 )
        {
            cout<<"Your Secret Number ranges between 500 and 1000 "<<endl;
            getch();
            chance++;
            break;
        }
        else {
            cout << "Your Secret Number is less then 500" << endl;
            getch();
            chance++;
            break;
        }

  case (3):
        if (random_number%5==0){
            cout << "Your Secret Number is Divisible by 5" << endl;
            getch();
            chance++;
            break;
            }
        else{
            cout << "Your Secret Number is not Divisible by 5" << endl;
            getch();
            chance++;
            break;
            }

    case (4):
            if (random_number%10==0){
            cout << "Your Secret Number is Divisible by 10" << endl;
            getch();
            chance++;
            break;
            }
            else{
            cout << "Your Secret Number is not Divisible by 10" << endl;
            getch();
            chance++;
            break;
            }

    case (5):
        if (random_number % 3==0){
            cout << "Your Secret Number is divisible by 3" << endl;
            getch();
            chance++;
            break;
        }

        else
            {
            cout << "Your Secret Number is  not divisible by 3" << endl;
            getch();
            chance++;
            break;
            }
    }
    return EXIT_FAILURE;
}

// Game Start-Up Function
int game::startgame() 
{
    system("cls");
    cout<<"Welcome TO The Game"<<endl;
    cout<<"Here the computer has generated a random number That you have to guess"<<endl;
    //timer();

    x.random_num();//calling function for random number
//  x.hints(); //calling hints for initial hints when the chance = 5;

    while (chance<5) // chance logic
    {
        int j=0;
        for (int i=j;i<chance;i++)
            {
       /*  if (x.random_number%2==0)
        {
            cout<<"Your Secret Number is an EVEN NUMBER"<<endl;
            getch();
            chance++;}

        else {
            cout<<"Your Secret Number is an ODD NUMBER!!!"<<endl;
            chance++;
        }
        */

                    cout<<"Enter Your number : "; // Taking the player input numbers
                    cin>> secret_number;
                    cout <<endl;
                    cout <<"\t*******************\t\t\t\t";

                if (secret_number == x.random_number)
                    {
                        cout << "\nCongrats you found the Secret Number!!";
                        cout << "\n";
                        cout << "Press Enter to Return to main menu";
                        getch();
                        return x.start();
                    }
                    x.hints();
                    j++;
        }
        chance++;
    }
    cout << "Sorry You have no chances left."<<endl
                 << "Now Returning to the Game Menu."<<endl;
            getch();
           return x.startgame();
}

// About the Game
int game::about() 
{
    system("cls");
    cout<<"This game is about Guessing the secret number in which a computer generates the random number which you"<<endl
         << "have to guess using the given hints in the game"<<endl;
        getch();
        return 0; //Returning SUCCESS of the function.
}


// Start Face of The Game Menu
int game::start() 
{
                        int save;
                        system("cls");
                        cout<<"\n"<<"\n"<<endl;
                    cout<<"\t\t\t"<<"Welcome to the game of finding the secret number generated!:"<<endl;
                                            cout<<"\t\t\t\t\t<-----::Menu::----->"<<endl;
                                            cout<<"\t\t\t\t\t    ________________   "<<endl;
                                            cout<<"\t\t\t\t\t   | 1. Start game  |   "<<endl;
                                            cout<<"\t\t\t\t\t   | 2. About       |  "<<endl;
                                            cout<<"\t\t\t\t\t   | 3. Help        |  "<<endl;
                                            cout<<"\t\t\t\t\t   | 4. Quit        |  "<<endl;
                                            cout<<"\t\t\t\t\t   |________________|  "<<endl;

                            cin>>save;
switch(save)
    {
    case 1:
        x.startgame();
        break;

    case 2:
        x.about();
        x.start();
        break;

    case 3:
         cout << "This is a Guessing Trivia where the player have to guess the Secret number " <<endl
              << "The player will get hints for guessing the number " << endl
              << "\n "
              << "To return to the main menu press ENTER " << endl;
              getch();

        x.start();
        break;

    case 4:
        break;

    default:
        system("cls");
        cout<<"You've made a mistake , give it a try again\n"<<endl;
        start();
        break;
    }
return EXIT_FAILURE;

}


int main()
{
        int choice;
        //int chance;
         cout<<"\t\t\t\t\t<-----::Login Page::----->"<<endl;
            cout<<"\t\t\t\t\t    ________________   "<<endl;
        cout<<"\t\t\t\t\t1.LOGIN\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t2.REGISTER\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t3.Exit\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t    ________________   \t\t\t\t\t"<<endl;
        cout<<"\n";
        cout<<"\t\t\t\t\t Enter your choice :\t\t\t\t"<<endl;
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case (1):
                        x.login();

                        break;
                case 2:
                        x.registr();
                        break;
                case 3:

                        cout<<"Thanks for using this program\nThis program is created by Sachin Shrestha, Lakpa Sherpa , Sagyan Shrestha\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl;
                        main();


        }

        return EXIT_SUCCESS;

}


// Login Function
int game::login() 
{
        system("cls");
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;

        ifstream input("database.txt"); // Opening
        while(input>>u>>p)
        {
                if(u==user && p==pass) //Matching The User Details

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
                cin.get();
                start();

        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your Username and Password\n";
                system("cls");
                main();
        }
        return EXIT_FAILURE;
}

// User Registration Function
int game::registr() 
{

        string reguser,regpass;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;

        fstream reg("database.txt",ios::app); // Input User Details
        reg<<reguser<<' '<<regpass<<endl;

        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();

        return EXIT_FAILURE; // Same like Returning 0 to Calling Function to Indicate Either Failure
                             // Or Problem in The Certain Code.
}
