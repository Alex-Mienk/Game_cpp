The easiest way to run it would be to open in visual studio and import these files to a new project. Then compile all and run the main.cpp

Otherwise, you would need a C++ compiler (e.g. g++, clang++)

Run the command:
g++ -std=c++11 -o my_program main.cpp Character.cpp HealTouchSpell.cpp Spell.cpp Warrior.cpp ArcaneMissileSpell.cpp Warlock.cpp ./my_program

Where my_program is the directory you will store the files in
