// Project:     catacombs(catacombs( ))
// Team:        RuffRiders
// Authors:     Ryan Appleby, Gabby Khan, Moon Skillin, Anuar Beisembayev
// Date:        09-28-2019 (hackUMBC)
// File:        character.cpp, file for character types
/* Description: This is the source code for our hackUMBC project, a text
   based adventure game set in fictional catacombs underneath real tunnels
   underneath the UMBC campus. It's a dungeon crawler, with relatively basic
   mechanics, and a constant hard coded map (no random room generation).    */

   #include "Character.h"


Character::Character(){

  // User inputs character information
  cout << "What is your name?" << endl;
  cin >> m_name;
  cout << "What is your class?" << endl;
  for (int i = 0; i < numClasses; i++){
    cout << i + 1 << ". " <<  m_classes[i] << endl;
  }
  cin >> m_class;
  while (m_class > 6 || m_class < 0){
    cout << "invalid choice! Please enter a choice 1-6" << endl;
    cin >> m_class;
  }

  // Character attributes are assigned
  m_class--;
  m_heal = m_health[m_class];
  m_spd = m_speed[m_class];
  m_attk = m_attack[m_class];
  m_def = m_defense[m_class];

}

Character::Character(int enemyNum){
  m_name = m_enemies[enemyNum];
  m_heal = m_Ehealth[enemyNum];
  m_attk = m_Eattack[enemyNum];
}
