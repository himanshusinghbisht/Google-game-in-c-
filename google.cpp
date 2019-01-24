 #include<iostream>
 #include<windows.h>
 #include<conio.h>
 #include<time.h>
 using namespace std;
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD CursorPosition;
 int count=0;
 void gotoxy(int x,int y);
 bool move=true;
 bool jump=false;
 bool on=false;
 bool swing=true;
 bool gameover=false;
 int x=10,y=18,legx=x,legy=y,handx1=x+1,handx2=x-1,handy1=y,handy2=y ;
 int obstacleX=60,obstacleY=18,obstacleX2=40,obstacleY2=18;
 int creation=0;
 int obs[10]={199,186,179,195,219,223,220,221,224};
 int scoretime=0;
 string name;
 void guy()
 {
 		////
    if(move==true)
    {
    	move=false;
	}
	else
	{
		move=true;
	}
	if(!move)
	{
		legx+=1;
	}
	else
	{
		legx-=1;
	}
		 
 	gotoxy(x,y);
 	clog << char(2);
 	//hands
 	if(swing)
 	{
	 
 	
 	gotoxy(handx2,handy2);
 	clog << char(92);
 	swing=false;
 }
 else
 {
 		gotoxy(handx1,handy1);
 	clog << char(47);
 
 	swing=true;
 }
 	
 	//hands
 	gotoxy(legx+1,legy+1);
 	clog << char(92);
 	
 	gotoxy(legx-1,legy+1);
 	clog << char(47);
 
 
 	
 	
 	////
 	if(jump)
	 {
	 	count++;
	 	if(count<=4)
	 	{
	 		y--;
	 		legy--;
	 		handy1--;
	 		handy2--;
		 }
		 if(count<=8&&count>4)
		 {
		 y++;
		 legy++;
		 handy1++;
	 		handy2++;
		 }
		 if(count==9)
		 {
		 	count=0;
		 	jump=false;
		 }
 }
}
//
void loose()
{
	if((obstacleX==x)&&(obstacleY==legy))
	gameover=true;
}
void score()
{
	gotoxy(60,5);
	clog << "score";
	gotoxy(60,7);
	if(scoretime<100000)
	{
			
	clog << scoretime;
	scoretime++;
}
	
}
//
void obstacles()
{
	srand(time(NULL));
	static int a=0;
		static int b=0;
 if(obstacleX>0&&obstacleX<=60)
 {
 	gotoxy(obstacleX,obstacleY);
 	clog << char(obs[a]);
 	obstacleX--;
 }
 if(obstacleX==0)
 {
 	a++;
 	if(a==9)
 	a=0;
 	obstacleX=60;
 }
 
 ////
 static int x;
 x=rand()%60;
 if(x>20)
 {
 	on=true;
 }
 
 if(on)
 {
  if(obstacleX2>0&&obstacleX2<=40)
 {
 	gotoxy(obstacleX2,obstacleY2);
 	clog << char(obs[a+1]);
 	obstacleX2--;
 }
 if(obstacleX2==0)
 {
 	b++;
 	if(b==9)
 	b=0;
 	obstacleX2=40;
 	on=false;
 }
 
}
}
//
 void input()
 {
 	if(_kbhit())
 	{
 		switch(_getch())
 		{
 			case 'w':
 				jump=true;
		 }
	 }
	 
	 
	 }
 
 
 
 void draw()
 {
 guy();
 	gotoxy(0,20);
 	for(int i=0;i<60;i++)
 	{
 		clog << char(176);
	 }
	 clog << "\n\n Player : " << name ;
 }
 int main()
 {
 	system("color a");
 	system("title google game");
 clog << "enter your name\n";
 cin >> name;
 
 	
 	while(!gameover)
 	{
 		system("cls");
 			clog << "TIME: " << __TIME__ << "\t\tDATE :" << __DATE__ ;
 		score();
 		draw();
 		loose();
 		obstacles();
 		input();
 		
 		
 		
 		
	 }
	 clog << "\n\n\n";
 	return 0;
 }
 
 void gotoxy(int x,int y)
 {
 	CursorPosition.X=x;
 	CursorPosition.Y=y;
 	SetConsoleCursorPosition(console,CursorPosition);
 }
