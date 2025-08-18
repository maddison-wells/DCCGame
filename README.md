# DCCGame

C++ game using SFML, based on the Dungeon Crawler Carl Series by Matt Dinniman

<h3>Goals List</h3>

<ul>
    <li>Get Carl to move into other areas - ❌</li>
    <li>Get Carl to interact with background - ❌</li>
    <li>Render background - ❌</li>
    <li>Render Carl and get him to move - ✅</li>
  </ul>

<h3>Refactor To-Do List</h3>
  <ul>
  <li> Refactor load() in Map to take all details from dataFile
    Not Started 17/8/25</li>
    <li>frameRate class
    - Rewatch part 16 1hr20.
    Not Started 12/8/25</li>
    <li>Movement function & walking animation
    - Not Started 5/8/25</li>
  </ul>

<h2>18th August 2025</h2>

Created a MapData struct

`std::stoi` turns a `string` into an `int`

So I'm up to 22/30 of the tutorial playlist and I was kinda thinking there was still a lot to cover in only 8 more lessons, turns out the tutorial is incomplete. Ive stilled learned a lot and will finish the available content but damn. Its probably good because I will really have to buckle in to get my level completed and might be able to boost my dopamine a bit more.

Today completed the datafile and parse, was able to load the titleSheet from there instead of coding it in. Need to go through when I have a little more attention span and sub in all the variables. I want to wait until I learn abut the editor and able to build my level one background out. So will add to my to-do.

<h2>17th August 2025</h2>

So the next step was to actually render a map onto the screen. At this stage of the learning process, I have assumed that a map is just a vector of numbers that is created. I suppose there is the option to assign names, like water, road etc but feel like maybe that is not a big time saver. Anyway, I created a dummyMap and then tired to figure out how to get it rendered. **So turning a 1D array into our 2D visual**

I read the documentation and found it lacking to what I was looking for, so I penciled out a general concept and then fed it to ChatGPT who tidied it up and gave me the below. I wanted to make sure I really understood, so have added additional inline comments below.

I think I need to practice algorithms more, as I understand how and I can think it out but actually getting it down is still tricky.

```cpp

void Map::DrawMapFromIDs(const std::vector<int>& mapData, int mapWidth, int mapHeight, sf::RenderWindow& window) //input when draw is called
{
    for (int y = 0; y < mapHeight; y++) { // for every row
        for (int x = 0; x < mapWidth; x++) { //we go column by column
            int i = x + y * mapWidth; // so that we give a number(index) to each position tile on our screen, 1D instead of 2 ie our Width is 60 and our position is y1, x 5 = that square has an index of 65.
            int tileID = mapData[i]; //that number position in our dummyMap has a value ie mapData[65] = '7'
            if (tileID >= 0 && tileID < tiles.size()) {
                Tile& t = tiles[tileID];// that value represents a tile in our tiles vector created in our load loop
                if (t.sprite) { //we create it - assign tile 7 to this square
                    t.sprite->setPosition(sf::Vector2f(x * tileWidth, y * tileHeight));
                    window.draw(*t.sprite);
                }
            }
        }
    }
}

void Map::Draw(sf::RenderWindow& window)
{
    DrawMapFromIDs(dummyMap, 60, 34, window);
}

```

Also started to learn about `std::fstream` which I suppose is the answer to my previous thoughts on how to use this efficiently for maps. I understand the benefit of having separate code for our maps, I assume you have a data file for each level and then just sub in as you go. We will see.

<h2>16th August 2025</h2>

I ran into the issue again where `sf::Sprite` has no default constructor, so trying to declare a `Tile` with a plain `sf::Sprite` caused the compiler to delete the default constructor and fail.

The solution was to use `std::unique_ptr<sf::Sprite>` instead. This lets us delay the construction of the sprite until we have a valid `sf::Texture`, avoiding the need for a default constructor and automatically managing memory.

I also used a vector instead of an array. I feel like having a mentor or working in a group would be really helpful here, I was able to find a work around and understand why it didn't work but I want to get it to work but already spent a lot of time on it the other day and don't want to stall my progress being caught up in the issue.

```cpp

// 2D tile map

tiles.clear();
tiles.reserve(totalTilesX * totalTilesY); //reserves memory

for (size_t y = 0; y < totalTilesY; y++) {
    for (size_t x = 0; x < totalTilesX; x++) {
        int i = x + y * totalTilesX;

        sf::IntRect rect(x * tileWidth, y * tileHeight, tileWidth, tileHeight);
        Tile tile(i, &tileSheetTexture, rect); // New Tile created here

        tile.sprite->setPosition(
            sf::Vector2f(100.f + static_cast<float>(x) * tileWidth,
                         100.f + static_cast<float>(y) * tileHeight)
        );

        tiles.emplace_back(std::move(tile)); // Tile is moved into the vector
    }
}

void Map::Draw(sf::RenderWindow& window) {
    for (auto& tile : tiles) {        //  range-based for loop
        if (tile.sprite) {
            window.draw(*tile.sprite); // dereference unique_ptr( if not dereferenced would give memory location)
        }
    }
}


```

<h2>15th August 2025</h2>

Arrays:
Memory management is better and its a built into the language of C++ unlike Vector(which is part of a library), better with speed. You need to initialise it with an amount, cant push more on later.

However, when I tried to use an array, I was having troubles with it needing a default constructor and was going around in circles. When I set the texture to the sprite, it wasn't liking that it was an array.

I ended up reverting back to a vector to construct sprites dynamically after we have a texture, allocating the memory first using `reserve` then `emplace_back` lets us build sprites with their required texture directly inside the vector, avoiding moving/extra memory.

Frustrated I couldn't get the array to work but hopefully I am about to still follow along with the tutorial as we make a map out of multiple sprites at a time

**Pointers**
`*`
Every title will have an ID. A pointer holds a memory address, but unlike reference we can change the memory address to something else. Makes sense for the map to be able to change. 8 byte pointer to a 10Mb texture, better than heaps of textures.

```cpp
int phoneNum = 2347892;

int* thePointer = &phoneNum;

std::cout << thePointer << std::endl; //returns memory address not value

std::cout << *thePointer << std::endl; //de-references

```

`Struct` - similar to class but all variables default to public unlike class that default to private. However, generally a struct is only for data, no functions etc.

<h2>14th August 2025</h2>

Making an editor

Tile is a single image that renders the world, using 32px x 32px

So a tilesheet is spilt into an array and then we tell the game to render giving each square of the game a relative number to the array, including 'empty' spots. The tutorial guy was able to load a small version of his entire sprite onto his screen but I wasn't able to that, it simply wouldn't appear. I tried a heap of trouble shooting but the solution seemed to be that the sprite was too big, once I used `sprite.setTextureRect` and set an amount, those tiles appeared.

So after adding in a health function for **Donut** my app crashed. I set up a constructor and everything worked fine except the health part.

Initially, I had my projectiles and collision logic inside **Carl**, but I was calculating projectile movement before properly accessing **Donut’s** position, and my projectile type or scope wasn’t consistent, which made them go to (0,0) or crashed the program. The fixes I made were: making sure projectiles were a vector of SFML drawable shapes, calculating direction only after confirming Donut exists and is loaded, checking collisions in a separate loop going backward when erasing projectiles, and ensuring all member variables like `boundingRectangle` were properly declared in the class. From this, I learned to always verify object existence and types before using them for movement or collisions, and to erase safely when looping through vectors.

In the tutorial, he renders the health above the enemy sprite but I will save that for later, as I want to have a health bar on top of the screen during game play.

<h2>13th August 2025</h2>

<h3>Tutorial Part 17 - Projectile Collision </h3>

projectile based:

Removing the projectile from the screen once they hit or go off screen. Need to be mindful of frames, if collision doesn't happen if too fast and colliding item isn't in frame. Can also happen if target is too small/thin

hitscan -

Casting a ray from certain origin and certain direction. If it hits, collision is detected.

Ray isn't cast from weapon but from the camera

Bullet Physics - Long shot, bullet drop

Fire Rate - Adding a condition to mouse press that uses deltaTime to calculate when the last bullet was fired and only allows the bullet to fire if fireRate(+= deltaTime) is >= maxFireRate which in this case is 1000(1s). fireRate needs to be reset to 0 with each loop. Faster bullets, change maxFireRate.

Another day, another lesson. The issue I was having yesterday, trying to put the frameRate stuff into its own class and failing came back to bite me in the ass. The same issue happened today and it was due to constructor/destructor. I should have persisted yesterday instead of being lazy to save myself the trouble today.

The issue was that in my `Carl.h` file, I was defining the constructor and destructor by including `{}` ie

```cpp
 Carl(){};
~Carl(){};
```

So when I went to my `Carl.cpp` and redefined both, the compiler was not happy. So now my `Carl.h` looks like this:

```cpp
 Carl();
~Carl();
```

<h2>12th August 2025</h2>

The tutorial moved the framerate code into its own class, but I couldn't quite get it to work and I was getting frustrated, so I have added it to my refactor list. I'm trying to be more mindful of my time when issues arise.

`~` destructor - same name as class and constructor - destroys.

<h2>11th August 2025</h2>

<h3>Tutorial Part 16 - Constructors, Destructors, Rendering Text </h3>

Render FPS - without Fraps
`FPS = 1000 / 16.67 ≈ 60`

To render, similar to sprite vs. texture relationship. `Text` is what is drawn but needs `Font` to say what to draw

```cpp
sf::Font font("../Assets/Fonts/Arial.ttf");
sf::Text frameRateText(font);
```

Reducing health
Destroy projectile when hits
Destroy projectile when outside

<h3>Tutorial Part 15 - Frame Rate </h3>

Uses Fraps to get frame rate we see that shooting bullets decreases frame rate, which slows the game.

`deltaTime` - Independent of frame rate

How long one frame takes to render. It will increase as my frame rate decreases to keep a stable game, we do this by:

1. Creating a clock and **restarting** it. I originally had it as reset and it tanked my game, do this in game loop.

2. From there we can calculate `deltaTime` and pass it in the Update loop

```cpp
  sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();
```

3. We then times the movement of sprites by `deltaTime`

I understand its important to game function but there are no dopamine hits in these theory based lessons 😴

<h2>10th August 2025</h2>

Funnily enough in the AABB tutorial, towards the end, the dude realised there was a intersection method already built in. I decided to read the docs and see if I could implement that myself.

```cpp
sf::FloatRect otherBox = ...;
if (const std::optional intersection = boundingBox.findIntersection(otherBox))
{
    // collision!
}
```

Don't really understand the difference between `getLocalBounds()` and `getGlobalBounds()` but that seems like a future me problem.

<h2>8th August 2025</h2>

<h3>Tutorial Part 14 - AABB Collision Detection </h3>

Axis Aligned Bounding Boxes

1Right > 2Left && 2Right > 1Left

<h3>Tutorial Part 13 </h3>

The goal of today was to clean up my code by creating classes for **Carl**,**Donut**, etc. However, I am now having trouble compiling them. I added my new header file to my `Makefile` but that didn't fix the issue. I also added a constructor but that is now also causing issue. Frustrated, I knew as soon as I started moving code, I would run into an issue.

Okay, so note to self, check youtube comments. I think a general practise I should implement is setting a time limit to trying to figure something out myself, then after x mins, look for it in the comments/use AI. I also didn't check the documentation, which should have been my first stop.

Explanation of what I was struggling with:

When you make an object of your class (like player), C++ automatically tries to create all the smaller parts inside it — these are called member variables.

For something like texture, C++ knows how to make it by itself because it has a simple way to create it without any extra info (a default constructor).

But for sprite, since version 3 of SFML, it needs some info to be created — it can’t just be made out of thin air. It needs a texture to work.

So, C++ can’t make sprite automatically unless you tell it how — which means you have to give it the texture when you create it. You do this by writing:

`Carl::Carl() : sprite(texture) {
    // now sprite is created using the texture you provide
}`

Classes

- Header file (.h/.hpp) - not complied. It's a blueprint. No code to execute. Is useful so that the large chunks are code aren't in multiple places, faster and smaller. Reduce compilation time

- .cpp - complied. Code to execute

- Reference `&`

- Static - let you use a function without having to create an object. (not Carl carl;) just Math. Not good for things where the variables will change ie health between 2 players, update on the other would to. Use when multiple objects will share the same data.

<h2>7th August 2025</h2>

<h3>Tutorial Part 12 - Creating and firing projectiles 🔫 *pow pow</h3>

`Direction Vector` = Target - Current location

`normalize` - length of vector (magnitude = pythagoras) make it equal 1, so that it moves in smaller increments - illusion of motion. Not preset, so need to use the function below.

** May need to have a case for 0,0 division **

```cpp

#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x *vector.x + vector.y * vector.y); //magnitude

    sf::Vector2f normalizedVector;

   normalizedVector.x = vector.x /m;
   normalizedVector.y = vector.y /m;


}
```

Steps for creating

1. Create NormalizeVector function outside main loop
2. Create vector projectiles, set shape - initialise
3. Create vector projectileDirection - initialise
4. Create variable for projectileSpeed - initialise
5. In game loop create `if` statement to add items to projectiles vector and set position of last item to position of firing sprite.
6. Game loop - `for loop` for each projectiles[i] - getting direction (sprite position - [i] position). - NormalizeVector(direction) - setPosition of i
7. in draw section - `for loop` that runs through projectiles vector and draws each i

This is all pretty straight forward logically, however remembering it all will take some practise.

<h2>6th August 2025</h2>

🎉 I forgot to mention I made it to my first goal yesterday. I was able to get **Carl** to move around the screen. Still need to finesse it with more character renders but it was for sure a win.

<p align="center">
<img src="img/gameplay/gameplay-2.png" width="250" height="180">
<img src="img/gameplay/gameplay-1.png" width="250" height="180">
</p>

Next goal is getting **Carl** to be able to interact with **Donut** and his environment, which is his apartment in the first level.

- Hexadecimal 0-F

- List - creates a variable for every event. ie (bullets)

`List<sf::sprite>` indexed based but in c++ its actual called a `Vector` and to add we use `push_back` and we use `size()` to get count

Example:

```cpp
std::vector<std::datatype> variable;

  variable.push_back(element);

std::cout << variable[index] << std::endl;

```

`size_t` an unsigned(non-negative numbers) integer type that can represent the size of the largest object your system can allocate. Use if vectors or containers you are using can't be negative. Otherwise use `int`

`capacity()` returns how many elements worth of memory have been allocated (reserved) in RAM

`reserve()` if vector size is known, you can reserve the amount/location of memory, meaning that during game loop if more items are added, there isn't a load being used to move the vector if capacity is reached. Best example case would be bullets, if there is a max amount of ammo, ie 200 bullets. The bullets vector can reserve 200 elements of memory, making the game faster.

<h2>5th August 2025</h2>

Ended up finishing up yesterday a little frustrated. As I mentioned before the tutorial I'm following is for an older version of SFML and I am working with SFML 3.0. I was having trouble getting my sprite to move around my screen with a key press event, it got to the point where I just needed to leave it and come back today with fresh eyes.

I solved the issue within 5 mins today... in the words of Ryland Grace I must have been in 'stupid mode'.

I've written the code for up,down,left and right by using a series of if statements, however, I feel there is probably a cleaner way to code this. So I will add it to my come back to it list.

<span style="color:orange; font-weight:bold;">By doing the movements outside the event loop, there is no delay in movement as the window class isn't being used.</span>

Next step, it rendering different sprites with the movement. And also create a limit to the movement, so the sprite can't be moved outside of the screen. Instead of watching the tutorial, I tried this myself by using `setTextureRect` in my `if `statement, which worked. I wonder again the code can be refactored. It doesn't seem to work for multiple renders though, when I did a quick google it looks like something called frames may be used. I will wait for the tutorial to cover that.

I found this really cool sprite generator - https://liberatedpixelcup.github.io/Universal-LPC-Spritesheet-Character-Generator/#

<p align="center">
  <strong>Here are my characters:</strong><br><br>

  <em>
    Carl sprite I generated — <a href="img/player/textures/sheet-credits.txt" target="_blank">Credit</a>
  </em>
  
  <em>
    Donut sprite from the "[LPC] Cats and Dogs" collection by bluecarrot16.<br>
    Licensed under CC-BY 3.0 / GPL 3.0 / GPL 2.0 / OGA-BY 3.0 — <a href="http://opengameart.org/content/lpc-cats-and-dogs" target="_blank">Source</a>
  </em>
</p>

<div style="text-align:center; display:flex; justify-content:center; gap:40px; align-items:center;">
  <div>
    <p><strong>Carl</strong></p>
    <img src="img/player/textures/carl.png" width="150" height="150" alt="Carl">
  </div>
  
  <div>
    <p><strong>Donut</strong></p>
    <img src="img/player/textures/donut.png" width="150" height="150" alt="Donut">
  </div>
</div>

<h2>4th August 2025</h2>

Another day, another Youtube tutorial.

- Texture - is a image made up of pixels. Can't 'draw' a texture only a sprite with a loaded texture.

- Sprite - can contain position, size, texture, scale, rotation. Apply/wrap a texture to the sprite and then move it.

<h2>3rd August 2025</h2>

The tutorial I am following is for an older version of SFML and when looking at the documentation to compare, it doesn't look like it has been updated either, which is interesting.

Still working my ways towards getting a pixel to move around the screen. Im interested in the idea of triple buffers, for example if you have a character that is about to move, the buffer will not know that is your intention until the event, so how useful is it?

Time will tell and by time I mean chatGPT. The way I understand it is that the buffer happens after the event not before, makes sense. So I guess the buffer just matches the screen until otherwise told.

What I learnt today:

- Vector 2f
  Origin (0,0) = (x,y) - which is in top left hand corner
  Used for position and direction.
  Can set a pivot point if needed to change origin point

- Antialiased shapes - smooth lines.

```cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "SFML shapes",
        sf::Style::Default,
        settings)}

```

- I drew and moved a circle around, which once the movement is related to an event, I would have completed my first goal

<img src="img/shape-tut.png">

<h2>2nd August 2025</h2>

That was painful. It took me 4hrs to get the compiler to work. I ended up finding this tutorial which was made within the month and was able to get to work from there. Also learned about Makefile, which is a helpful tool. I'm not sure why I can't just use the run button but you win some, you lose some.

https://www.youtube.com/watch?v=g4iqNGcw3-Q&ab_channel=SuboptimalEngineer

What I learnt today after the chaos:

- The game loop(update and draw functions), screen tearing (refresh rate imbalance) and triple buffers using 2 back-buffers.
- V-sync - monitor vs frames per second

<h2>1st August 2025</h2>

Still making my way through the online tutorial series, I've decided it will probably take about a month to work my way through. As I go I will be thinking about how each lesson related to my game.

Annoyingly, there is an issue with the SFML version I have installed and it doesn't like my code. This is where I get annoyed with self-learning because it takes ages to sort out issues, it would be good to have a mentor for things like this. I use chatGPT for this but sometimes I feel like I just go around in circles.

<h2>18th July 2025</h2>

https://www.youtube.com/playlist?list=PLs6oRBoE2-Q_fX_rzraQekRoL7Kr7s5xi

<h2>13th July 2025</h2>

15hr layover in Hong Kong finished off the intro course to C++

The thing I like about coding is that even though there are lots of languages the fundamentals are generally the same. So once you have a good understanding of loops and variables etc, you can use that knowledge as a blueprint to learn new things.

<h2>10th July 2025</h2>

<h3>Things to research:</h3>

<ol>Which 2D library to use</ol>
<ol>How to move an object around a screen</ol>

I feel like the fundamentals are very similar to Javascript, wondering if I should keep using CodeDex or just try jump in.

I got a copy of<a href="https://www.packtpub.com/en-us/product/sfml-game-development-by-example-9781785287343" target="_blank">
<em>SFML Game Development By Example: Create and develop exciting games from start to finish using SFML</em>
</a>

I saw a TikTok yesterday of some dude saying there's no point in learning C++. I'm not sure why I chose to understand it. Just struck out as interesting.

<h3>✅ Pros of C++</h3>
  <ul>
    <li>High performance and fast execution</li>
    <li>Fine control over memory and system resources</li>
    <li>Object-Oriented Programming (OOP) support</li>
    <li>Rich Standard Template Library (STL)</li>
    <li>Cross-platform compatibility</li>
    <li>Mature language with lots of community support</li>
    <li>Compatible with C code and libraries</li>
  </ul>

  <h3>❌ Cons of C++</h3>
  <ul>
    <li>Steep learning curve and complex syntax</li>
    <li>Manual memory management (risk of memory leaks, bugs)</li>
    <li>Lack of built-in safety features (e.g., garbage collection)</li>
    <li>Longer compile times</li>
    <li>Poor support for GUI/web out of the box</li>
    <li>Difficult debugging, especially with pointers/templates</li>
  </ul>

<h2>10th July 2025</h2>

It's funny how working towards a project that generally interests you is far more exhilarating than one that doesn't. Today, I did some more fundamental learning on Codedex. I'm also using ChatGPT to help answer questions that I have, such as 'Why do I need to use std:: to declare a string variable but not a double?'. I find its a good tool when self learning because you can just ask it the stupidest questions and you get a quick answer. I know using AI is a touchy subject but its not going anywhere so better to get on board then get let behind.

<h2>9th July 2025</h2>

After 12 months of not coding a single line of code, I thought it would be fun to dust of my skills and dive into a completely new language C++. Although I think about working in FinTech the most, working in gaming is something that has always been at the back of my mind. Imagine playing GTA and being able to say 'I coded that handbag you just stole off that Grandma'

I've decided to turn one of my favourite book series into a game, using the old-school Pokémon game as inspiration, like below. The reason for this is:

<li>Pokemon is ICONIC</li>
<li>I will be able to find graphics easily online, instead of spending 2 weeks drawing a tree and not coding</li>
<li>I assume there will be a lot of online resources to help me on my journey</li>
  <br>

<h3>To do list:</h3>

<ol>Scope out project: Write a brief 'script' of what the game will look like</ol>
<ol>Learn some basic C++: I have started a Codedex course just to compare to other languages I know</ol>
<ol>Look into how C++ integrates with 2D game framework or multimedia libraries</ol>

  <br>
<div style="white-space: nowrap;">
  <img src="https://i.redd.it/youddpmwkvba1.jpg" alt="Pokemon game scene" width="200">
  <img src="https://m.media-amazon.com/images/I/81EENArWHmL.jpg" alt="Dungeon Crawler Carl book cover" height="200">
</div>

<h3>Scope/Script</h3>

Long-term goal one is to build the first level of the game.

Intro: Small room, Carl playing CoD, sleeping Donut (cat). Text appears, prompting the player to locate Carl's smokes. The player can walk around the room until they find it, interacting with other objects.
Once the cigarette is lit, the room fills with smoke. The player must quickly open the window, timed. Once the window opens, Donut jumps out into tree. Have to dress Carl for the cold, pink crocs and coat, walk down the stairs inside the apartment (or maybe just a lazy out one door and automatically outside.)
Then, when outside, something like the apple catcher game, Carl tries to coax Donut out of the tree, and branches fall, which he must avoid. After avoiding x amount of branches, Ms Parsons yells at him, the world collapses, and the dungeon appears. Carl and Donut enter > Level Two.

Step one:

Build initial background and make Carl be able to walk around it.

```

```
