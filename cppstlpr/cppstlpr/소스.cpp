#define CRT_SECURE_NO_WARNING
#include <iostream>
#include <vector>
#include <conio.h>//iostream�� �ٸ��� Ű���忡 �Է¹��� ���� ���ۿ��� �����ߴ� return
#include <cstdlib>
#include <ctime>
using namespace std;
#define TTable_X 20
#define TTable_y 38


//ȭ��ǥ�� 2byte�� �ƽ�Ű�ڵ�Ȯ��
#define LEFT 75//��
#define RIGHT 77//��
#define UP 72//��
#define DOWN 80//��

class Mainmenu {
public: 
	Mainmenu() 
	{
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "############  #########  ############  @@@@@@@@   @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      #       #                #       @      @   @   @          \n";
        cout << "\t\t"; cout << "      #       #                #       @      @   @   @          \n";
        cout << "\t\t"; cout << "      #       #########        #       @     @    @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      #       #                #       @ @ @      @             @\n";
        cout << "\t\t"; cout << "      #       #                #       @    @                   @\n";
        cout << "\t\t"; cout << "      #       #########        #       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
        cout << "\t\t"; cout << "                ������ �����Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n";
        cout << "\t\t"; cout << "                   press c if you want quitgame\n";
        getchar();//�ƹ�Ű �Է� ��ٸ�
        system("cls");//�ܼ� â clear
	}

};
/*1�� ��*/
const int block1[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}
        },

};
/*2�� ��*/
const int block2[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },

};
/*3�� ��*/
const int block3[4][4][4] = {
        {
                        {0, 2, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 2, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 2, 0},
                        {2, 2, 2, 0},
                        {0, 0, 0, 0}

        },

};
/*4�� ��*/
const int block4[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}

        },

};
/*5�� ��*/
const int block5[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 2},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },

};
class Block
{
protected:
    int shape[4][4][4];//shape[rotate][y][x]
    int x;//x��ǥ
    int y;//y��ǥ
    int rotationCount; //shape[0][y][x], shape[1][y][x]
public:
    int getShape(int rotationCount, int y, int x)   {
        return shape[rotationCount][y][x];
    }
    int getX()   {
        return x;
    }
    int getY()   {
        return y;
    }
    int getRotationCount()   {
        return rotationCount;
    }
    void down()    {
        y++;
    }
    void left()  {
        x++;
    }
    void right()  {
        x--;
    }
    void rotate() {
        rotationCount = (rotationCount + 1) % 4;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y)  {
        this->y = y;
    }
    void setRotationCount(int r) {
        this->rotationCount = r;
    }
    void setShape(int r, int y, int x, int value)
    {
        this->shape[r][y][x] = value;
    }
    void up() {
        y--;//harddrop ó����
    }
};
//1�� �� Ŭ����
class Block1 : public Block {
public:
    Block1() {
        x = TTable_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block1[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*2�� �� Ŭ����*/
class Block2 : public Block {
public:
    Block2() {
        x = TTable_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block2[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*3�� �� Ŭ����*/
class Block3 : public Block {
public:
    Block3() {
        x = TTable_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block3[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*4�� �� Ŭ����*/
class Block4 : public Block {
public:
    Block4() {
        x = TTable_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block4[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*5�� �� Ŭ����*/
class Block5 : public Block {
public:
    Block5() {
        x = TTable_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block5[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
class GameTable {
    int x;
    int y;
    Block* blockObject;
    vector<vector <int>> table;
public:
    GameTable(int x, int y) {
        this->x = x;
        this->y = y;
        blockObject = nullptr;
        for (int i = 0; i < y; i++) {
            vector<int> temp;
            for (int j = 0; j < x; j++)
            {
                temp.push_back(0);
            }
            table.push_back(temp);
        }
        for (int i = 0; i < x; i++)
        {
            table[0][i] = 1;
            table[y - 1][i] = 1;
        }
        for (int i = 1; i < y-1; i++)
        {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
    }
    void DrawGameTable(){
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (table[i][j] == 1)
                    cout << "��";
                else cout << "  ";
            }
            cout << "\n";
        }

    }
    void createBlock() {
        srand((unsigned int)time(NULL));
        int select = rand() % 5 + 1;
        if (select == 1) 
            blockObject = new Block1;
        else if(select==2)
            blockObject = new Block2;
        else if(select==3)
            blockObject = new Block3;
        else if(select==4)
            blockObject = new Block4;
        else if(select==5)
            blockObject = new Block5;
        for (int i = 0; i < 4 ;i++)
        {
            for (int j = 0; j< 4; j++) {
                int Y = j + blockObject->getY();
                int X = x + blockObject->getX();
                table[Y][X] = blockObject->getShape(blockObject->getRotationCount(),i,j); //block on game table class
            }
        }
    }
};
void gameStart()
{
    char control_char;
    while (control_char != 'c')// c �� �Է¹��� ������ ��������
    {
        
    }

}
int main()
{
    int menunum;
    system("mode con cols=100 lines=40 | title tettris game");
    GameTable gt(TTable_X, TTable_y);
    Mainmenu();
    gt.DrawGameTable();
    cin >> menunum;
    return 0;
}