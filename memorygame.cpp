//code by angeline-crl
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int choice1, choice2, choice3;
int lives;
int row, col;
int flag, flag2;
int pts=0;
int r=0, c=0, r2=0, c2=0;
int num1=0, num2=0;
int i,j;
int num[50][50];
int verify[50][50];

void menu();
void generate_num();
void start();
void display();
void displaytrial();
void select1();
void select2();
void check();
void check2();
void life();
void points();
void addtolist();
void inst();
void trialtitle();
void trial();
void reset();
void difficulty();

int main(){
	
	menu();

	exit(0);
	return 0;
}

void menu(){
	cout << " - - - - - Memory Game - - - - -"
		 << "\n          >   MENU   <"
		 << "\n\n ( Select # to Perform: )"
		 << "\n\n [1] START Game"
		 << "\n [0] EXIT"
		 << "\n\n [2] Instructions"
		 << "\n [3] TRIAL Game"
		 << "\n\n   >> ";
		 cin >> choice1;
		 
	do{	
		if(choice1==1){
			system("cls");
			start();
		}
		else if(choice1==2){
			system("cls");
			inst();
			system("cls");
			menu();
		}
		
		else if(choice1==3){
			system("cls");
			trial();
		}
		else if(choice1==0){
			exit(0);
		}
	}while(choice1!=0);
}

void generate_num(){
	srand (time(NULL));
	for(i=1; i<=row; i++){
		for(j=1; j<=col; j++){
			num[i][j] = rand() % 9+1;
		}
	}
}

void display(){
	cout << "\n\n";
	for(j=1; j<=col; j++){
		cout << "\t" << j;
	}
	
	cout << endl;
	
	cout << "    ";
	for(j=1; j<=col*4; j++)
		cout << " -";
	
	for(i=1; i<=row; i++){
		cout << "\n\n" << " " << i <<" | ";
		for(j=1; j<=col; j++){
			if(r==i && c==j)
			cout << "\t" << num[i][j];
			
			else if(r2==i && c2==j)
			cout << "\t" << num[i][j];
			
			else if(verify[i][j]==1)
			cout << "\t" << num[i][j];
			
			else
			cout << "\t*";
		}
	}
}

void displaytrial(){
	cout << "\n\n";
	for(j=1; j<=col; j++){
		cout << "\t" << j;
	}
	
	cout << endl;
	
	cout << "    ";
	for(j=1; j<=col*4; j++)
		cout << " -";
	
	for(i=1; i<=row; i++){
		cout << "\n\n" << " " << i <<" | ";
		for(j=1; j<=col; j++){
			if(r==i && c==j)
			cout << "\t" << num[i][j];
			
			else if(r2==i && c2==j)
			cout << "\t" << num[i][j];
			
			else if(verify[i][j]==1)
			cout << "\t" << num[i][j];
			
			else
			cout << "\t*" << num[i][j];
		}
	}
}

void select1(){
	cout << "\n\n [  Select a Place!  ]"
		 << "\n\n - - - 1st Number - - -"
		 << "\n > Enter the [Row #]: ";
		 cin >> r;
	cout << " > Enter the [Col #]: ";
		 cin >> c;
}

void select2(){
	cout << "\n\n [  Select a Place!  ]"
		 << "\n\n - - - 2nd Number - - -"
		 << "\n > Enter the [Row #]: ";
		 cin >> r2;
	cout << " > Enter the [Col #]: ";
		 cin >> c2;
}

void check(){
	for(i=1; i<=row; i++){
		for(j=1; j<=col; j++){
			if(r==i && c==j)
				num1 = num[i][j];
		}
	}
	
	for(i=1; i<=row; i++){
		for(j=1; j<=col; j++){
			if(r2==i && c2==j)
				num2 = num[i][j];
		}
	}
	
	if(num1==num2)
		flag = 1;
	else
		flag = 0;
}
void check2(){
	for(i=1; i<=row; i++){
		for(j=1; j<=col; j++){
			if(r==i && c==j){
				if(verify[i][j]==1)
				flag2 = 1;}
				
				else{
				flag = 0;}
		}
	}
}

void check3(){
	for(i=1; i<=row; i++){
		for(j=1; j<=col; j++){
			if(r2==i && c2==j){
				if(verify[i][j]==1)
				flag2 = 1;}
				
				else{
				flag = 0;}
		}
	}
}

void addtolist(){
	for(i=1; i<=row; i++){
			for(j=1; j<=col; j++){
				if(r==i && c==j)
					verify[i][j] = 1;
			}
		}
		
	for(i=1; i<=row; i++){
			for(j=1; j<=col; j++){
				if(r2==i && c2==j)
					verify[i][j] = 1;
			}
		}
}

void inst(){
	cout << " - - - - - Memory Game - - - - -"
		 << "\n       >   HOW TO PLAY   <"
		 << "\n\n [    Welcome to Memory Game!    ]"
		 << "\n\n 1. You will be given an 4 x 4 table"
		 << "\n\n 2. Select 2 places \n   (Coordinates being: ROW, COLUMN)"
		 << "\n\n 3. If the numbers on the 2 places MATCH,\n    you get a Point!"
		 << "\n\n 4. If the numbers are DIFFERENT, the numbers will\n    be hidden and you'll have to Try Again."
		 << "\n\n 5. If you DIDN'T MATCH, you lose a LIFE"
		 << "\n\n 6. The game ENDS once LIFE is depleted"
		 << "\n\n 7. In TRIAL MODE, There is no LIFE and all numbers are shown.";
		 
	cout << "\n\n Press any key to Return to Menu"
		 << "\n   >> ";
	system("pause>0");
}

void trialtitle(){
	cout << " - - - - - Memory Game - - - - -"
		 << "\n     >  TRIAL in PROGRESS..  <";
}

void title(){
	cout << " - - - - - Memory Game - - - - -"
		 << "\n     >  GAME in PROGRESS..  <";
}


void start(){
	row = 4;
	col = 4;
	difficulty();
	
	choice2 = 1;
	generate_num();
	
while(choice2!=0){
	
	if(lives<=0){
		break;
	}
	
	life();
	points();
	title();
	display();
	
	do{
		flag2 = 0;
		select1();
		
		if(r>row || c>col){
			cout << "\n\n [OOPS!] Target is out of Bounds";
	
			cout << "\n\n  >> Press any key to Try Again..";
			system("pause>0");
			system("cls");
			
			life();
			points();
			title();
			display();
		}
		
		check2();
		if(flag2==1){
			cout << "\n\n [OOPS!] You have already MATCHED this Tile";
		
				cout << "\n\n  >> Press any key to Try Again..";
				system("pause>0");
				system("cls");
				
			life();
			points();
			title();
			display();
			}
			
	}while((r>row || c>col) || flag2==1);
		system("cls");
		
			life();
			points();
			title();
			display();

	do{
		flag2 = 0;
		select2();
		 
		if(r2>row || c2>col){
			cout << "\n\n [OOPS!] Target is out of Bounds";
	
			cout << "\n\n  >> Press any key to Try Again..";
			system("pause>0");
			system("cls");
			
			life();
			points();
			title();
			display();
		}
		
		else if(r==r2 && c==c2){
		cout << "\n\n [OOPS!] You have already Picked"
				 << "\n Row " << r << " Column " << c << " as Place #1";
	
			cout << "\n\n  >> Press any key to Try Again..";
			system("pause>0");
			system("cls");
			
			life();
			points();
			title();
			display();
		}
		
		check3();
		if(flag2==1){
			cout << "\n\n [OOPS!] You have already MATCHED this Tile";
		
				cout << "\n\n  >> Press any key to Try Again..";
				system("pause>0");
				system("cls");
				
				life();
				points();
				title();
				display();
			}
		
	}while((r==r2 && c==c2) || (r2>row || c2>col) || flag2==1);
		
	system("cls");
	life();
	points();
	title();
	display();

	
	check();
	if(flag==1){
		cout << "\n\n > It's a Match! <\n    [+1 Point]";
		addtolist();
		pts++;
		
		cout << "\n\n  > [1] Match another Number"
			 << "\n  > [0] Return to MENU"
			 << "\n\n     >> ";
			cin >> choice2;
		
		if(choice2==1){
			system("cls");
		}else if(choice2==0){
			system("cls");
			menu();
			reset();
		}
	}
	else if(flag==0){
		r = 0;
		c = 0;
		r2 = 0;
		c2 = 0;
		lives--;
		
		cout << "\n\n         > Sorry.. <\n [ The Numbers didn't Match ]";
		
		cout << "\n\n  > [1] Match another Number"
			 << "\n  > [0] Return to MENU"
			 << "\n\n     >> ";
			cin >> choice2;
		
		if(choice2==1){
			system("cls");
		}else if(choice2==0){
			system("cls");
			menu();
			reset();
		}
	}
}
	
	life();
	points();
	title();
	display();

	cout << "\n\n\n     >       Game Over       <"
		 << "\n\n        TOTAL POINTS: " << pts
		 << "\n\n          [1] Return to MENU"
			 << "\n          [0] EXIT"
			 << "\n\n           >> ";
			cin >> choice2;
		
		if(choice2==1){
			system("cls");
			menu();
			reset();
		}else if(choice2==0){
			exit(0);
		}
}

void trial(){
	row = 4;
	col = 4;
	
	generate_num();
	choice2=1;
	
while(choice2!=0){
	
	cout << " LIFE: X\n";
	points();
	trialtitle();
	displaytrial();
	
	do{
		flag2 = 0;
		select1();
		
		if(r>row || c>col){
			cout << "\n\n [OOPS!] Target is out of Bounds";
	
			cout << "\n\n  >> Press any key to Try Again..";
			system("pause>0");
			system("cls");
			
			cout << " LIFE: X\n";
			points();
			trialtitle();
			displaytrial();
		}
		
		check2();
		if(flag2==1){
			cout << "\n\n [OOPS!] You have already MATCHED this Tile";
		
				cout << "\n\n  >> Press any key to Try Again..";
				system("pause>0");
				system("cls");
				
				trialtitle();
				displaytrial();
			}
			
	}while((r>row || c>col) || flag2==1);
		system("cls");
		
		cout << " LIFE: X\n";
		points();
		trialtitle();
		displaytrial();

	do{
		flag2 = 0;
		select2();
		 
		if(r2>row || c2>col){
			cout << "\n\n [OOPS!] Target is out of Bounds";
	
			cout << "\n\n  >> Press any key to Try Again..";
			system("pause>0");
			system("cls");
			
			cout << " LIFE: X\n";
			points();
			trialtitle();
			displaytrial();
		}
		
		else if(r==r2 && c==c2){
		cout << "\n\n [OOPS!] You have already Picked"
				 << "\n Row " << r << " Column " << c << " as Place #1";
	
			cout << "\n\n  >> Press any key to Try Again..";
			system("pause>0");
			system("cls");
			
			cout << " LIFE: X\n";
			points();
			trialtitle();
			displaytrial();
		}
		
		check3();
		if(flag2==1){
			cout << "\n\n [OOPS!] You have already MATCHED this Tile";
		
				cout << "\n\n  >> Press any key to Try Again..";
				system("pause>0");
				system("cls");
				
				cout << " LIFE: X\n";
				points();
				trialtitle();
				displaytrial();
			}
		
	}while((r==r2 && c==c2) || (r2>row || c2>col) || flag2==1);
		
	system("cls");
	cout << " LIFE: X\n";
	points();
	trialtitle();
	displaytrial();

	
	check();
	if(flag==1){
		cout << "\n\n > It's a Match! <\n    [+1 Point]";
		addtolist();
		pts++;
		
		cout << "\n\n  > [1] Match another Number"
			 << "\n  > [0] Return to MENU"
			 << "\n\n     >> ";
			cin >> choice2;
		
		if(choice2==1){
			system("cls");
		}else if(choice2==0){
			system("cls");
			menu();
			reset();
		}
	}
	else if(flag==0){
		r = 0;
		c = 0;
		r2 = 0;
		c2 = 0;
		lives--;
		
		cout << "\n\n         > Sorry.. <\n [ The Numbers didn't Match ]";
		
		cout << "\n\n  > [1] Match another Number"
			 << "\n  > [0] Return to MENU"
			 << "\n\n     >> ";
			cin >> choice2;
		
		if(choice2==1){
			system("cls");
		}else if(choice2==0){
			system("cls");
			menu();
			reset();
		}
	}
}
}

void life(){
	cout << " LIFE: ";
	for(i=1; i<=lives; i++){
		cout << "<3 ";
	}
	cout << endl;
}

void points(){
	cout << " POINTS: " << pts << endl;
}

void reset(){
	lives = 0;
	pts = 0;
	choice2 = 1;
	
	for(i=1; i<=row; i++){
		for(j=1; j<=col; j++){
			verify[i][j] = 0;
		}
	}
	difficulty();
	generate_num();
	system("cls");
}

void difficulty(){
	system("cls");
	cout << "\n - - - - - SELECT DIFFICULTY - - - - -"
		 << "\n\n [1] Easy - 15 Lives"
		 << "\n [2] Medium - 10 Lives"
		 << "\n [3] Hard - 5 Lives"
		 << "\n\n   >> ";
		 cin >> choice3;
		 
	if(choice3==1){
		lives=15;
	}else if(choice3==2){
		lives=10;
	}else if(choice3==3){
		lives=5;
	}
	system("cls");
}
