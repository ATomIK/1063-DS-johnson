/**
* @ProgramName: Program-1
* @Author: Thomas Johnson
* @Description:
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 02 06 2017
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
    int r;
    int g;
    int b;
};

int main(){
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");

    int width;               //width of image
    int height;              //height of image

    rgb **imgArray;         //Pointer var for our 2D array because we
                            //don't know how big the image will be!

    ifile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right
                            //size. After we get these two values, we can
                            //now allocate memory for our 2D array.

    imgArray = new rgb*[height];    //This array points to every row

    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }

    //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;
        }
    }

    //We could make any changes we want to the color image here

    /**
    * @FunctionName: flipVert
    * @Description:
    *     Loops through rows of RGB values and reverses their row position.
    * @Params:
    *    rgb** image - 2D array holding rgb values
    *    int width - width of image
    *    int height - height of image
    * @Returns:
    *    void
    */
    void flipVert(rgb** image,int width,int height){

    }

    /**
    * @FunctionName: flipHorz
    * @Description:
    *     Loops through columns of RGB values and reverses their column position.
    * @Params:
    *    rgb** image - 2D array holding rgb values
    *    int width - width of image
    *    int height - height of image
    * @Returns:
    *    void
    */
    void flipHorz(rgb** image,int width,int height){

    }

    /**
    * @FunctionName: grayScale
    * @Description:
    *     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
    * @Params:
    *    rgb** image - 2D array holding rgb values
    *    int width - width of image
    *    int height - height of image
    * @Returns:
    *    void
    */
    void grayScale(rgb** image,int width,int height){

    }

    /**
    * @FunctionName: changeColor
    * @Description:
    *     Loops through a 2D array and turns every RGB value into the new color.
    * @Params:
    *    rgb** image - 2D array holding rgb values
    *    int width - width of image
    *    int height - height of image
    *    rgb newColor - a struct holding the new color for the image.
    * @Returns:
    *    void
    */
    void changeColor(rgb** image,int width, int height, rgb newColor){
       // loop through image
       // assign newColor to each location in array
    }

    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }


  return 0;
}
