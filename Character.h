// Project:     catacombs(catacombs( ))
// Team:        RuffRiders
// Authors:     Ryan Appleby, Gabby Khan, Moon Skillin, Anuar Beisembayev
// Date:        09-28-2019 (hackUMBC)
// File:        Character.h, file for our character types
/* Description: This is the source code for our hackUMBC project, a text
   based adventure game set in fictional catacombs underneath real tunnels
   underneath the UMBC campus. It's a dungeon crawler, with relatively basic
   mechanics, and a constant hard coded map (no random room generation).    */

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Character{
public:
  // default constructor
  Character();

  // overloaded constructor
  Character(int);

  // character stats
  int m_heal;
  int m_attk;
  int m_def;
  int m_spd;

  //parallel arrays for character class info
  string m_classes[6] = {"Warrior", "Mage", "Cleric", "Ninja", "Monk", "Student"};
  int m_health[6] = {25, 18, 21, 20, 27, 20};
  int m_attack[6] = {8, 8, 6, 4, 5, 5};
  int m_defense[6] = {4, 2, 3, 5, 6, 1};
  int m_speed[6] = {2, 3, 3, 5, 4, 7};
  string m_name;
  int m_class;

  string m_enemies[7] = {"VSCO Squirrel", "Zombie Loan Packet", "Father No-Time", "Creeper... Aw Man", "Final Parking Spot", "False Grit", "Dr. P"};
  int m_Ehealth[7] = {3, 3, 3, 3, 3, 6, 7};
  int m_Eattack[7] = {3, 3, 3, 3, 3, 5, 5};
private:
  int numClasses = 6;
};
#endif
