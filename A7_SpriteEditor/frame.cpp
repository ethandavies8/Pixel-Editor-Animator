/*
* The Cuties
* CS 3505
* Spritz Pixel Editor
*
* Implementation file for the Frame class
*/

#include "frame.h"
#include <vector>

// Constructor to create an empty frame
Frame::Frame(int size)
{
    // Pre-fill an empty frame with fully transparent pixels
    for (int height = 0; height < size; height++) {
        vector<Pixel> row;

        for (int width = 0; width < size; width++)
            row.push_back({0, 0, 0, 0}); // Set all pixels in the row as empty

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
    pixels[y][x] = newPixel;
}
