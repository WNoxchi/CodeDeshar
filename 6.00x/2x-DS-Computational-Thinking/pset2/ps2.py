# 6.00.2x Problem Set 2: Simulating robots
# Wayne H Nixalo - 22-Nov-2016 11:46

import math
import random

import ps2_visualize
import pylab

# For Python 3.5:
from ps2_verify_movement35 import testRobotMovement
# If you get a "Bad magic number" ImportError, you are not using Python 3.5


# === Provided class Position
class Position(object):
    """
    A Position represents a location in a two-dimensional room.
    """
    def __init__(self, x, y):
        """
        Initializes a position with coordinates (x, y).
        """
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def getNewPosition(self, angle, speed):
        """
        Computes and returns the new Position after a single clock-tick has
        passed, with this object as the current position, and with the
        specified angle and speed.

        Does NOT test whether the returned position fits inside the room.

        angle: number representing angle in degrees, 0 <= angle < 360
        speed: positive float representing speed

        Returns: a Position object representing the new position.
        """
        old_x, old_y = self.getX(), self.getY()
        angle = float(angle)
        # Compute the change in position
        delta_y = speed * math.cos(math.radians(angle))
        delta_x = speed * math.sin(math.radians(angle))
        # Add that to the existing position
        new_x = old_x + delta_x
        new_y = old_y + delta_y
        return Position(new_x, new_y)

    def __str__(self):
        return "(%0.2f, %0.2f)" % (self.x, self.y)


# === Problem 1     -   22-Nov-2016 12:46 - 22-Nov-2016 15:45
class RectangularRoom(object):
    """
    A RectangularRoom represents a rectangular region containing clean or dirty
    tiles.

    A room has a width and a height and contains (width * height) tiles. At any
    particular time, each of these tiles is either clean or dirty.
    """
    def __init__(self, width, height):
        """
        Initializes a rectangular room with the specified width and height.

        Initially, no tiles in the room have been cleaned.

        width: an integer > 0
        height: an integer > 0
        """
        # raise NotImplementedError
        self.width = width
        self.height = height
        self.status = []
        for x in range(width):
            self.status.append([])
            for y in range(height):
                self.status[x].append(0)


    def cleanTileAtPosition(self, pos):
        """
        Mark the tile under the position POS as cleaned.

        Assumes that POS represents a valid position inside this room.

        pos: a Position
        """
        x = int(math.floor(pos.getX()))
        y = int(math.floor(pos.getY()))
        self.status[x][y] = 1


    def isTileCleaned(self, m, n):
        """
        Return True if the tile (m, n) has been cleaned.

        Assumes that (m, n) represents a valid tile inside the room.

        m: an integer
        n: an integer
        returns: True if (m, n) is cleaned, False otherwise
        """
        return self.status[m][n]

    def getNumTiles(self):
        """
        Return the total number of tiles in the room.

        returns: an integer
        """
        return self.width * self.height

    def getNumCleanedTiles(self):
        """
        Return the total number of clean tiles in the room.

        returns: an integer
        """
        ter = 0
        for x in range(self.width):
            for y in range(self.height):
                ter += self.status[x][y]
        return ter

    def getRandomPosition(self):
        """
        Return a random position inside the room.

        returns: a Position object.
        """
        x = random.randint(0, self.width - 1)
        y = random.randint(0, self.height - 1)
        return Position(x, y)


    def isPositionInRoom(self, pos):
        """
        Return True if pos is inside the room.

        pos: a Position object.
        returns: True if pos is in the room, False otherwise.
        """
        x = int(math.floor(pos.getX()))
        y = int(math.floor(pos.getY()))
        if x >= 0 and x < self.width and y >= 0 and y < self.height:
            return True
        else:
            return False



# === Problem 2 -   22-Nov-2016 16:26
class Robot(object):
    """
    Represents a robot cleaning a particular room.

    At all times the robot has a particular position and direction in the room.
    The robot also has a fixed speed.

    Subclasses of Robot should provide movement strategies by implementing
    updatePositionAndClean(), which simulates a single time-step.
    """
    def __init__(self, room, speed):
        """
        Initializes a Robot with the given speed in the specified room. The
        robot initially has a random direction and a random position in the
        room. The robot cleans the tile it is on.

        room:  a RectangularRoom object.
        speed: a float (speed > 0)
        """
        self.room = room
        self.speed = speed
        # self.position = Position(random.randint(0, room.width - 1),
        #                          random.randint(0, room.height - 1))
        self.position = room.getRandomPosition()
        self.direction = random.randint(0, 359)

    def getRobotPosition(self):
        """
        Return the position of the robot.

        returns: a Position object giving the robot's position.
        """
        return self.position

    def getRobotDirection(self):
        """
        Return the direction of the robot.

        returns: an integer d giving the direction of the robot as an angle in
        degrees, 0 <= d < 360.
        """
        return self.direction

    def setRobotPosition(self, position):
        """
        Set the position of the robot to POSITION.

        position: a Position object.
        """
        self.position = position

    def setRobotDirection(self, direction):
        """
        Set the direction of the robot to DIRECTION.

        direction: integer representing an angle in degrees
        """
        self.direction = direction

    def updatePositionAndClean(self):
        """
        Simulate the raise passage of a single time-step.

        Move the robot to a new position and mark the tile it is on as having
        been cleaned.
        """
        raise NotImplementedError # don't change this!


# === Problem 3 -   22-Nov-2016 20:09
class StandardRobot(Robot):
    """
    A StandardRobot is a Robot with the standard movement strategy.

    At each time-step, a StandardRobot attempts to move in its current
    direction; when it would hit a wall, it *instead* chooses a new direction
    randomly.
    """
    def updatePositionAndClean(self):
        """
        Simulate the raise passage of a single time-step.

        Move the robot to a new position and mark the tile it is on as having
        been cleaned.
        """
        # update position:
        pos = self.getRobotPosition()
        kerlapos = pos.getNewPosition(self.getRobotDirection(), self.speed)
        if self.room.isPositionInRoom(kerlapos):
            self.setRobotPosition(kerlapos)
            if not self.room.isTileCleaned(int(math.floor(kerlapos.getX())),
                                       int(math.floor(kerlapos.getY()))):
                self.room.cleanTileAtPosition(kerlapos)
        else:
            self.setRobotDirection(random.randint(0,359))


#        while self.room.getNumCleanedTiles() < self.room.getNumTiles():
#            self.position = self.getNewPosition(self.direction, self.speed)
#            if self.isPositionInRoom(self.position):
#                if not self.isTileCleaned(int(math.floor(self.position.getX())),
#                                     int(math.floor(self.position.getY()))):
#                    self.cleanTileAtPosition(self.position)
#                # if tile already clean; just repeat loop
#                else:
#                    pass
#            # if position outside of room:
#            else:
#                self.direction = self.setRobotDirection(random.randint(0,359))


# Uncomment this line to see your implementation of StandardRobot in action!
#testRobotMovement(StandardRobot, RectangularRoom)


# === Problem 4 -   22-Nov-2016 20:09   -   22-Nov-2016 21:06|22-Nov-2016 21:58
def runSimulation(num_robots, speed, width, height, min_coverage, num_trials,
                  robot_type):
    """
    Runs NUM_TRIALS trials of the simulation and returns the mean number of
    time-steps needed to clean the fraction MIN_COVERAGE of the room.

    The simulation is run with NUM_ROBOTS robots of type ROBOT_TYPE, each with
    speed SPEED, in a room of dimensions WIDTH x HEIGHT.

    num_robots: an int (num_robots > 0)
    speed: a float (speed > 0)
    width: an int (width > 0)
    height: an int (height > 0)
    min_coverage: a float (0 <= min_coverage <= 1.0)
    num_trials: an int (num_trials > 0)
    robot_type: class of robot to be instantiated (e.g. StandardRobot or
                RandomWalkRobot)
    """
    # avg = runSimulation(10, 1.5, 15, 20, 0.8, 30, StandardRobot)

    # late to submission -> taken/referenced from: https://github.com/Theofilos-Chamalis/edX-6.00.2x-Introduction-to-Computational-Thinking-and-Data-Science/blob/eba44829a021e22485f8d31996fcfbb12d5aef26/Running%20The%20Simulation.py
    trialsList = []

    # Run num_trials amt of tests:
    for trial in range(num_trials):
       # Create room:
       room = RectangularRoom(width, height)
       robotList = []

       # Create robots & add to robotList:
       for n in range(num_robots):
           robotList.append(robot_type(room, speed))

       # run animation:
    #    anim = ps2_visualize.RobotVisualization(num_robots, width, height, delay = 0.07)
       steps = 0

       # Give each robot a turn while the room isn't cleaned enough:
       while(float(room.getNumCleanedTiles())/room.getNumTiles()) <= min_coverage:
        #    anim.update(room, robotList)
           # print room.getNumCleanedTiles()
           # print steps
           for bot in robotList:
               # print bot
#              #-->? anim.update(room, robot)    # robot instead of robotList?
               bot.updatePositionAndClean()
           steps += 1

       # Add the test to trialsList
       trialsList.append(steps)
    #    anim.done()
    # return average of all values in trialsList:
    return float(sum(trialsList))/len(trialsList)

    # # alternate version reference from: https://github.com/felipetdsa/6.002x-ProblemSet2/blob/master/ps2.py
    # avg = 0.
    # trial = 0
    # #robots_list = []
    # #room = RectangularRoom(width, height)
    # #for i in xrange(num_robots):
    # #    robots_list.append(robot_type(room, speed))
    #
    # #    anim = ps2_visualize.RobotVisualization(num_robots, width, height)
    #
    # while trial < num_trials:
    #     robots_list = []
    #     room = RectangularRoom(width, height)
    #     for i in range(num_robots):
    #         robots_list.append(robot_type(room, speed))
    #
    #     anim = ps2_visualize.RobotVisualization(num_robots, width, height) #Uncomment for visualization
    #     clock_ticks = 0
    #     done = 0
    #     while done < min_coverage:
    #         anim.update(room, robots_list) #Uncomment for visualization
    #         #print room.getNumCleanedTiles()
    #         #print room.getNumTiles()
    #         for robot in robots_list:
    #             robot.updatePositionAndClean()
    #             clock_ticks += 1
    #         done = float (room.getNumCleanedTiles()) / (room.getNumTiles())
    #         #print 'Done' + str(done)
    #     avg += clock_ticks // len(robots_list)
    #     trial += 1
    #     anim.done() #Uncomment for visualization
    #
    # return (avg//num_trials)


# Uncomment this line to see how much your simulation takes on average
#print(runSimulation(1, 1.0, 10, 10, 0.75, 30, StandardRobot))
#runSimulation(4, 1.0, 10, 10, 0.75, 30, StandardRobot)

# === Problem 5 -   22-Nov-2016 21:59   -   22-Nov-2016 23:25
class RandomWalkRobot(Robot):
    """
    A RandomWalkRobot is a robot with the "random walk" movement strategy: it
    chooses a new direction at random at the end of each time-step.
    """
    def updatePositionAndClean(self):
        """
        Simulate the passage of a single time-step.

        Move the robot to a new position and mark the tile it is on as having
        been cleaned.
        """
        pos = self.getRobotPosition()
        self.setRobotDirection(random.randint(0,359))
        kerlapos = pos.getNewPosition(self.getRobotDirection(), self.speed)
        if self.room.isPositionInRoom(kerlapos):
            self.setRobotPosition(kerlapos)
            if not self.room.isTileCleaned(int(math.floor(kerlapos.getX())),
                                       int(math.floor(kerlapos.getY()))):
                self.room.cleanTileAtPosition(kerlapos)
        else:
            self.setRobotDirection(random.randint(0,359))
#        pass
runSimulation(2, 1.0, 10, 10, 0.75, 10, RandomWalkRobot)

def showPlot1(title, x_label, y_label):
    """
    What information does the plot produced by this function tell you?
    """
    num_robot_range = range(1, 11)
    times1 = []
    times2 = []
    for num_robots in num_robot_range:
        print("Plotting", num_robots, "robots...")
        times1.append(runSimulation(num_robots, 1.0, 20, 20, 0.8, 20, StandardRobot))
        times2.append(runSimulation(num_robots, 1.0, 20, 20, 0.8, 20, RandomWalkRobot))
    pylab.plot(num_robot_range, times1)
    pylab.plot(num_robot_range, times2)
    pylab.title(title)
    pylab.legend(('StandardRobot', 'RandomWalkRobot'))
    pylab.xlabel(x_label)
    pylab.ylabel(y_label)
    pylab.show()


def showPlot2(title, x_label, y_label):
    """
    What information does the plot produced by this function tell you?
    """
    aspect_ratios = []
    times1 = []
    times2 = []
    for width in [10, 20, 25, 50]:
        height = 300//width
        print("Plotting cleaning time for a room of width:", width, "by height:", height)
        aspect_ratios.append(float(width) / height)
        times1.append(runSimulation(2, 1.0, width, height, 0.8, 200, StandardRobot))
        times2.append(runSimulation(2, 1.0, width, height, 0.8, 200, RandomWalkRobot))
    pylab.plot(aspect_ratios, times1)
    pylab.plot(aspect_ratios, times2)
    pylab.title(title)
    pylab.legend(('StandardRobot', 'RandomWalkRobot'))
    pylab.xlabel(x_label)
    pylab.ylabel(y_label)
    pylab.show()


# === Problem 6
# NOTE: If you are running the simulation, you will have to close it
# before the plot will show up.

#
# 1) Write a function call to showPlot1 that generates an appropriately-labeled
#     plot.
#
#       (... your call here ...)
#
showPlot1("Plotting 10 robots", "Number of Robots", "Times")

#
# 2) Write a function call to showPlot2 that generates an appropriately-labeled
#     plot.
#
#       (... your call here ...)
#
showPlot2("Cleaning time for Rooms by Sizes", "Aspect Ratio", "Time")
