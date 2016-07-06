/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.01 GRectangle.cpp
 *-------------------------------------------------<*>
 *  06-Jul-2016 07:28 - 06-Jul-2016 08:25
*/

/*
    The gtypes.h interface included in Appendix A exports a few useful classes
    designed to work together with the graphics library.
    Using the description of the GRectangle class in Appendix A for reference,
    implement the GRectangle class.
*/

// I'm using the actual implementation to go along w/ bc what am I doing

#include "gtypes.h"
#include <string>
#include "hashcode.h" // <-- what is this?
#include "strlib.h"

/*
 * Class: GRectangle
 * -----------------
 * This type contains real-valued x, y, width, and height fields.  It is
 * used to represent the bounding box of a graphical object.
 */
class GRectangle {
public:
    /*
     * Constructor: GRectangle
     * Usage: GRectangle empty;
     *        GRectangle r(x, y, width, height);
     * -----------------------------------------
     * Creates a <code>GRectangle</code> object with the specified components.
     * If these parameters are not supplied, the default constructor sets
     * these fields to 0.
     */
    GRectangle::GRectangle(){
        x = 0;
        y = 0;
        width = 0;
        height = 0;
    }
    // not sure what to do with this one; haven't covered "this->" pointers yet so....?
    GRectangle::GRectangle(double x, double y, double width, double height){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    /*
     * Method: getX
     * Usage: double x = r.getX();
     * ---------------------------
     * Returns the x component of the rectangle.
     */
    double GRectangle::getX() const {
        return x;
    }

    /*
     * Method: getY
     * Usage: double y = pt.getY();
     * ----------------------------
     * Returns the y component of the rectangle.
     */
    double GRectangle::getY() const {
        return y;
    }

    /*
     * Method: getWidth
     * Usage: double width = r.getWidth();
     * -----------------------------------
     * Returns the width component of the rectangle.
     */
    double GRectangle::getWidth() const {
        return width;
    }

    /*
     * Method: getHeight
     * Usage: double height = pt.getHeight();
     * --------------------------------------
     * Returns the height component of the rectangle.
     */
    double GRectangle::getHeight() const {
        return height;
    }

    /*
     * Method: isEmpty
     * Usage: if (r.isEmpty()) ...
     * ---------------------------
     * Returns <code>true</code> if the rectangle is empty.
     */
    bool GRectangle::isEmpty() const {
        return width <= 0 || height <= 0;   // ok didnt know it was that easy
    }

    /*
     * Method: contains
     * Usage: if (r.contains(pt)) ...
     *        if (r.contains(x, y)) ...
     * --------------------------------
     * Returns <code>true</code> if the rectangle contains the given point,
     * which may be specified either as a point or as distinct coordinates.
     */
    bool GRectangle::contains(double x, double y) const {
        return x >= this->x && y >= this->y
                && x < this-x + width
                && y < this-y + height;
    }
    bool GRectangle::contains(GPoint pt) const {
        return contains(pt.getX(), pt.getY());
    }

    /*
     * Method: toString
     * Usage: string str = r.toString();
     * ---------------------------------
     * Converts the <code>GRectangle</code> to a string in the form
     * <code>"(</code><i>x</i><code>,</code>&nbsp;<i>y</i><code>,</code>
     * <i>width</i><code>,</code>&nbsp;<i>height</i><code>)"</code>.
     */
    // I'm assuming realToString is already defined as it is in the real implementation
    std::string GRectangle::toString() const {
        return "(" + realToString(x) + ", " + realToString(y) + ", "
                + realToString(width) + ", " + realToString(height) + ")";
    }

private:
    // Instance variables:
    double x;
    double y;
    double width;
    double height;

    // friend declarations:
    friend bool operator==(const GRectangle & r1, const GRectangle & r2);
    friend bool operator!=(const Grectangle & r1, const Grectangle & r2);
    // no idea what this is:
    friend int hashBode(const GRectangle & r);

};
