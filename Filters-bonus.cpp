// FCI – Programming 1 – 2022 - Assignment 3
// Program: Filters-bonus.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author1:  Adel Magdy Abd El-Hay  ID1 : 20210190  group: S16
// Author2:  Roaa Talat mohamed  ID2: 20210138  group: S16
// Author3:  Asmaa Saleh Farghaly  ID3: 20211014  group: S16
// last UpDate:    20 April 2022

// import libraries
#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;
// inatilize SIZE of image 256 * 256
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char rotate[SIZE][SIZE][RGB];

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

void detectImageEdges();

void EnlargeImage(int &quarter);

void EnlargeImage1();

void EnlargeImage2();

void EnlargeImage3();

void EnlargeImage4();

void shrinkAhalfImage();

void shrinkAthirdImage();

void shrinkQuarterImage();

void blurImage();

void mirrorImage();

void mirrorDownUp();

void mirrorUpDown();

void mirrorRightLeft();

void mirrorLeftRight();


void shuffleImage1(int &a);

void shuffleImage2(int &b);

void shuffleImage3(int &c);

void shuffleImage4(int &d);


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
            detectImageEdges();
            saveImage();
            cout << '7' << endl;
        } else if (choose == '8') {
            int quarter;
            cout << "which one of the four quarters do you want to get bigger ? ";
            cin >> quarter;
            loadImage();
            EnlargeImage(quarter);
            saveRotate();
        } else if (choose == '9') {
            string choose;
            cout << "Shrink to 1/2, 1/3 or 1/4: ";
            cin >> choose;
            loadImage();
            if (choose == "1/2") {
                shrinkAhalfImage();
            } else if (choose == "1/3") {
                shrinkAthirdImage();
            } else if (choose == "1/4") {
                shrinkQuarterImage();
            } else {
                cout << "invalid";
            }
            saveRotate();
            cout << '9' << endl;
        } else if (choose == 'a') {
            loadImage();
            mirrorImage();
            saveImage();
            cout << 'a' << endl;
        } else if (choose == 'b') {
            int a, b, c, d;
            cout << "which order do you want : ";
            cin >> a >> b >> c >> d;
            loadImage();
            shuffleImage1(a);
            shuffleImage2(b);
            shuffleImage3(c);
            shuffleImage4(d);
            saveRotate();
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

void loadSecondImage() {
    char image2FileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name of image2: ";
    cin >> image2FileName;

    // Add to image file name .bmp extension and load image
    strcat(image2FileName, ".bmp");
    readRGBBMP(image2FileName, image2);
}

void mergeImage() {
    // initialize average matrix
    int avg[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                // get the average of the pixels of the two images
                avg[i][j][k] = (image[i][j][k] + image2[i][j][k]) / 2;
                image[i][j][k] = avg[i][j][k];
            }
        }
    }
}

void Invert() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                // subtract from 255 the value of pixel to invert the image
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}

// definition of function for lighten the image
void lightenImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                if ((image[i][j][k] *= 1.5) > 255) {
                    image[i][j][k] = 255;
                } else {
                    image[i][j][k] *= 1.5;
                }
            }
        }
    }
}

// definition of function for darken the image
void darkenImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image[i][j][k] *= 0.5;
            }
        }
    }
}


void blurImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int m = 0; m < RGB; ++m) {
                int sum = 0;
                for (int k = 0; k < 7; ++k) {
                    for (int l = 0; l < 7; ++l) {
                        for (int n = 0; n < 7; ++n) {
                            sum += image[i + k][j + l][m + n];
                        }
                    }
                }
                image[i + 3][j + 3][m + 3] = sum / 343;
            }
        }
    }
}

void convertImageToBlackAndWhiteImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j][0] = ((image[i][j][0]) * 0.3);
            image[i][j][1] = ((image[i][j][1]) * 0.59);
            image[i][j][2] = ((image[i][j][2]) * 0.11);
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                if (image[i][j][k] > 127) {
                    image[i][j][k] = 255;
                } else {
                    image[i][j][k] = 0;
                }
            }
        }
    }
}

void flipImage() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0, a = SIZE - 1; j < a; j++, a--) {
            for (int k = 0; k < RGB; ++k) {
                swap(image[j][i][k], image[a][i][k]);
            }
        }
    }
}

void detectImageEdges() {
    int i = 0;
    int j = 0;
    int k = 0;
    for (; i < SIZE; i++) {
        for (; j < SIZE; j++) {
            for (; k < RGB; k++) {
                if ((image[i][j][k]) - (image[i + 1][j + 1][k + 1]) >= 25) {
                    image[i][j][k] = 0;
                } else {
                    image[i][j][k] = 255;
                }
            }
        }
    }
}

void shrinkAhalfImage() {
    int sum = 0;
    int i = 0, j = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int n = 0; n < RGB; n++) {
                rotate[i][j][n] = 255;
            }
        }
    }
    for (int i = 0, k = 0; i < SIZE; i += 2, k++) {
        for (int j = 0, l = 0; j < SIZE; j += 2, l++) {
            for (int n = 0, m = 0; n < RGB; n += 2, m++) {
                sum = (image[i][j][n] + image[i][j + 1][n] + image[i + 1][j][n] + image[i + 1][j + 1][n]) / 4;
                rotate[k][l][m] = sum;
            }
        }

    }
}

void shrinkAthirdImage() {
    int sum = 0;
    int i = 0, j = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int n = 0; n < RGB; n++) {
                rotate[i][j][n] = 255;
            }
        }
    }
    for (int i = 0, k = 0; i < SIZE; i += 3, k++) {
        for (int j = 0, l = 0; j < SIZE; j += 3, l++) {
            for (int n = 0, m = 0; n < RGB; n += 3, m++) {
                sum = (image[i][j][n] + image[i][j + 1][n] + image[i][j + 2][n] + image[i + 1][j][n] +
                       image[i + 1][j + 1][n]
                       + image[i + 1][j + 2][n] + image[i + 2][j][n] + image[i + 2][j + 1][n] +
                       image[i + 2][j + 2][n]) / 9;
                rotate[k][l][m] = sum;
            }
        }

    }
}


void shrinkQuarterImage() {
    int sum = 0;
    int i = 0, j = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int n = 0; n < RGB; n++) {
                rotate[i][j][n] = 255;
            }
        }
    }
    for (int i = 0, k = 0; i < SIZE; i += 4, k++) {
        for (int j = 0, l = 0; j < SIZE; j += 4, l++) {
            for (int n = 0, m = 0; n < RGB; n += 4, m++) {
                sum = (image[i][j][n] + image[i][j + 1][n] + image[i][j + 2][n] + image[i][j + 3][n] +
                       image[i + 1][j][n] + image[i + 1][j + 1][n] + image[i + 1][j + 2][n] + image[i + 1][j + 3][n] +
                       image[i + 2][j][n] + image[i + 2][j + 1][n]
                       + image[i + 2][j + 2][n] + image[i + 2][j + 3][n] + image[i + 3][j][n] + image[i + 3][j + 1][n] +
                       image[i + 3][j + 2][n] + image[i + 3][j + 3][n]) / 16;
                rotate[k][l][m] = sum;
            }
        }

    }
}

void mirrorLeftRight() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int k = 0; k < RGB; ++k) {
                image[i][SIZE - 1 - j][k] = image[i][j][k];
            }
        }
    }
}

void mirrorRightLeft() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 256; j > SIZE / 2; --j) {
            for (int k = 0; k < RGB; ++k) {
                image[i][SIZE - 1 - j][k] = image[i][j][k];
            }
        }
    }
}

void mirrorUpDown() {
    for (int i = 0; i < SIZE / 2; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image[SIZE - 1 - i][j][k] = image[i][j][k];
            }
        }
    }
}

void mirrorDownUp() {
    for (int i = 256; i > SIZE / 2; --i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image[SIZE - 1 - i][j][k] = image[i][j][k];
            }
        }
    }
}

void mirrorImage() {
    char mirrorSide;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
    cin >> mirrorSide;
    if (mirrorSide == 'l') {
        mirrorLeftRight();
    } else if (mirrorSide == 'r') {
        mirrorRightLeft();
    } else if (mirrorSide == 'u') {
        mirrorUpDown();
    } else if (mirrorSide == 'd') {
        mirrorDownUp();
    } else {
        cout << "invalid side" << endl;
    }
}

void rotateImage(int &degreeOfRotate) {
    // if the user want to rotate the image 90 degree call the function rotate_90_degree
    // if the user want to rotate 180 degree call the function rotate_180_degree
    // if the user want to rotate 2700 degree call the function rotate_270_degree
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

//  definition of function for rotate image by 180 degree
void rotate_180_degree() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                rotate[SIZE - i][SIZE - j][k] = image[i][j][k];
            }
        }
    }
}

// definition of function for rotate the image by 90 degree
void rotate_90_degree() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                rotate[i][j][k] = image[SIZE - j][i][k];
            }
        }
    }
}

// definition of function for rotate the image by 270 degree
void rotate_270_degree() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                rotate[i][j][k] = image[j][SIZE - i][k];
            }
        }
    }
}

void EnlargeImage(int &quarter) {
    if (quarter == 1) {
        EnlargeImage1();
    } else if (quarter == 2) {
        EnlargeImage2();
    } else if (quarter == 3) {
        EnlargeImage3();
    } else if (quarter == 4) {
        EnlargeImage4();
    } else {
        cout << "invalid quarter " << endl;
    }
}

void EnlargeImage1() {
    for (int i = 0, k = 0; i < (SIZE / 2), k < SIZE; k += 2, i++) {
        for (int j = 0, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2) {
            for (int m = 0; m < RGB; m++) {
                rotate[k][l][m] = image[i][j][m];
                rotate[k][l + 1][m] = image[i][j][m];
                rotate[k + 1][l][m] = image[i][j][m];
                rotate[k + 1][l + 1][m] = image[i][j][m];
            }
        }
    }
}

void EnlargeImage2() {
    for (int i = 0, k = 0; i < SIZE, k < SIZE; k += 2, i++) {
        for (int j = SIZE / 2, l = 0; j < SIZE, l < SIZE; j++, l += 2) {
            for (int m = 0; m < RGB; m++) {
                rotate[k][l][m] = image[i][j][m];
                rotate[k][l + 1][m] = image[i][j][m];
                rotate[k + 1][l][m] = image[i][j][m];
                rotate[k + 1][l + 1][m] = image[i][j][m];
            }
        }
    }
}

void EnlargeImage3() {
    for (int i = SIZE / 2, k = 0; i < SIZE, k < SIZE; k += 2, i++) {
        for (int j = 0, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2) {
            for (int m = 0; m < RGB; m++) {
                rotate[k][l][m] = image[i][j][m];
                rotate[k][l + 1][m] = image[i][j][m];
                rotate[k + 1][l][m] = image[i][j][m];
                rotate[k + 1][l + 1][m] = image[i][j][m];
            }
        }
    }
}

void EnlargeImage4() {
    for (int i = SIZE / 2, k = 0; i < SIZE, k < SIZE; k += 2, i++) {
        for (int j = SIZE / 2, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2) {
            for (int m = 0; m < RGB; m++) {
                rotate[k][l][m] = image[i][j][m];
                rotate[k][l + 1][m] = image[i][j][m];
                rotate[k + 1][l][m] = image[i][j][m];
                rotate[k + 1][l + 1][m] = image[i][j][m];
            }
        }
    }
}

void shuffleImage1(int &a) {
    if (a == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[i][j][m] = image[i][j][m];
                }
            }
        }
    } else if (a == 2) {
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++) {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (a == 3) {
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (a == 4) {
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    }
}

void shuffleImage2(int &b) {
    if (b == 1) {
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++) {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (b == 2) {
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++) {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (b == 3) {
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (b == 4) {
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    }
}

void shuffleImage3(int &c) {
    if (c == 1) {
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++) {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (c == 2) {
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++) {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (c == 3) {
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++) {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (c == 4) {
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++) {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    }
}

void shuffleImage4(int &d) {
    if (d == 1) {
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++) {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (d == 2) {
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++) {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (d == 3) {
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++) {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (d == 4) {
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++) {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++) {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    }
}
