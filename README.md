# DCCGame

C++ game based on the Dungeon Crawler Carl Series by Matt Dinniman

<h3>Refactor To-Do List</h3>
  <ul>
    <li>Movement function & walking animation
    - Not Started 5/8/25</li>
  </ul>

<h2>5th August 2025</h2>

Ended up finishing up yesterday a little frustrated. As I mentioned before the tutorial I'm following is for an older version of SFML and I am working with SFML 3.0. I was having trouble getting my sprite to move around my screen with a key press event, it got to the point where I just needed to leave it and come back today with fresh eyes.

I solved the issue within 5 mins today... in the words of Ryland Grace I must have been in stupid mode.

I've written the code for up,down,left and right by using a series of if statements, however, I feel there is probably a cleaner way to code this. So I will add it to my come back to it list.

<span style="color:orange; font-weight:bold;">By doing the movements outside the event loop, there is no delay in movement as the window class isn't being used.</span>

Next step, it rendering different sprites with the movement. And also create a limit to the movement, so the sprite can't be moved outside of the screen. Instead of watching the tutorial, I tried this myself by using `setTextureRect` in my `if `statement, which worked. I wonder again the code can be refactored. It doesn'e seem to work for multiple renders though, when I did a quick google it looks like something called frames may be used. I will wait for the tutorial to cover that.

I found this really cool sprite generator - https://liberatedpixelcup.github.io/Universal-LPC-Spritesheet-Character-Generator/#

<a href="img/player/textures/sheet-credits.txt" target="_blank">
<em>Credit to the creators 
</em>
</a>

Here is my character Carl

<img src="img/player/textures/carl.png" width="150" height="150">

And here is Donut
"[LPC] Cats and Dogs" Artist: bluecarrot16 License: CC-BY 3.0 / GPL 3.0 / GPL 2.0 / OGA-BY 3.0 Please link to opengameart: http://opengameart.org/content/lpc-cats-and-dogs"

<img src="img/player/textures/donut.png" width="75" height="75">

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

What I learnt today after the choas:

- The game loop(update and draw functions), screen tearing (refresh rate imbalance) and triple buffers using 2 back-buffers.
- V-sync - mointor vs frames per second

<h2>1st August 2025</h2>

Still making my way through the online tutorial series, I've decided it will probably take about a month to work my way through. As I go I will be thinking about how each lesson related to my game.

Annoyingly, there is an issue with the SFML version I have instaled and it doesn't like my code. This is where I get annoyed with self-learning because it takes ages to sort out issues, it would be good to have a mentor for things like this. I use chatGPT for this but sometimes I feel like I just go around in circles.

<h2>18th July 2025</h2>

https://www.youtube.com/playlist?list=PLs6oRBoE2-Q_fX_rzraQekRoL7Kr7s5xi

<h2>13th July 2025</h2>

15hr layover in Hong Kong finished off the intro course to C++

The thing I like about coding is that even though there are lots of languges the fundementals are generally the same. So once you have a good understanding of loops and variables etc, you can use that knowledge as a blueprint to learn new things.

<h2>10th July 2025</h2>

<h3>Things to research:</h3>

<ol>Which 2D library to use</ol>
<ol>How to move an object around a screen</ol>

I feel like the fundementals are very similar to Javascript, wondering if I should keep using codedex or just try jump in.

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

After 12 months of not coding a single line of code, I thought it would be fun to dust of my skills and dive into a completely new language C++. Although I think about working in fintech the most, working in gaming is something that has always been at the back of my mind. Imagine playing GTA and being able to say 'I coded that handbag you just stole off that Grandma'

I've decided to turn one of my favourite book series into a game, using the old-school Pokémon game as inspiration, like below. The reason for this is:

<li>Pokemon is ICONIC</li>
<li>I will be able to find graphics easily online, instead of spending 2 weeks drawing a tree and not coding</li>
<li>I assume there will be a lot of online resources to help me on my journey</li>
  <br>

<h3>To do list:</h3>

<ol>Scope out project: Write a brief 'script' of what the game will look like</ol>
<ol>Learn some basic C++: I have started a codedex course just to compare to other languages I know</ol>
<ol>Look into how C++ integrates with 2D game framework or multimedia libraries</ol>

  <br>
<div style="white-space: nowrap;">
  <img src="https://i.redd.it/youddpmwkvba1.jpg" alt="Pokemon game scene" width="200">
  <img src="https://m.media-amazon.com/images/I/81EENArWHmL.jpg" alt="Dungeon Crawler Carl book cover" height="200">
</div>

<h3>Scope/Script</h3>

Long-term goal one is to build the first level of the game.

Intro: Small room, Carl playing CoD, sleeping Donut (cat). Text appears, prompting the player to locate Carl's smokes. The player can walk around the room until they find it, interacting with other objects.
Once the cigarette is lit, the room fills with smoke. The player must quickly open the window, timed. Once the window opens, Donut jumps out into tree. Have to dress Carl for the cold, pink crocs and coat, walk down the stairs inside the apartment ( or maybe just a lazy out one door and automatically outside.
Then, when outside, something like the apple catcher game, Carl tries to coax Donut out of the tree, and branches fall, which he must avoid. After avoiding x amount of branches, Ms Parsons yells at him, the world collapses, and the dungeon appears. Carl and Donut enter > Level Two.

Step one:

Build inital background and make Carl be able to walk around it.

```

```
