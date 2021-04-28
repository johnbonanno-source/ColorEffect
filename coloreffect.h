#ifndef COLOREFFECT_H
#define COLOREFFECT_H

//loads a PNG image from the named file, changes every pixel to a shade of gray, then saves the resulting image to the named output file. (For each pixel, take the average of the red, green, and blue values; then set red, green, and blue to that average.)
void make_grayscale(const char *input_image, const char *output_image);



//posterizes the given image. For each pixel, set the red value to 32 if between 0 and 63; 96 if between 64 and 127; 160 if between 128 and 191; and 224 if at least 192. Do the same for the green and blue values as well
void posterize(const char *input_image, const char *output_image);



//doubles the size of the given image. So an image of size 2880×1800 would be blown up to 5760×3600. Each pixel of the original should become four pixels in the blown-up version (e.g. if the pixel at (0, 0) is red in the original, then in the blown-up one the pixels at (0, 0), (1, 0), (0, 1), and (1, 1) should all be red.) 
void blow_up(const char *input_image, const char *output_image);

#endif

