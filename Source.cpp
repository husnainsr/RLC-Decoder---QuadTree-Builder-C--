#include <iostream>
#include <fstream>
#include <ctime>
#include "Hashing.h"
#include "List.h""
#include "Image.h"
#include "queue.h"

using namespace std;

class QuadTree
{
    struct Node
    {
        char value;
        bool isLeaf;
        Node* TopLeft;
        Node* TopRight;
        Node* BottomLeft;
        Node* BottomRight;

        Node(char x, bool isLeaf, Node* TL, Node* TR, Node* BL, Node* BR)
        {
            this->value = x;
            this->TopLeft = TL;
            this->TopRight = TR;
            this->BottomLeft = BL;
            this->BottomRight = BR;
        }
    };
    Node* root;

    void postorder_display(Node*);
    void preorder_display(Node*);
    Node* construct(int **Matrix, int row, int col, int width)
    {
        bool full_true = true, full_false = true;

        for (int i = row; i < row + width; i++)
        {
            for (int j = col; j < col + width; j++)
            {
                if (Matrix[i][j] == 0)
                    full_false = false;
                else
                    full_true = false;

                if (!full_true && !full_false)
                    break;
            }
        }

        if (full_true)
            return new Node('b', true, nullptr, nullptr, nullptr, nullptr);

        if (full_false)
            return new Node('w', false, nullptr, nullptr, nullptr, nullptr);

        width >>= 1;

        Node* TopLeft, * TopRight, * BottomLeft, * BottomRight;

        TopLeft = construct(Matrix, row, col, width);
        TopRight = construct(Matrix, row, col + width, width);
        BottomLeft = construct(Matrix, row + width, col, width);
        BottomRight = construct(Matrix, row + width, col + width, width);

        return new Node('g', false, TopLeft, TopRight, BottomLeft, BottomRight);
    }

public:
    QuadTree();

    void Construct_Tree(int **Matrix, int size)
    {
        root = construct(Matrix, 0, 0, size);
    }
    void preorder()
    {
        preorder_display(root);
    }
    void postorder()
    {
        postorder_display(root);
    }
};

QuadTree::QuadTree()
{
    root = NULL;
}

void QuadTree::postorder_display(Node* root)
{
    if (root)
    {
        postorder_display(root->TopLeft);
        postorder_display(root->TopRight);
        postorder_display(root->BottomLeft);
        postorder_display(root->BottomRight);
        cout << root->value << " ";
    }
}

void QuadTree::preorder_display(Node* root)
{
    if (root)
    {
        preorder_display(root->TopLeft);
        preorder_display(root->TopRight);
        cout << root->value << " ";
        preorder_display(root->BottomLeft);
        preorder_display(root->BottomRight);
    }
}

string operationsTime()
{
	struct tm t;
	time_t curr_time;
	curr_time = time(NULL);
	localtime_s(&t, &curr_time);
	string timee = (to_string(t.tm_hour) + ':' + to_string(t.tm_min) + ':' + to_string(t.tm_sec));
	return timee;
}

string fileNameTime()
{
	struct tm t;
	time_t curr_time;
	curr_time = time(NULL);
	localtime_s(&t, &curr_time);
	string timee = ("log_" + to_string(t.tm_year + 1990) + to_string(t.tm_mon + 1) + to_string(t.tm_mday) + to_string(t.tm_hour) + to_string(t.tm_min) + to_string(t.tm_sec) + ".txt");
	return timee;
}
void display_menu()
{
    cout << "\n1- To Run RLC Question";
    cout << "\n2- To Run Hashing Question";
    cout << "\n3- To Run Quad Tree Question";
    cout << "\n4- To Terminate the Question";
}
void display_q5Menu()
{
    cout << "\n1- To Convert into quad Tree";
    cout << "\n2- To Print Post Order ";
    cout << "\n3- To Print Pre Order ";
    cout << "\n4- To Terminate the Question";
}
void display_q1Menu()
{
    cout << "\n1- Convert the Image into RLC Encoding";
    cout << "\n2- Convert the Image into RLC Decoding";
    cout << "\n3- To display the Avg Black Pixels in Row";
    cout << "\n4- To convert it into Negative Image";
    cout << "\n5- To Terminate this";
    cout << "\nEnter Choice: ";
}
int main()
{
	string logData = "";
	string name = "";
    string fileTesting = "";
    Image quad; //for quad tree
    quad.read("camel-6.pgm");
    QuadTree qt;
    int** matrix = quad.getImage();
    int size = quad.getRow();

	Image temp;
    int option = 0;
    Image imageTest;
	Hashing table(23);
	//temp.hashRead(name);
    int choice = 0;
    bool invalidChoice = false;
    int choice2 = 0;

    //reading all images for hashing
  
        /*for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 10; k++)
            {

                name = "image" + to_string(0) + to_string(j) + to_string(k) + ".pgm";
                temp.hashRead(name);
                table.insert(temp);
            }
        }*/
    
    cout << "Data Base is being Created Kindly wait\n";
    logData += "\n----Q2 Data Base is building " + operationsTime();
    fstream ofile(fileNameTime(), ios::out);
    while (choice != 4)
    {
        system("CLS");
        display_menu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            system("CLS");
            logData += "\nQ4 Run RLC Question " + operationsTime();
            logData += "\n-----------------------------------------------------------------------------------------";
            while (choice2 != 5)
            {
                display_q1Menu();
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    system("CLS");
                    logData += "\n----Q4 RLC Encoding is Called. " + operationsTime();
                    temp.RLC_Encoded();
                    cout << "\nImage is Successfully Converted into rlcEncoding.txt Format ";
                    break;
                case 2:
                    logData += "\n----Q4 RLC Decoding is Called. " + operationsTime();
                    system("CLS");
                    temp.RLC_Decoded();
                    break;
                case 3:
                    logData += "\n----Q4 Avg Black Pixels in Row Function is Called. " + operationsTime();
                    system("CLS");
                    temp.RLC_Black();
                    break;
                case 4:
                    logData += "\n----Q4 Image is Converted into Negative. " + operationsTime();
                    system("CLS");
                    temp.RLC_Negative();
                    temp.save("RLCnegative.pgm");
                    temp.convertNegative();
                    cout << "\nImage is Successfully Converted and saved into RLCnegative.pgm Format ";
                    break;
                case 5:
                    logData += "\n----Q4 Question 1 is terminated. " + operationsTime();
                    break;
                default:
                    logData += "\n----Q4 Worng input. " + operationsTime();
                    cout << "\nWrong Input. ";
                    system("Pause");
                    system("CLS");
                    break;
                }
            }
            break;
        case 2:
            system("CLS");
            logData += "\n-----------------------------------------------------------------------------------------";
            logData += "\nQuestion 6 Hashing is Selected " + operationsTime();
            do {
                cout << "\nEnter testFile Name: ";
                cin >> fileTesting;
                //fileTesting = "image000.pgm";
                imageTest.hashRead(fileTesting);
                table.display();
                if(table.search(imageTest))
                    logData += "\n----Q6 Image Sucessfully found in data base. " + operationsTime();
                else
                    logData += "\n----Q6 Image is not in data base. " + operationsTime();

                cout << "\Do you want to search another file? Enter 1 for Yes, 0 for No: ";
                cin >> option;
            } while (option != 0);
        
            logData += "\n----Q6 Question  is terminated. " + operationsTime();
            system("Pause");
            break;
        case 3:
            system("CLS");
            logData += "\n-----------------------------------------------------------------------------------------";
            logData += "\nQuestion 5 Quad Tree is Selected " + operationsTime();
            do {
                display_q5Menu();
                cout << "\nEnter Choice: ";
                cin >> option;
                //fileTesting = "image000.pgm";
                if (option == 1)
                {
                    qt.Construct_Tree(matrix, size);
                    logData += "\n----Q5 Quad Tree is sucessfully constructed. " + operationsTime();
                }
                else if (option == 2)
                {
                    qt.postorder();
                    logData += "\n----Q5 Post order is printed. " + operationsTime();
                }
                else if (option == 3)
                {
                    qt.preorder();
                    logData += "\n----Q5 Pre order is printed. " + operationsTime();
                }
            } while (option != 4);
            logData += "\n----Q5 Question  is terminated. " + operationsTime();
            break;
        case 4:
            cout << "You have successfully exited the program\n";
            break;
        default:
            cout << "Wrong Input\n";
            cout << "Enter to go back\n";
            cin.ignore();
        }
    }
    ofile << logData;
    ofile.close();


	
	

	

	return 0;
}