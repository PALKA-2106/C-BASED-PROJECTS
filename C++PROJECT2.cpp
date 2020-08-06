#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int player;
void swap_player_marker();
//to draw the tic tac toe initial state over console
void drawBoard(){
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t "<<board[0][0]<<" | "<<" "<<board[0][1]<<" | "<<" "<<board[0][2]<<endl;
	cout<<"\t\t\t\t\t\t--------------\n";
	cout<<"\t\t\t\t\t\t "<<board[1][0]<<" | "<<" "<<board[1][1]<<" | "<<" "<<board[1][2]<<endl;
	cout<<"\t\t\t\t\t\t--------------\n";
	cout<<"\t\t\t\t\t\t "<<board[2][0]<<" | "<<" "<<board[2][1]<<" | "<<" "<<board[2][2]<<endl;
}

bool placemarker(int slot){
	int row=slot/3;
	int col;
	if(slot%3==0){
    row--;
	col=2;
    }
	else col=(slot%3) -1;
	if(board[row][col]!='X' && board[row][col]!='O'){
	board[row][col]=current_marker;
	return true;
}
return false;
	
}
int winner(){
	for(int i=0;i<3;i++){
		//for row matching
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2] )
		return player;
		//for column matching
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i] )
		return player;
		//for diagonal matching
		if(board[0][0]==board[1][1]&&board[1][1]==board[2][2] )
		return player;
		//for diagonal matching
		if(board[0][2]==board[1][1]&&board[1][1]==board[2][0] )
		return player;
	}
	
	return 0;
}
void game(){
	cout<<"\t\t\t\t\t\tPLAYER1 CAN CHOOSE HIS MARKER: ";
	char player1;
	cin>>player1;
	int won;
	player=1;
	current_marker=player1;
	drawBoard();
	for(int i=0;i<9;i++){
		cout<<"IT'S PLAYER "<<player<<"'S TURN. ENTER YOUR SLOT: ";
		int slot;
		cin>>slot;
		if(slot<1 || slot>9){
			cout<<"\t\t\t\t\t\tTHIS SLOT IS NOT EXISTING !!! GO FOR ANOTHER SLOT\n";
			i--;
			continue;
		}
		if(!placemarker(slot)){
			cout<<"\t\t\t\t\t\tTHIS SLOT IS ALREADY OCCUPIED !!! GO FOR ANOTHER SLOT\n";
			i--;
			continue;
		}
		drawBoard();
		won=winner();
		if(won==1){
		cout<<"\t\t\t\t\t\tPLAYER 1 WON!!!! CONGRATULATIONS\n";
		break;
	    }
		if(won==2){
			cout<<"\t\t\t\t\t\tPLAYER 2 WON!!!! CONGRATULATIONS\n";
			break;
		}
		swap_player_marker();
	}
	if(won==0) cout<<"\t\t\t\t\t\tNOBODY WON:( IT WAS A TIE GAME\n";
}
void swap_player_marker(){
	if(current_marker=='X') current_marker='O';
	else current_marker='X';
	
	if(player==1) player=2;
	else player=1; 
}
int main(){
	game();
}
