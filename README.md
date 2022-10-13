# 42_Cub3D

![42_logo](https://user-images.githubusercontent.com/76601093/193692098-d4b16956-1dab-40b8-9aae-31b254efc5ee.jpg)


  > "This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever."

  > "Now, it’s your turn to relive History..."

## Description

The aim of this project is to explore ray-casting with the goal to make a dynamic view inside a maze.

It is the second design project in the 42Cursus and the students are able to learn about graphics, events and masks, colors, fill shapes, windows, etc.

To be able to do this 3D Game is necessary to "explore the playful practical applications of mathematics without having to understand the specifics.

The project must be done using the Ray-Casting principles and it should be a 3D graphical representation from inside of a maze from a first-person perpective.

## Documentation

[42 Docs - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

[Raycasting - Lode Vandevenne](https://lodev.org/cgtutor/raycasting.html)

## Installing minilibx

    git clone https://github.com/42Paris/minilibx-linux.git
    cd minilibx-linux

    make

    sudo apt install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev
    
	cd /usr/local/man/
	sudo mkdir man1

    (Return to the minilibx-linux directory)

    sudo cp man/man1/* /usr/local/man/man1/
    sudo cp libmlx.a /usr/local/lib/
    sudo cp mlx.h /usr/local/include/
    
    man mlx
    (Must show the minilibx manual)

### Important

   It was made for Mac, so may not be able to move on linux because of the key bindings