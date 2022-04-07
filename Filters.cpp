// Program: Filters.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author1:  Adel Magdy Abd El-Hay ID1 : 20210190
// Author2:  Roaa Talat mohamed  ID2: 20210138
// Author3:  Asmaa Saleh Farghaly ID3: 20211014
// last UpDate:    7 April 2022

// import libraries
#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;
// inatilize SIZE of image 256 * 256
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char rotate[SIZE][SIZE];

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

// declaration of function for rotate the image 90 degree
void rotate_90_degree();

// declaration of function for rotate the image 180 degree
void rotate_180_degree();

// declaration of function for rotate the image 270 degree
void rotate_270_degree();

// declaration of function for darken an image
void darkenImage();

// declaration of function for lighten an image
void lightenImage();

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
            convertImageToBlackAndWhiteImage();
            saveImage();
        } else if (choose == '2') {
            loadImage();
            Invert();
            saveImage();
        } else if (choose == '3') {
            loadImage();
            loadSecondImage();
            mergeImage();
            saveImage();
        } else if (choose == '4') {
            loadImage();
            flipImage();
            saveImage();
        } else if (choose == '5') {
            int degreeOfRotate;
            cout << "Rotate (90), (180) or (270) degree? ";
            cin >> degreeOfRotate;
            loadImage();
            rotateImage(degreeOfRotate);
            saveRotate();
        } else if (choose == '6') {
            char choose1;
            cout << "do you want to (d)arken or (l)ighten? ";
            cin >> choose1;
            loadImage();
            if (choose1 == 'l') {
                lightenImage();
            } else if (choose1 == 'd') {
                darkenImage();
            } else {
                cout << "invalid";
            }
            saveImage();
        } else if (choose == '7') {
            loadImage();
            saveImage();
            cout << '7' << endl;
        } else if (choose == '8') {
            loadImage();
            saveImage();
            cout << '8' << endl;
        } else if (choose == '9') {
            loadImage();
            saveImage();
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
    readGSBMP(imageFileName, image);
}

// definition of function for save the image
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

// definition of function for save the rotate image
void saveRotate() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, rotate);
}

// definition of function for convert image to black and white image
void convertImageToBlackAndWhiteImage() {
    // inatialize average to calculate the average of the pixels of image
    int avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > avg) {
                // convert all pixels that greater than average to White
                image[i][j] = 255;
            } else {
                // convert all pixels that less than average to Black
                image[i][j] = 0;
            }
        }
    }
}

void Invert() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = 255 - image[i][j];
        }
    }
}

//  definition of function for Flip The Image
void flipImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0, k = SIZE - 1; j < k; j++, k--) {
            // reverse elements of every column.
            swap(image[j][i], image[k][i]);
        }
    }
}

// Function to rotate the rotate by 180 degree
void rotate_180_degree() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0, k = SIZE - 1; j < k; j++, k--) {
            // reverse elements of every column.
            swap(image[j][i], image[k][i]);
        }
    }
}

// Function for transpose of matrix
void rotate_90_degree() {
    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {
            rotate[i][j] = image[SIZE - j][i];
        }
    }
}


// function for rotete the image by 270 degree
void rotate_270_degree() {
    rotate_90_degree();
    rotate_180_degree();
}

// function for rotate the image like the user want (90), (180) or (270)
void rotateImage(int &degreeOfRotate) {
    if (degreeOfRotate == 90) {
        rotate_90_degree();
    } else if (degreeOfRotate == 180) {
        rotate_180_degree();
    } else if (degreeOfRotate == 270) {
        rotate_270_degree();
    } else {
        cout << "invalid degree" << endl;
    }
}

void loadSecondImage() {
    char image2FileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name of image2: ";
    cin >> image2FileName;

    // Add to image file name .bmp extension and load image
    strcat(image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);
}

void mergeImage() {
    int avg[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            avg[i][j] = (image[i][j] + image2[i][j]) / 2;
            image[i][j] = avg[i][j];
        }
    }
}

void lightenImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {

            if ((image[i][j] *= 1.5) > 255) {
                image[i][j] = 255;
            } else {
                image[i][j] *= 1.5;
            }
        }
    }
}

void darkenImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] *= 0.5;
        }
    }
}
FileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

// definition of function for save the image
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

// definition of function for convert image to black and white image
void convertImageToBlackAndWhiteImage() {
    // inatialize average to calculate the average of the pixels of image
    int avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > avg) {
                // convert all pixels that greater than average to White
                image[i][j] = 255;
            } else {
                // convert all pixels that less than average to Black
                image[i][j] = 0;
            }
        }
    }
}

void Invert() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = 255 - image[i][j];
        }
    }
}

//  definition of function for Flip The Image
void flipImage() {
    rotate_180_degree();
}

// Function to rotate the rotate by 180 degree
void rotate_180_degree() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0, k = SIZE - 1; j < k; j++, k--) {
            // reverse elements of every column.
            swap(image[j][i], image[k][i]);
        }
    }
}

// Function for transpose of matrix
void rotate_90_degree() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image[j][i];

            // swap every column with the opposite row
            //swap(image[i][j], image[j][i]);
        }
    }
}

// function for rotete the image by 270 degree
void rotate_270_degree() {
    rotate_90_degree();
    rotate_180_degree();
}

// function for rotate the image like the user want (90), (180) or (270)
void rotateImage(int &degreeOfRotate) {
    if (degreeOfRotate == 90) {
        rotate_90_degree();
    } else if (degreeOfRotate == 180) {
        rotate_180_degree();
    } else if (degreeOfRotate == 270) {
        rotate_270_degree();
    } else {
        cout << "invalid degree" << endl;
    }
}

void loadSecondImage() {
    char image2FileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name of image2: ";
    cin >> image2FileName;

    // Add to image file name .bmp extension and load image
    strcat(image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);
}

void mergeImage() {
    int avg[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            avg[i][j] = (image[i][j] + image2[i][j]) / 2;
            image[i][j] = avg[i][j];
        }
    }
}

void lightenImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {

            if ((image[i][j] *= 1.5 ) > 255) {
                image[i][j] = 255;
            }else {
                image[i][j] *= 1.5;
            }
        }
    }
}

void darkenImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] *= 0.5;
        }
    }
}
