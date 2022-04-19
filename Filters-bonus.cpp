// FCI – Programming 1 – 2022 - Assignment 3
// Program: Filters-bonus.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author1:  Adel Magdy Abd El-Hay  ID1 : 20210190  group: S16
// Author2:  Roaa Talat mohamed  ID2: 20210138  group: S16
// Author3:  Asmaa Saleh Farghaly  ID3: 20211014  group: S16
// last UpDate:    7 April 2022

// import libraries
#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;
// inatilize SIZE of image 256 * 256
unsigned char image[][SIZE][RGB];
unsigned char image2[][SIZE][RGB];
unsigned char rotate[][SIZE][RGB];

// declaration of function for load the image
void loadImage();

// declaration of function for save the image
void saveImage();

// declaration of function for to load new image for rotate
void saveRotate();

// declaration of function for convert the image to black and white image
void convertImageToBlackAndWhiteImage();

// declaration of function for invert the colour of image
void Invert();

// declaration of function for two images
void mergeImage();

// declaration of function for to loadimage2
void loadSecondImage();

//  declaration of function for Flip The Image
void flipImage();

// declaration of function for Rotate the Image
void rotateImage(int &degreeOfRotate);

// declaration of function for rotate the image 180 degree
void rotate_180_degree();

// declaration of function for rotate the image 90 degree
void rotate_90_degree();

// declaration of function for rotate the image 270 degree
void rotate_270_degree();

// declaration of function for lighten an image
void lightenImage();

// declaration of function for darken an image
void darkenImage();

void detectImage();

void EnlargeImage(int &quarter);
void EnlargeImage1();
void EnlargeImage2();
void EnlargeImage3();
void EnlargeImage4();

void shrinkAhalfImage();
void shrinkAthirdImage();
void shrinkQuarterImage();

void blurImage();


int main() {
    char choose = ' ';
    while (choose != '0') {
        cout << "Ahlan ya user ya habibi \U0001F44B\U0001F60A" << endl;
        cout << "Please select a filter to apply or 0 to exit: " << endl;
        cout << "1- Black & White Filter" << endl;
        cout << "2- Invert Filter" << endl;
        cout << "3- Merge Filter" << endl;
        cout << "4- Flip Image" << endl;
        cout << "5- Rotate Image" << endl;
        cout << "6- Darken and Lighten Image" << endl;
        cout << "7- Detect Image Edges" << endl;
        cout << "8- Enlarge Image" << endl;
        cout << "9- Shrink Image" << endl;
        cout << "a- Mirror 1/2 Image" << endl;
        cout << "b- Shuffle Image" << endl;
        cout << "c- Blur Image" << endl;
        cout << "s- Save the image to a file" << endl;
        cout << "0- Exit" << endl;
        cin >> choose;
        if (choose == '1') {
            loadImage();
            // call the Filter 1
            convertImageToBlackAndWhiteImage();
            saveImage();
        } else if (choose == '2') {
            loadImage();
            // call the Filter 2
            Invert();
            saveImage();
        } else if (choose == '3') {
            loadImage();
            // call the Filter 3
            loadSecondImage();
            mergeImage();
            saveImage();
        } else if (choose == '4') {
            loadImage();
            // call the Filter 4
            flipImage();
            saveImage();
        } else if (choose == '5') {
            int degreeOfRotate;
            cout << "Rotate (90), (180) or (270) degree? ";
            cin >> degreeOfRotate;
            loadImage();
            // call the Filter 5
            rotateImage(degreeOfRotate);
            saveRotate();
        } else if (choose == '6') {
            char choose1;
            cout << "do you want to (d)arken or (l)ighten? ";
            cin >> choose1;
            loadImage();
            if (choose1 == 'l') {
                // call the Filter 6 (ligthen)
                lightenImage();
            } else if (choose1 == 'd') {
                // call the Filter 6 (darken)
                darkenImage();
            } else {
                cout << "invalid";
            }
            saveImage();
        } else if (choose == '7') {
            loadImage();
            detectImage();
            saveImage();
            cout << '7' << endl;
        } else if (choose == '8') {
            int quarter;
            cout<<"which one of the four quarters do you want to get bigger ? ";
            cin>> quarter;
            loadImage();
            EnlargeImage(quarter);
            saveRotate();
        } else if (choose == '9') {
            string choose;
            cout<<"Shrink to 1/2, 1/3 or 1/4: ";
            cin>>choose;
            loadImage();
            if (choose == "1/2"){
                shrinkAhalfImage();
            }else if (choose == "1/3"){
                shrinkAthirdImage();
            } else if (choose == "1/4"){
                shrinkQuarterImage();
            }else {
                cout << "invalid";
            }
            saveRotate();
            cout << '9' << endl;
        } else if (choose == 'a') {
            loadImage();
            saveImage();
            cout << 'a' << endl;
        } else if (choose == 'b') {
            loadImage();
            saveImage();
            cout << 'b' << endl;
        } else if (choose == 'c') {
            loadImage();
            blurImage();
            saveImage();
            cout << 'c' << endl;
        } else if (choose == 's') {
            loadImage();
            saveImage();
            cout << 's' << endl;
        } else {
            return 0;
        }
    }
    return 0;
}

// definition of function for load the image
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}

// definition of function for save the image
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

// definition of function for save the rotate image
void saveRotate() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, rotate);
}