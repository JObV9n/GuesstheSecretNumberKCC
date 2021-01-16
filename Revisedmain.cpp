#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<process.h>
#include<conio.h>
#include<windows.h>
//#include<dos.h>
//include "Mouse_pointer.h"
/*
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

const wchar_t CLASS_NAME[]  = "Mouse Input";

    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    //  the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);



            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

*/




using namespace std;


class game{ //Main CLASS

private:
    int choice;
    int random_number;
    int secret_number;
    int chance=1;

public:
int login();
int registr();
int random_num();
int startgame();
int about();
int start();
int hints();

//int player_score();
}x;

//Random Number Generation
 int game::random_num()
{
	srand((unsigned int) time(0));

   x.random_number=rand()%100+1;
    return x.random_number;

}


//Hints Function
int game:: hints(){

    switch(chance) // Switch conditions of hints for the player
    {
         case (1):
        if (x.random_number < 100 && x.random_number > 80 )
        {
            cout<<"\n"<<random_number<<endl;
            cout<<"\n\t\tYour Secret Number ranges between 80 and 100 "<<endl;
            getch();
            chance++;
            break;
        }
        else {
            cout<<"\n"<<random_number<<endl;
            cout << "\n\t\tYour Secret Number is less then 80" << endl;
            getch();
            chance++;
            break;
        }
     case (2):
        if (x.random_number < 80 && x.random_number > 60 )
        {
            cout<<"\n\t\tYour Secret Number ranges between 60 and 80 "<<endl;
            getch();
            chance++;
            break;
        }
        else {
            cout << "\n\t\tYour Secret Number is less then 60" << endl;
            getch();
            chance++;
            break;
        }
         case (3):
        if (x.random_number < 60 && x.random_number > 30 )
        {
            cout<<"\n\t\tYour Secret Number ranges between 30 and 60 "<<endl;
            getch();
            chance++;
            break;
        }
        else {
            cout << "\n\t\tYour Secret Number is less then 30" << endl;
            getch();
            chance++;
            break;
        }
          case (4):
        if (x.random_number < 30 && x.random_number > 1 )
        {
            cout<<"\n\t\tYour Secret Number ranges between 1 and 30 "<<endl;
            getch();
            chance++;
            break;
        }

    case (5):
        if (x.random_number%2==0)
        {
            cout<<"\n\t\tYour Secret Number is an EVEN NUMBER"<<endl;
            getch();
            chance++;
            break;
        }
        else {
            cout<<"\n\t\tYour Secret Number is an ODD NUMBER!!!"<<endl;
            getch();
            chance++;
            break;
        }

    case (6):
            if (random_number%10==0){
            cout << "\n\t\tYour Secret Number is Divisible by 10" << endl;
            getch();
            chance++;
            break;
            }


    case (7):
        cout<< "\nThis is your final hint !!!!"<<endl;

        if (random_number % 3==0){
            cout << "\n\t\tYour Secret Number is divisible by 3" << endl;
            getch();
            chance++;
            break;
        }
        else{
            cout<<" \n\t\tYour secret number is not divisible by 3." << endl;
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
    cout<<" Welcome To The Game"<<endl;
    cout<<" Here the computer has generated a random number That you have to guess"<<endl;
    cout<<" The number you should guess lies between 1 to 100 "<<endl;
 //   x.random_num();


    while (chance<8) // chance logic
    {

        int j=0;
        for (int i=j;i<chance;i++)
            {

                    cout<<"\nEnter Your number : "; // Taking the player input numbers
                    cin>> secret_number;
                    cout <<"\n";
                    cout <<"\t\t\t*******************";

                if (secret_number == x.random_number)
                    {
                        cout << "\nCongrats you found the Secret Number!!";
                        cout << "\n\n\n";

                        cout<<"Your Score is : " << (7-x.chance)*20<<endl;

                        cout << "Press Enter to Return to main menu";
                        getch();
                        return x.start();

                    }
                     x.hints();
                    j++;
        }
        chance++;
    }
    cout << "\n Sorry You have no chances left."<<endl;
    cout<<"\nYour secret number is "<<x.random_num()<<endl;
    cout<< "\nNow Returning to the Game Menu."<<endl;
    system("pause");
           return x.start();
}

// About the Game
int game::about()
{
    system("cls");
    cout<<"This game is about Guessing the secret number.\nIn which a computer generates the random number which you"<<endl;
     cout << "have to guess using the given hints in the game."<<endl;
        getch();
        return 0; //Returning SUCCESS of the function.
}


// Start Face of The Game Menu
int game::start()
{
                        int save;
                        system("cls");
                        system("Color 7c");
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

    }
return EXIT_FAILURE;

}

//Main Page
int main()
{
        system("Color A1");
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

                        cout<<"Thanks for using this program.\nThis program is created by Sachin Shrestha, Lakpa Sherpa , Sagyan Shrestha\n\n";
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
        string user,u,p;
        string pass;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        char password = _getch();
        while(password !=13){
            pass.push_back(password);
            cout<<"*";
            password= getch();
        }
        //cin>>pass;


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
                cout<<"\nHello"<<user<<"\nLOGIN SUCESS\n We're glad that you're here.\nThanks for logging in\n";
                getch();
                //cin.get();
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

        string reguser;
        string regpass="";
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        char pass;
        pass= getch();
        while(pass!=13){
            regpass.push_back(pass);
            cout<<"*";
            pass= getch();
        }
        //cin>>regpass;

        fstream reg("database.txt",ios::app); // Input User Details in databae.txt
        reg<<reguser<<' '<<regpass<<endl;

        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();

        return EXIT_FAILURE; // Same like Returning 0 to Calling Function to Indicate Either Failure
                             // Or Problem in The Certain Code.
}

