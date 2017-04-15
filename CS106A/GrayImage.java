/*
 * File: GrayImage.java
 * --------------------
 * Creates grayscale version of an image.
 */

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
