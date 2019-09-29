// Project:     catacombs(catacombs( ))
// Team:        RuffRiders
// Authors:     Ryan Appleby, Gabby Khan, Moon Skillin, Anuar Beisembayev
// Date:        09-28-2019 (hackUMBC)
// File:        Game.cpp, game file to run game
/* Description: This is the source code for our hackUMBC project, a text
   based adventure game set in fictional catacombs underneath real tunnels
   underneath the UMBC campus. It's a dungeon crawler, with relatively basic
   mechanics, and a constant hard coded map (no random room generation).    */

#include "Game.h"
#include "Character.h"

//Game constructor, pass in a Created Character
Game::Game(Character ch){
  srand(time(NULL));
  int count = 1;
  pair<int, int> roomPair;
  // character string declaration
  cout << ch.m_name << " is a "<< ch.m_classes[ch.m_class] << ". They say hello!" << endl;
  int randomNum;

  // outputing stat data
  cout << "Health: " << ch.m_heal << endl;
  cout << "Attack: " << ch.m_attk << endl;
  cout << "Defense: " << ch.m_def << endl;
  cout << "Speed: " << ch.m_spd << endl;
  // int i = start space
  // roomIndex = 0 when starting
  int roomIndex = 0;
  // original push pair
  roomPair = {-1, 99};
  // possible choices that a user can make when moving
  vector<int> possibleChoices;
  // direction option that is chosen
  int chosenDirection;
  // next location chosen room number
  int nextLocation;
  // dynamically create new ToFrom
  ToFrom* toFrom = new ToFrom(roomPair);
  // push value to current room
  m_currentRoom.push(toFrom);
  // while you have not completed the maze (hardcoded)

  // flavor text beginning
  cout << "You wake up in a dark, slightly damp, very dank room. The last thing" << endl;
  cout << "you remember is finally deciding to try to exercise. You went to the" << endl;
  cout << "RAC, and then... and then...\nAnd then you woke up here." << endl;
  cout << "You can tell you're deep underground. You have to get out of here." << endl;

  while (m_currentRoom.read().second != 4 && m_currentRoom.read().second != 5 && ch.m_heal != 0){
    // possible choices cleared
    possibleChoices.resize(0);
    // iterater value set to 1
    count = 1;
    cout << "You are in room " << m_currentRoom.read().second << "."<< endl;
    randomNum = rand() % 10 + 1;

    // battle encounter code
    if (randomNum < int((100 - (m_currentRoom.read().second % 100)) / 10)){
      cout << "Battle Start!" << endl;
      int enemyType = rand() % 5 + 1;
      enemyType--;
      Character enemy = Character(enemyType);
      Battle(ch, enemy);
      // if you die
      if (ch.m_heal <= 0){
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "F" << endl;
        cout << "Segmentation fault (core dump)" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "jk" << endl;
      }
    }

    if (ch.m_heal > 0){
      cout << "Where do you want to go?" << endl;
      cout << "0. Investigate" << endl;
      // for the array of neighbors
      for (int j = 0; j < 4; j++){
        // if the value is not -1
        if (m_rooms.at(m_currentRoom.read().second).at(j) != -1){
          // put the value options into possible choices
          cout << count << ". " << m_choices[j] << endl;
          possibleChoices.push_back(j);
          count++;
        }
      }
      do {
        // user input
        cin >> roomIndex;
        if (roomIndex < 0 || roomIndex > count - 1){
          cout << "Invalid option." << endl;
        }

      }while (roomIndex < 0 || roomIndex > count - 1);
        if(roomIndex == 0){
            cout << m_flavorText.at(m_currentRoom.read().second) << endl;
          }
          else{
            chosenDirection = possibleChoices[roomIndex - 1];
            // if user moves north
            if (chosenDirection == 0){
              nextLocation = m_currentRoom.read().second - 10;
            }
            // if user moves south
            else if (chosenDirection == 1){
              nextLocation = m_currentRoom.read().second + 10;
            }
            // if user moves west
            else if (chosenDirection == 2){
              nextLocation = m_currentRoom.read().second - 1;
            }
            // if user moves east
            else if (chosenDirection == 3){
              nextLocation = m_currentRoom.read().second + 1;
            }
            // if you move back to previous location, pop
            if (nextLocation == m_currentRoom.read().first){
              m_currentRoom.pop();
            }
            // else push onto the stack
            else{
              roomPair = {m_currentRoom.read().second, nextLocation};
              toFrom = new ToFrom(roomPair);
              m_currentRoom.push(toFrom);
            }

          }
        }
      }
    if (ch.m_heal > 0){
      cout << "You are in room " << m_currentRoom.read().second << "."<< endl;
      cout << m_flavorText.at(m_currentRoom.read().second) << endl;

      // ending flavor m_flavorText
      cout << "The smell of old paper and stressed students is thick here." << endl;
      cout << "You've made it to the base of the AOK library and gallery, your route to freedom" << endl;
      cout << "You swipe your student ID in the slot by the elevator, swipe it again" << endl;
      cout << "because it didn't work the first time (ugh), and press the button." << endl;
      cout << "The doors slide open with grandeur, and you enter the elevator car." << endl;
      cout << "\nWhen the doors open next, you're standing on the seventh floor of" << endl;
      cout << "the library, looking out over a beautiful sunrise. To your right, you" << endl;
      cout << "see the silhouette of Dr. Freeman Hrabowski, illuiminated.\n" << endl;
      cout << "He turns, and smiles at you. The world fades away...\n\n" << endl;
      cout << "Congrats, you won the game!" << endl;

    }
  };

  void Game::Battle(Character ch, Character chE){
    int userChoice;
    cout << "You are in battle! Its time to decide" << endl;
    bool flee = false;
      // while neither are dead
      while (ch.m_heal > 0 && chE.m_heal > 0 && !flee){
        cout << "1. Fight" << endl;
        cout << "2. Flee" << endl;
        cout << "3. Item" << endl;
        cin >> userChoice;
        while (userChoice < 1 || userChoice > 3){
          cout << "invalid input" << endl;
          cin >> userChoice;
        }
      if (userChoice == 1){
        // subtract health
        cout << ch.m_name << " attacked " << chE.m_name << endl;
        // subtract health from attack
        chE.m_heal = chE.m_heal - ch.m_attk;
        // if health is less than 0, set it to 0
        if (chE.m_heal < 0){
          chE.m_heal = 0;
        }
        cout << chE.m_heal << " is the enemy health now" << endl;
        // if health is not yet 0, attack
        if (chE.m_heal > 0){
          cout << chE.m_name << " attacked " << ch.m_name << endl;
          ch.m_heal = ch.m_heal - chE.m_attk;
          // if health is less than 0, set it to 0
          if (ch.m_heal < 0){
            ch.m_heal = 0;
          }
          cout << ch.m_heal << " is your health now" << endl;
        }
      }
    else if (userChoice == 2){
      int randEscape = rand() % 10 + 1;
      // if the escape value is greater than speed, no escape
      if (randEscape > ch.m_spd){
        cout << "You couldn't get away" << endl;
      }
      //else, Flee
      else{
        cout << "In panic, you fled!" << endl;
        flee = true;
        m_currentRoom.pop();
        cout << "You are in room " << m_currentRoom.read().second << "."<< endl;
      }
    }
    else if (userChoice == 3){
      cout << "Coming soon!" << endl;
    }
  }
  }
