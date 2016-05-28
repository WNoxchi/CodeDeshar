13-Jan-2016 19:24
Solved the horizontal separation issue. Multiply both BRICK_WIDTH & BRICK_SEP (separation) by the current stage of iteration. Because the width and separation are different sizes, multiplying them by the same factor results in an even spacing that doesn't shrink or grow.

13-Jan-2016 19:32
Starting work on player paddle.

14-Jan-2016 00:25
Finished work on player paddle. Enabled mouse-tracked movement within proper bounds. The problem I had was 2 bugs which worked to hide each other. Firstly, I learned that re-declaring the Paddle object as a GRect when drawing it breaks the OOP abstraction - in practical terms the computer no longer knew what the hell I meant when I'd later tell it "move the paddle there" -- "huh? what paddle?" [NullPointerException].  Secondly my coordinates were off. I was telling the computer to move the paddle somewhere off-screan. The first bug results in no movement, the second makes the paddle disappear.

14-Jan-2016 00:34
Started working on Ball animation.

14-Jan-2016 02:00
Successfully implemented ball animation & wall-collision detection/bouncing. Started work on object collisions.

14-Jan-2016 03:07
The ball now bounces off the paddle and bricks are removed when hit. Need to implement bouncing on brick collision.

14-Jan-2016 03:58
Basic functionality done. Game works. Added a "You Lose!!!" message.

14-Jan-2016 04:11
Added Click-to-Start. Done for the night.
