# Bootleg 2048



## Description
A 2048 clone with some minor differences, written in C using [ncurses](https://invisible-island.net/ncurses/) for the display. Due to formatting difficulties caused by displaying multiple digit numbers, the exponent x is displayed instead of the actual result of 2<sup>x</sup>. The game stops at 2<sup>10</sup> (1024) instead of 2<sup>11</sup> (2048) for the same reason.

This project, while not very large in scale, presented a few challenges. Making sure the tile movement logic was accurate to the original game was more difficult than I expected, and there were a lot of little bugs that needed to be fixed.


## Instructions

### Build
Simply run the command:
```bash
> make
```

This first builds `customlib.a` (the custom standard-library replacement) inside `customlib/`, then compiles and links the game into a `2048` executable in the project root.
Other targets:
```bash
> make clean   # remove object files
> make fclean  # remove object files and the executable
> make re      # fclean + all
```

### Run
The executable can be run using
```bash
> ./2048
```

### How to play
1. Two tiles are placed on a 4x4 board to start.
2. Move all tiles at once with a key:
   - **w**: up
   - **a**: left
   - **s**: down
   - **d**: right
3. Tiles that collide at the same level merge into the next level up, and a new tile is added after every move that changes the board.
4. Reach the top-level tile (shown as `*`) to win, or lose once the board fills up with no merges left to make.
5. When the game ends, choose whether to play again (`y`/`n`).
