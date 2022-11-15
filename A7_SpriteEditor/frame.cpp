/*
* The Cuties
* CS 3505
* Spritz Pixel Editor
*
* Reviewed by: Nami Eskandarian
*
* Implementation file for the Frame class
*/

#include "frame.h"
#include <QJsonObject>
#include <QJsonArray>

// Constructor to create an empty frame
Frame::Frame(int size) {

    // Pre-fill an empty frame with fully transparent pixels
    for (int height = 0; height < size; height++) {
        QVector<Pixel> row;

        for (int width = 0; width < size; width++)
            row.push_back({255, 255, 255, 0}); // Set all pixels in the row as empty

        pixels.push_back(row); // Push this row of empty pixels onto the frame
    }
}

// Constructor to duplicate a frame
Frame::Frame(const Frame& other) {
    pixels = other.pixels;
}

// Get the pixel based on the position on the screen
Pixel Frame::getPixel(int x, int y) {
    return pixels[y][x];
}

// Set the pixel based on the position on the screen
void Frame::setPixel(int x, int y, Pixel newPixel) {
    if(x < (int)pixels.size() && y < (int)pixels.size() && x >= 0 && y >= 0){
        pixels[y][x] = newPixel;
    }
}

// Assignment operator for frame class
Frame& Frame::operator=(const Frame& other) {
    pixels = other.pixels;
    return *this;
}

// Helper method to retrieve a JsonArray from this object
QJsonArray Frame::getJsonArray() {

    QJsonArray frame;

    for (int i = 0; i < pixels.size(); i++) {
        QJsonArray arr;

        // Create an array of pixels
        for (Pixel& pixel : pixels[i]) {
            QJsonArray pix;
            pix.push_back(pixel.red);
            pix.push_back(pixel.green);
            pix.push_back(pixel.blue);
            pix.push_back(pixel.alpha);

            arr.push_back(pix);
        }

        frame.push_back(arr);
    }

    return frame;
}
