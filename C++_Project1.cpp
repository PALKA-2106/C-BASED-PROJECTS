#include <iostream>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
void start();
int menu();
int k=0;  //index variable

int main()
{
    start();
    string name[100];
    string no[100];
    int check=0;
    int top_contacts=0;
    do{
    	// to add contacts
      if(check==1){
      	cout<<"\t\t\t\t\tName: ";
      	cin>>name[k];
      	cout<<"\t\t\t\t\tPhone Number: ";
      	cin>>no[k];
      	k++;
      	top_contacts++;
	  }	
	  // display contacts
	  else if(check==2){
	  	for(int i=0;i<k;i++){
	  		if(name[i]!="\0")
	  		cout<<"\t\t\t\t\tName: "<<name[i]<<"\t\tPhone Number: "<<no[i]<<endl;
		  }
	  }
	  //search by number
	  else if(check==3){
	  	string temp;
	  	cout<<"\t\t\t\t\tENTER THE NUMBER TO BE SEARCHED";
	  	cin>>temp;
	  	int check2=0;
	  	for(int i=0;i<k;i++){
	  		if(temp==no[i]){
	  			cout<<"\t\t\t\t\tName: "<<name[i]<<"\t\tPhone Number: "<<no[i]<<endl;
	  			check2++;
			  }
		  }
		  if(check2!=0)
			   cout<<"\t\t\t\t\tTHE NUMBER IS FOUND IN UR CONTACT LIST\n";
		  else
			   cout<<"\t\t\t\t\tTHE NUMBER IS NOT FOUND IN UR CONTACT LIST\n";
	  }
	  //search by name
	  else if(check==4){
	  	string temp;
	  	cout<<"\t\t\t\t\tENTER THE NAME TO BE SEARCHED";
	  	cin>>temp;
	  	int check2=0;
	  	for(int i=0;i<k;i++){
	  		transform(temp.begin(), temp.end(), temp.begin(), ::tolower); 
	  		transform(name[i].begin(), name[i].end(), name[i].begin(), ::tolower); 
	  		if(temp==name[i]){
	  			cout<<"\t\t\t\t\tName: "<<name[i]<<"\t\tPhone Number: "<<no[i]<<endl;
	  			check2++;
			  }
		}
		if(check2!=0)
			   cout<<"\t\t\t\t\tTHE NAME IS FOUND IN UR CONTACT LIST\n";
		else
			   cout<<"\t\t\t\t\tTHE NAME IS NOT FOUND IN UR CONTACT LIST\n";
	  }
	  //update
	  else if(check==5){
	  	string temp,temp1,temp2;
	  	cout<<"\t\t\t\t\tENTER THE NAME TO BE UPDATED";
	  	cin>>temp;
	  	int check2=0;
	  	for(int i=0;i<k;i++){
	  		transform(temp.begin(), temp.end(), temp.begin(), ::tolower); 
	  		transform(name[i].begin(), name[i].end(), name[i].begin(), ::tolower); 
	  		if(temp==name[i]){
	  			cout<<"\t\t\t\t\tNEW NAME";
	  			cin>>temp1;
	  			cout<<"\t\t\t\t\tNEW NUMBER";
	  			cin>>temp2;
	  			name[i]=temp1;
	  			no[i]=temp2;
	  			check2++;
	  			cout<<"\t\t\t\t\tUPDATED SUCCESSFULLY\n";
			  }
			if(check2!=0)
			   cout<<"\t\t\t\t\tTHE CONTACT HAS BEEN UPDATED IN UR CONTACT LIST\n";
			else
			   cout<<"\t\t\t\t\tTHE CONTACT IS NOT FOUND IN UR CONTACT LIST\n";
		  }
	  }
	  //delete
	  else if(check==6){
	  	string temp;
	  	cout<<"\t\t\t\t\tENTER THE NAME TO BE DELETED";
	  	cin>>temp;
	  	int check2=0;
	  	for(int i=0;i<k;i++){
	  		transform(temp.begin(), temp.end(), temp.begin(), ::tolower); 
	  		transform(name[i].begin(), name[i].end(), name[i].begin(), ::tolower); 
	  		if(temp==name[i]){
	  			cout<<"\t\t\t\t\tDELETED SUCCESSFULLY\n";
	  			cout<<"\t\t\t\t\tName: "<<name[i]<<"\t\tPhone Number: "<<no[i]<<endl;
	  			name[i]="\0";
	  			no[i]="\0";
	  			check2++;
	  			top_contacts--;
			  }
	    	}
			if(check2!=0)
			   cout<<"\t\t\t\t\tTHE NAME IS FOUND IN UR CONTACT LIST\n";
			else
			   cout<<"\t\t\t\t\tTHE NAME IS NOT FOUND IN UR CONTACT LIST\n";
	  }
	  //delete all
	  else if(check==7){
	  		cout<<"\t\t\t\t\tDELETED SUCCESSFULLY\n";
	  		for(int i=0;i<k;i++){
	  			name[i]="\0";
	  			no[i]="\0";
	  	    }
			k=0;
			top_contacts=0;
	  }
	  // display number of contacts
	  else if(check==8)
	  	cout<<"\t\t\t\t\t\tTOTAL NUMBER OF CONTACTS IN LIST ARE"<<top_contacts<<endl;
	  check=menu();
	  
	}while(check!=9);
    return 0;
}
//function for loading bar in C++
void start(){
    system("Color 0B");  //used to give color to the loading bar that we want to display on our screen from windows.h library(range of colors 0-9 background color of console and to change the color of the text A-F)
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";  //\n is just to bring the loading bar in the center of the page from up to down of the page
    cout<<"\t\t\t\t\t-----------------------------\n";
    cout<<"\t\t\t\t\t-----------------------------\n";
    cout<<"\t\t\t\t\tPHONE BOOK APPLICATION\n";
    cout<<"\t\t\t\t\t-----------------------------\n";
    cout<<"\t\t\t\t\t-----------------------------\n\n";
    cout<<"\t\t\t\t\tLoading"; //\t is just used to bring the loading bar in the center of the page from left to right of the page
    char x=219; //used to fill loading bar(it is the ASCII code of the symbol which appear like small filled rectangle such kind of rectangles are used to fill our loading bar to show the viewer how much it is completed)
    for(int i=0;i<20;i++){ 
        cout<<x;    //if we only this statement then we will be able to see only a complete loaded bar not the time of processing bar
        if(i<10)
        Sleep(300); // sleep function is used to show viewer that loading bar is being filled in this manner and speed(to use it windows.h library is used)
        if(i>=10)
        Sleep(25);
    }
    // now we have to clear our console
    system("cls"); //after loading gets over we want the loading bar to disappear from the screen so this function is used from windows.h library
}


int menu()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------\n";
    cout<<"\t\t\t\t\tPHONE BOOK APPLICATION\n";
    cout<<"\t\t\t\t\t-----------------------------\n";
    cout<<"\t\t\t\t\t[1] ADD CONTACTS\n";
    cout<<"\t\t\t\t\t[2] DISPLAY ALL CONTACTS\n";
    cout<<"\t\t\t\t\t[3] SEARCH BY NUMBER\n";
    cout<<"\t\t\t\t\t[4] SEARCH BY NAME\n";
    cout<<"\t\t\t\t\t[5] UPDATE\n";
    cout<<"\t\t\t\t\t[6] DELETE\n";
    cout<<"\t\t\t\t\t[7] DELETE ALL\n";
    cout<<"\t\t\t\t\t[8] NUMBER OF CONTACTS\n";
    cout<<"\t\t\t\t\t-----------------------------\n";
    cout<<"\t\t\t\t\t[9] EXIT\n";
    cout<<"\t\t\t\t\t-----------------------------\n";
    int a;
    cin>>a;
    system("cls");
    return a;
}
