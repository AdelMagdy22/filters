// FCI – Programming 1 – 2022 - Assignment 3
// Program: Filters-bonus.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load colour image and store in another file
// Author1:  Adel Magdy Abd El-Hay  ID1 : 20210190  group: S16
// Author2:  Roaa Talat mohamed  ID2: 20210138  group: S16
// Author3:  Asmaa Saleh Farghaly  ID3: 20211014  group: S16
// last UpDate:    22 April 2022

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

// declaration of function for convert the image to gray scale image to use it in other filters
void convertImageToGray();

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

// declaration of function for darken an image
void darkenImage();

// declaration of function for Rotate the Image
void rotateImage(int &degreeOfRotate);

// declaration of function for rotate the image 180 degree
void rotate_180_degree();

// declaration of function for rotate the image 90 degree
void rotate_90_degree();

// declaration of function for rotate the image 270 degree
void rotate_270_degree();

// declaration of function for to load new image for rotate
void saveRotate();


// declaration of function for lighten an image
void lightenImage();

// declaration of function for detect edges of image
void detectImageEdges();

// declaration of function for enlarge image
void EnlargeImage(int &quarter);
void EnlargeImage1();
void EnlargeImage2();
void EnlargeImage3();
void EnlargeImage4();

// declaration of function for shrink image to a half
void shrinkAhalfImage();
// declaration of function for shrink image to a third
void shrinkAthirdImage();
// declaration of function for shrink image to a quarter
void shrinkQuarterImage();

// declaration of function for miror 1/2 image
void mirrorImage();
void mirrorDownUp();
void mirrorUpDown();
void mirrorRightLeft();
void mirrorLeftRight();

// declaration of function for shuffle image
void shuffleImage1(int &a);
void shuffleImage2(int &b);
void shuffleImage3(int &c);
void shuffleImage4(int &d);

// declaration of function for blur image
void blurImage();


int main()
{
    char choose = ' ';
    while (choose != '0')
    {   // enter face of the program
        // let the user to choose what the filter he/she wants
        cout << "Ahlan ya user ya habibi" << endl;
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
        if (choose == '1')
        {
            loadImage();
            // call the Filter 1
            convertImageToBlackAndWhiteImage();
            saveImage();
        } else if (choose == '2')
        {
            loadImage();
            // call the Filter 2
            Invert();
            saveImage();
        } else if (choose == '3')
        {
            loadImage();
            // call the Filter 3
            loadSecondImage();
            mergeImage();
            saveImage();
        } else if (choose == '4')
        {
            loadImage();
            // call the Filter 4
            flipImage();
            saveImage();
        } else if (choose == '5')
        {
            int degreeOfRotate;
            cout << "Rotate (90), (180) or (270) degree? ";
            cin >> degreeOfRotate;
            loadImage();
            // call the Filter 5
            rotateImage(degreeOfRotate);
            saveRotate();
        } else if (choose == '6')
        {
            char choose1;
            cout << "do you want to (d)arken or (l)ighten? ";
            cin >> choose1;
            loadImage();
            if (choose1 == 'l')
            {
                // call the Filter 6 (ligthen)
                lightenImage();
            } else if (choose1 == 'd')
            {
                // call the Filter 6 (darken)
                darkenImage();
            } else
            {
                cout << "invalid";
            }
            saveImage();
        } else if (choose == '7')
        {
            loadImage();
            // call the Filter 7
            detectImageEdges();
            saveImage();
            cout << '7' << endl;
        } else if (choose == '8')
        {
            int quarter;
            cout << "which one of the four quarters do you want to get bigger ? ";
            cin >> quarter;
            loadImage();
            // call the Filter 8
            EnlargeImage(quarter);
            saveRotate();
        } else if (choose == '9')
        {
            string choose;
            cout << "Shrink to 1/2, 1/3 or 1/4: ";
            cin >> choose;
            loadImage();
            if (choose == "1/2")
            {
                // call the Filter 9 (half)
                shrinkAhalfImage();
            } else if (choose == "1/3")
            {
                // call the Filter 9 (A Third)
                shrinkAthirdImage();
            } else if (choose == "1/4")
            {
                // call the Filter 9 (Quarter)
                shrinkQuarterImage();
            } else
            {
                cout << "invalid";
            }
            saveRotate();
        } else if (choose == 'a')
        {
            loadImage();
            // call the Filter a
            mirrorImage();
            saveImage();
        } else if (choose == 'b')
        {
            int a, b, c, d;
            cout << "which order do you want : ";
            cin >> a >> b >> c >> d;
            loadImage();
            shuffleImage1(a);
            shuffleImage2(b);
            shuffleImage3(c);
            shuffleImage4(d);
            saveRotate();
        } else if (choose == 'c')
        {
            loadImage();
            // call the Filter c
            blurImage();
            saveImage();
        } else if (choose == 's')
        {
            loadImage();
            saveImage();
        } else
        {
            cout << "See you later" << endl;
            return 0;
        }
    }
    return 0;
}

// definition of function for load the image
void loadImage()
{
    char imageFileName[100];

    // Get coloured image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}

// definition of function for save the image
void saveImage()
{
    char imageFileName[100];

    // Get coloured image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
// definition of function for convert the image to gray to use it in 2 Filters (1 and 7)
void convertImageToGray()
{
    double gray;
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // equation for percentage of (red, green and blue) in gray image
            // to convert all pixels to gray scale
            gray = (((image[i][j][0]) * 0.3) + ((image[i][j][1]) * 0.59) + ((image[i][j][2]) * 0.11));
            // assign the value of the gray to all pixels
            image[i][j][0] = gray;
            image[i][j][1] = gray;
            image[i][j][2] = gray;
        }
    }
}

// definition of function for convert the image to black and white image
void convertImageToBlackAndWhiteImage()
{
    // call the function of convertImageToGray
    // to make the convert easier
    convertImageToGray();
    // nested 3 for loops to loop each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                // if the value of pixel greater than 127 (that refer to the level of colour in that pixel is low )
                // else (that refer to the level of colour in that pixel is high )
                if (image[i][j][k] > 127) {
                    // convert the pixel of image to white
                    image[i][j][k] = 255;
                } else {
                    // convert the pixel of image to black
                    image[i][j][k] = 0;
                }
            }
        }
    }
}

// definition of function for invert the colour of image
void Invert()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                // subtract from 255 the value of pixel to invert the image
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}

// definition of function for load the second image that will use in merge image
void loadSecondImage()
{
    char image2FileName[100];
    // Get coloured image file name
    cout << "Enter the source image file name of image2: ";
    cin >> image2FileName;

    // Add to image file name .bmp extension and load image
    strcat(image2FileName, ".bmp");
    readRGBBMP(image2FileName, image2);
}

// definition of function for merge two images to one image
void mergeImage()
{
    // initialize average matrix
    int avg[SIZE][SIZE][RGB];
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                // get the average of the pixels of the two images
                avg[i][j][k] = (image[i][j][k] + image2[i][j][k]) / 2;
                image[i][j][k] = avg[i][j][k];
            }
        }
    }
}

// definition of function for
void flipImage()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0, a = SIZE - 1; j < a; j++, a--)
        {
            for (int k = 0; k < RGB; ++k)
            {
                swap(image[j][i][k], image[a][i][k]);
            }
        }
    }
}

//  definition of function for rotate image by 180 degree
void rotate_180_degree()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                rotate[SIZE - i][SIZE - j][k] = image[i][j][k];
            }
        }
    }
}

// definition of function for rotate the image by 90 degree
void rotate_90_degree()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                rotate[i][j][k] = image[SIZE - j][i][k];
            }
        }
    }
}

// definition of function for rotate the image by 270 degree
void rotate_270_degree()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                rotate[i][j][k] = image[j][SIZE - i][k];
            }
        }
    }
}
// definition of function for rotateImage
void rotateImage(int &degreeOfRotate)
{
    // if the user want to rotate the image 90 degree call the function rotate_90_degree
    // if the user want to rotate 180 degree call the function rotate_180_degree
    // if the user want to rotate 2700 degree call the function rotate_270_degree
    if (degreeOfRotate == 90)
    {
        rotate_90_degree();
    } else if (degreeOfRotate == 180)
    {
        rotate_180_degree();
    } else if (degreeOfRotate == 270)
    {
        rotate_270_degree();
    } else
    {
        cout << "invalid degree" << endl;
    }
}

// definition of function for save the rotated image
void saveRotate()
{
    char imageFileName[100];

    // Get coloured image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, rotate);
}

// definition of function for lighten the image
void lightenImage()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            { 
                //if the result of multiplying each pixel by 1.5 bigger than 255 let it be 255(be white)
                //else multiply each pixel by 1.5(be lighten)
                if ((image[i][j][k] *= 1.5) > 255)
                {
                    image[i][j][k] = 255;
                } else
                {
                    image[i][j][k] *= 1.5;
                }
            }
        }
    }
}

// definition of function for darken the image
void darkenImage()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            { 
                //multiply each pixel by 0.5(be darken)
                image[i][j][k] *= 0.5;
            }
        }
    }
}

// definition of function for the edges of an image
void detectImageEdges()
{
    // call function convertImageToGray
    convertImageToGray();
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                // if result of subtract two adjecant pixels greater than or equal to 5 (convert the first pixel to black)
                // else (convert the first pixel to white)
                if (((image[i][j][k]) - (image[i + 1][j + 1][k])) >= 5)
                {
                    image[i][j][k] = 0;
                } else
                {
                    image[i][j][k] = 255;
                }
            }

        }

    }
}

void EnlargeImage1()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < (SIZE / 2), k < SIZE; k += 2, i++)
    {
        for (int j = 0, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2)
        {
            for (int m = 0; m < RGB; m++)
            {
                rotate[k][l][m] = image[i][j][m];
                rotate[k][l + 1][m] = image[i][j][m];
                rotate[k + 1][l][m] = image[i][j][m];
                rotate[k + 1][l + 1][m] = image[i][j][m];
            }
        }
    }
}

void EnlargeImage2()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < SIZE, k < SIZE; k += 2, i++)
    {
        for (int j = SIZE / 2, l = 0; j < SIZE, l < SIZE; j++, l += 2)
        {
            for (int m = 0; m < RGB; m++)
            {
                rotate[k][l][m] = image[i][j][m];
                rotate[k][l + 1][m] = image[i][j][m];
                rotate[k + 1][l][m] = image[i][j][m];
                rotate[k + 1][l + 1][m] = image[i][j][m];
            }
        }
    }
}

void EnlargeImage3()
{
    // 3 nested loops to loop in each pixel
    for (int i = SIZE / 2, k = 0; i < SIZE, k < SIZE; k += 2, i++)
    {
        for (int j = 0, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2)
        {
            for (int m = 0; m < RGB; m++)
            {
                rotate[k][l][m] = image[i][j][m];
                rotate[k][l + 1][m] = image[i][j][m];
                rotate[k + 1][l][m] = image[i][j][m];
                rotate[k + 1][l + 1][m] = image[i][j][m];
            }
        }
    }
}

void EnlargeImage4()
{
    // 3 nested loops to loop in each pixel
    for (int i = SIZE / 2, k = 0; i < SIZE, k < SIZE; k += 2, i++)
    {
        for (int j = SIZE / 2, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2)
        {
            for (int m = 0; m < RGB; m++)
            {
                rotate[k][l][m] = image[i][j][m];
                rotate[k][l + 1][m] = image[i][j][m];
                rotate[k + 1][l][m] = image[i][j][m];
                rotate[k + 1][l + 1][m] = image[i][j][m];
            }
        }
    }
}

// definition of function for EnlargeImage
void EnlargeImage(int &quarter)
{
    if (quarter == 1)
    {
        EnlargeImage1();
    } else if (quarter == 2)
    {
        EnlargeImage2();
    } else if (quarter == 3)
    {
        EnlargeImage3();
    } else if (quarter == 4)
    {
        EnlargeImage4();
    } else
    {
        cout << "invalid quarter " << endl;
    }
}

// definition of function for shrink an Image to (a half)
void shrinkAhalfImage()
{
    int sum = 0;
    // 3 nested loops to loop in each pixel
    //convert each pixel to white
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int n = 0; n < RGB; n++)
            {
                rotate[i][j][n] = 255;
            }
        }
    }
    // 3 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < SIZE; i += 2, k++)
    {
        for (int j = 0, l = 0; j < SIZE; j += 2, l++)
        {
            for (int n = 0; n < RGB; n++)
            { 
                //get the average of 4 pixels (square)
                // take this average and put it in the rotate
                sum = (image[i][j][n] + image[i][j + 1][n] + image[i + 1][j][n] + image[i + 1][j + 1][n]) / 4;
                rotate[k][l][n] = sum;
            }
        }
    }
}

// definition of function for shrink an Image to (a third)
void shrinkAthirdImage()
{
    int sum = 0;
    // 3 nested loops to loop in each pixel
    //convert each pixel to white
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int n = 0; n < RGB; n++)
            {
                rotate[i][j][n] = 255;
            }
        }
    }
    // 3 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < SIZE; i += 3, k++)
    {
        for (int j = 0, l = 0; j < SIZE; j += 3, l++)
        {
            for (int n = 0; n < RGB; n++)
            { 
                //get the average of 9 pixels
                // take this average and put it in the rotate
                sum = (image[i][j][n] + image[i][j + 1][n] + image[i][j + 2][n] + image[i + 1][j][n] +
                       image[i + 1][j + 1][n]
                       + image[i + 1][j + 2][n] + image[i + 2][j][n] + image[i + 2][j + 1][n] +
                       image[i + 2][j + 2][n]) / 9;
                rotate[k][l][n] = sum;
            }
        }

    }
}

// definition of function for shrink an Image to (a Quarter)
void shrinkQuarterImage()
{
    int sum = 0;
    int i = 0, j = 0;
    // 3 nested loops to loop in each pixel
     //convert each pixel to white
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int n = 0; n < RGB; n++)
            {
                rotate[i][j][n] = 255;
            }
        }
    }
    // 3 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < SIZE; i += 4, k++)
    {
        for (int j = 0, l = 0; j < SIZE; j += 4, l++)
        {
            for (int n = 0; n < RGB; n++)
            { 
                //get the average of 16 pixels
                // take this average and put it in the rotate
                sum = (image[i][j][n] + image[i][j + 1][n] + image[i][j + 2][n] + image[i][j + 3][n] +
                       image[i + 1][j][n] + image[i + 1][j + 1][n] + image[i + 1][j + 2][n] + image[i + 1][j + 3][n] +
                       image[i + 2][j][n] + image[i + 2][j + 1][n]
                       + image[i + 2][j + 2][n] + image[i + 2][j + 3][n] + image[i + 3][j][n] + image[i + 3][j + 1][n] +
                       image[i + 3][j + 2][n] + image[i + 3][j + 3][n]) / 16;
                rotate[k][l][n] = sum;
            }
        }

    }
}

// definition of function for mirror the half of image (left to right)
void mirrorLeftRight()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE / 2; j++)// we loop in columns to (SIZE / 2) because to mirror half of image
        {
            for (int k = 0; k < RGB; ++k)
            {
                // mirror each pixel
                // ex: the pixel [0][0][0] will mirror in pixel [0][255][0]
                // the pixel [0][1][0] will mirror in pixel [0][254][0] and so on
                image[i][SIZE - 1 - j][k] = image[i][j][k];
            }
        }
    }
}

// definition of function for mirror the half of image (right to left)
void mirrorRightLeft()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 256; j > SIZE / 2; --j)// we loop in columns to (SIZE / 2) because to mirror half of image
                                            // we inverse the count to start from the end
        {
            for (int k = 0; k < RGB; ++k)
            {
                // mirror each pixel
                // ex: the pixel [0][0][0] will mirror in pixel [0][255][0]
                // the pixel [0][1][0] will mirror in pixel [0][254][0] and so on
                image[i][SIZE - 1 - j][k] = image[i][j][k];
            }
        }
    }
}

// definition of function for mirror the half of image (up to down)
void mirrorUpDown()
{
     // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE / 2; ++i)// we loop in rows to (SIZE / 2) because to mirror half of image
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                // mirror each pixel
                // ex: the pixel [0][0][0] will mirror in pixel [255][0][0]
                // the pixel [1][0][0] will mirror in pixel [254][0][0] and so on
                image[SIZE - 1 - i][j][k] = image[i][j][k];
            }
        }
    }
}

// definition of function for mirror the half of image (down to up)
void mirrorDownUp()
{
    // 3 nested loops for loop to each pixel
    for (int i = 255; i > SIZE / 2; --i)// we loop in rows to (SIZE / 2) because to mirror half of image
                                        // we inverse the count to start from the end
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                // mirror each pixel
                // ex: the pixel [0][0][0] will mirror in pixel [255][0][0]
                // the pixel [1][0][0] will mirror in pixel [254][0][0] and so on
                image[SIZE - 1 - i][j][k] = image[i][j][k];
            }
        }
    }
}

// definition of function for mirror half an image
void mirrorImage()
{
    char mirrorSide;
    // give the user choice of mirror side
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
    cin >> mirrorSide;
    // if mirrorSide == l --> call mirrorLeftRight
    // else if mirrorSide == r --> call mirrorRightLeft
    // else if mirrorSide == u --> call mirrorUpDown
    // else if mirrorSide == d --> call mirrorDownUp
    // else invalid side
    if (mirrorSide == 'l')
    {
        // call mirrorLeftRight function
        mirrorLeftRight();
    } else if (mirrorSide == 'r')
    {
        // call mirrorRightLeft function
        mirrorRightLeft();
    } else if (mirrorSide == 'u')
    {
        // call mirrorUpDown function
        mirrorUpDown();
    } else if (mirrorSide == 'd')
    {
        // call mirrorDownUp function
        mirrorDownUp();
    } else
    {
        cout << "invalid side" << endl;
    }
}

// definition of function for shuffle Image
void shuffleImage1(int &a)
{
    if (a == 1)
    {
         // 3 nested loops to loop in each pixel
        for (int i = 0; i < SIZE / 2; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[i][j][m] = image[i][j][m];
                }
            }
        }
    } else if (a == 2)
    {
         // 3 nested loops to loop in each pixel
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++)
        {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (a == 3)
    {
         // 3 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++)
        {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++)
            {
                for (int m = 0; m < RGB; m++) {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (a == 4)
    {
         // 3 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++)
        {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    }
}

void shuffleImage2(int &b)
{
    if (b == 1)
    {
         // 3 nested loops to loop in each pixel
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++)
        {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (b == 2)
    {
         // 3 nested loops to loop in each pixel
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++)
        {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (b == 3)
    {
         // 3 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++)
        {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (b == 4)
    {
         // 3 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++)
        {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    }
}

void shuffleImage3(int &c)
{
    if (c == 1)
    {
        // 3 nested loops to loop in each pixel
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++)
        {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (c == 2)
    {
        // 3 nested loops to loop in each pixel
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++)
        {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (c == 3)
    {
        // 3 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++)
        {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (c == 4)
    {
        // 3 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++)
        {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    }
}

void shuffleImage4(int &d)
{
    if (d == 1)
    {
        // 3 nested loops to loop in each pixel
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++)
        {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (d == 2)
    {
        // 3 nested loops to loop in each pixel
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++)
        {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (d == 3)
    {
        // 3 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++)
        {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    } else if (d == 4)
    {
        // 3 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++)
        {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++)
            {
                for (int m = 0; m < RGB; m++)
                {
                    rotate[k][l][m] = image[i][j][m];
                }
            }
        }
    }
}

// definition of function for blur Image
void blurImage()
{
    // 3 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int m = 0; m < RGB; ++m)
            { 
                // 3 nested loops to loop in each pixel
                //this loop will make a cube of pixels (7rows, 7columns, 7channels)
                int sum = 0;
                for (int k = 0; k < 7; ++k)
                {
                    for (int l = 0; l < 7; ++l)
                    {
                        for (int n = 0; n < 7; ++n)
                        { 
                            //sum of this pixels
                            sum += image[i + k][j + l][m + n];
                        }
                    }
                } 
                //put the average of this pixels in the middle of the cube
                image[i + 3][j + 3][m + 3] = sum / 343;
            }
        }
    }
}
