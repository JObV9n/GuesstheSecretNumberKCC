#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctime>
#include<process.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<stdio.h>
//#include<SFML/Graphics.hpp>

// To be checked :- line 96


using namespace std;

class game{

public:
    int choice,chance=5;
    int y,random_number;
    int hrs=0,mins=0,sec=0;

int login();
int registr();
int display_Clock();
int timer();
int random_num();
int startgame();
int about();
int start();
bool ghadi=true;

//sf::RenderWindow console;

}x;

 int game::random_num()
{
	srand(time(0));

    random_number=rand()%1000+1;
    return random_number;

}

int game::timer()
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


int game::startgame()
{

system("cls");
    cout<<"Welcome TO The Game"<<endl;
    cout<<"Here the computer has generated a random number That you have to guess"<<endl;
    //timer();

}

int game::about()
{
    system("cls");
    cout<<"This game is about Guessing the secret number in which a computer generates the random number which you"<< "have to guess using the given hints in the game"<<endl;
        getch();
        return start();
}


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

    case 3:
        goto hints;

    case 4:
        exit(0);

    default:
        system("cls");
        cout<<"You've made a mistake , give it a try again\n"<<endl;
    }


        cin.ignore();
        return save;

hints:
   do{

    if (random_number%2==0)
    {
        cout<<"Your Secret Number is an EVEN NUMBER"<<endl;
        getch();

        if (chance=='4')
        {
            cout<<"Your Secret Number is Divisible by a PRIME Number from 0-9!"<<endl;
            getch();
        }
    }
    else if (random_number%2!=0)
        {
        cout<<"Your Secret Number is an ODD NUMBER"<<endl;
        getch();

        }
    else
    {
        cout<<"Your Secret Number is imaginary so sorry for your time!";
        getch();
    }
}
while(x.start());

return 0;

}


int main()
{
    /*sf:: RenderWindow console( sf:: VideoMode(750,550),"Guess The secret No.");
    sf :: Event event;

    while(console.isOpen())
    {
        while(console.pollEvent(event)){
            if((event.type == sf:: Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf:: Keyboard::Escape))){
                console.close();
            }
            if((event.type == sf:: Event :: KeyPressed) && (event.key.code == sf::Keyboard :: Space)){
                console.close();
            }
        }
    }
}
// 184-198 just game checking ko lagi matra ho
*/

        int choice,chance;
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
                case 1:
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

        if (kbhit(1)){
            x.startgame();

            goto hints;



}

hints:
do
{

    if (x.random_number%2==0)
    {
        cout<<"Your Secret Number is an EVEN NUMBER"<<endl;
        getch();

        if (x.chance=='4')
        {
            cout<<"Your Secret Number is Divisible by a PRIME Number from 0-9!"<<endl;
            getch();
        }
    }
    else if (x.random_number%2!=0)
        {
        cout<<"Your Secret Number is an ODD NUMBER"<<endl;
        getch();

        }
    else
    {
        cout<<"Your Secret Number is imaginary so sorry for your time!";
        getch();
    }
}




}



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

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

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
                cin.get();
                start();

        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your Username and password\n";
                system("cls");
                main();
        }
}

int game::registr()
{

        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;

        fstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;

        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();



}



