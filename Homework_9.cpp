
#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <thread>
#include <conio.h>

#pragma comment(lib, "winmm")

using namespace std;

string q_a_mass(string get_s, int get, int turn)
{
        string quests[15] = { "Name of our Galexy is ? ", "Most tought animal is ?", "Multyuniverse theory mean: ?", "Highest point of Earth is ?", "Strong atomic interaction is ?",
        "First Newtin law mean ?", "Minimal biologycal unit of heredity ?", "Japan was isolated islands web to ... year", "First who reach Amerika was ?",
        "Burning is a chemical reaction what mean ...", "First computer was invented in ... year", "Warmest point of fire is ?", "0 by K temperature system is ... by C",
        "Cat is ?", "Pascal first law ?" };
        string answers[15][4] = { {"Milky Way", "Universy", "Andromeda", "Alpha Centauri"}, {"Tardigrades", "Lion", "Ant", "Elephant"},
            {"existing of paralel universes", "existing of another worlds", "existing of other life", "existing of other you"}, {"Everest", "Chogori", "Kanchenjunga", "Lhotse"},
            {"attraction between nucleons", "attraction between cores", "attractions between electrons", "atraction between protons"},
            {"Any body will stay in his condition till other forse will change it", "Any forse have opposite forse equal streng", "a = F/m", "E = mc^2"},
            {"DNA", "RNA", "protein", "Chromosome"}, {"1603-1868", "1520-1603", "1868-1900", "1603-1823"}, {"Vikings", "France", "Italy", "England"},
            {"Light and heat emission", "Energy emission", "heat emission", "Light absorption"}, {"1927", "1938", "1939", "1940"}, {"outer", "middle", "core", "all equal"},
            {"-273", "-237", "0", "-247"}, {"fluid animal", "fluid", "unknown", "animal"},
            {"preasure on gas/fluid transmitted in all directions equally", "preasure on gas imposible", "preasure is not-inertial forse", "preasure throught fluid will go without barriers"} };

            if (turn == 0)
                get_s = quests[get];
            else if (turn == 1)
                get_s = answers[get][0];
            else if (turn == 2)
                get_s = answers[get][1];
            else if (turn == 3)
                get_s = answers[get][2];
            else if (turn == 4)
                get_s = answers[get][3];
            return(get_s);
}

int pressed(int key)
{
    int count = 0;
    while (count< 500)
    {
        bool somethingpressed = _kbhit();
        if (somethingpressed)
        {
            key = _getch();
            break;
        }
        count++;
        Sleep(1);
    }
    return(key);
}

int main()
{
    int key;
    srand(time(0));
    string question;
    string a_0, a_1, a_2, a_3;
    string a_mass[4] = { a_0, a_1, a_2, a_3 };
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t\tOH! THE LUCKER!\n\n\n1 - Start\n\n2 - Exit\n\n";
        key = _getch();
        cout << key << "\n";
        if (key == 49)
        {
            bool is_end = false;
            for (int quest = 0; quest < 15 && is_end == false; quest++)
            {
                key = 0;
                int get = rand() % 15;
                question = q_a_mass(question, get, 0);
                a_0 = q_a_mass(question, get, 1);
                a_1 = q_a_mass(question, get, 2);
                a_2 = q_a_mass(question, get, 3);
                a_3 = q_a_mass(question, get, 4);
                for (int round = 60; round > 0 && key != 97 && key != 98 && key != 99 && key != 100 ; --round)
                {
                    system("cls");
                    cout << "\t\t\t\t" << round << "\n" << "\n\t\t" << question << "\n\nA: " << a_0 << "\n\nB: " << a_1 << "\n\nC: " << a_2 << "\n\nD: " << a_3 << "\n";
                    key = pressed(0);
                }
                if (key == 97)
                {
                    system("cls");
                    cout << "\n\n\t\t\tright!";
                    if (quest == 14)
                    {
                        system("cls");
                        cout << "\n\n\n\t\t\t\tYOU WIN!";
                    }
                    Sleep(1000);
                }
                else
                {
                    system("cls");
                    cout << "\n\n\t\t\twell, YOU LOOSE!";
                    Sleep(1000);
                    continue;
                }
            }
        }
        else if (key == 48)
        {
            exit(1);
        }
    }
}