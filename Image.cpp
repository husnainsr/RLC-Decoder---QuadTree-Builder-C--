#include "Image.h"
#include <fstream>
#include <iostream>
using namespace std;


Image::Image()
{
    arr = NULL;
    row = col = countR = countC = 0;
}
Image::Image(const Image& obj)
{
    this->row = obj.row;
    this->col = obj.col;
    setSize(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = obj.arr[i][j];
        }
    }
    //_arr = new int[_size];

    //for (int i = 0; i < _size; i++)
        //*_arr[i] = *obj._arr[i];
}
void Image::setSize(int r, int c)
{
    arr = new int* [r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = 255;
        }
    }
    row = r;
    col = c;
}
void Image::insert(int value)
{

    if (row != countR)
    {
        if (value == 32 || value == 0)
        {
            cout << value << " ";
            arr[countR][countC] = 0;
            countC++;
        }
        else
        {
            arr[countR][countC] = 255;
            countC++;
        }
        if (countC < (col))
        {
            countC = 0;
            countR++;
        }
    }
}
void Image::setRow(int r)
{
    row = r;
}
void Image::setCol(int c)
{
    col = c;
}
int Image::getRow()
{
    return row;
}
int Image::getCol()
{
    return col;
}
void Image::save(string n)
{
    string line1 = "P5\n";
    line1 += "#" + n + "\n" + "#converted PNM file\n" + to_string(col) + " " + to_string(row) + "\n" + "255\n";

    ofstream object(n);
    object << line1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                object << (char(0));
            }
            else if (arr[i][j] == 255)
            {
                object << char(255);
            }
        }
    }
    object.close();

}
string Image::getFileName()
{
    return filename;
}
void Image::read(string name)
{
    int word = 0;
    ifstream object;
    filename = name;
    int count = 0;
    string data;
    object.open(name, ios::in);
    if (object.is_open())
    {
        while (!object.eof())
        {
            object >> data;
            if (count == 5)
                this->col = (stoi(data));
            if (count == 6)
                this->row = (stoi(data));
            if (count == 7)
                break;
            count++;
        }
    }
    else
        cout << "File not found" << endl;
    object.close();
    //creating array according to the size
    setSize(row, col);
    //reading data into the array
    char c;
    object.open(name, ios::in);
    for (int i = 0; i < 5; i++) //skipping first four lines
        getline(object, data);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            object.get(c);
            if ((int(c)) == 0 || (int(c)) == 32)
            {
                arr[i][j] = 0;
            }
            else
                arr[i][j] = 255;
        }
    }



    /* while (!object.eof())
     {
         object.get(c);
         insert(int(c));
     }*/
    object.close();

}
void Image::displayImage()
{
    int j;
    int i;
    for (i = 0; i < row; i++)
    {
        cout << i << " = ";
        for (j = 0; j < col; j++)
        {
            //cout << arr[i][j];
            if (arr[i][j] == 0)
            {
                cout << ".";
            }
            else
                cout << "*";
        }
        cout << " " << j << endl;
    }
}
int Image::getPixel(int r, int c)
{
    if ((r >= 0 && r < row) && (c >= 0 && c < col))
        return arr[r][c];
    return -1;
}
void Image::setPixel(int r, int c, int val)
{
    if ((r >= 0 && r < row) && (c >= 0 && c < col))
        arr[r][c] = val;
}
//Q1 a part
double Image::mean()
{
    long int sum = 0;
    double average = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            sum += arr[i][j];

    average = sum / double(row * col);

    cout << "Mean Pixels    = " << average << endl;
    return average;
}
//Q1 b part
void Image::countPixels()
{
    int white = 0;
    int black = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                black += 1;
            }
            else
                white += 1;

        }
    }
    cout << "Black Pixels    = " << black << endl;
    cout << "White Pixels    = " << white << endl;

}
//Q1 c part
void Image::avgBlack()
{
    int black = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                black += 1;
            }
        }
    }
    cout << "Avg Black Pixels    = " << (black / (row)) << endl;

}
//Q1 d part
void Image::convertNegative()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
                arr[i][j] = 255;
            else
                arr[i][j] = 0;
        }
    }
}
void Image::RLC_Encoded()
{
    List coordinate;
    int start = 0;
    int end = 0;
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                int k = j + 1;
                start = j;
                end = j;
                for (k; k < col; k++)
                {
                    if (arr[i][k] == 0)
                    {
                        end = k;
                    }
                    else
                        break;
                }
                coordinate.addAtLast(start);
                coordinate.addAtLast(end);

                j = k - 1;
            }
        }
        coordinate.addAtLast(-1);
    }
    fstream object("rlcEncoding.txt", ios::out);
    object << row << " " << col << " \n";
    Node* iterator;
    iterator = coordinate.getHead();
    while (iterator != nullptr)
    {
        object << iterator->get_data() << " ";
        if (iterator->get_data() == -1)
            object << "\n";
        iterator = iterator->get_next();
    }
    cout << "RLC Encoding done\n";
}
void Image::RLC_Decoded()
{
    List coordinate;
	fstream object("rlcEncoding.txt", ios::in);
	int count = 0, rows = 0, cols = 0;

	object >> rows;
	object >> cols;
	setSize(rows, cols);
	int i = 0;
	int temp;
	while (!object.eof())
	{
		object >> temp;
		coordinate.addAtLast(temp);
		i++;
	}
	object.close();
	Node* iterator = coordinate.getHead();
	while (iterator != nullptr)
	{
		if (iterator->get_data() == -1)
		{
			count++;
			iterator = iterator->get_next();
		}
		else
		{
			for (int j = iterator->get_data(); j <= iterator->get_next()->get_data(); j++)
			{
				arr[count][j]=0;
				
			}
			iterator = iterator->get_next()->get_next();
		}
		
		if (count == this->row)
			break;
	}
	save("RLC_decoded.pgm");
	cout << "Image Saved as RLC_decoded.PGM\n";
}
void Image::RLC_Black()
{
    avgBlack();
}
void Image::RLC_Negative()
{
    convertNegative();
}
void Image::hashRead(string name)
{
    int word = 0;
    ifstream object;
    filename = name;
    int count = 0;
    string data;
    //cout << filename << " ";
    object.open(name, ios::in);
    if (object.is_open())
    {
        while (!object.eof())
        {
            object >> data;
            if (count == 4)
                this->col = (stoi(data));
            if (count == 5)
                this->row = (stoi(data));
            if (count == 6)
                break;
            count++;
        }
    }
    else
        cout << "File not found" << endl;
    object.close();
    //creating array according to the size
    setSize(row, col);
    //reading data into the array
    char c;
    object.open(name, ios::in);
    for (int i = 0; i < 4; i++) //skipping first four lines
    {
        getline(object, data);
    }
    int num;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            object>>num;
            if (num == 0 || num == 32)
            {
                arr[i][j] = 0;
            }
            else
                arr[i][j] = 255;
        }
    }
    //displayImage();



    /* while (!object.eof())
     {
         object.get(c);
         insert(int(c));
     }*/
    object.close();

}
int** Image::getImage()
{
    return arr;
}