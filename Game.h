// Project:     catacombs(catacombs( ))
// Team:        RuffRiders
// Authors:     Ryan Appleby, Gabby Khan, Moon Skillin, Anuar Beisembayev
// Date:        09-28-2019 (hackUMBC)
// File:        Game.h, header file
/* Description: This is the source code for our hackUMBC project, a text
   based adventure game set in fictional catacombs underneath real tunnels
   underneath the UMBC campus. It's a dungeon crawler, with relatively basic
   mechanics, and a constant hard coded map (no random room generation).    */

#ifndef GAME_H
#define GAME_H
#include "Character.h"
#include "MyStack.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class Game{

const int VACANT = -1;

public:
  Game();
  Game(Character ch);
  void Battle(Character ch, Character chE);

private:
  // array of possible choices of directions
  string m_choices[4] = {"NORTH", "SOUTH", "WEST", "EAST"};
  // pair of ints to push on stack
  pair<int, int> m_roomPair;
  // stack of current room var
  MyStack m_currentRoom;

  vector<string> m_flavorText = {
"You can faintly smell motor oil and gasoline fumes.",
"You can faintly smell motor oil and gasoline fumes.",
 "You can faintly smell motor oil and gasoline fumes.",
 "",
"This is it. You're at the base of the AOK library.",
"This is it. You're at the base of the AOK library.",
"",
"",
"",
"",
"To the West, you can see some gnarled roots.",
"",
"Nothing particularly noteworthy here.",
"",
"You smell dusty books. You must be close.",
"You smell dusty books. You must be close.",
 "",
"",
"",
"",
"To the West, you can see some gnarled roots. They extend across the ceiling, too.",
 "Tree roots weave across the span of the ceiling.",
"Tree roots weave across the span of the ceiling.",
"If you really listen for it, you can hear water running through pipes.",
"You can hear, very faintly, the sound of water running through pipes.",
"You can hear shoes hitting the ground far above you.",
"Nothing particularly noteworthy here.",
 "Nothing particularly noteworthy here.",
"",
 "You can hear… donuts? You… aren’t sure how that’s possible.",
 "To the West, you can see some gnarled roots. They reach across part of the ceiling, too.",
 "Tree roots weave across the span of the ceiling.",
 "Tree roots weave across the span of the ceiling.",
"Nothing particularly noteworthy here.",
"Nothing particularly noteworthy here.",
"",
"",
"Nothing particularly noteworthy here.",
"From above, you hear people serving falafel (in frustratingly small amounts).",
 "You vaguely hear the roar of many, many idiot college kids talking.",
 "You can actually see some sunlight streaming down… someone installed a skylight?",
 "",
 "",
"",
 "",
 "",
"",
 "",
 "Nothing particularly noteworthy here.",
 "",
 "You can actually see some sunlight streaming down… someone installed a skylight?",
 "",
 "",
 "",
 "You can see a trickle of saltwater running down the North wall… freshmen’s tears…",
 "You can hear shoes hitting the ground far above you.",
 "The sound of harsh wind whipping past a construction site fills the room.",
 "Nothing particularly noteworthy here.",
 "Nothing particularly noteworthy here.",
 "",
 "You can actually see some sunlight streaming down… someone installed a skylight?",
 "",
 "The dulcet tones of 10 year old computers whirring drifts through the ceiling.",
 "The dulcet tones of 10 year old computers whirring drifts through the ceiling.",
 "The bitter syrup of baristas’ tears coats the South wall and drips from the roof.",
"You can hear shoes hitting the ground far above you.",
"The sounds of chalk on chalkboards grates on you, even this far down.",
"The sounds of chalk on chalkboards grates on you, even this far down.",
 "Nothing particularly noteworthy here.",
"this is a null room but ayyyyy ;P ",
 "Nothing particularly noteworthy here… wait, huh? The South wall seems... weird.",
"",
"The dulcet tones of 10 year old computers whirring drifts through the ceiling.",
"",
 "",
 "You can hear shoes hitting the ground far above you.",
 "",
 "",
 "You smell chlorine and sweat…",
"",
 "",
 "Nothing particularly noteworthy here. Unless… what’s going on with the North wall?",
 "You can hear a very muffled voice talking about… pythons?",
 "",
 "",
 "Honors college freshmen have distinct energy signatures… you can sense many here.",
 "You have a vision of a single brick far above you. The side of it says ‘eat the rich.’",
 "You have a vision of a single brick far above you. The side of it says ‘eat the rich.’",
 "",
 "You think a distant thought, criss-crossed plastic stretched over a round metal frame.",
 "",
 "",
 "",
 "You can hear a very muffled voice talking about… pythons?",
 "Honors college freshmen have distinct energy signatures… you can sense many here.",
 "Honors college freshmen have distinct energy signatures… you can sense many here.",
 "You have a vision of a single brick far above you. The side of it says ‘eat the rich.’",
 "You have a vision of a single brick far above you. The side of it says ‘eat the rich.’",
 "The smell of sweat and exposed shoulders filters in from above.",
"You can hear a basketball thumping on the roof overhead. You must be below the RAC."


};

  //hard coded items
  vector<pair<vector<string>, vector<int>>> m_items{
    {{"a sandwich", "f l a v o r get", " flavor use"}, {10, 0, 0, 0}},



  };

  // data of each cells neighbors
  vector<vector<int>> m_rooms = {
    {-1, 10, -1, 1},
    {-1, -1, 0, 2},
    {-1, 12, 1, -1},
    {-1, -1, -1, -1},
    {-1, 14, -1, 5},
    {-1, 15, 4, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {0, 20, -1, -1},
    {-1, -1, -1, -1},
    {2, 22, -1, -1},
    {-1, -1, -1, -1},
    {4, 24, -1, 15},
    {5, 25, 14, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {10, 30, -1, -1},
    {-1, 31, -1, -1},
    {12, -1, -1, 23},
    {-1, -1, 22, 24},
    {14, 34, 23, -1},
    {14, -1, -1, 26},
    {-1, -1, 25, 27},
    {-1, 37, 26, -1},
    {-1, -1, -1, -1},
    {-1, 39, -1, -1},
    {20, 40, -1, -1},
    {21, -1, -1, 32},
    {-1, -1, 31, 33},
    {-1, -1, 32, 34},
    {24, -1, 33, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {27, -1, -1, 38},
    {-1, 48, 37, 39},
    {29, -1, 38, -1},
    {30, 50, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {38, 58, -1, -1},
    {-1, -1, -1, -1},
    {40, 60, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, 64, -1, 55},
    {-1, -1, 54, 56},
    {-1, 66, 55, 57},
    {-1, -1, 56, 58},
    {48, -1, 57, -1},
    {-1, -1, -1, -1},
    {50, 70, -1, -1},
    {-1, -1, -1, -1},
    {-1, 72, -1, 63},
    {-1, -1, 62, 64},
    {54, -1, 63, 65},
    {-1, 75, 64, 66},
    {56, -1, 65, 67},
    {-1, -1, 66, 68},
    {-1, 78, 67, -1},
    {-1, -1, -1, -1},
    {60, -1, -1, -1},
    {-1, -1, -1, -1},
    {62, 82, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {65, 85, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {68, 88, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, 82},
    {72, -1, 81, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {75, 95, -1, 86},
    {-1, 96, 85, 87},
    {-1, -1, 86, 88},
    {78, -1, 87, -1},
    {-1, 99, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, -1},
    {-1, -1, -1, 94},
    {-1, -1, 93, 95},
    {85, -1, 94, -1},
    {86, -1, -1, 97},
    {-1, -1, 96, 98},
    {-1, -1, 97, 99},
    {89, -1, 98, -1}
  };
  // this is a list of the rooms and their valid exits, ordered NSWE

};

#endif
