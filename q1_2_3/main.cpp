//Ahmet Berker KOÇ 2232320
#include <iostream> //  Standard Input / Output Streams Library.
#include <fstream>
using namespace std;  // instead of using std::

//Queation 1 implementation of Sokoban class
class Sokoban
{
	private:					//private part
		char puzzle[6][8];		//2D char array for puzzle
		int row;				// for finding player row location
		int column;				//for finding player locatin location
	public:
		Sokoban();					//default constructor called with no arguments
		Sokoban(char puz[6][8]);		//constructor with argument 2D puzzle array
		Sokoban(string text);		//constructor for read from text
		Sokoban(const Sokoban &obj);	//copy constructor
		Sokoban &operator=(const Sokoban &rhs);	//coppy assignment operator
		bool move_up();				//move_up method is a bool function. It returns true if operation is valid and return false otherwise. Also change player location
		bool move_down();			//move_down method is a bool function. It returns true if operation is valid and return false otherwise.Also change player location
		bool move_left();			//move_left method is a bool function. It returns true if operation is valid and return false otherwise.Also change player location
		bool move_right();			//move_right method is a bool function. It returns true if operation is valid and return false otherwise.Also change player location
		bool is_solved();			//is_solved method checks whether puzzle is solved or not
		void print_puzzle();		//print_puzzle displays the puzzle current state

};
// default constructor is defined
Sokoban::Sokoban(){
}
// constructor is defined. 2D array argumant and puzzle array equalize element by element
Sokoban::Sokoban(char puz[6][8]){
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			puzzle[i][j]=puz[i][j];
			if(puzzle[i][j]=='@' ||puzzle[i][j]=='+'){		//to find player location
				row=i;				//row of player
				column=j;		//column of player
			}
		}
	}
}
//constructor is defined for read from text
Sokoban::Sokoban(string text){

string path = text;
char dummy;/* newline character will be read in dummy */
ifstream file;/* input file stream */

file.open(path);
for(int i=0; i<6; ++i){
    for(int j=0; j<8; ++j){
        file >> noskipws >> puzzle[i][j]; /* read a character like cin noskipws is required for reading whitespaces */
    }
    file >> noskipws >> dummy;/* read the newline character at the end of each line */
}
file.close();

for(int i=0;i<6;i++){	//find player location
    for(int j=0;j<8;j++){
        if (puzzle[i][j]=='@' || puzzle[i][j]=='+'){
            row=i;
            column=j;
            }
        }
    }
}
//copy constructor is defined. A copy constructor is a member function which initializes an object using another object of the same class.
Sokoban::Sokoban(const Sokoban &obj){
	int i,j;
	for(i=0;i<6;i++){			//equalize element by element
		for(j=0;j<8;j++){
			puzzle[i][j]=obj.puzzle[i][j];

		}
	}
	row=obj.row;			//assign location information
	column=obj.column;  		//	assign  location information
}
//copy assignment operator is defined assignment operator is called when an already initialized object is assigned a new value from another existing object.
Sokoban& Sokoban::operator=(const Sokoban &rhs){
	int i,j;

	for(i=0;i<6;i++){		//equalize element by element
		for(j=0;j<8;j++){
			puzzle[i][j]=(rhs.puzzle)[i][j];
		}
	}

	row=rhs.row;//	assign  location information
	column=rhs.column;//	assign  location information
	return *this;//	return this
}

bool Sokoban::move_down(){ //move down method is defined
	char temp;
	if(puzzle[row][column]=='@')		//first determine player is @ or + because after changing location. We should find whether old location is ' ' or '.'
		temp='@';
	else
		temp='+';
	if(puzzle[row+1][column]=='#')		//wall is unmovable return false
		return false;
	if(puzzle[row+1][column]=='.'){			// if next location is '.', it became '+' after move
		puzzle[row+1][column]='+';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		row=row+1;							//change row return true
		return true;
	}
	if(puzzle[row+1][column]==' '){		// if next location is ' ', it became '@' after move
		puzzle[row+1][column]='@';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		row=row+1;	//change row return true
		return true;
	}
	if(puzzle[row+1][column]=='$'){
		if (puzzle[row+2][column]=='#' || puzzle[row+2][column]=='$' || puzzle[row+2][column]=='*') //check whether '$' can move
			return false;		//if it cannot move return false
		else if(puzzle[row+2][column]==' '){		//if it can move cange row, row+1 and row+2 accordingly.
			puzzle[row+2][column]='$';
			puzzle[row+1][column]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row+1;	//change row return true
		return true;
		}
		else if(puzzle[row+2][column]=='.'){//if it can move cange row, row+1 and row+2 accordingly.
			puzzle[row+2][column]='*';
			puzzle[row+1][column]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row+1;//change row return true
		return true;
		}
	}
	if(puzzle[row+1][column]=='*'){			//check whether '*' can move
		if (puzzle[row+2][column]=='#' || puzzle[row+2][column]=='$' || puzzle[row+2][column]=='*')
			return false;//if it cannot move return false
		else if(puzzle[row+2][column]==' '){	//if it can move cange row, row+1 and row+2 accordingly.
			puzzle[row+2][column]='$';
			puzzle[row+1][column]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row+1;//change row return true
		return true;
		}
		else if(puzzle[row+2][column]=='.'){	//if it can move cange row, row+1 and row+2 accordingly.
			puzzle[row+2][column]='*';
			puzzle[row+1][column]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row+1;//change row return true
		return true;
		}
	}

}
// same operations is done for move up. Sama conditions are checked
bool Sokoban::move_up(){//move up method is defined
		char temp;
	if(puzzle[row][column]=='@')
		temp='@';
	else
		temp='+';
	if(puzzle[row-1][column]=='#')
		return false;
	if(puzzle[row-1][column]=='.'){
		puzzle[row-1][column]='+';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		row=row-1;
		return true;
	}
	if(puzzle[row-1][column]==' '){
		puzzle[row-1][column]='@';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		row=row-1;
		return true;
	}
	if(puzzle[row-1][column]=='$'){
		if (puzzle[row-2][column]=='#' || puzzle[row-2][column]=='$' || puzzle[row-2][column]=='*')
			return false;
		else if(puzzle[row-2][column]==' '){
			puzzle[row-2][column]='$';
			puzzle[row-1][column]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row-1;
		return true;
		}
		else if(puzzle[row-2][column]=='.'){
			puzzle[row-2][column]='*';
			puzzle[row-1][column]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row-1;
		return true;
		}
	}
	if(puzzle[row-1][column]=='*'){
		if (puzzle[row-2][column]=='#' || puzzle[row-2][column]=='$' || puzzle[row-2][column]=='*')
			return false;
		else if(puzzle[row-2][column]==' '){
			puzzle[row-2][column]='$';
			puzzle[row-1][column]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row-1;
		return true;
		}
		else if(puzzle[row-2][column]=='.'){
			puzzle[row-2][column]='*';
			puzzle[row-1][column]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row-1;
		return true;
		}
	}
}
// same operations is done for move right. Sama conditions are checked
bool Sokoban::move_right(){//move right method is defined
		char temp;
	if(puzzle[row][column]=='@')
		temp='@';
	else
		temp='+';
	if(puzzle[row][column+1]=='#')
		return false;
	if(puzzle[row][column+1]=='.'){
		puzzle[row][column+1]='+';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		column=column+1;
		return true;
	}
	if(puzzle[row][column+1]==' '){
		puzzle[row][column+1]='@';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		column=column+1;
		return true;
	}
	if(puzzle[row][column+1]=='$'){
		if (puzzle[row][column+2]=='#' || puzzle[row][column+2]=='$' || puzzle[row][column+2]=='*')
			return false;
		else if(puzzle[row][column+2]==' '){
			puzzle[row][column+2]='$';
			puzzle[row][column+1]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		column=column+1;
		return true;
		}
		else if(puzzle[row][column+2]=='.'){
			puzzle[row][column+2]='*';
			puzzle[row][column+1]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		column=column+1;
		return true;
		}
	}
	if(puzzle[row][column+1]=='*'){
		if (puzzle[row][column+2]=='#' || puzzle[row][column+2]=='$' || puzzle[row][column+2]=='*')
			return false;
		else if(puzzle[row][column+2]==' '){
			puzzle[row][column+2]='$';
			puzzle[row][column+1]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		column=column+1;
		return true;
		}
		else if(puzzle[row][column+2]=='.'){
			puzzle[row][column+2]='*';
			puzzle[row][column+1]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		column=column+1;
		return true;
		}
	}
}
// same operations is done for move left. Sama conditions are checked
bool Sokoban::move_left(){//move left method is defined
	char temp;
	if(puzzle[row][column]=='@')
		temp='@';
	else
		temp='+';
	if(puzzle[row][column-1]=='#')
		return false;
	if(puzzle[row][column-1]=='.'){
		puzzle[row][column-1]='+';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		column=column-1;
		return true;
	}
	if(puzzle[row][column-1]==' '){
		puzzle[row][column-1]='@';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		column=column-1;
		return true;
	}
	if(puzzle[row][column-1]=='$'){
		if (puzzle[row][column-2]=='#' || puzzle[row][column-2]=='$' || puzzle[row][column-2]=='*')
			return false;
		else if(puzzle[row][column-2]==' '){
			puzzle[row][column-2]='$';
			puzzle[row][column-1]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		column=column-1;
		return true;
		}
		else if(puzzle[row][column-2]=='.'){
			puzzle[row][column-2]='*';
			puzzle[row][column-1]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		column=column-1;
		return true;
		}
	}
	if(puzzle[row][column-1]=='*'){
		if (puzzle[row][column-2]=='#' || puzzle[row][column-2]=='$' || puzzle[row][column-2]=='*')
			return false;
		else if(puzzle[row][column-2]==' '){
			puzzle[row][column-2]='$';
			puzzle[row][column-1]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		column=column-1;
		return true;
		}
		else if(puzzle[row][column-2]=='.'){
			puzzle[row][column-2]='*';
			puzzle[row][column-1]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		column=column-1;
		return true;
		}
	}

}

bool Sokoban::is_solved(){//is solved method is defined. Check there is any '$'. If there is no '$' return true
	int i,j,a=1;
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			if(puzzle[i][j]=='$')
				a=0;
		}
	}
	if(a==1)
		return true;
	else
		return false;
}

void Sokoban::print_puzzle(){//print puzzle method is defined
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			cout<<puzzle[i][j];
		}
		cout<<endl;
	}
}
//Question2 stackqueue class implementation
template <class T>
class StackQueue
{
	private:
		T list[500];	//size is determined by 500
		int front;		//front,rear,count is private. private is behave like top in stack and rear keeps the first filled element in the array
		int rear;
		int count;
	public:
		StackQueue(void);	//constructor
		void Push_front(const T& item);		//push front method. Push the item to the list
		T Pop_rear(void);	//pop rear method, return item and pop from rear of thelist
		T Pop_front(void);	//pop front method, return item and pop from from of the list
		int counter(void)const;	// count the element in the list
};

template<class T>
StackQueue<T>::StackQueue(void){	//constructor definition

	front=-1;			//start from -1 like top of stack
	rear=0;
	count=0;
}
template<class T>
void StackQueue<T>::Push_front(const T& item){
	if(count<=500){ 		//check exceeding the list size

	count++;				//increment count
	front=(front+1)%500;	//front is increase
	list[front]=item;	//item is put into list
	}
	else 							//exceed limit error
		cerr<< "Error FULL"<<endl;
}

template<class T>
T StackQueue<T>::Pop_front(void){//pop front method is defined
	if(count>0){		//error empty check
	T temp;
	count--;				//count decrement
	temp=list[front];		//take item
	front=front-1;			//one element is removed so front--. the list gets shorter from the front
	return temp;		//return item
	}

}

template<class T>
T StackQueue<T>::Pop_rear(void){//pop rear method is defined
	if(count>0){//error empty check
	T temp;
	count--;			//count decrement
	temp=list[rear];	//take item
	rear++;				//one element is removed so rear++, the list gets shorter from the rear
	return temp;		//	return item
	}

}
template<class T>
int StackQueue<T>::counter(void)const{		//counter method is defined
	return count;		//return number of element in the list
}

int main(){
	//char x[6][8]={{'#','#','#','#','#','#',' ',' '},  // I checked by writing my own array
    //              {'#','.',' ',' ','.','#','#','#'},
    //               {'#','@','$','#','$',' ',' ','#'},
    //              {'#','$','.',' ','.','$',' ','#'},
    //             {'#',' ',' ',' ',' ','$','.','#'},
    //            {'#','#','#','#','#','#','#','#'}};

	char command;			//to take input
	Sokoban berker("Sample_puzzle.txt"); //read from file
	//Sokoban	berker(x);		//Sokaban object is created
	StackQueue<Sokoban> sq;	//Stackqueue object is created
	sq.Push_front(berker);			//push initla state of the puzzle
	berker.print_puzzle();	//show initila state of the puzzle
	while(1){			//infinete loop, if r is taken then break the loop
		cin>>command;		//take input
		if(command=='w'){		//check what is input
			if(berker.move_up()){//if move is valid,move operation is done and enter if

				sq.Push_front(berker);	//store new berker object which is moved up
				berker.print_puzzle();	//display new puzzle
			}
			else
				cout<<"TRY AGAIN INVALID COMMAND"<<endl;//if invalid move, show warning
		}
		else if(command=='s'){//check what is input
			if(berker.move_down()){//if move is valid,move operation is done and enter if

			sq.Push_front(berker);	//store new berker object which is moved down
			berker.print_puzzle();//display new puzzle
			}
			else
				cout<<"TRY AGAIN INVALID COMMAND"<<endl;//if invalid move, show warning
		}
		else if(command=='a'){//check what is input
			if(berker.move_left()){//if move is valid,move operation is done and enter if

				sq.Push_front(berker);//store new berker object which is moved left
				berker.print_puzzle();//display new puzzle
			}
			else
				cout<<"TRY AGAIN INVALID COMMAND"<<endl;//if invalid move, show warning
		}
		else if(command=='d'){//check what is input
			if(berker.move_right()){	//if move is valid,move operation is done and enter if
				sq.Push_front(berker);//store new berker object which is moved right
				berker.print_puzzle();//display new puzzle
			}
			else
				cout<<"TRY AGAIN INVALID COMMAND"<<endl;//if invalid move, show warning
		}
		else if(command=='z'){//check what is input
			sq.Pop_front();			//pop last move
			berker=sq.Pop_front();	//to  show the previous step pop and push
			sq.Push_front(berker);
			berker.print_puzzle();//display previous puzzle
		}
		else if(command=='r'){//check what is input

			while(sq.counter()>0){	//until counter is equal to zero i.e. reaching empty list

				berker=sq.Pop_rear();	//pop from rear i.e. from first puzzle to last one
				berker.print_puzzle(); //display all valid movement for puzzle
			}
			break; //finish the program
		}
		if (berker.is_solved()==true)
			cout<<"CONGRATULATIONS YOU WON !!!"<<endl;	//display message if puzzle is solved
		if(sq.counter()>500){
			cout<<"LIMIT OF MOVEMENT(500),GAME OVER!!!";//display message if reach limit of list[500]
			break;
		}



	}


	return 0;
}
