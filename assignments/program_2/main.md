```c++
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
struct rgb {
	int r;
	int g;
	int b;
};

class ImageManip {
private:
	rgb** imgArray;
	int width;
	int height;
	ifstream ifile;
	ofstream ofile;
	string ifile_name;
	string ofile_name;

	/**
	* @FunctionName: readFile
	* @Description:
	*     Reads through file assigning rgb values to imgArray after
	*	  declaring height/width.
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void readFile() {
		ifile.open(ifile_name);
		ifile >> width >> height;
			
		imgArray = new rgb*[height];

		for (int i = 0; i<height; i++) {
			imgArray[i] = new rgb[width];
		}

		for (int i = 0; i<height; i++) {
			for (int j = 0; j<width; j++) {
				ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
			}
		}
	}

	/**
	* @FunctionName: readFile
	* @Description:
	*     Writes to out file.
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void writeFile() {
		ofile.open(ofile_name);
		ofile << width << " " << height << endl;
		for (int i = 0; i<height; i++) {
			for (int j = 0; j<width; j++) {
				ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
			}
			ofile << endl;
		}
	}

public:
	// constructor isn't required. class is already initialized.

	/**
	* @FunctionName: flipVert
	* @Description:
	*     Loops through rows of RGB values and reverses their row position.
	* @Params:
	*    string ifile_n - input file name
	*    string ofile_n - output file name
	* @Returns:
	*    void
	*/
	void flipVert(string ifile_n, string ofile_n) {
		ifile_name = ifile_n;
		ofile_name = ofile_n;
		readFile();
		for (int c = 0; c<width; c++) {
			imgArray[c] = imgArray[height - 1 - c];
		}
	}

	/**
	* @FunctionName: flipHorz
	* @Description:
	*     Loops through columns of RGB values and reverses their column position.
	* @Params:
	*    string ifile_n - input file name
	*    string ofile_n - output file name
	* @Returns:
	*    void
	*/
	void flipHorz(string ifile_n, string ofile_n) {
		ifile_name = ifile_n;
		ofile_name = ofile_n;
		readFile();
		for (int r = 0; r<height; r++) {
			for (int c = 0; c<width; c++) {
				imgArray[r][c] = imgArray[r][width - 1 - c];
			}
		}
	}

	/**
	* @FunctionName: grayScale
	* @Description:
	*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
	* @Params:
	*    string ifile_n - input file name
	*    string ofile_n - output file name
	* @Returns:
	*    void
	*/
	void grayScale(string ifile_n, string ofile_n) {
		ifile_name = ifile_n;
		ofile_name = ofile_n;
		readFile();
		int avg;
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				avg = (imgArray[r][c].r + imgArray[r][c].g + imgArray[r][c].b) / 3;
				imgArray[r][c].r = avg;
				imgArray[r][c].g = avg;
				imgArray[r][c].b = avg;
			}
		}
	}

	// destructor; required to write out results at the end of program
	~ImageManip() {
		writeFile();
	}
};

int main() {

	ImageManip image;
	image.grayScale("octocat.txt", "response.txt");

	return 0;

}
```
