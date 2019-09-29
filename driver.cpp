// Project:     catacombs(catacombs( ))
// Team:        RuffRiders
// Authors:     Ryan Appleby, Gabby Khan, Moon Skillin, Anuar Beisembayev
// Date:        09-28-2019 (hackUMBC)
// File:        driver.cpp, runs the main code
/* Description: This is the source code for our hackUMBC project, a text
   based adventure game set in fictional catacombs underneath real tunnels
   underneath the UMBC campus. It's a dungeon crawler, with relatively basic
   mechanics, and a constant hard coded map (no random room generation).    */

//////// section: header /////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Character.h"

#include "MyStack.h"
using namespace std;

//////// section: function main //////////////////////////////////////////////
int main(){
  Character character = Character(); // variable for the player char.

  // create game and character
  Game game = Game(character);
  return 0;
}
