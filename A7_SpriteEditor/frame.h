/*
* The Cuties
* CS 3505
* Spritz Pixel Editor
*
* Reviewed by: Nami Eskandarian
*
* Header file for the Frame class
*/

#ifndef FRAME_H
#define FRAME_H

#include <QJsonObject>

// This Pixel struct will hold the color of an individual pixel on the screen
struct Pixel{
   int red, green, blue, alpha;
};

class Frame
{
public:
    Frame(int size); // Constructor for frame takes sprite size
    Frame(const Frame& other); // Can duplicate frames

    Pixel getPixel(int x, int y); // Get the pixel and its colors
    void setPixel(int x, int y, Pixel newPixel); // Set the pixel's colors
    Frame& operator=(const Frame& other);
    QJsonArray getJsonArray();

private:
    QVector<QVector<Pixel>> pixels; // A 2D array of pixels, each pixel is a Pixel struct of [red, blue, green, alpha]
};

#endif // FRAME_H
