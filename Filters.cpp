// FCI – Programming 1 – 2022 - Assignment 3
// Program: Filters.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
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

// declaration of function for
void detectImageEdges();

// declaration of function for
void EnlargeImage(int &quarter);
void EnlargeImage1();
void EnlargeImage2();
void EnlargeImage3();
void EnlargeImage4();

// declaration of function for shrink Image to a half
void shrinkAhalfImage();
// declaration of function for shrink Image to a third
void shrinkAthirdImage();
// declaration of function for shrink Image to a quarter
void shrinkQuarterImage();

// mirror half image
void mirrorImage();

// declaration of function for shuffle Image
void shuffleImage1(int &a);
void shuffleImage2(int &b);
void shuffleImage3(int &c);
void shuffleImage4(int &d);

// declaration of function for blur the Image
void blurImage();


int main()
{
    char choose = ' ';
    while (choose != '0')
    {
        // enter face of the program
        // let the user to choose what the filter he/she wants
        cout << "Ahlan ya user ya habibi " << endl;
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
                // call the Filter (a half)
                shrinkAhalfImage();
            } else if (choose == "1/3")
            {
                // call the Filter (a third)
                shrinkAthirdImage();
            } else if (choose == "1/4")
            {
                // call the Filter (a quarter)
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
void convertImageToBlackAndWhiteImage()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > 127)
            {
                // convert all pixels that greater than 127(level of gray is low) to White
                image[i][j] = 255;
            } else
            {
                // convert all pixels that less than 127(level of gray is high) to Black
                image[i][j] = 0;
            }
        }
    }
}

// definition of function for invert evere black pixel turned to white and every white pixel
// turned to black and every gray pixel is turned to opposite level of brightness
void Invert()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // subtract from 255 the value of pixel to invert the image
            image[i][j] = 255 - image[i][j];
        }
    }
}

// definition of function for load the second image
void loadSecondImage()
{
    char image2FileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name of image2: ";
    cin >> image2FileName;

    // Add to image file name .bmp extension and load image
    strcat(image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);
}

// definition of function for to merge two images to one image
void mergeImage()
{
    // initialize average matrix
    int avg[SIZE][SIZE];
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
         {
            // get the average of the pixels of the two images
            avg[i][j] = (image[i][j] + image2[i][j]) / 2;
            image[i][j] = avg[i][j];
        }
    }
}

//  definition of function for Flip The Image
void flipImage()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0, k = SIZE - 1; j < k; j++, k--)
        {
            // reverse elements of every column.
            swap(image[j][i], image[k][i]);
        }
    }
}

//  definition of function for rotate image by 180 degree
void rotate_180_degree()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            rotate[SIZE - i][SIZE - j] = image[i][j];
        }
    }
}

// definition of function for rotate the image by 90 degree
void rotate_90_degree()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            rotate[i][j] = image[SIZE - j][i];
        }
    }
}

// definition of function for rotate the image by 270 degree
void rotate_270_degree()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            rotate[i][j] = image[j][SIZE - i];
        }
    }
}


// definition of function for rotate the image like the user want (90), (180) or (270)
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
    } else {
        cout << "invalid degree" << endl;
    }
}

// definition of function for save the rotate image
void saveRotate()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, rotate);
}


// definition of function for lighten the image
void lightenImage()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if ((image[i][j] *= 1.5) > 255)
            {
                image[i][j] = 255;
            } else {
                image[i][j] *= 1.5;
            }
        }
    }
}

// definition of function for darken the image
void darkenImage()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] *= 0.5;
        }
    }
}

// definition of function for detect the edges of an image
void detectImageEdges()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // if result of subtract two adjecant pixels greater than or equal to 20 (convert it to black)
            // else (convert the pixel to white)
            if ((image[i][j]) - (image[i + 1][j + 1]) >= 20)
            {
                image[i][j] = 0;
            } else
            {
                image[i][j] = 255;
            }
        }
    }
}


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

void EnlargeImage1()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < (SIZE / 2), k < SIZE; k += 2, i++)
    {
        for (int j = 0, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2)
        {
            rotate[k][l] = image[i][j];
            rotate[k][l + 1] = image[i][j];
            rotate[k + 1][l] = image[i][j];
            rotate[k + 1][l + 1] = image[i][j];

        }
    }
}

void EnlargeImage2()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < SIZE, k < SIZE; k += 2, i++)
    {
        for (int j = SIZE / 2, l = 0; j < SIZE, l < SIZE; j++, l += 2)
        {
            rotate[k][l] = image[i][j];
            rotate[k][l + 1] = image[i][j];
            rotate[k + 1][l] = image[i][j];
            rotate[k + 1][l + 1] = image[i][j];
        }
    }
}

void EnlargeImage3()
{
    // 2 nested loops to loop in each pixel
    for (int i = SIZE / 2, k = 0; i < SIZE, k < SIZE; k += 2, i++)
    {
        for (int j = 0, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2)
        {
            rotate[k][l] = image[i][j];
            rotate[k][l + 1] = image[i][j];
            rotate[k + 1][l] = image[i][j];
            rotate[k + 1][l + 1] = image[i][j];
        }
    }
}

void EnlargeImage4()
{
    // 2 nested loops to loop in each pixel
    for (int i = SIZE / 2, k = 0; i < SIZE, k < SIZE; k += 2, i++)
    {
        for (int j = SIZE / 2, l = 0; j < (SIZE / 2), l < SIZE; j++, l += 2)
        {
            rotate[k][l] = image[i][j];
            rotate[k][l + 1] = image[i][j];
            rotate[k + 1][l] = image[i][j];
            rotate[k + 1][l + 1] = image[i][j];
        }
    }
}

void shrinkAhalfImage()
{
    int sum = 0;
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            rotate[i][j] = 255;
        }
    }
    // 2 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < SIZE; i += 2, k++)
    {
        for (int j = 0, l = 0; j < SIZE; j += 2, l++)
        {
            sum = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 4;
            rotate[k][l] = sum;
        }

    }
}

void shrinkAthirdImage()
{
    int sum = 0;
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            rotate[i][j] = 255;
        }
    }
    // 2 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < SIZE; i += 3, k++)
    {
        for (int j = 0, l = 0; j < SIZE; j += 3, l++)
        {
            sum = (image[i][j] + image[i][j + 1] + image[i][j + 2] + image[i + 1][j] + image[i + 1][j + 1] +
                   image[i + 1][j + 2] + image[i + 2][j] + image[i + 2][j + 1] + image[i + 2][j + 2]) / 9;
            rotate[k][l] = sum;
        }

    }
}


void shrinkQuarterImage()
{
    int sum;
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            rotate[i][j] = 255;
        }
    }
    // 2 nested loops to loop in each pixel
    for (int i = 0, k = 0; i < SIZE; i += 4, k++)
    {
        for (int j = 0, l = 0; j < SIZE; j += 4, l++)
        {
            sum = (image[i][j] + image[i][j + 1] + image[i][j + 2] + image[i][j + 3] + image[i + 1][j] +
                   image[i + 1][j + 1] + image[i + 1][j + 2] + image[i + 1][j + 3] + image[i + 2][j] +
                   image[i + 2][j + 1]
                   + image[i + 2][j + 2] + image[i + 2][j + 3] + image[i + 3][j] + image[i + 3][j + 1] +
                   image[i + 3][j + 2] + image[i + 3][j + 3]) / 16;
            rotate[k][l] = sum;
        }

    }
}

// definition of function for mirror the half left to right
void mirrorLeftRight()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE / 2; j++)// we loop in columns to (SIZE / 2) because to mirror half of image
        {
            // mirror each pixel
            // ex: the pixel [0][0] will mirror in pixel [0][255]
            // the pixel [0][1] will mirror in pixel [0][254] and so on
            image[i][SIZE - 1 - j] = image[i][j];
        }
    }
}

// definition of function for mirror the half right to left
void mirrorRightLeft()
{
     // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 256; j > SIZE / 2; --j)// we loop in columns to (SIZE / 2) because to mirror half of image
                                            // we inverse the count to start from the end
        {
            // mirror each pixel
            // ex: the pixel [0][0] will mirror in pixel [0][255]
            // the pixel [0][1] will mirror in pixel [0][254] and so on
            image[i][SIZE - 1 - j] = image[i][j];
        }
    }
}

// definition of function for mirror the half Up to Down
void mirrorUpDown() {
    for (int i = 0; i < SIZE / 2; ++i)// we loop in columns to (SIZE / 2) because to mirror half of image
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // mirror each pixel
            // ex: the pixel [0][0] will mirror in pixel [255][0]
            // the pixel [1][0] will mirror in pixel [254][0] and so on
            image[SIZE - 1 - i][j] = image[i][j];
        }
    }
}

// definition of function for mirror the half Down to Up
void mirrorDownUp() {
    for (int i = 256; i > SIZE / 2; --i)// we loop in columns to (SIZE / 2) because to mirror half of image
                                        // we inverse the count to start from the end
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // mirror each pixel
            // ex: the pixel [0][0] will mirror in pixel [255][0]
            // the pixel [1][0] will mirror in pixel [254][0] and so on
            image[SIZE - 1 - i][j] = image[i][j];

        }
    }
}

void mirrorImage()
{
    char mirrorSide;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
    cin >> mirrorSide;
    if (mirrorSide == 'l')
    {
        mirrorLeftRight();
    } else if (mirrorSide == 'r')
    {
        mirrorRightLeft();
    } else if (mirrorSide == 'u')
    {
        mirrorUpDown();
    } else if (mirrorSide == 'd')
    {
        mirrorDownUp();
    } else
    {
        cout << "invalid side" << endl;
    }
}

void shuffleImage1(int &a)
{
    if (a == 1)
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0; i < SIZE / 2; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                rotate[i][j] = image[i][j];
            }
        }
    } else if (a == 2)
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++)
        {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (a == 3)
    {
        // 2 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++)
        {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (a == 4)
    {
        // 2 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++)
        {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    }
}

void shuffleImage2(int &b)
{
    if (b == 1)
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++)
        {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (b == 2)
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0, k = 0; i < SIZE / 2; i++, k++)
        {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (b == 3)
    {
        // 2 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++)
        {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (b == 4)
    {
        // 2 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++)
        {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    }
}

void shuffleImage3(int &c)
{
    if (c == 1)
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++)
        {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (c == 2)
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++)
        {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (c == 3)
    {
        // 2 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++)
        {
            for (int j = 0, l = 0; j < SIZE / 2; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (c == 4)
    {
        // 2 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++)
        {
            for (int j = SIZE / 2, l = 0; j < SIZE; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    }
}

void shuffleImage4(int &d)
{
    if (d == 1)
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++)
            {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (d == 2)
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0, k = SIZE / 2; i < SIZE / 2; i++, k++)
        {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++)
                {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (d == 3)
    {
        // 2 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++)
        {
            for (int j = 0, l = SIZE / 2; j < SIZE / 2; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    } else if (d == 4)
    {
        // 2 nested loops to loop in each pixel
        for (int i = SIZE / 2, k = SIZE / 2; i < SIZE; i++, k++)
        {
            for (int j = SIZE / 2, l = SIZE / 2; j < SIZE; j++, l++)
            {
                rotate[k][l] = image[i][j];
            }
        }
    }
}


void blurImage()
{
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int sum = 0;
            for (int k = 0; k < 7; ++k)
            {
                for (int l = 0; l < 7; ++l)
                {
                    sum += image[i + k][j + l];
                }
            }
            image[i + 3][j + 3] = sum / 49;
        }
    }
}
