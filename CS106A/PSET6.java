/*
 * File: CountNames.java
 * ---------------------
 * CS106A PSet 6.2
 * ---------------------
 * Wayne H. Noxchi
 * Start: 01-Feb-2016 07:12 | Finish: 01-Feb-2016 08:27
 */

// so it's HashMap.put(key, value)
// so entering a name adds key if not exist, & adds 1 to value, start at 1
// so how to do that..
// need to find out what is << .hasNext() >>
// hu yu << .get(name) >>
// hu yu << .keySet() >> a << .iterator() >> a

import acm.program.*;
import java.util.*;

public class CountNames extends ConsoleProgram {

    public void run() {
        // initialize a hashmap to contain names:
        HashMap<String,Integer> nameMap = new HashMap<String,Integer>();

        readMap(nameMap);
        printMap(nameMap);
    }

    private void readMap(<String,Integer> map) {
        while (true) {
            String name = readLine("Enter name: ");
            if (name.equals("")) break;

            // See if name already appeared in map. Update count if it did,
            // create new count if it didn't.

            Integer count = map.get(name);
            if (count == null) {
                count = new Integer(1);
            } else {
                count = new Integer(count + 1);
            }
            map.put(name, count);
        }
    }

    private void printMap(<String,Integer> map) {
        // start by creating an Iterator object of type <String> to go over the map
        Iterator<String> iter = map.keySet().iterator();   // keySet() returns a K-V pair (set)
        while (iter.hasNext()) {
            String key = iter.next();
            int count = map.get(key);
            println("Entry [" + key + "] has count " + count);
        }
    }
}


// -----------------------------------------------------------------------------


/*
 * CS106A Programming Methodology
 * Problem Set 6.1
 * flipHorizontal.java
 * --------------------
 * flips a GImage horizontally
 * --------------------
 * Wayne H. Noxchi
 * Start: 31-Jan-2016 21:06 | Finish: 31-Jan-2016 22:23
 */


    private GImage flipHorizontal(GImage image) {
        int[][] array = image.getPixelArray();
        int height = array.length;
        int width = array[0].length;
        for (int row = 0; row < height; row++) {
            for (int p1 = 0; p1 < width / 2; p1++) {
                int p2 = width - p1 - 1;
                int temp = array[row][p1];
                array[row][p1] = array[row][p2];
                array[row][p2] = temp;
            }
        }
        return new GImage(array);
    }

// From book for reference:
     private GImage flipVertical(GImage image) {
         int[][] array = image.getPixelArray();
         int height = array.length;
         for (int p1 = 0; p1 < height / 2; p1++) {
             int p2 = height - p1 - 1;
             int[] temp = array[p1];
             array[p1] = array[p2];
             array[p2] = temp;
         }
         return new GImage(array)
     }

// From lecture 17:

/*
 * File: GrayImage.java
 * --------------------
 * Creates grayscale version of an image.
 */
/*

import acm.program.*;
import acm.graphics.*;

public class GrayImage extends GraphicsProgram {

    public void run() {
        GImage image = new GImage("photo.jpg");
        GImage grayImage = createGrayscaleImage(image);

        image.scale(0.5);
        add(image, 10, 50);

        grayImage.scale(0.5);
        add(grayImage, 250, 50);
    }

    private GImage createGrayscaleImage(GImage image) {
        int[][] array = image.getPixelArray();

        int height = array.length;
        int width = array[0].length;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int pixel = array[i][j];

                int r = GImage.getRed(pixel);
                int g = GImage.getGreen(pixel);
                int b = GImage.getBlue(pixel);

                int xx = computeLuminosity(r, g, b);

                array[i][j] = GImage.createRGBPixel(xx, xx, xx);
            }
        }
        return new GImage(array);
    }

    private int computeLuminosity(int r, int g, int b) {
        return GMath.round(0.299 * r + 0.587 * g + 0.114 * b);
    }
}


*/
// -*- mode:java;-*-
