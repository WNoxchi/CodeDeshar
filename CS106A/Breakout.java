/*
 * File: Breakout.java
 * Wayne H. Noxchi
 * -------------------
 * CS106A Assignment 3
 * Start:   13-Jan-2016 17:56
 */
import acm.graphics.*;
import acm.program.*;
import acm.util.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
public class Breakout extends GraphicsProgram {
/** Width and height of application window in pixels */
 public static final int APPLICATION_WIDTH = 400;
 public static final int APPLICATION_HEIGHT = 600;
/** Dimensions of game board (usually the same) */
 private static final int WIDTH = APPLICATION_WIDTH;
 private static final int HEIGHT = APPLICATION_HEIGHT;
/** Dimensions of the paddle */
 private static final int PADDLE_WIDTH = 60;
 private static final int PADDLE_HEIGHT = 10;
/** Offset of the paddle up from the bottom */
 private static final int PADDLE_Y_OFFSET = 30;
/** Number of bricks per row */
 private static final int NBRICKS_PER_ROW = 10;
/** Number of rows of bricks */
 private static final int NBRICK_ROWS = 10;
/** Separation between bricks */
 private static final int BRICK_SEP = 4;
/** Width of a brick */
 private static final int BRICK_WIDTH =
 (WIDTH - (NBRICKS_PER_ROW - 1) * BRICK_SEP) / NBRICKS_PER_ROW;
/** Height of a brick */
 private static final int BRICK_HEIGHT = 8;
/** Radius of the ball in pixels */
 private static final int BALL_RADIUS = 10;
/** Offset of the top brick row from the top */
 private static final int BRICK_Y_OFFSET = 70;
/** Number of turns */
 private static final int NTURNS = 3;

 // Instance Variables
 private GRect Paddle;   //  Paddle
 private double vx, vy;  //  Variables Ball Velocity XY components
 private GOval Ball;     //  Ball

     public void run() {
     /* You fill this in, along with any subsidiary methods */
          addMouseListeners();
          drawBricks();
          drawPaddle();
          drawBall();
          ballMove();
     }

     // Draw and color bricks.
     private void drawBricks() {
          for (int i = 0; i < NBRICK_ROWS; i++) {
              for (int j = 0; j < NBRICKS_PER_ROW; j++) {
                  int colors = i / 2;
                  GRect brick = new GRect(BRICK_WIDTH, BRICK_HEIGHT);
                  brick.setFilled(true);
                  add(brick, (BRICK_SEP * j + BRICK_WIDTH * j), (BRICK_Y_OFFSET + BRICK_SEP*i + BRICK_HEIGHT * i));
                  brick.setColor(chooseColor(i / 2));
              }
          }
     }

     private void drawPaddle() {
         // Add Player's Paddle
          Paddle = new GRect(PADDLE_WIDTH, PADDLE_HEIGHT);
          Paddle.setFilled(true);
          Paddle.setColor(Color.BLACK);
          add(Paddle, (APPLICATION_WIDTH - PADDLE_WIDTH) / 2, APPLICATION_HEIGHT - PADDLE_Y_OFFSET * 2);
     }

     // Draw Ball
     private void drawBall() {
         Ball = new GOval(BALL_RADIUS, BALL_RADIUS);
         Ball.setFilled(true);
         add(Ball, (APPLICATION_WIDTH - BALL_RADIUS * 2) / 2, APPLICATION_HEIGHT / 2);
     }

     // Ball Motion
     private void ballMove() {
         waitForClick();
         vy = rgen.nextDouble(2.0, 9.0);
         vx = rgen.nextDouble(2.0, 9.0);
         if (rgen.nextBoolean(0.5)) vx = -vx;
         while(true) {
             Ball.move(vx, vy);
             checkForCollision();
             GObject collider = getCollidingObject();
             if (collider == Paddle) {
                 vy = -vy;
                //  Ball.move(vx, vy);
             }
             else if (collider != null) {
                 remove(collider);
                 vy = -vy;
             }
             pause(50);
         }
     }

     // Collision Check
     private void checkForCollision() {
         if (Ball.getY() < BALL_RADIUS) {
             vy = -vy;
             Ball.move(vx, vy);
         }
         if (Ball.getX() > APPLICATION_WIDTH - BALL_RADIUS * 2 || Ball.getX() < BALL_RADIUS) {
             vx = -vx;
             Ball.move(vx, vy);
         }
         else if (Ball.getY() > APPLICATION_HEIGHT - BALL_RADIUS * 3) {
             GLabel Loser = new GLabel("YOU LOSE!!!");
             Loser.setFont("Times-69");
             Loser.setColor(Color.RED);
             add(Loser, (APPLICATION_WIDTH - Loser.getWidth()) / 2, APPLICATION_HEIGHT/2);
         }
     }

     // Returns Object involved in collision, null otherwise.
     private GObject getCollidingObject() {
         if ((getElementAt(Ball.getX(), Ball.getY())) != null) {
             return getElementAt(Ball.getX(), Ball.getY());
         }
         else if ((getElementAt(Ball.getX() + BALL_RADIUS * 2, Ball.getY())) != null) {
             return getElementAt(Ball.getX() + BALL_RADIUS * 2, Ball.getY());
         }
         else if ((getElementAt(Ball.getX(), Ball.getY() + BALL_RADIUS * 2)) != null) {
             return getElementAt(Ball.getX(), Ball.getY() + BALL_RADIUS * 2);
         }
         else if ((getElementAt(Ball.getX() + BALL_RADIUS * 2, Ball.getY() + BALL_RADIUS * 2)) != null) {
             return getElementAt(Ball.getX() + BALL_RADIUS * 2, Ball.getY() + BALL_RADIUS * 2);
         }
         else {
             return null;
         }
     }

     // making the mouse track the paddle
     public void mouseMoved(MouseEvent e) {
         if (e.getX() > PADDLE_WIDTH && e.getX() < APPLICATION_WIDTH - PADDLE_WIDTH) {
         Paddle.setLocation(e.getX() - PADDLE_WIDTH / 2, APPLICATION_HEIGHT - PADDLE_Y_OFFSET - PADDLE_HEIGHT * 4);
         }
     }

     // Switch to assign integer codes to colors
     private Color chooseColor(int color) {
         switch(color) {
             case 0: return Color.RED;
             case 1: return Color.ORANGE;
             case 2: return Color.YELLOW;
             case 3: return Color.GREEN;
             case 4: return Color.CYAN;
             default: return Color.BLACK;
         }
     }
     public RandomGenerator rgen = new RandomGenerator();
 }
