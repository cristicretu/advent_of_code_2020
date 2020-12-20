# Advent of Code 2020

My first time at aoc - cpp and python

### Running the programs

------

The solutions are standalone cpp programs so no worries about compiling.

They are tested with 

```
g++ -std=c++14 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result // fast 
g++ -std=c++14 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG // slow but safe
```

