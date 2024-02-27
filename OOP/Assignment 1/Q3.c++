#include <iostream>
#include <string>
using namespace std;
class ChessPiece 
{
private:
  string name;
  char symbol;
  string color;
public: 
  // Default constructor
  ChessPiece()
  {
    name="pawn";
    symbol='P';
    color="white";
  }
  ChessPiece(string PieceName, char PieceSymbol, string PieceColor)
  {
    name=PieceName;
    symbol=PieceSymbol;
    color=PieceColor;
  }
  string getName()
  {
    return name;
  }
  char getSymbol()
  {
    return symbol;
  }
  string getColor()
  {
    return color;
  }
  void setName(string PieceName)
  {
    name=PieceName;
  }
  void setSymbol(char PieceSymbol)
  {
    symbol=PieceSymbol;
  }  
  void setColor(string PieceColor)
  {
    color=PieceColor;
  }
};
class ChessBoard
{
private:
  ChessPiece* board[8][8];
public:
  ChessBoard()
  {
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
        board[i][j]=nullptr;    
      }
    }
    board[0][0]=new ChessPiece("Rook",'R',"white");
    board[0][1]=new ChessPiece("Knight",'N',"white");
    board[0][2]=new ChessPiece("Bishop",'B',"white");
    board[0][3]=new ChessPiece("Queen",'Q',"white");
    board[0][4]=new ChessPiece("King",'K',"white");
    board[0][5]=new ChessPiece("Bishop",'B',"white");
    board[0][6]=new ChessPiece("Knight",'N',"white");
    board[0][7]=new ChessPiece("Rook",'R',"white");
    for(int i=0;i<8;i++)
    {
      board[1][i]=new ChessPiece("Pawn",'P',"white");   
    }
    board[7][0]=new ChessPiece("Rook",'R',"black");
    board[7][1]=new ChessPiece("Knight",'N',"black");
    board[7][2]=new ChessPiece("Bishop",'B',"black");
    board[7][3]=new ChessPiece("Queen",'Q',"black");
    board[7][4]=new ChessPiece("King",'K',"black");
    board[7][5]=new ChessPiece("Bishop",'B',"black");
    board[7][6]=new ChessPiece("Knight",'N',"black");
    board[7][7]=new ChessPiece("Rook",'R',"black");
    for(int i=0;i<8;i++)
    {
      board[6][i]=new ChessPiece("Pawn",'P',"black");   
    }
  }
  void display()
  {
    cout<<"  A B C D E F G H"<<endl;
    for(int i=0;i<8;i++)
    {
      cout<<8-i<<" ";
      for(int j=0;j<8;j++)
      {
        if(board[i][j]==nullptr)
        {
          cout<<"- ";
        }
        else
        {
          cout<<board[i][j]->getSymbol()<<" ";
        }
      }
      cout<<8-i<<endl;
    }
    cout<<"  A B C D E F G H"<<endl;
  }
  bool move(string from, string to)
  {
    int fromRow=8-from[1]+'0';
    int fromCol=from[0]-'A';
    int toRow=8-to[1]+'0';
    int toCol=to[0]-'A';
    if(fromRow<0 || fromRow>7 || fromCol<0 || fromCol>7 || toRow<0 || toRow>7 || toCol<0 || toCol>7)
    {
      cout<<"Wrong input"<<endl;
      return false;
    }
    if(board[fromRow][fromCol]==nullptr)
    {
      cout<<"No piece available at this positon"<<endl;
      return false;
    }
    if(board[toRow][toCol]!=nullptr && board[toRow][toCol]->getColor()==board[fromRow][fromCol]->getColor())
    {
      cout<<"Cannot move to a position occupied by your own piece"<<endl;
      return false;
    }
    if(board[fromRow][fromCol]->getName()=="Pawn") 
    {
      if(toCol==fromCol)
      {
        int ToRow=toRow-fromRow;
        if((board[fromRow][fromCol]->getColor()=="white" && ToRow==-1) || (board[fromRow][fromCol]->getColor()=="black" && ToRow==1))
        {
            if(board[toRow][toCol]==nullptr)
            {
                delete board[toRow][toCol];
                board[toRow][toCol]=board[fromRow][fromCol];
                board[fromRow][fromCol]=nullptr;
                return true;
            }
            else
            {
                cout<<"Position is occupied"<<endl;
                return false;
            }
        }
        else if((board[fromRow][fromCol]->getColor()== "white" && ToRow==-2 && fromRow==6) ||
                           (board[fromRow][fromCol]->getColor()=="black" && ToRow==2 && fromRow==1))
        {
            if(board[toRow][toCol]==nullptr && board[fromRow-ToRow/2][toCol]==nullptr)
            {
                delete board[toRow][toCol];
                board[toRow][toCol]=board[fromRow][fromCol];
                board[fromRow][fromCol]=nullptr;
                return true;
            }
            else
            {
                cout<<"Position is occupied"<<endl;
                return false;
            }
        }
        else
        {
            cout<<"Invalid move"<<endl;
            return false;
        }
      }
      else
      {
          cout<<"Invalid move"<<endl;
          return false;
      }
    }
    return false;
  }
};
int main()
{
  ChessBoard board;
  board.display();
  return 0;
}
