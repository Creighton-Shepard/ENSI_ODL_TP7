# ENSI-ODL-TP5

##Author : Christophe Génard

## Purpose
Simulate the Connect4 game

## Compile Command (at the project root)
### game & tests

`make`

### clean object file

`make clean` 

### clean library

`make clean_library` 

## Run Command (at the project root)
### Run the game

`./bin/Connect4 <file>`
    -> working example : `./bin/Connect4 ./data/Current_dim.txt`

### Run the tests
#### Run matrix tests

`./bin/testmatrix`

#### Run game tests

`./bin/testgame`







export LD_LIBRARY_PATH=./lib/