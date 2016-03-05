#include<iostream>
using namespace std;

const int MAX_COLOR_VAL = 1000;
const int MIN_COLOR_VAL = 0;
const int IMAGE_ROW_SIZE = 10;
const int IMAGE_COL_SIZE = 18;
const int MIN_IMAGE_ROW_SIZE = 0;
const int MIN_IMAGE_COL_SIZE = 0;

class ColorClass
{
	private:
		int redVal;
		int greenVal;
		int blueVal;
		//setColorClipped is a helper function for setting colors
		//and checking clipped status		
		bool setColorClipped(int inRed, int inGreen, int inBlue);
	public:
		ColorClass();
		ColorClass(int inRed, int inGreen, int inBlue);
		void setToBlack();
		void setToRed();
		void setToGreen();
		void setToBlue();
		void setToWhite();
		bool setTo(int inRed, int inGreen, int inBlue);
		bool setTo(ColorClass &inColor);
		bool addColor(ColorClass &rhs);
		bool subtractColor(ColorClass &rhs);
		bool adjustBrightness(double adjFactor);
		void printComponentValues();
};

ColorClass::ColorClass()
{
	redVal = MAX_COLOR_VAL;
	greenVal = MAX_COLOR_VAL;
	blueVal = MAX_COLOR_VAL;
	
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
	redVal = inRed;
	greenVal = inGreen;
	blueVal = inBlue;
}

void ColorClass::setToBlack()
{
	redVal = MIN_COLOR_VAL;
	greenVal = MIN_COLOR_VAL;
	blueVal = MIN_COLOR_VAL;
}

void ColorClass::setToRed()
{
	redVal = MAX_COLOR_VAL;
	greenVal = MIN_COLOR_VAL;
	blueVal = MIN_COLOR_VAL;
}

void ColorClass::setToGreen()
{
	redVal = MIN_COLOR_VAL;
	greenVal = MAX_COLOR_VAL;
	blueVal = MIN_COLOR_VAL;
}

void ColorClass::setToBlue()
{
	redVal = MIN_COLOR_VAL;
	greenVal = MIN_COLOR_VAL;
	blueVal = MAX_COLOR_VAL;
}

void ColorClass::setToWhite()
{
	redVal = MAX_COLOR_VAL;
	greenVal = MAX_COLOR_VAL;
	blueVal = MAX_COLOR_VAL;
}

bool ColorClass::setColorClipped(int inRed, int inGreen, int inBlue)
{
	bool clipped = false;
	
	if(MIN_COLOR_VAL <= inRed && inRed <= MAX_COLOR_VAL)
	{
		redVal = inRed;
	}
	if(inRed <= MIN_COLOR_VAL)
	{
		redVal = MIN_COLOR_VAL;
		clipped = true;
	}
	if(inRed >= MAX_COLOR_VAL)
	{
		redVal = MAX_COLOR_VAL;
		clipped = true;
	}
	if(MIN_COLOR_VAL <= inGreen && inGreen <= MAX_COLOR_VAL)
	{
		greenVal = inGreen;
	}
	if(inGreen <= MIN_COLOR_VAL)
	{
		greenVal = MIN_COLOR_VAL;
		clipped = true;
	}
	if(inGreen >= MAX_COLOR_VAL)
	
	{
		greenVal = MAX_COLOR_VAL;
		clipped = true;
	}

	if(MIN_COLOR_VAL <= inBlue && inBlue <= MAX_COLOR_VAL)
	{
		blueVal = inBlue;
	}
	if(inBlue <= MIN_COLOR_VAL)
	{
		blueVal = MIN_COLOR_VAL;
		clipped = true;
	}
	if(inBlue >= MAX_COLOR_VAL)
	
	{
		blueVal = MAX_COLOR_VAL;
		clipped = true;
	}
	
	return clipped;

}

bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
	bool clipped;
	clipped = setColorClipped(inRed, inGreen, inBlue);
	return clipped;
}

bool ColorClass::setTo(ColorClass &inColor)
{
	bool clipped;
	clipped = setColorClipped(
	          inColor.redVal, 
	          inColor.greenVal, 
	          inColor.blueVal
	          );
	return clipped;
}

bool ColorClass::addColor(ColorClass &rhs)
{
	bool clipped;
	int redValAdded = redVal + rhs.redVal;
	int greenValAdded = greenVal + rhs.greenVal;
	int blueValAdded = blueVal + rhs.blueVal;
	clipped = setColorClipped(redValAdded, greenValAdded, blueValAdded);
	return clipped;
}

bool ColorClass::subtractColor(ColorClass &rhs)
{
	bool clipped;
	int redValSub = redVal - rhs.redVal;
	int greenValSub= greenVal - rhs.greenVal;
	int blueValSub = blueVal - rhs.blueVal;
	
	clipped = setColorClipped(redValSub, greenValSub, blueValSub);
	return clipped;
}

bool ColorClass::adjustBrightness(double adjFactor)
{
	bool clipped;
	int redValAdj = int(redVal * adjFactor);
	int greenValAdj = int(greenVal * adjFactor);
	int blueValAdj = int(blueVal * adjFactor);
	
	clipped = setColorClipped(redValAdj, greenValAdj, blueValAdj);
	return clipped;
}

void ColorClass::printComponentValues()
{
	cout << "R: "<< redVal <<" G: "<< greenVal <<" B: "<< blueVal;
}

class RowColumnClass
{
	private:
		int row;
		int column;
		
	public:
		RowColumnClass();
		void setRowCol(int inRow, int inCol);
		void setRow(int inRow);
		void setCol(int inCol);
		int getRow();
		int getCol();
		void addRowColTo(RowColumnClass &inRowCol);
		void printRowCol();
};


RowColumnClass::RowColumnClass()
{
	;
}

void RowColumnClass::setRowCol(int inRow, int inCol)
{
	row = inRow;
	column = inCol;
}

void RowColumnClass::setRow(int inRow)
{
	row = inRow;
}

void RowColumnClass::setCol(int inCol)
{
	column = inCol;
}

int RowColumnClass::getRow()
{
	return row;
}

int RowColumnClass::getCol()
{
	return column;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
	row += inRowCol.row;
	column += inRowCol.column;
}

void RowColumnClass::printRowCol()
{
	cout <<"["<<row<<","<<column<<"]";
}

class ColorImageClass
{
	private:
		ColorClass imgPixels[IMAGE_ROW_SIZE][IMAGE_COL_SIZE];
		
	public:
		ColorImageClass();
		void initializeTo(ColorClass &inColor);
		bool addImageTo(ColorImageClass &rhsImg);
		bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd []);
		bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
		bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass & outColor);
		void printImage();
};

ColorImageClass::ColorImageClass()
{
	;
}

void ColorImageClass::initializeTo(ColorClass &inColor)
{
	for (int i = 0; i < IMAGE_ROW_SIZE; i++)
	{
		for (int j = 0; j < IMAGE_COL_SIZE; j++)
		{
			imgPixels[i][j].setTo(inColor);
		}
	}
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
	bool clipped = false;
	
	for (int i = 0; i < IMAGE_ROW_SIZE; i++)
	{
		for (int j = 0; j < IMAGE_COL_SIZE; j++)
		{
			clipped = imgPixels[i][j].addColor(rhsImg.imgPixels[i][j]); 
		}
	}
	return clipped;
}

bool ColorImageClass::addImages(
					  int numImgsToAdd, 
					  ColorImageClass imagesToAdd []
					  )
{
	bool clipped = false;
	ColorClass cc;
	cc.setToBlack();
	
	//Initialize all pixels to black (R: 0, G: 0, B: 0), when adding images from 
    //imagesToAdd, the RGB values will be added to 0, 0, 0. Same as assigning sum
    //values from imagesToAdd
	this -> initializeTo(cc);
	
	for (int i = 0; i < numImgsToAdd; i++)
	{
		
		clipped = this -> addImageTo(imagesToAdd[i]);
	}
	
	return clipped;
}

bool ColorImageClass::setColorAtLocation(
					  RowColumnClass &inRowCol, 
					  ColorClass &inColor
					  )
{
	bool validLocation = false;
	int rowIdx= inRowCol.getRow();
	int colIdx = inRowCol.getCol();
	if ((MIN_IMAGE_ROW_SIZE <= rowIdx && rowIdx <= IMAGE_ROW_SIZE)
		&& (MIN_IMAGE_COL_SIZE <= colIdx && colIdx <= IMAGE_COL_SIZE))
	{
		imgPixels[rowIdx][colIdx].setTo(inColor);
		validLocation = true;
	}		
	
	return validLocation;			
}
bool ColorImageClass::getColorAtLocation(
					  RowColumnClass &inRowCol, 
					  ColorClass & outColor
					  )
{
	bool validLocation = false;
	int rowIdx= inRowCol.getRow();
	int colIdx = inRowCol.getCol();
	if ((MIN_IMAGE_ROW_SIZE <= rowIdx && rowIdx <= IMAGE_ROW_SIZE)
		&& (MIN_IMAGE_COL_SIZE <= colIdx && colIdx <= IMAGE_COL_SIZE))
	{
		outColor.setTo(imgPixels[rowIdx][colIdx]);
		validLocation = true;
	}
	
	return validLocation;		
}

void ColorImageClass::printImage()
{
	for (int i = 0; i < IMAGE_ROW_SIZE; i++)
	{
		for (int j = 0; j < IMAGE_COL_SIZE; j++)
		{
			imgPixels[i][j].printComponentValues();
			if (j < IMAGE_COL_SIZE - 1)
			{
				cout<<"--";
			}
		}
		cout<<endl;
	}
}

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else

int main()
{
	ColorClass testColor;
	RowColumnClass testRowCol;
	RowColumnClass testRowColOther;
	ColorImageClass testImage;
	ColorImageClass testImages[3];

	//Test some basic ColorClass operations...
	testColor.setToBlack();
	cout << "Initial: ";
	testColor.printComponentValues();
	cout << endl;

	testColor.setToBlack();
	cout << "Black: ";
	testColor.printComponentValues();
	cout << endl;

	testColor.setToGreen();
	cout << "Green: ";
	testColor.printComponentValues();
	cout << endl;

	testColor.adjustBrightness(0.5);
	cout << "Dimmer Green: ";
	testColor.printComponentValues();
	cout << endl;

	//Test some basic RowColumnClass operations...
	testRowCol.setRowCol(2, 8);
	cout << "Want 2,8: ";
	testRowCol.printRowCol();
	cout << endl;

	testRowColOther.setRowCol(4, 2);
	testRowCol.addRowColTo(testRowColOther);
	cout << "Want 6,10: ";
	testRowCol.printRowCol();
	cout << endl;

	//Test some basic ColorImageClass operations...
	testColor.setToRed();
	testImage.initializeTo(testColor);

	testRowCol.setRowCol(555, 5);
	cout << "Want: Color at [555,5]: Invalid Index!" << endl;
	cout << "Color at ";
	testRowCol.printRowCol();
	cout << ": ";
	if (testImage.getColorAtLocation(testRowCol, testColor))
	{
		testColor.printComponentValues();
	}
	else
	{
		cout << "Invalid Index!";
	}
	cout << endl;

	testRowCol.setRow(4);
	cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
	cout << "Color at ";
	testRowCol.printRowCol();
	cout << ": ";
	if (testImage.getColorAtLocation(testRowCol, testColor))
	{
		testColor.printComponentValues();
	}
	else
	{
		cout << "Invalid Index!";
	}
	cout << endl;

	//Set up an array of images of different colors
	testColor.setToRed();
	testColor.adjustBrightness(0.25);
	testImages[0].initializeTo(testColor);
	testColor.setToBlue();
	testColor.adjustBrightness(0.75);
	testImages[1].initializeTo(testColor);
	testColor.setToGreen();
	testImages[2].initializeTo(testColor);

	//Modify a few individual pixel colors
	testRowCol.setRowCol(4, 2);
	testColor.setToWhite();
	testImages[1].setColorAtLocation(testRowCol, testColor);

	testRowCol.setRowCol(2, 4);
	testColor.setToBlack();
	testImages[2].setColorAtLocation(testRowCol, testColor);

	//Add up all images in testImages array and assign result
	//to the testImage image
	testImage.addImages(3, testImages);
	
	//Check some certain values
	cout << "Added values:" << endl;
	for (int colInd = 0; colInd < 8; colInd += 2)
	{
		testRowCol.setRowCol(4, colInd);
		cout << "Color at ";
		testRowCol.printRowCol();
		cout << ": ";
		if (testImage.getColorAtLocation(testRowCol, testColor))
		{
			testColor.printComponentValues();
		}
		else
		{
			cout << "Invalid Index!";
		}
		cout << endl;
	}
	
	for (int rowInd = 0; rowInd < 8; rowInd += 2)
	{
		testRowCol.setRowCol(rowInd, 4);
		cout << "Color at ";
		testRowCol.printRowCol();
		cout << ": ";
		if (testImage.getColorAtLocation(testRowCol, testColor))
		{
			testColor.printComponentValues();
		}
		else
		{
			cout << "Invalid Index!";
		}
		cout << endl;
	}
	
	cout << "Printing entire test image:" << endl;
	testImage.printImage();

	return 0;
}

#endif
