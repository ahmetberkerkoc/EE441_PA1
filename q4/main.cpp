//Ahmet Berker KOÇ 2232320
#include <iostream> //  Standard Input / Output Streams Library.
#include <fstream>
using namespace std;  // instead of using std::
//Sokaban part and its comment is same as first file therefore I continue my comment from node class.
class Sokoban
{
	private:
		char puzzle[6][8];
		int row;
		int column;
	public:
		Sokoban();
		Sokoban(char puz[6][8]);
		Sokoban(string text);		//constructor for read from text
		Sokoban(const Sokoban &obj);
		Sokoban &operator=(const Sokoban &rhs);
		bool move_up();
		bool move_down();
		bool move_left();
		bool move_right();
		bool is_solved();
		void print_puzzle();

};
Sokoban::Sokoban(){
}
Sokoban::Sokoban(char puz[6][8]){
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			puzzle[i][j]=puz[i][j];
			if(puzzle[i][j]=='@' ||puzzle[i][j]=='+'){
				row=i;
				column=j;
			}
		}
	}
}
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

Sokoban::Sokoban(const Sokoban &obj){
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			puzzle[i][j]=obj.puzzle[i][j];

		}
	}
	row=obj.row;
	column=obj.column;
}
Sokoban& Sokoban::operator=(const Sokoban &rhs){
	int i,j;

	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			puzzle[i][j]=(rhs.puzzle)[i][j];
		}
	}

	row=rhs.row;
	column=rhs.column;
}

bool Sokoban::move_down(){
	char temp;
	if(puzzle[row][column]=='@')
		temp='@';
	else
		temp='+';
	if(puzzle[row+1][column]=='#')
		return false;
	if(puzzle[row+1][column]=='.'){
		puzzle[row+1][column]='+';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		row=row+1;
		return true;
	}
	if(puzzle[row+1][column]==' '){
		puzzle[row+1][column]='@';
		if(temp=='@')
			puzzle[row][column]=' ';
		else
			puzzle[row][column]='.';
		row=row+1;
		return true;
	}
	if(puzzle[row+1][column]=='$'){
		if (puzzle[row+2][column]=='#' || puzzle[row+2][column]=='$' || puzzle[row+2][column]=='*')
			return false;
		else if(puzzle[row+2][column]==' '){
			puzzle[row+2][column]='$';
			puzzle[row+1][column]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row+1;
		return true;
		}
		else if(puzzle[row+2][column]=='.'){
			puzzle[row+2][column]='*';
			puzzle[row+1][column]='@';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row+1;
		return true;
		}
	}
	if(puzzle[row+1][column]=='*'){
		if (puzzle[row+2][column]=='#' || puzzle[row+2][column]=='$' || puzzle[row+2][column]=='*')
			return false;
		else if(puzzle[row+2][column]==' '){
			puzzle[row+2][column]='$';
			puzzle[row+1][column]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row+1;
		return true;
		}
		else if(puzzle[row+2][column]=='.'){
			puzzle[row+2][column]='*';
			puzzle[row+1][column]='+';
			if(temp=='@')
				puzzle[row][column]=' ';
			else
				puzzle[row][column]='.';
		row=row+1;
		return true;
		}
	}

}

bool Sokoban::move_up(){
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

bool Sokoban::move_right(){
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

bool Sokoban::move_left(){
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

bool Sokoban::is_solved(){
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

void Sokoban::print_puzzle(){
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			cout<<puzzle[i][j];
		}
		cout<<endl;
	}
}

//implementatio of Node class

template <class T>//to reach with easily(no need to use method) next prev and data is in public
class Node{

	public:
		T data;
		Node<T> *next;
		Node<T> *prev;

		Node(const T&item, Node<T>* prtNext=NULL,Node<T>* prtPrev=NULL);
};
//constructor of node
template<class T>
Node<T>::Node(const T&item,Node<T>*ptrNext,Node<T>*ptrPrev):data(item),next(ptrNext),prev(ptrPrev){
}

//linkedlist class implementation
template<class T>
class LinkedList{		//rear and front is private node pointer
	private:
		Node<T> *rear;
		Node<T>	*front;
	public:
		LinkedList();		//constructor
		void insertAttheEnd(const T &data);	//insert from the front
		T removeRear();	//pop from the rear
		T removeFront();		//pop from the front
};
//constructor of linkedlist
template<class T>
LinkedList<T>::LinkedList(){
	rear=NULL;
	front=NULL;
}
//insert from front insertAttheEnd method is defined
template<class T>
void LinkedList<T>::insertAttheEnd(const T &data){
Node<T> *current=rear,*y,*x=NULL;
y=new Node<T>(data,x,x); //allocation for adding item with data, NULL next and NULL prev
if(rear==NULL){		//check empty list
	LinkedList();		//to create
	rear=y;			//for first rear and front is equal to new item
	front=y;
}
else if(current->next==NULL){	//check list with one element. It can be redundant but I want to check it
	current->next=y;
	y->prev=current;	//add new element and prev next connections is done
	y->next=NULL;
	front=y;
}
else{			//add new element and prev next connections is done
	front->next=y;
	y->next=NULL;
	y->prev=front;
	front=y;
}

}
template<class T>
T LinkedList<T>::removeFront(){
	Node<T> *current=front,*temp;
	//I didn't check empty linkedlist because I control it with counter when calling removeFront
	if(front==rear){		//if there is one element
		temp=front;	//remove operation is done both rear and front are null. keep last element in the temp
		rear=NULL;
		front=NULL;
		return temp->data;	//return temp->data
	}
	else{		//if there is more than one element
		front=current->prev;//prev and next connections are done. keep last element in the temp
		current->prev->next=NULL;	//new front next is NULL
		current->prev=NULL;	// current is remove from list but to safety prev become null
		return current->data;//return temp->data
	}
}
template<class T>
T LinkedList<T>::removeRear(){
	Node<T> *current=rear,*temp;
//I didn't check empty linkedlist because I control it with counter when calling removeRear
	if(front==rear){//if there is one element
		temp=rear;
		rear=NULL;
		front=NULL;
		return temp->data;
	}
	else{ //if there is more than one element
		rear=current->next;//prev and next connection is done. keep last element in the temp
		current->next->prev=NULL;	//new rear prev is NULL
		current->next=NULL;// current is remove from list but to safety next become null
		return current->data;
	}
}
//there is linkedlist insted of array(first file) in private
template <class T>
class StackQueue
{
	private:
		LinkedList<T> list;	//linkedlist enable limitless element

		int count;
	public:
		StackQueue(void);
		void Push_front(const T& item);
		T Pop_rear(void);
		T Pop_front(void);
		int counter(void)const;

};
//constructor
template<class T>
StackQueue<T>::StackQueue(void){

	count=0;
}
//push_fron is defined according to linkedlist
template<class T>
void StackQueue<T>::Push_front(const T& item){

	count++; //increase count
	list.insertAttheEnd(item); //add to list


}
//pop_fron is defined according to linkedlist
template<class T>
T StackQueue<T>::Pop_front(void){
	if(count>0){ //enable to prevent operation on NULL. Thanks to this I didn't check NULL in linkedlist method decleration
	T temp;
	count--;	//decrease counter
	temp=list.removeFront();	//remove from front of the list
	return temp;
}

}
//pop_rear is defined according to linkedlist
template<class T>
T StackQueue<T>::Pop_rear(void){
	if(count>0){//enable to prevent operation on NULL. Thanks to this I didn't check NULL in linkedlist method decleration
	T temp;
	count--;//decrease counter
	temp=list.removeRear();//remove from rear of the list
	return temp;
	}

}
//counter is defined
template<class T>
int StackQueue<T>::counter(void)const{
	return count;
}

//main and its comments are same as first file
int main(){
	//char x[6][8]={{'#','#','#','#','#','#',' ',' '}, // I checked by writing my own array
    //               {'#','.',' ',' ','.','#','#','#'},
    //               {'#','@','$','#','$',' ',' ','#'},
    //               {'#','$','.',' ','.','$',' ','#'},
    //               {'#',' ',' ',' ',' ','$','.','#'},
    //               {'#','#','#','#','#','#','#','#'}};
	char command;
	Sokoban berker("Sample_puzzle.txt"); //read from file
	//Sokoban	berker(x);
	StackQueue<Sokoban> sq;
	sq.Push_front(berker);
	berker.print_puzzle();
	while(1){
		cin>>command;
		if(command=='w'){
			if(berker.move_up()){

				sq.Push_front(berker);
				berker.print_puzzle();
			}
			else
				cout<<"TRY AGAIN INVALID COMMAND"<<endl;
		}
		else if(command=='s'){
			if(berker.move_down()){

			sq.Push_front(berker);
			berker.print_puzzle();
			}
			else
				cout<<"TRY AGAIN INVALID COMMAND"<<endl;
		}
		else if(command=='a'){
			if(berker.move_left()){

				sq.Push_front(berker);
				berker.print_puzzle();
			}
			else
				cout<<"TRY AGAIN INVALID COMMAND"<<endl;
		}
		else if(command=='d'){
			if(berker.move_right()){
				sq.Push_front(berker);
				berker.print_puzzle();
			}
			else
				cout<<"TRY AGAIN INVALID COMMAND"<<endl;
		}
		else if(command=='z'){

			sq.Pop_front();
			berker=sq.Pop_front();
			sq.Push_front(berker);
			berker.print_puzzle();
		}
		else if(command=='r'){

			while(sq.counter()>0){

				berker=sq.Pop_rear();
				berker.print_puzzle();
			}
			break;
		}
		if (berker.is_solved()==true)
			cout<<"CONGRATULATIONS YOU WON !!!"<<endl;
	}


	return 0;
}
