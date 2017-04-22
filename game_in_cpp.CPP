#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include <time.h>
//2 min game
char ch,phvalue=1;
clock_t start, end;
clock_t t1,t2;//time interval =t2-t1=1sec
int nt_time=170;//sec
int y,p,c,x,x1,y1=20,pg=1,ox[200],oy[200],i=0,j=0,phase=phvalue;
int x2=15,y2=11,x3=15,y3=1,x4=26,y4=2,xa5=14,ya5=1,xb5=22,yb5=1,x6=16,y6=1,
    x7=12,ya7=7,yb7=8,yc7=9,yd7=10,ye7=11;//cordinates of 1st obst tree
int x8=26,ya8=4,yb8=5,yc8=6,yd8=7,ye8=8;//cordinates of 2nd obst tree
int ltyb,rtyb;//y cordinates of left and right boundry
int upxb,dnxb;//used in chamber frame
int i1=0,j1=0,x9=10,y9=1,x10=15,y10=1,xa11=9,ya11=1,xb11=9,yb11=1,x14=9,ya14=5,
    yb14=6,yc14=7,yd14=8,ye14=9,yf14=10,yg14=11,x12,y12=10;
int x13,y13=1,x15=9,y15=2,y17=3,y17b=2,x17,x17b,i17,x16=12,y16=2;
int r=0,cx1=9,cy1=1,rx=35,ray=24,rby=23,rcy=25,rax=34,rbx=36,raxl=33;
int ko17=9,kc2,tmpc2=9,kcb2,tmpbc2=31,xc2[12],xc2b[12],yc2=7,ic2,ycb2=10;
int t=2; //used in c2
int ya18=3,yb18=1,x19,y19=1,xa18,xb18,y20=1,x20=9,ya20=5,yb20=6,yc20=7,yd20=8,ye20=9,yf20=10,yg20=11;
int x21=31,ya21=5,yb21=6,yc21=7,yd21=8,ye21=9,yf21=10,yg21=11,x22,y22=1;
int t23=1,xa23=9,xb23=9,xc23=9,xd23=9,xe23=9,xf23=9,xg23=9,ya23,yb23,yc23,yd23,ye23,yf23,yg23;
int tmpo23=0;//used in rt and lft fn for o23
int y24=1,x24=9,xc24[12],xc24b[12],yc24=7,ic24,ycb24=10,kc24,tmpc24=9,kcb24,tmpbc24=31;
int xa25=9,xb25=10,xc25=11,xd25=12,xe25=13,xf25=14,xg25=15,xh25=16,y25=7;
int xa26=9,xb26=10,xc26=11,xd26=12,xe26=13,xf26=14,xg26=15,xh26=16,y26=10;
int xa28=11,xb28=12,xc28=13,xd28=14,y28=9,ba28=0,bb28=0,bc28=0,bd28=0; //ba28,bb28...is the num of tyms bonus is taken
int xa27=21,xb27=22,xc27=23,xd27=24,xe27=25,xf27=26,xg27=27,xh27=28,y27=23,t27=0;
int ttrolley=1;
int x29,y29=13;
int x30a,y30a=12,xa30=11,ya30=5,xb30=9,yb30=6,xc30=13,yc30=6,xd30=11,yd30=7,xe30=11,ye30=6;
int xa31=29,ya31=5,xb31=27,yb31=6,xc31=31,yc31=6,xd31=29,yd31=7,xe31=29,ye31=6;
int xa32=20,ya32=5,xb32=18,yb32=6,xc32=22,yc32=6,xd32=20,yd32=7,xe32=20,ye32=6;
int be303132=0;//among thre $ signs of o30,o31 and o32, only one can be taken
int xal,xfl=17,yal=2,xbl,ybl=3,xcl,ycl=4,xdl,ydl=5,xel,yel=6,yfl=7;
int t2xa=9,t2xb=10,t2xc=11,t2xd=12,t2xe=13,t2xf=14,t2xg=15,t2xh=16,t2y=14;
int tl=0;//for ladder man
int btxa=11,btxb=12,btxc=13,btxd=14,btxe=15,btxf=16,btxg=17,btxh=18,bty=19;
int fxa=60,fxb=61,fxc=63,fxd=65,fxe=66,fya=15,fyb=14,fyc=13,fyd=16,fye=17;//of football
int f2xa=14,f2xb=15,f2xc=17,f2xd=19,f2xe=20,f2ya=15,f2yb=14,f2yc=13,f2yd=16,f2ye=17;//of football2
int f3xa=37,f3xb=38,f3xc=40,f3xd=42,f3xe=43,f3ya=12,f3yb=11,f3yc=10,f3yd=13,f3ye=14;//of football3
int f4xa=60,f4xb=61,f4xc=63,f4xd=65,f4xe=66,f4ya=10,f4yb=9,f4yc=8,f4yd=11,f4ye=12;//of football4
int f5xa=14,f5xb=15,f5xc=17,f5xd=19,f5xe=20,f5ya=10,f5yb=9,f5yc=8,f5yd=11,f5ye=12;//of football5
int bo6=0,b14=0;
int tb=0,tf=0;//total bonus, total fouls and net points
int o1=0,o2=0,o3=0,o4=0,o5=0,o6=0,o7=0,o8=0,o9=0,o10=0,o11=0,o12=0,o13=0,o14=0,
    o15=0,o16=0,o17=0,o17b=0,o18=0,o19=0,o20=0,o21=0,o22=0,o23=0,o24=0,o28=0,
    o30=0,o30a=0,o31=0,o32=0,of=0;//number of times the obstacles are called
float tpoints=-1000;
int sbltb,sbrytb,sbup,sbdn;//frame of scoreboard
int tax=34,thx=34,tbx=35,tcx=36,tdx=37,tex=38,tfx=39,tgx=40,tix=40;
int st1x=34,st1y=16,st2x=35,st2y=15,st3x=37,st3y=14,st4x=39,st4y=15,st5x=40,st5y=16;//for the stars of trolley
void intropage()
{
	int ux,tx,sx,ax,vx,uy=9,ty=9,sy=9,ay=9,vy=9;
	int kx,hx,ak1x,ak2x,n1x,n2x,ak3x,ky=11,hy=11,ak1y=11,ak2y,n1y=11,n2y=11,ak3y;
	int px=34,py;
	int pzx,pzy=17,gmx,gmy=17;
	//textcolor(3);
	for(ux=1;ux<=30;ux++)
	{
		//textcolor(5);
		gotoxy(ux,uy);
		//textcolor(5);
		//textbackgroun//d(15);
		cout<<"U";
		gotoxy(ux-1,uy);
		cout<<" ";
		delay(25);
		gotoxy(1,25);//to take cursor at the corner
	}
	for(tx=1;tx<=32;tx++)
	{
		gotoxy(tx,ty);
		cout<<"T";
		gotoxy(tx-1,ty);
		cout<<" ";
		if(tx-1==30)
		{
			gotoxy(tx-1,ty);
			cout<<"U";
		}
		delay(25);
		gotoxy(1,25);//to take cursor at the corner
	}
	for(sx=1;sx<=34;sx++)
	{
		//textcolor(6);
		gotoxy(sx,sy);
		cout<<"S";
		gotoxy(sx-1,sy);
		cout<<" ";
		if(sx-1==30)
		{
			gotoxy(sx-1,sy);
			cout<<"U";
		}
		if(sx-1==32)
		{
			gotoxy(sx-1,sy);
			cout<<"T";
		}
		delay(25);
		gotoxy(1,25);//to take cursor at the corner
	}
	for(ax=1;ax<=36;ax++)
	{
		gotoxy(ax,ay);
		cout<<"A";
		gotoxy(ax-1,ay);
		cout<<" ";
		if(ax-1==30)
		{
			gotoxy(ax-1,ay);
			cout<<"U";
		}
		if(ax-1==32)
		{
			gotoxy(ax-1,ay);
			cout<<"T";
		}
		if(ax-1==34)
		{
			gotoxy(ax-1,ay);
			cout<<"S";
		}
		delay(25);
		gotoxy(1,25);//to take cursor at the corner
	}
	for(vx=1;vx<=38;vx++)
	{
		gotoxy(vx,vy);
		cout<<"V";
		gotoxy(vx-1,vy);
		cout<<" ";
		if(vx-1==30)
		{
			gotoxy(vx-1,vy);
			cout<<"U";
		}
		if(vx-1==32)
		{
			gotoxy(vx-1,vy);
			cout<<"T";
		}
		if(vx-1==34)
		{
			gotoxy(vx-1,vy);
			cout<<"S";
		}
		if(vx-1==36)
		{
			gotoxy(vx-1,vy);
			cout<<"A";
		}
		delay(25);
		gotoxy(1,25);//to take cursor at the corner
	}
	for(kx=80;kx>=41;kx--)
	{
		gotoxy(kx,ky);
		cout<<"K";
		gotoxy(kx+1,ky);
		cout<<" ";
		delay(25);
		gotoxy(1,25);//to take cursor at the corner
	}
	for(hx=80;hx>=43;hx--)
	{
		gotoxy(hx,hy);
		cout<<"H";
		gotoxy(hx+1,hy);
		cout<<" ";
		delay(25);
		gotoxy(1,25);//to take cursor at the corner
	}
	for(ak1x=80;ak1x>=45;ak1x--)
	{
		gotoxy(ak1x,ak1y);
		cout<<"A";
		gotoxy(ak1x+1,ak1y);
		cout<<" ";
		delay(25);
		gotoxy(1,25);//to take cursor at tak1e corner
	}
	for(n1x=80;n1x>=47;n1x--)
	{
		gotoxy(n1x,n1y);
		cout<<"N";
		gotoxy(n1x+1,n1y);
		cout<<" ";
		delay(25);
		gotoxy(1,25);//to take cursor at tak2e corner
	}
	for(n2x=80;n2x>=49;n2x--)
	{
		gotoxy(n2x,n2y);
		cout<<"N";
		gotoxy(n2x+1,n2y);
		cout<<" ";
		delay(25);
		gotoxy(1,25);//to take cursor at tak2e corner
	}
	for(ak1x=80;ak1x>=51;ak1x--)
	{
		gotoxy(ak1x,ak1y);
		cout<<"A";
		gotoxy(ak1x+1,ak1y);
		cout<<" ";
		delay(25);
		gotoxy(1,25);//to take cursor at tak2e corner
	}
	for(py=25;py>=15;py--)
	{
		gotoxy(px,py);
		cout<<"P R E S E N T S";
		gotoxy(px,py+1);
		cout<<"               ";
		//delay(100);
	}
	for(pzx=1,gmx=74;pzx<=30;pzx++,gmx--)
	{
		gotoxy(pzx,pzy);
		cout<<"P U Z Z L E";
		gotoxy(pzx-1,pzy);
		cout<<" ";
		gotoxy(gmx,gmy);
		cout<<"G A M E";
		gotoxy(gmx+7,pzy);
		cout<<" ";
		//delay(100);
	}
	for(rtyb=5,ltyb=5;rtyb<=20,ltyb<=20;ltyb++,rtyb++)
	{

		gotoxy(8,rtyb);
		cout<<"s";
		gotoxy(73,ltyb);
		cout<<"s";
	}
	for(upxb=8,dnxb=8;upxb<=73,dnxb<=73;upxb++,dnxb++)
	{

		gotoxy(upxb,5);//vertical limit: 5 to 25
		cout<<"~";
		gotoxy(dnxb,20);
		cout<<"~";
	}
	//delay(3000);
	phvalue=getch();
	if(phvalue=='1')
	phase=1;
	else if(phvalue=='2')
	phase=2;
	else if(phvalue=='3')
	phase=3;
	else if(phvalue=='4')
	phase=4;
	else if(phvalue=='5')
	phase=5;
	else if(phvalue=='6')
	phase=6;
	else if(phvalue=='7')
	phase=7;
	else if(phvalue=='8')
	phase=8;
	else
	phase=1;
	clrscr();

}
void scoreboard()
{
	for(sbltb=10,sbrytb=10;sbltb<=18,sbrytb<=18;sbltb++,sbrytb++)
	{
		gotoxy(45,sbltb);
		cout<<".";
		gotoxy(68,sbrytb);
		cout<<".";
	}
	for(sbup=45,sbdn=45;sbup<=68,sbdn<=68;sbup++,sbdn++)
	{
		gotoxy(sbup,10);
		cout<<"_";
		gotoxy(sbdn,18);
		cout<<"_";
	}
	gotoxy(47,11);
	cout<<"Total Points: ";
	gotoxy(61,11);
	cout<<tpoints;
	gotoxy(47,13);
	cout<<"Bonus taken: ";
	gotoxy(61,13);
	cout<<tb;
	gotoxy(47,15);
	cout<<"Fouls done: ";
	gotoxy(61,15);
	cout<<tf;
	gotoxy(47,17);
	cout<<"Timer: ";
	cout<<170-((t1 - start) / CLK_TCK);

}
void chamberscoreboard()
{
	for(sbltb=21,sbrytb=21;sbltb<=25,sbrytb<=25;sbltb++,sbrytb++)
	{
		gotoxy(28,sbltb);
		cout<<".";
		gotoxy(53,sbrytb);
		cout<<".";
	}
	for(sbup=28,sbdn=28;sbup<=53,sbdn<=53;sbup++,sbdn++)
	{
		gotoxy(sbup,21);
		cout<<"_";
		gotoxy(sbdn,25);
		cout<<"_";
	}
	gotoxy(30,22);
	cout<<"Total Points: ";
	gotoxy(44,22);
	cout<<tpoints;
	gotoxy(30,23);
	cout<<"Bonus taken: ";
	gotoxy(44,23);
	cout<<tb;
	gotoxy(30,24);
	cout<<"Fouls done: ";
	gotoxy(44,24);
	cout<<tf;
	gotoxy(30,25);
	cout<<"Timer:";
	gotoxy(44,25);
	cout<<170-((t1 - start) / CLK_TCK);


}
void rocket()
{

	while(ray>1)
	{
		gotoxy(rx,rby);
		cout<<"^";
		gotoxy(rx,ray);
		cout<<"!";
		gotoxy(rx,rcy);
		cout<<"*";
		gotoxy(rax,ray);
		cout<<"/";
		gotoxy(rbx,ray);
		cout<<"\\";
		gotoxy(rx,rcy+1);
		cout<<" ";
		gotoxy(rax,ray+1);
		cout<<" ";
		gotoxy(rbx,ray+1);
		cout<<" ";
		ray--;rby--;rcy--;
		gotoxy(x,y);
		delay(200);

	}
}
void obstacle1()
{
	if(o1==0)//o1==0 means that obs 1 is never been called
	{
	//tpoints=tpoints+5000;
		start = clock();
		o1++;
	}
	end = clock();//timer stops

	if((tpoints>75000)&&(r==0))//r==0 means rocket is never been called yet
	{
		rocket();
		r++;
	}
	for(x1=18;x1<=23;x1++)
	{
		gotoxy(x1,y1);
		if(x1%2==0)
		{
			cout<<"=";
			if((x1==x)&&(y1==y))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);
			}
		}
		else
		cout<<" ";
	}
}

void obstacle2()
{
	/*if(o2==0){tpoints=tpoints+5000;o2++;} */
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x2=12;x2<=28;x2++)
	{
		gotoxy(x2,y2);
		if(x2%2!=0)
		{
			cout<<"O";
			if((x2==x)&&(y2==y))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);
			}
		}
		else
		cout<<" ";
	}
}
void obstacle3()
{
	/*if(o3==0){tpoints=tpoints+5000;o3++;} */
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x3=10;x3<=31;x3++)
	{
		gotoxy(x3,y3);
		if(x3%5==0)
		{
			cout<<"|";
			if((x3==x)&&(y3==y))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);
			}
		}
		else
		{
			cout<<" ";

		}
	}
}
void obstacle4()
{
	if(o4==0){tpoints=tpoints+5000;o4++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x4=12;x4<=28;x4++)
	{
		gotoxy(x4,y4);
		if(x4%2==0)
		{
			cout<<"#";
			if((x4==x)&&(y4==y))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);
			}
		}
		else
		{
			cout<<" ";
		}
	}
}
void obstacle5()
{
	if(o5==0){tpoints=tpoints+5000;o5++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	if(tpoints>5000)
	{
		rocket();
	}
	gotoxy(xa5,ya5);
	cout<<"=";
	gotoxy(xb5,yb5);
	cout<<"=";
	if((xa5==x)&&(ya5==y)||(xb5==x)&&(yb5==y))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
}
int tmpo6=0;//used only in o6 function
void obstacle6()
{
	if(o6==0){tpoints=tpoints+5000;o6++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	tmpo6++;
	gotoxy(x6-1,y6);
	cout<<" ";
	gotoxy(x6,y6);
	cout<<"$";
	if((x6==x)&&(y6==y))
	{
		if(bo6==0)
		{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"Bonus";
		//delay(200);
		bo6++;
		tb++;tpoints=tpoints+3000;
		}

	}

	if(tmpo6%2==0)//for two 'w' clicks, x6 will change once
	{
		if(x6==26)
		x6=16;
		x6++;
	}
}

void obstacle7()
{
		if(o7==0){tpoints=tpoints+5000;o7++;}
		if((tpoints>75000)&&(r==0))
		{
			rocket();
			r++;
		}
		gotoxy(x7,ya7);
		cout<<"^";
		gotoxy(x7,yb7);
		cout<<"^";
		gotoxy(x7,yc7);
		cout<<"^";
		gotoxy(x7,yd7);
		cout<<"^";
		gotoxy(x7,ye7);
		cout<<"^";
		//cout<<ya7;
		if((x7==x)&&((ya7==y)||(yb7==y)||(yc7==y)||(yd7==y)||(ye7==y)))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}

}
void obstacle8()
{
		if(o8==0){tpoints=tpoints+5000;o8++;}
		if((tpoints>75000)&&(r==0))
		{
			rocket();
			r++;
		}
		gotoxy(x8,ya8);
		cout<<"^";
		gotoxy(x8,yb8);
		cout<<"^";
		gotoxy(x8,yc8);
		cout<<"^";
		gotoxy(x8,yd8);
		cout<<"^";
		gotoxy(x8,ye8);
		cout<<"^";
		//cout<<ya8;
		if((x8==x)&&((ya8==y)||(yb8==y)||(yc8==y)||(yd8==y)||(ye8==y)))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}

}
void obstacle9()//it will never appear with o7
{
	if(o9==0){tpoints=tpoints+5000;o9++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	x9=10;
	if(y9%2==0)
	{
		for(x9=10;x9<=28;x9++)
		{
			if(x9%2==0)
			{
				gotoxy(x9,y9);
				cout<<"#";
				if((x9==x)&&(y9==y))
				{
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
					gotoxy(2,15);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					//delay(200);
				}
			 }
			else
			{
				gotoxy(x9,y9);
				cout<<" ";
			}
		}
	}
	else
	{
		for(x9=10;x9<=28;x9++)
		{
			if(x9%2==0)
			{
				gotoxy(x9,y9);
				cout<<" ";
			}
			else
			{
				gotoxy(x9,y9);
				cout<<"0";
				if((x9==x)&&(y9==y))
				{
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
					gotoxy(2,15);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					//delay(200);
				}
			}
		}
	}
}
void comment1()
{
	gotoxy(cx1,cy1); //cx1=9and cy1=9
	cout<<"     @";
	gotoxy(cx1,cy1-1); //cx1=9and cy1=9
	cout<<"     ^";
	gotoxy(cx1,cy1);
	cout<<" ";
	gotoxy(10,10);
	cout<<"You have to take '@'";
	gotoxy(10,12);
	cout<<"to his queen...!!";
	gotoxy(10,14);
	cout<<"GOOD LUCK...:D";
	cx1++;

}
void obstacle10()
{
	if(o10==0){tpoints=tpoints+5000;o10++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x10=15;x10<=25;x10++)
	{
		gotoxy(x10,y10);
		cout<<"=";//from x10=15 to x10=26
	}
	for(x10=15;x10<=25;x10++)
	{
		if((x10==x)&&(y10==y))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}
	}
}
void obstacle11()
{
	if(o11==0){tpoints=tpoints+5000;o11++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(xa11=9;xa11<=31;xa11++)
	{
		gotoxy(xa11,ya11);
		cout<<"=";
		//cout<<"========       ========";

	}
	for(xa11=17;xa11<=23;xa11++)
	{
		gotoxy(xa11,ya11);
		cout<<" ";
	}

		/*if((xa11==17)||(xa11==18)||(xa11==19)||(xa11==20)||(xa11==21)||(xa11==22)||(xa11==23))
		{
			gotoxy(xa11,ya11);
			cout<<" ";
		} */
	for(xa11=9;xa11<=31;xa11++)
	{
		if(ya11==22)
		{
			if((xa11!=17)&&(xa11!=18)&&(xa11!=19)&&(xa11!=20)&&(xa11!=21)&&(xa11!=22)&&(xa11!=23)&&(x==xa11))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);
			}
		}
	}
}
/*	gotoxy(xb11,yb11);
	cout<<"====  ===========  ====";
	/*for(xb11=9;xb11<=31;xb11++)
	{
		gotoxy(xb11,yb11);
		cout<<"=";

		general formula of this obstacle
	       if((xb11==5)||(xb11==6)||(xb11==26)||(xb11==27))
		{
			gotoxy(xb11,yb11);
			cout<<" ";
		}
		if((xb11==14)||(xb11==15)||(xb11==26)||(xb11==27))
		{
			gotoxy(xb11,yb11);
			cout<<" ";
		}
		if((xb11==x)&&(yb11==23)&&(x!=14)&&(x!=15)&&(x!=26)&&(x!=27))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}
	} */

void obstacle12()
{
	if(o12==0){tpoints=tpoints+5000;o12++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	x12=9;
	if(y12%2==0)
	{
		for(x12=10;x12<=31;x12++)
		{
			if(x12%2==0)
			{
				gotoxy(x12,y12);
				cout<<">"; //this will be the actual obstacle
				if((x12==x)&&(y12==y))
				{
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
					gotoxy(2,15);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					//delay(200);
				}
			 }
			else
			{
				gotoxy(x12,y12);
				cout<<" ";
			}
		}
	}
	else
	{
		for(x12=9;x12<=31;x12++)
		{
			if(x12%2==0)
			{
				gotoxy(x12,y12);
				cout<<" ";
			}
			else
			{
				gotoxy(x12,y12);
				cout<<"<";
				if((x12==x)&&(y12==y))
				{
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
					gotoxy(2,15);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					//delay(200);
				}
			}
		}
	}
}
void obstacle13()
{
	if(o13==0){tpoints=tpoints+5000;o13++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	if(y13<18)
	{
		for(x13=9;x13<=31;x13++)
		{
			gotoxy(x13,y13);
			cout<<"v";
		}
	}
	else
	{
		for(x13=9;x13<=31;x13++)
		{
			gotoxy(x13,y13);
			if(x13%2!=0)
			{
				cout<<"V";
				if((x13==x)&&(y13==y))
				{
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
					gotoxy(2,15);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					//delay(200);
				}
			}
			else
			cout<<" ";
		}
	}

}
void obstacle14()
{
		if(o14==0){tpoints=tpoints+5000;o14++;}
		if((tpoints>75000)&&(r==0))
		{
			rocket();
			r++;
		}
		gotoxy(x14,ya14);
		cout<<"T";
		gotoxy(x14,yb14);
		cout<<"A";
		gotoxy(x14,yc14);
		cout<<"K";
		gotoxy(x14,yd14);
		cout<<"E";
		gotoxy(x14,ye14);
		cout<<" ";
		gotoxy(x14,yf14);
		cout<<"M";
		gotoxy(x14,yg14);
		cout<<"E";
		if((ya14==y)||(yb14==y)||(yc14==y)||(yd14==y)||(ye14==y)||(yf14==y)||(yg14==y))
		{
			if(x14==x)
			{
				if(b14==0)
				{
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
					gotoxy(2,15);
					cout<<"BONUS";
					tb++;tpoints=tpoints+3000;
					b14++;
					//delay(200);
				}
			}
		}
		//cout<<"yg14="<<yg14;
		//cout<<"\nx14="<<x14;

}
void obstacle15()
{
	if(o15==0){tpoints=tpoints+5000;o15++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x15=10;x15<=31;x15++)
	{
		gotoxy(x15,y15);
		if(x15%2==0)
		{
			cout<<"|";
			if((x15==x)&&(y15==y))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);
			}
		}
		else if(x15%3==0)
		{
			cout<<"_";
			if((x15==x)&&(y15==y))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);
			}


		}
		else
		cout<<" ";
	}
}
void obstacle16()
{
	if(o16==0){tpoints=tpoints+5000;o16++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x16=12;x16<=28;x16++)
	{
		gotoxy(x16,y16);
		if(x16%2==0)
		{
			cout<<"#";
			if((x16==x)&&(y16==y))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);
			}
		}
		else
		{
			cout<<" ";
		}
	}
}

/*void obstacle17()
{
	for(i17=0;i17<22;i17++)
	{
		gotoxy(x17[i17],y17); //for 2nd and the last component of obs17
		cout<<"=";//the last character of this line will not be an = but a space
			   //the space is at x17=31 which is not included in this loop
			   //so at x==31 and y=23, no foul will occur because that location is not included in this loop
		if((x17[i17]==x)&&(y17==22))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(200);
		}
	}
} */

void obstacle17()
{
	if(o17==0){tpoints=tpoints+5000;o17++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x17=9;x17<=30;x17++)
	{
		gotoxy(x17,y17);
		cout<<"=";
		if((x==x17)&&(y==y17))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(200);
		}
	}
}
void obstacle17b()
{
	if(o17b==0){tpoints=tpoints+5000;o17b++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x17b=9;x17b<=31;x17b++)
	{
		if(x17b%2==0)
		{
			gotoxy(x17b,y17b);
			cout<<"=";
			if((x==x17b)&&(y==y17b))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);
			}
		}
	}
}
void comment2()
{
	for(ic2=0;ic2<12;ic2++)
	{
		gotoxy(xc2[ic2],yc2);
		cout<<".";
	}
	for(int ic2b=0;ic2b<12;ic2b++)
	{
		gotoxy(xc2b[ic2b],ycb2);
		cout<<".";
	}

}
void obstacle18()
{
	if(o18==0){tpoints=tpoints+5000;o18++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(int xa18=9;xa18<=31;xa18++)
	{
		gotoxy(xa18,ya18) ;
		cout<<"_";
		if(xa18==20)
		{
			gotoxy(xa18,ya18);
			cout<<" ";
		}
		if((xa18==x)&&(ya18==y)&&(xa18!=20))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}
	}
	for(xb18=10;xb18<=30;xb18++)
	{
		gotoxy(xb18,yb18);
		cout<<"_";
	}
	for(xb18=9;xb18<=31;xb18++)
	{
		if((xb18==x)&&(yb18==y)&&(x!=31))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}

	}


}
void obstacle19()
{
	if(o19==0){tpoints=tpoints+5000;o19++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	x19=9;
	if(y19%2==0)
	{
		for(x19=10;x19<=31;x19++)
		{
			if(x19%2==0)
			{
				gotoxy(x19,y19);
				cout<<"M";
				if((x19==x)&&(y19==y))
				{
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
					gotoxy(2,15);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					//delay(200);
				}
			 }
			else
			{
				gotoxy(x19,y19);
				cout<<" ";
			}
		}
	}
	else
	{
		for(x19=9;x19<=31;x19++)
		{
			if(x19%2==0)
			{
				gotoxy(x19,y19);
				cout<<" ";
			}
			else
			{
				gotoxy(x19,y19);
				cout<<"W";
				if((x19==x)&&(y19==y))
				{
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
					gotoxy(2,15);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					//delay(200);
				}
			}
		}
	}
}
void obstacle20()
{
	if(o20==0){tpoints=tpoints+5000;o20++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
		gotoxy(x20,ya20);
		cout<<"X";
		gotoxy(x20,yb20);
		cout<<"X";
		gotoxy(x20,yc20);
		cout<<"X";
		gotoxy(x20,yd20);
		cout<<"X";
		gotoxy(x20,ye20);
		cout<<"X";
		gotoxy(x20,yf20);
		cout<<"X";
		gotoxy(x20,yg20);
		cout<<"X";
		if((x20==x)&&(((ya20+1)==y)||((yb20+1)==y)||((yc20+1)==y)||((yd20+1)==y)||((ye20+1)==y)||((yf20+1)==y)))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}

}
void obstacle21()
{
	if(o21==0){tpoints=tpoints+5000;o21++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
		gotoxy(x21,ya21);
		cout<<"X";
		gotoxy(x21,yb21);
		cout<<"X";
		gotoxy(x21,yc21);
		cout<<"X";
		gotoxy(x21,yd21);
		cout<<"X";
		gotoxy(x21,ye21);
		cout<<"X";
		gotoxy(x21,yf21);
		cout<<"X";
		gotoxy(x21,yg21);
		cout<<"X";
		if((x21==x)&&(((ya21+1)==y)||((yb21+1)==y)||((yc21+1)==y)||((yd21+1)==y)||((ye21+1)==y)||((yf21+1)==y)))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}
}
void obstacle22()
{
	if(o22==0){tpoints=tpoints+5000;o22++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x22=9;x22<=31;x22++)
	{
		gotoxy(x22,y22);
		if(x22%2==0)
		{
			cout<<"|";
			if((x22==x)&&(y22==23))

			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);

			}
		}
		else
		{
			cout<<" ";

		}
	}
}
/*void obstacle23()
{
	tmpo23=1;
	for(int xa23=9;xa23<=31;xa23++)
	{
		gotoxy(xa23,ya23) ;
		cout<<"_";
		if((ya23%2==0)&&(xa23%2==0))
		{
			gotoxy(xa23,ya23);
			cout<<" ";
		}
		if((xa23==x)&&(ya23==y)&&(xa23%2!=0))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}
	}
	for(xb23=9;xb23<=31;xb23++)
	{
		gotoxy(xb23,yb23);
		cout<<"_";
		if(yb23%2==0)
		{
			gotoxy(xb23,yb23);
			cout<<" ";
		}
		if((yb23%2==0)&&(xb23==x)&&(yb23==y))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			//delay(200);
		}

	}


}   */
/*void obstacle23()
{
	gotoxy(9,5);
	cout<<"_______________________";
	gotoxy(9,6);
	gotoxy(xa23,ya23);//5
	cout<<"_________     ________";
	gotoxy(xb23,yb23);
	cout<<"  |  |  |  |  |  |  |  ";
	gotoxy(xc23,yc23);
	cout<<"  |  |  |  |  |  |  |  ";
	gotoxy(xd23,yd23);
	cout<<"_______  ____  ________";
	gotoxy(xe23,ye23);
	cout<<"~~~  ~~~~~~~~~~~~~  ~~~";
	gotoxy(xf23,yf23);
	cout<<"________       ________";
	gotoxy(xg23,yg23);
	cout<<"|__|  |__|   |__|  |__|";
} */
void obstacle23()
{

	//ya23=5,yb23=6,yc23=7,yd23=9,ye23=11,yf23=13,yg23=15
	if(o23==0){tpoints=tpoints+10000;o23++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}

	for(xa23=9;xa23<=31;xa23++)
	{
		gotoxy(xa23,ya23);
		cout<<"_";//18-22
		if((xa23==18)||(xa23==19)||(xa23==20)||(xa23==21)||(xa23==22))
		{
			gotoxy(xa23,ya23);
			cout<<" ";
		}
		else
		{
			if((y==6)&&(x==xa23))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);
			}
		}

	}
	for(xb23=9;xb23<=31;xb23++)
	{
		gotoxy(xb23,yb23);
		cout<<" ";//9-10,1213,1516,1819,2122,2425,2728,3031
		if((xb23==11)||(xb23==14)||(xb23==17)||(xb23==20)||(xb23==23)||(xb23==26)||(xb23==29))
		{
			gotoxy(xb23,yb23);
			cout<<"|";
			if((y==7)&&(x==xb23))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);
			}
		}
	}
	for(xc23=9;xc23<=31;xc23++)
	{
		gotoxy(xc23,yc23);
		cout<<" ";//9-10,1213,1516,1819,2122,2425,2728,3031
		if((xc23==11)||(xc23==14)||(xc23==17)||(xc23==20)||(xc23==23)||(xc23==26)||(xc23==29))
		{
			gotoxy(xc23,yc23);
			cout<<"|";
			if((y==8)&&(x==xc23))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);
			}
		}
	}
	for(xd23=9;xd23<=31;xd23++)
	{
		gotoxy(xd23,yd23);
		cout<<"_";//1617,2223
		if((xd23==16)||(xd23==17)||(xd23==22)||(xd23==23))
		{
			gotoxy(xd23,yd23);
			cout<<" ";

		}
		else
		{
			if((y==10)&&(x==xd23))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);
			}
		}
	}
	for(xe23=9;xe23<=31;xe23++)
	{
		gotoxy(xe23,ye23);
		cout<<"~";//1213 ,2728
		if((xe23==12)||(xe23==13)||(xe23==27)||(xe23==28))
		{
			gotoxy(xe23,ye23);
			cout<<" ";
		}
		else
		{
			if((y==12)&&(x==xe23))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);
			}
		}
	}
	for(xf23=9;xf23<=31;xf23++)
	{
		gotoxy(xf23,yf23);
		cout<<"_";//17-23
		if((xf23==17)||(xf23==18)||(xf23==19)||(xf23==20)||(xf23==21)||(xf23==22)||(xf23==23))
		{
			gotoxy(xf23,yf23);
			cout<<" ";
		}
		else
		{
			if((y==14)&&(x==xf23))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);
			}
		}
	}
	for(xg23=9;xg23<=31;xg23++)
	{
		gotoxy(xg23,yg23);
		cout<<"_";//1314,192021, 2627
		if((xg23==13)||(xg23==14)||(xg23==19)||(xg23==20)||(xg23==21)||(xg23==26)||(xg23==27))
		{
			gotoxy(xg23,yg23);
			cout<<" ";
		}
		else
		{
			if((y==16)&&(x==xg23))
			{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				delay(200);
			}
		}
	}

}
void obstacle24()
{
	if(o24==0){tpoints=tpoints+5000;o24++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x24=9;x24<=31;x24++)
	{
		if(x24%3==0)
		{
			gotoxy(x24,y24);
			cout<<"v";
		}
	}
	//for(x24=9;x24<=31;x24++)
	//{
		if((x24%3==0)&&(x24==x)&&(y24==22))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);


		}
	//}

}
void obstacle25()
{
	/*if(o==0){tpoints=tpoints+5000;o++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	} */
	gotoxy(xa25,y25);
	cout<<"_";
	gotoxy(xb25,y25);
	cout<<"_";
	gotoxy(xc25,y25);
	cout<<"_";
	gotoxy(xd25,y25);
	cout<<"_";
	gotoxy(xe25,y25);
	cout<<"_";
	gotoxy(xf25,y25);
	cout<<"_";
	gotoxy(xg25,y25);
	cout<<"_";
	gotoxy(xh25,y25);
	cout<<"_";
}
void obstacle26()
{
	/*if(o==0){tpoints=tpoints+5000;o++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}no need*/
	gotoxy(xa26,y26);
	cout<<"_";
	gotoxy(xb26,y26);
	cout<<"_";
	gotoxy(xc26,y26);
	cout<<"_";
	gotoxy(xd26,y26);
	cout<<"_";
	gotoxy(xe26,y26);
	cout<<"_";
	gotoxy(xf26,y26);
	cout<<"_";
	gotoxy(xg26,y26);
	cout<<"_";
	gotoxy(xh26,y26);
	cout<<"_";
}
void obstacle27()//its a lift
{
	gotoxy(xa27,y27);
	cout<<"-";
	gotoxy(xb27,y27);
	cout<<"-";
	gotoxy(xc27,y27);
	cout<<"-";
	gotoxy(xd27,y27);
	cout<<"-";
	gotoxy(xe27,y27);
	cout<<"-";
	gotoxy(xf27,y27);
	cout<<"-";
	gotoxy(xg27,y27);
	cout<<"-";
	gotoxy(xh27,y27);
	cout<<"-";
}
void obstacle28()
{
	if(o28==0){tpoints=tpoints+5000;o28++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	gotoxy(xa28,y28);
	cout<<"$";
	gotoxy(xb28,y28);
	cout<<"$";
	gotoxy(xc28,y28);
	cout<<"$";
	gotoxy(xd28,y28);
	cout<<"$";
	gotoxy(35,7);
	cout<<"Take bonus  by moving left when ";
	gotoxy(35,8);
	cout<<"lift reaches the bonus crate";
	if((xa28==x)&&(y28==(y-1)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"BONUS:)";
		delay(100);
		ba28++;
	}
	if((xb28==x)&&(y28==(y-1)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"BONUS:)";
		delay(100);
		bb28++;
	}
	if((xc28==x)&&(y28==(y-1)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"BONUS:)";
		delay(100);
		bc28++;
	}
	if((xd28==x)&&(y28==(y-1)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"BONUS:)";
		delay(100);
		bd28++;
	}
}
void obstacle29()
{
	/*if(o29==0){tpoints=tpoints+5000;o++;}no points for this*/
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x29=9;x29<=31;x29++)
	{
		gotoxy(x29,y29);
		cout<<"_";
	}
	for(x29=9;x29<=31;x29++)
	{
		if((x29==x)&&(y29==y))
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
	}
}
void obstacle30a()
{
	if(o30a==0){tpoints=tpoints+5000;o30a++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	for(x30a=9;x30a<=31;x30a++)
	{
		gotoxy(x30a,y30a);
		cout<<"X";
		if(x30a==20)
		{
			gotoxy(x30a,y30a);
			cout<<" ";
		}

	}
	//for(x30a=9;x30a<=31;x30a++) no need of this for loop
	//{
		if((x!=20)&&(y30a==22))
		{
			gotoxy(x,y);
			cout<<"*";
			//cout<<"\a";
			gotoxy(2,15);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
	//}

}
void obstacle30()
{
	if(o30==0){tpoints=tpoints+5000;o30++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	gotoxy(xa30,ya30);
	cout<<"^";
	gotoxy(xb30,yb30);
	cout<<"<";
	gotoxy(xc30,yc30);
	cout<<">";
	gotoxy(xd30,yd30);
	cout<<"v";
	gotoxy(xe30,ye30);
	cout<<"$";
	//@ will face foul when it will touch,component a,b,c,d or e
	if(((xa30==x)&&(ya30==y))||((xb30==x)&&(yb30==y))||
	((xc30==x)&&(yc30==y))||((xd30==x)&&(yd30==y)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";
		tf++;tpoints=tpoints-1000;
		delay(100);
	}
	if((xe30==x)&&(ye30==y))//for $ sign
	{
		if(be303132==0)
		{
			gotoxy(x,y);
			cout<<"*";
			cout<<"\a";
			gotoxy(2,15);
			cout<<"BONUS";
			//delay(100);
			be303132++;
			tb++;tpoints=tpoints+3000;
		}
	}

}
void obstacle31()
{
	if(o31==0){tpoints=tpoints+5000;o31++;}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	gotoxy(xa31,ya31);
	cout<<"^";
	gotoxy(xb31,yb31);
	cout<<"<";
	gotoxy(xc31,yc31);
	cout<<">";
	gotoxy(xd31,yd31);
	cout<<"v";
	gotoxy(xe31,ye31);
	cout<<"$";
	if(((xa31==x)&&(ya31==y))||((xb31==x)&&(yb31==y))||
	((xc31==x)&&(yc31==y))||((xd31==x)&&(yd31==y)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
	if((xe31==x)&&(ye31==y))//for $ sign
	{
		if(be303132==0)
		{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS";
		//delay(100);
		be303132++;
		tb++;tpoints=tpoints+3000;
		}
	}

}
void obstacle32()
{
	if(o32==0)
	{
		tpoints=tpoints+5000;
		o32++;
	}
	if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}
	gotoxy(xa32,ya32);
	cout<<"^";
	gotoxy(xb32,yb32);
	cout<<"<";
	gotoxy(xc32,yc32);
	cout<<">";
	gotoxy(xd32,yd32);
	cout<<"v";
	gotoxy(xe32,ye32);
	cout<<"$";
	if(((xa32==x)&&(ya32==y))||((xb32==x)&&(yb32==y))||
	((xc32==x)&&(yc32==y))||((xd32==x)&&(yd32==y)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
	if((xe32==x)&&(ye32==y))//for $ sign
	{
		if(be303132==0)
		{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS";
		//delay(100);
		be303132++;
		tb++;tpoints=tpoints+3000;
		}
	}

}

void ladder()
{
	for(xal=17;xal<=23;xal++)
	{
		gotoxy(xal,yal);
		cout<<"_";
		if((xal==17)||(xal==23))
		{
			gotoxy(xal,yal);
			cout<<"|";
		}

	}
	for(xbl=17;xbl<=23;xbl++)
	{
		gotoxy(xbl,ybl);
		cout<<"_";
		if((xbl==17)||(xbl==23))
		{
			gotoxy(xbl,ybl);
			cout<<"|";
		}

	}
	for(xcl=17;xcl<=23;xcl++)
	{
		gotoxy(xcl,ycl);
		cout<<"_";
		if((xcl==17)||(xcl==23))
		{
			gotoxy(xcl,ycl);
			cout<<"|";
		}

	}
	for(xdl=17;xdl<=23;xdl++)
	{
		gotoxy(xdl,ydl);
		cout<<"_";
		if((xdl==17)||(xdl==23))
		{
			gotoxy(xdl,ydl);
			cout<<"|";
		}

	}
	for(xel=17;xel<=23;xel++)
	{
		gotoxy(xel,yel);
		cout<<"_";
		if((xel==17)||(xel==23))
		{
			gotoxy(xel,yel);
			cout<<"|";
		}

	}
	gotoxy(xfl,yfl); //xfl=17
	cout<<"|";
	gotoxy((xfl+6),yfl);
	cout<<"|";
	int tn1ay=15,tn1by=12;
	for(int tn1ax=33;tn1ax<=80;tn1ax++) //for the tunnel on right side
	{
		gotoxy(tn1ax,tn1ay);
		cout<<"_";
	}
	for(int tn1bx=33;tn1bx<=80;tn1bx++) //for the tunnel on right side
	{
		gotoxy(tn1bx,tn1by);
		cout<<"_";
	}

}
void trolley2()
{
	gotoxy(t2xa,t2y);
	cout<<" ";
	gotoxy(t2xb,t2y);
	cout<<"_";
	gotoxy(t2xc,t2y);
	cout<<"_";
	gotoxy(t2xd,t2y);
	cout<<"_";
	gotoxy(t2xe,t2y);
	cout<<"_";
	gotoxy(t2xf,t2y);
	cout<<"_";
	gotoxy(t2xg,t2y);
	cout<<"_";
	gotoxy(t2xh,t2y);
	cout<<"_";
}
void basementtrolley()
{
	gotoxy(btxa,bty);
	cout<<" ";
	gotoxy(btxb,bty);
	cout<<"_";
	gotoxy(btxc,bty);
	cout<<"_";
	gotoxy(btxd,bty);
	cout<<"_";
	gotoxy(btxe,bty);
	cout<<"_";
	gotoxy(btxf,bty);
	cout<<"_";
	gotoxy(btxg,bty);
	cout<<"_";
	gotoxy(btxh,bty);
	cout<<"_";
}
void football()
{
	if(of==0)
	{
		tpoints=tpoints+20000;
		of++;
	}
	/*if((tpoints>75000)&&(r==0))
	{
		rocket();
		r++;
	}no rocket option in it*/
	gotoxy(fxa,fya);
	cout<<"<";
	gotoxy(fxb,fyb);
	cout<<"<";
	gotoxy(fxc,fyc);
	cout<<"^";
	gotoxy(fxd,fyb);
	cout<<">";
	gotoxy(fxe,fya);
	cout<<">";
	gotoxy(fxd,fyd);
	cout<<">";
	gotoxy(fxc,fye);
	cout<<"v";
	gotoxy(fxb,fyd);
	cout<<"<";
	if(((x==fxa)&&((y-1)==fya))||((x==fxb)&&((y-1)==fyb))||
	((x==fxc)&&((y-1)==fyc))||((x==fxd)&&((y-1)==fyb))||
	((x==fxe)&&((y-1)==fya))||((x==fxd)&&((y-1)==fyd))||
	((x==fxc)&&((y-1)==fye))||((x==fxb)&&((y-1)==fyd)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}

}
void football2()
{
	gotoxy(f2xa,f2ya);
	cout<<"<";
	gotoxy(f2xb,f2yb);
	cout<<"<";
	gotoxy(f2xc,f2yc);
	cout<<"^";
	gotoxy(f2xd,f2yb);
	cout<<">";
	gotoxy(f2xe,f2ya);
	cout<<">";
	gotoxy(f2xd,f2yd);
	cout<<">";
	gotoxy(f2xc,f2ye);
	cout<<"v";
	gotoxy(f2xb,f2yd);
	cout<<"<";
	if(((x==f2xa)&&((y-1)==f2ya))||((x==f2xb)&&((y-1)==f2yb))||
	((x==f2xc)&&((y-1)==f2yc))||((x==f2xd)&&((y-1)==f2yb))||
	((x==f2xe)&&((y-1)==f2ya))||((x==f2xd)&&((y-1)==f2yd))||
	((x==f2xc)&&((y-1)==f2ye))||((x==f2xb)&&((y-1)==f2yd)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
}
void football3() //it will never move,a stationary obstacle
{
	gotoxy(f3xa,f3ya);
	cout<<">";
	gotoxy(f3xb,f3yb);
	cout<<">";
	gotoxy(f3xc,f3yc);
	cout<<"v";
	gotoxy(f3xd,f3yb);
	cout<<"<";
	gotoxy(f3xe,f3ya);
	cout<<"<";
	gotoxy(f3xd,f3yd);
	cout<<"<";
	gotoxy(f3xc,f3ye);
	cout<<"^";
	gotoxy(f3xb,f3yd);
	cout<<">";
	gotoxy(40,12);
	cout<<"X";
	if(((x==f3xa)&&((y-1)==f3ya))||((x==f3xb)&&((y-1)==f3yb))||
	((x==f3xc)&&((y-1)==f3yc))||((x==f3xd)&&((y-1)==f3yb))||
	((x==f3xe)&&((y-1)==f3ya))||((x==f3xd)&&((y-1)==f3yd))||
	((x==f3xc)&&((y-1)==f3ye))||((x==f3xb)&&((y-1)==f3yd)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
	if((x==40)&&(y==12))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
}
void football4()
{
	gotoxy(f4xa,f4ya);
	cout<<"<";
	gotoxy(f4xb,f4yb);
	cout<<"<";
	gotoxy(f4xc,f4yc);
	cout<<"^";
	gotoxy(f4xd,f4yb);
	cout<<">";
	gotoxy(f4xe,f4ya);
	cout<<">";
	gotoxy(f4xd,f4yd);
	cout<<">";
	gotoxy(f4xc,f4ye);
	cout<<"v";
	gotoxy(f4xb,f4yd);
	cout<<"<";
	if(((x==f4xa)&&((y-1)==f4ya))||((x==f4xb)&&((y-1)==f4yb))||
	((x==f4xc)&&((y-1)==f4yc))||((x==f4xd)&&((y-1)==f4yb))||
	((x==f4xe)&&((y-1)==f4ya))||((x==f4xd)&&((y-1)==f4yd))||
	((x==f4xc)&&((y-1)==f4ye))||((x==f4xb)&&((y-1)==f4yd)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}

}
void football5()
{
	gotoxy(f5xa,f5ya);
	cout<<"<";
	gotoxy(f5xb,f5yb);
	cout<<"<";
	gotoxy(f5xc,f5yc);
	cout<<"^";
	gotoxy(f5xd,f5yb);
	cout<<">";
	gotoxy(f5xe,f5ya);
	cout<<">";
	gotoxy(f5xd,f5yd);
	cout<<">";
	gotoxy(f5xc,f5ye);
	cout<<"v";
	gotoxy(f5xb,f5yd);
	cout<<"<";
	if(((x==f5xa)&&((y-1)==f5ya))||((x==f5xb)&&((y-1)==f5yb))||
	((x==f5xc)&&((y-1)==f5yc))||((x==f5xd)&&((y-1)==f5yb))||
	((x==f5xe)&&((y-1)==f5ya))||((x==f5xd)&&((y-1)==f5yd))||
	((x==f5xc)&&((y-1)==f5ye))||((x==f5xb)&&((y-1)==f5yd)))
	{
		gotoxy(x,y);
		cout<<"*";
		cout<<"\a";
		gotoxy(2,15);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}

}

void c2frame()
{
			for(rtyb=5,ltyb=5;rtyb<=20,ltyb<=20;ltyb++,rtyb++)
			{
				gotoxy(52,rtyb);//horozontal limit: 1 to 80
				cout<<".";
				gotoxy(28,ltyb);
				cout<<".";
			}
			for(upxb=28,dnxb=28;upxb<=52,dnxb<=52;upxb++,dnxb++)
			{

				gotoxy(upxb,5);//vertical limit: 5 to 25
				cout<<".";
				gotoxy(dnxb,20);
				cout<<".";
			}
			for(upxb=39;upxb<=42;upxb++)
			{

				gotoxy(upxb,5);//to make a gate on the frame
				cout<<" ";
			}
			for(rtyb=5,ltyb=5;rtyb>=1,ltyb>=1;ltyb--,rtyb--)
			{
				gotoxy(42,rtyb);//horozontal limit: 1 to 80
				cout<<"|";
				gotoxy(39,ltyb);
				cout<<"|";
			}/*to make an exit pipe which will take '@' to the next chamber
			   when x is 40 or 41*/

}
void finalobstacle()
{
	for(i=21;i<=25;i++)
	{
		gotoxy(i,18);
		cout<<"T";
	}
	for(i=21;i<=25;i++)
	{
		gotoxy(i,17);
		cout<<"|";
	}                    //       *
	for(i=21;i<=25;i++)  //     *   *
	{                    //    *   ^ *
		gotoxy(i,16);//    | @ @ |
		cout<<"^";   //    |-----|
	}

	for(i=1;i<=80;i++)
	{
		gotoxy(i,19);//to create a road
		cout<<"_";
	}

}
void finalpipe()
{
	for(i=1;i<=15;i++)
	{
		gotoxy(8,i);
		cout<<"|";
		gotoxy(2,i);
		cout<<"|";
	}
}
/*void down()
{

	clrscr();
	obstacle();
	y1--;
	if(y1==0)
	{
		y1=25;
	}
} */
void right()
{
	if((170-((t1 - start) / CLK_TCK))<=0)
	{
		for(i=1,j=70;i<70;i++,j--)
		{
			gotoxy(i,6);
			cout<<" TIME UP";
			gotoxy(j,18);
			cout<<"TIME UP ";
			gotoxy(35,12);
			cout<<"GAME OVER";
			delay(50);
		}
		getch();
		exit(0);
	}
	if(phase!=7)
	{
		if(x==31)
		{
			gotoxy(x,y);
			cout<<" ";
			x=9;
		}
		else
		{
			x++;
			gotoxy(x-1,y);
			cout<<" ";
		}
		gotoxy(47,11);
		cout<<"Total Points: ";
		gotoxy(61,11);
		cout<<tpoints;
		gotoxy(47,13);
		cout<<"Bonus taken: ";
		gotoxy(61,13);
		cout<<tb;
		gotoxy(47,15);
		cout<<"Fouls done: ";
		gotoxy(61,15);
		cout<<tf;
	}
	else //for the chamber
	{
		if(x==52)
		{
		gotoxy(x,y);
		cout<<" ";
		x=29;
		}
		else
		{
		x++;
		gotoxy(x-1,y);
		cout<<" ";

		}
		gotoxy(30,22);
		cout<<"Total Points: ";
		gotoxy(44,22);
		cout<<tpoints;
		gotoxy(30,23);
		cout<<"Bonus taken: ";
		gotoxy(44,23);
		cout<<tb;
		gotoxy(30,24);
		cout<<"Fouls done: ";
		gotoxy(44,24);
		cout<<tf;
	}
	if((x==9)&&(y==22)&&(yb18==22)) //used in ob18
	{
		gotoxy(x,y-1);
		cout<<"_";
	}
	if(y1==23)
	{
	    for(x1=18;x1<=23;x1++)
	    if((x1%2==0)&&(x1==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000000;
	    }
	}
	if(y2==23)
	{
	    for(x2=12;x2<=28;x2++)
	    if((x2%2!=0)&&(x2==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y3==23)
	{
	    for(x3=10;x3<=31;x3++)
	    if((x3%5==0)&&(x3==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y4==23)
	{
	    for(x4=12;x4<=28;x4++)
	    if((x4%2==0)&&(x4==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(ya5==23)
	{
	    if((xa5==x)||(xb5==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y6==23)
	{
	    if(x==26)//$ reches at y cordinate 23 when its x is 26
	    {
		if(bo6==0)
		{
			cout<<"\a";
			gotoxy(35,12);
			cout<<"BONUS";
			bo6++;
			tb++;tpoints=tpoints+3000;
		}
	    }
	}
	if(((x7-1)==x)&&((ya7==23)||(yb7==23)||(yc7==23)||(yd7==23)||(ye7==23)))
	{
		gotoxy(x,y);
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
	if(((x8+1)==x)&&((ya8==23)||(yb8==23)||(yc8==23)||(yd8==23)||(ye8==23)))
	{
		gotoxy(x,y);
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
	/*here one of them among ya8 or yb8....... will always remain 23
	to remuv this ambiguity some editing is done in void up function */
	if(y9==23)
	{
	    for(x9=10;x9<=28;x9++)
	    if((x9%2==0)&&(x9==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y10==23)
	{
		for(x10=15;x10<=25;x10++)
		if(x10==x)
		{
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		}
	}

	if(ya11==24)
	{
		if((x!=17)&&(x!=18)&&(x!=19)&&(x!=20)&&(x!=21)&&(x!=22)&&(x!=23))
		{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);

		}


	}
	if(y12==23)
	{
	    if(x%2==0)
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y13==23)
	{
		for(x13=9;x13<=31;x13++)
		{
			gotoxy(x13,y13);
			if((x==x13)&&(x13%2!=0))
			{
				cout<<"\a";
				gotoxy(35,12);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			}
		}
	}
	if((ya14==y)||(yb14==y)||(yc14==y)||(yd14==y)||(ye14==y)||(yf14==y)||(yg14==y))
		{
			if((x14-4)==x)
			{
				if(b14==0)
				{
					gotoxy(x,y);
					//cout<<"*";
					cout<<"\a";
					gotoxy(35,12);
					cout<<"BONUs";
					tb++;tpoints=tpoints+3000;
					b14++;
					delay(200);
				}
			}
		}
	if(y15==24) //as y15 gets an inc of 2, so at y=22, y15 will not be 22, it will be 24
	{
		for(x15=10;x15<=31;x15++)
		{

			if(x==x15)
			{
			if((x%2==0)||(x%3==0))
			{
				gotoxy(35,12);
				cout<<"\a";
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			}
			}
		}
	}
	if(y16==24)
	{
	    for(x16=12;x16<=28;x16++)
	    if((x16%2==0)&&(x16==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y17==23)
	{
		for(x17=9;x17<=31;x17++)
		{
			if(x17!=31)
			{
				if(x==x17)
				{
					gotoxy(35,12);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
				}
			}
		}
	}
	if(y17b==23)
	{
		for(x17b=9;x17b<=31;x17b++)
		{
			if(x17b%2==0)
			{
				if(x17b==x)
				{
					gotoxy(35,12);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
				}
			}
		}
	}
	if(ya18==23)
	{
		if(x!=20)
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if(yb18==23)
	{
		if(x!=31)
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if(y19==23)
	{
	    if(x%2==0)
	    {
		//M will be encountered by '@'
			//gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;

	    }
	}
	if(((x20-1)==x)&&((ya20==23)||(yb20==23)||(yc20==23)||(yd20==23)||(ye20==23)||(yf20==23)||(yg20==23)))
	{
		gotoxy(x,y);
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
	if(((x21+1)==x)&&((ya21==23)||(yb21==23)||(yc21==23)||(yd21==23)||(ye21==23)||(yf21==23)||(yg21==23)))
	{
		gotoxy(x,y);
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
	if(y22==19)//the '@' and obs22 will meet at y18=18 but due to inc in void up fn
	// y18 will be 19 at the tym of conciding
	{
	    if(x%2==0)
	    {
		//M will be encountered by '@'
			//gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;

	    }
	}
	if((ya23==5)&&(y==5))/*ya23=5 and when '@' reaches there,
	its y cordinate is 6  */
	{
		if((x!=18)&&(x!=19)&&(x!=20)&&(x!=21)&&(x!=22))
		{
			gotoxy(35,12);
			cout<<"fOUL";
			cout<<"\a";
		}
	}
	if((yb23==6)&&(y==6))
	{
		if((x!=11)&&(x!=14)&&(x!=17)&&(x!=20)&&(x!=23)&&(x!=26)&&(x!=29))
		{
		//no need of any statement
		}
		else
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yc23==7)&&(y==7))
	{
		if((x!=11)&&(x!=14)&&(x!=17)&&(x!=20)&&(x!=23)&&(x!=26)&&(x!=29))
		{

		}
		else
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yd23==9)&&(y==9))
	{
		if((x!=16)&&(x!=17)&&(x!=22)&&(x!=20)&&(x!=23))
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((ye23==11)&&(y==11))
	{
		if((x!=12)&&(x!=13)&&(x!=27)&&(x!=28))
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yf23==13)&&(y==13))
	{
		if((x!=17)&&(x!=18)&&(x!=19)&&(x!=20)&&(x!=21))
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yg23==15)&&(y==15))
	{
		if((x!=13)&&(x!=14)&&(x!=19)&&(x!=20)&&(x!=21)&&(x!=26)&&(x!=27))
		{

			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((x%3==0)&&(y24==23))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
 /*	if(((y29-1)==y)&&(y27>=11)&&(y27<=18))//foul is must in this obstacle
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}  */

	if(((xa28+1)==x)&&(y28==y)&&(phase==4))
	{
		if(ba28==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS:)";
		delay(100);
		ba28++;
		}
	}
	if(((xb28+1)==x)&&(y28==y)&&(phase==4))
	{
		if(bb28==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS:)";
		delay(100);
		bb28++;
		}
	}
	if(((xc28+1)==x)&&(y28==y)&&(phase==4))
	{
		if(bc28==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS:)";
		delay(100);
		bc28++;
		}
	}
	if(((xd28+1)==x)&&(y28==y)&&(phase==4))
	{
		if(bd28==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS:)";
		delay(100);
		bd28++;
		}
	}
	if((y30a==22)&&(x!=20))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
	if(((xa32==x)&&(ya32==y))||((xb32==x)&&(yb32==y))||
	((xc32==x)&&(yc32==y))||((xd32==x)&&(yd32==y)))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(100);
	}
	if((xe32==x)&&(ye32==y))//for $ sign
	{
		if(be303132==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS";
		//delay(100);
		be303132++;
		}
	}
	if(((xa31==x)&&(ya31==y))||((xb31==x)&&(yb31==y))||
	((xc31==x)&&(yc31==y))||((xd31==x)&&(yd31==y)))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(100);
	}
	if((xe31==x)&&(ye31==y))//for $ sign
	{
		if(be303132==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS";
		//delay(100);
		be303132++;
		}
	}
	if(((xa30==x)&&(ya30==y))||((xb30==x)&&(yb30==y))||
	((xc30==x)&&(yc30==y))||((xd30==x)&&(yd30==y)))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(100);
	}
	if((xe30==x)&&(ye30==y))//for $ sign
	{
		if(be303132==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS";
		//delay(100);
		be303132++;
		}
	}
		if((((x==fxa)&&((y-0)==fya))||((x==fxb)&&((y-0)==fyb))||
		((x==fxc)&&((y-0)==fyc))||((x==fxd)&&((y-0)==fyb))||
		((x==fxe)&&((y-0)==fya))||((x==fxd)&&((y-0)==fyd))||
		((x==fxc)&&((y-0)==fye))||((x==fxb)&&((y-0)==fyd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(75,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
		if((((x==f2xa)&&((y-0)==f2ya))||((x==f2xb)&&((y-0)==f2yb))||
		((x==f2xc)&&((y-0)==f2yc))||((x==f2xd)&&((y-0)==f2yb))||
		((x==f2xe)&&((y-0)==f2ya))||((x==f2xd)&&((y-0)==f2yd))||
		((x==f2xc)&&((y-0)==f2ye))||((x==f2xb)&&((y-0)==f2yd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}

		if((((x==f3xa)&&((y-0)==f3ya))||((x==f3xb)&&((y-0)==f3yb))||
		((x==f3xc)&&((y-0)==f3yc))||((x==f3xd)&&((y-0)==f3yb))||
		((x==f3xe)&&((y-0)==f3ya))||((x==f3xd)&&((y-0)==f3yd))||
		((x==f3xc)&&((y-0)==f3ye))||((x==f3xb)&&((y-0)==f3yd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
		if((x==40)&&(y==12)&&(fxa==29)&&(phase==5))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
		if((((x==f4xa)&&((y-0)==f4ya))||((x==f4xb)&&((y-0)==f4yb))||
		((x==f4xc)&&((y-0)==f4yc))||((x==f4xd)&&((y-0)==f4yb))||
		((x==f4xe)&&((y-0)==f4ya))||((x==f4xd)&&((y-0)==f4yd))||
		((x==f4xc)&&((y-0)==f4ye))||((x==f4xb)&&((y-0)==f4yd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
		if((((x==f5xa)&&((y-0)==f5ya))||((x==f5xb)&&((y-0)==f5yb))||
		((x==f5xc)&&((y-0)==f5yc))||((x==f5xd)&&((y-0)==f5yb))||
		((x==f5xe)&&((y-0)==f5ya))||((x==f5xd)&&((y-0)==f5yd))||
		((x==f5xc)&&((y-0)==f5ye))||((x==f5xb)&&((y-0)==f5yd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}



}
void left()
{
	if((170-((t1 - start) / CLK_TCK))<=0)
	{
		for(i=1,j=70;i<70;i++,j--)
		{
			gotoxy(i,6);
			cout<<" TIME UP";
			gotoxy(j,18);
			cout<<"TIME UP ";
			gotoxy(35,12);
			cout<<"GAME OVER";
			delay(50);
		}
		getch();
		exit(0);
	}
	if(phase!=7)
	{
		if(x==9)
		{
			gotoxy(x,y);
			cout<<" ";
			x=31;
		}
		else
		{
			x--;
			gotoxy(x+1,y);
			cout<<" ";
		}
		gotoxy(47,11);
		cout<<"Total Points: ";
		gotoxy(61,11);
		cout<<tpoints;
		gotoxy(47,13);
		cout<<"Bonus taken: ";
		gotoxy(61,13);
		cout<<tb;
		gotoxy(47,15);
		cout<<"Fouls done: ";
		gotoxy(61,15);
		cout<<tf;
	}
	else //pahse=7 means chamber is present
	{
		if(x==29)
		{
			gotoxy(x,y);
			cout<<" ";
			x=52;
		}
		else
		{
			x--;
			gotoxy(x+1,y);
			cout<<" ";
		}
		gotoxy(30,22);
		cout<<"Total Points: ";
		gotoxy(44,22);
		cout<<tpoints;
		gotoxy(30,23);
		cout<<"Bonus taken: ";
		gotoxy(44,23);
		cout<<tb;
		gotoxy(30,24);
		cout<<"Fouls done: ";
		gotoxy(44,24);
		cout<<tf;

	}
	if((x==9)&&(y==22)&&(yb18==22)) //used in ob18
	{
		gotoxy(x,y-1);
		cout<<"_";
	}
	if(y1==23)
	{
	    for(x1=18;x1<=23;x1++)
	    if((x1%2==0)&&(x1==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y2==23)
	{
	    for(x2=12;x2<=28;x2++)
	    if((x2%2!=0)&&(x2==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y3==23)
	{
	    for(x3=10;x3<=31;x3++)
	    if((x3%5==0)&&(x3==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y4==23)
	{
	    for(x4=12;x4<=28;x4++)
	    if((x4%2==0)&&(x4==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(ya5==23)
	{
	    if((xa5==x)||(xb5==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y6==23)
	{
	    if(x==26)
	    {
		if(bo6==0)
		{
			cout<<"\a";
			gotoxy(35,12);
			cout<<"BONUS";
			bo6++;
			tb++;tpoints=tpoints+3000;
		}
	    }
	}
	if(((x7-1)==x)&&((ya7==23)||(yb7==23)||(yc7==23)||(yd7==23)||(ye7==23)))
	{
		gotoxy(x,y);
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
	if(((x8+1)==x)&&((ya8==23)||(yb8==23)||(yc8==23)||(yd8==23)||(ye8==23)))
	{
		gotoxy(x,y);
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
	if(y9==23)
	{
		for(x9=10;x9<=28;x9++)
		if((x9%2==0)&&(x9==x))
		{
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		}
	}
	if(y10==23)
	{
		for(x10=15;x10<=25;x10++)
		if(x10==x)
		{
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		}
	}
	if(ya11==24)
	{
		if((x!=17)&&(x!=18)&&(x!=19)&&(x!=20)&&(x!=21)&&(x!=22)&&(x!=23))
		{
				gotoxy(x,y);
				cout<<"*";
				cout<<"\a";
				gotoxy(2,15);
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
				//delay(200);

		}


	}
	if(y12==23)
	{
	    if(x%2==0)
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y13==23)
	{
		for(x13=9;x13<=31;x13++)
		{
			gotoxy(x13,y13);
			if((x==x13)&&(x13%2!=0))
			{
				gotoxy(35,12);
				cout<<"\a";
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			}
		}
	}
	if((ya14==y)||(yb14==y)||(yc14==y)||(yd14==y)||(ye14==y)||(yf14==y)||(yg14==y))
	{
		if((x14-4)==x)
		{
			if(b14==0)
			{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(35,12);
			cout<<"BONUS";
			tb++;
			tpoints=tpoints+3000;
			b14++;
			delay(200);
			}
		}
	}
	if(y15==24) //as y15 gets an inc of 2, so at y=22, y15 will not be 22, it will be 24
	{
		for(x15=10;x15<=31;x15++)
		{

			if(x==x15)
			{
			if((x%2==0)||(x%3==0))
			{
				gotoxy(35,12);
				cout<<"\a";
				cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			}
			}
		}
	}
	if(y16==24)
	{
	    for(x16=12;x16<=28;x16++)
	    if((x16%2==0)&&(x16==x))
	    {
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
	    }
	}
	if(y17==23)
	{
		for(x17=9;x17<=31;x17++)
		{
			if(x17!=31)
			{
				if(x==x17)
				{
					gotoxy(35,12);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
				}
			}
		}
	}
	if(y17b==23)
	{
		for(x17b=9;x17b<=31;x17b++)
		{
			if(x17b%2==0)
			{
				if(x17b==x)
				{
					gotoxy(35,12);
					cout<<"FOUL ";tf++;tpoints=tpoints-1000;
					gotoxy(x,y);
					cout<<"*";
					cout<<"\a";
				}
			}
		}
	}
	if(ya18==23)
	{
		if(x!=20)
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if(yb18==23)
	{
		if(x!=31)
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if(y19==23)
	{
	    if(x%2==0)
	    {
		//M will be encountered by '@'
			//gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;

	    }
	}
	if(((x20-1)==x)&&((ya20==23)||(yb20==23)||(yc20==23)||(yd20==23)||(ye20==23)||(yf20==23)||(yg20==23)))
	{
		gotoxy(x,y);
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
	if(((x21+1)==x)&&((ya21==23)||(yb21==23)||(yc21==23)||(yd21==23)||(ye21==23)||(yf21==23)||(yg21==23)))
	{
		gotoxy(x,y);
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(200);
	}
	if(y22==19)//the '@' and obs22 will meet at y18=18 but due to inc in void up fn
	// y18 will be 19 at the tym of conciding
	{
	    if(x%2==0)
	    {
		//M will be encountered by '@'
			//gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;

	    }
	}
	if((ya23==5)&&(y==5))/*ya23=5 and when '@' reaches there,
	its y cordinate is 6  */
	{
		if((x!=18)&&(x!=19)&&(x!=20)&&(x!=21)&&(x!=22))
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yb23==6)&&(y==6))
	{
		if((x!=11)&&(x!=14)&&(x!=17)&&(x!=20)&&(x!=23)&&(x!=26)&&(x!=29))
		{

		}
		else
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yc23==7)&&(y==7))
	{
		if((x!=11)&&(x!=14)&&(x!=17)&&(x!=20)&&(x!=23)&&(x!=26)&&(x!=29))
		{

		}
		else
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yd23==9)&&(y==9))
	{
		if((x!=16)&&(x!=17)&&(x!=22)&&(x!=20)&&(x!=23))
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((ye23==11)&&(y==11))
	{
		if((x!=12)&&(x!=13)&&(x!=27)&&(x!=28))
		{
			gotoxy(5,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yf23==13)&&(y==13))
	{
		if((x!=17)&&(x!=18)&&(x!=19)&&(x!=20)&&(x!=21))
		{
			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((yg23==15)&&(y==15))
	{
		if((x!=13)&&(x!=14)&&(x!=19)&&(x!=20)&&(x!=21)&&(x!=26)&&(x!=27))
		{

			gotoxy(35,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			cout<<"\a";
		}
	}
	if((x%3==0)&&(y24==23))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
	/*if(((y29-1)==y)&&(y27>=9)&&(y27<=18))//foul is must in this obstacle
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	} */

	if(((xa28+1)==x)&&(y28==y)&&(phase==4))
	{
		if(ba28==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS:)";
		delay(100);
		ba28++;
		}
	}
	if(((xb28+1)==x)&&(y28==y)&&(phase==4))
	{
		if(bb28==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS:)";
		delay(100);
		bb28++;
		}
	}
	if(((xc28+1)==x)&&(y28==y)&&(phase==4))
	{
		if(bc28==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS:)";
		delay(100);
		bc28++;
		}
	}
	if(((xd28+1)==x)&&(y28==y)&&(phase==4))
	{
		if(bd28==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS:)";
		delay(100);
		bd28++;
		}
	}
	if((y30a==22)&&(x!=20))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		delay(100);
	}
	if(((xa32==x)&&(ya32==y))||((xb32==x)&&(yb32==y))||
	((xc32==x)&&(yc32==y))||((xd32==x)&&(yd32==y)))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(100);
	}
	if((xe32==x)&&(ye32==y))//for $ sign
	{
		if(be303132==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS";
		//delay(100);
		be303132++;
		}
	}
	if(((xa31==x)&&(ya31==y))||((xb31==x)&&(yb31==y))||
	((xc31==x)&&(yc31==y))||((xd31==x)&&(yd31==y)))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(100);
	}
	if((xe31==x)&&(ye31==y))//for $ sign
	{
		if(be303132==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS";
		//delay(100);
		be303132++;
		}
	}
	if(((xa30==x)&&(ya30==y))||((xb30==x)&&(yb30==y))||
	((xc30==x)&&(yc30==y))||((xd30==x)&&(yd30==y)))
	{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"FOUL ";tf++;tpoints=tpoints-1000;
		//delay(100);
	}
	if((xe30==x)&&(ye30==y))//for $ sign
	{
		if(be303132==0)
		{
		gotoxy(x,y);
		//cout<<"*";
		cout<<"\a";
		gotoxy(35,12);
		cout<<"BONUS";
		//delay(100);
		be303132++;
		}
	}
		if((((x==fxa)&&((y-0)==fya))||((x==fxb)&&((y-0)==fyb))||
		((x==fxc)&&((y-0)==fyc))||((x==fxd)&&((y-0)==fyb))||
		((x==fxe)&&((y-0)==fya))||((x==fxd)&&((y-0)==fyd))||
		((x==fxc)&&((y-0)==fye))||((x==fxb)&&((y-0)==fyd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(75,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
		if((((x==f2xa)&&((y-0)==f2ya))||((x==f2xb)&&((y-0)==f2yb))||
		((x==f2xc)&&((y-0)==f2yc))||((x==f2xd)&&((y-0)==f2yb))||
		((x==f2xe)&&((y-0)==f2ya))||((x==f2xd)&&((y-0)==f2yd))||
		((x==f2xc)&&((y-0)==f2ye))||((x==f2xb)&&((y-0)==f2yd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}

		if((((x==f3xa)&&((y-0)==f3ya))||((x==f3xb)&&((y-0)==f3yb))||
		((x==f3xc)&&((y-0)==f3yc))||((x==f3xd)&&((y-0)==f3yb))||
		((x==f3xe)&&((y-0)==f3ya))||((x==f3xd)&&((y-0)==f3yd))||
		((x==f3xc)&&((y-0)==f3ye))||((x==f3xb)&&((y-0)==f3yd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
		if((x==40)&&(y==12)&&(fxa==29)&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
		if((((x==f4xa)&&((y-0)==f4ya))||((x==f4xb)&&((y-0)==f4yb))||
		((x==f4xc)&&((y-0)==f4yc))||((x==f4xd)&&((y-0)==f4yb))||
		((x==f4xe)&&((y-0)==f4ya))||((x==f4xd)&&((y-0)==f4yd))||
		((x==f4xc)&&((y-0)==f4ye))||((x==f4xb)&&((y-0)==f4yd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;tpoints=tpoints-1000;
			delay(100);
		}
		if((((x==f5xa)&&((y-0)==f5ya))||((x==f5xb)&&((y-0)==f5yb))||
		((x==f5xc)&&((y-0)==f5yc))||((x==f5xd)&&((y-0)==f5yb))||
		((x==f5xe)&&((y-0)==f5ya))||((x==f5xd)&&((y-0)==f5yd))||
		((x==f5xc)&&((y-0)==f5ye))||((x==f5xb)&&((y-0)==f5yd)))&&(phase==7))
		{
			gotoxy(x,y);
			//cout<<"*";
			cout<<"\a";
			gotoxy(70,12);
			cout<<"FOUL ";tf++;
			tpoints=tpoints-1000;
			delay(100);
		}





}
void up()
{

	clrscr();
	t1=clock();
	//delay(75);
	if((phase!=4)&&(phase!=6)&&(phase!=7)&&(phase!=8))
	{
		gotoxy(x,y+1);
		cout<<"@";
	}
	if((phase!=7)&&(phase!=6))//chamber1 is not present
	{
		for(rtyb=1,ltyb=1;rtyb<=25,ltyb<=25;ltyb++,rtyb++)
		{
			gotoxy(32,rtyb);
			cout<<"|";
			gotoxy(8,ltyb);
			cout<<"|";
		}
		scoreboard();
	}
	if((phase==7)||(phase==6))
	{
		chamberscoreboard();
	}
	kc24=tmpc24;
	for(j=0;j<12;j++) //used for c2
	{
		xc24b[j]=kc24;
		kc24++;
	}
	kcb24=tmpbc24;
	for(j=0;j<12;j++) //used for c2
	{
		xc24[j]=kcb24;
		kcb24--;
	}


	switch(phase)
	{
	case 1:

	if(y1<=25)//all first 3 obst will appear
	{
		obstacle1();
		obstacle2();
		obstacle3();
		y1++;
		y2++;
		y3++;

	} //y1 will disappear


	else  //o3 and o6 cant be seen togather
	{

		if(y2<=25) //o2 and o3 will appear
		{
			obstacle2();
			obstacle3();
			y2++;
			y3++;
		}
		else //o2 will disappear and o3 will appear
		{
			if(y3<=15) //only o3 will appear
			{
				obstacle3();
				y3++;
			}
			else if((y3>=15)&&(y3<25)) //o3 and o4 will appear through this loop
			{
				obstacle3();
				y3++;
				if(y4<=8)//only o3 and o4
				{
					obstacle4();
					y4++;
				}
				else if((y4>=8)&&(y4<25))//o3,o4 and o5 will appear
				{
					obstacle4();
					y4++;
					if(ya5<=25)
					{
						obstacle5();
						ya5++;
						yb5++;
					}
				}
				/*else THIS MEANS:when y4 is greater than 25(which is not possible since
				till now y3 is less than 25
				{
					if(ya5<=25)//only o5 will appear
					{
						obstacle5();
						ya5++;
						yb5++;
					}
				}no need of this loop becoz if y3 is less than 25 then
				 y4 will surely be less than 25
				 */
			}
			else//y3 is greater then 25 so o3 will disappear
			{
				if(y4<25)//y4 will appear
				{
					obstacle4();
					y4++;
				}
				if(ya5<25) //y5 will appear
				{
					if(ya5<=12)
					{
						obstacle5();
						ya5++;
						yb5++;
					}
					else if((ya5>=12)&&(ya5<25))
					{
						obstacle5();
						ya5++;
						yb5++;
						obstacle6();
						y6++;
					}
				}
				//this else will be executed when o5 will disappear
				else//o7 and o5 will never be togather
				{
					if(y6<25)//for approx 3 cordinates, o6,o7 and o8 will appear togather
					{
						obstacle6();
						y6++;
						obstacle7();
						ya7++;yb7++;yc7++;yd7++;ye7++;
						if(x7<=28)
						{

							x7++;
						}
						/*else
						{
							x7=12;
							obstacle7();
						}        */
						if(ye7>=20)//now o8 will also appear
						{
							//x8=26;
							obstacle8();
							ya8++;yb8++;yc8++;yd8++;ye8++;
							if(x8>=12)
							{

								x8--;
							}
							/*else
							{
								x8=26;
								obstacle8();
							}  */
						}
					}
					else //o6 is disappeared
					{
						if(ye7<25)//now o7 and o8 will appear
						{
							obstacle7();
							ya7++;yb7++;
							yc7++;yd7++;ye7++;
							if(x7<=28)
							{

								x7++;
							}
							/*else
							{
								x7=12;
								obstacle7();
							}       */
							obstacle8();
							ya8++;yb8++;yc8++;yd8++;ye8++;

							if(x8>=12)
							{

								x8--;
							}
							/*else
							{
								x8=26;
								obstacle8();
							} */

						} //now o7 has dissappeared as ye7 is now greater than 25
						else//o8 will appear with o9
						{
							ya7=yb7=yc7=yd7=ye7=25;//A DOUBT: ONLY 25 CAN BE USED?
							if(ye8<16)//till ye8 is less than 16. o9 will not appear
							{
								obstacle8();
								ya8++;yb8++;yc8++;yd8++;ye8++;

								if(x8>=12)
								{
									//obstacle8();
									x8--;
								}
								/*else
								{
									x8=26;
									obstacle8();
								} */
							}
							else if((ye8>=16)&&(ye8<25))//now ye8 is greater than 16, both o8 and o9 will appear
							{
								obstacle8();
								ya8++;yb8++;yc8++;yd8++;ye8++;

								if(x8>=12)
								{
									//obstacle8();
									x8--;
								}
								else
								/*{
									x8=26;
									obstacle8();
								}*/
								obstacle9();
								y9++;
							}
							else//now there will be no o8 as now ye8 is greater then 25
							{
								ya8=yb8=yc8=yd8=ye8=25;//and not 23
								if(y9<25)  //only o9 will appear

								{
									if(y9<=16)
									{
										obstacle9();
										y9++;
									}
									else
									{
										obstacle9();
										y9++;
										comment1();
										if(cx1%2==0)
										cy1++;

									}

								}
								else //only comment 1 will appear
								{
									if(cx1<=26)
									{
										comment1();
										cy1++;
										if(cx1%2==0)
										cy1++;
									}
									else//none of the obstacles from o1 to o9 will appear
									phase++;
								}
							}

					}

				}
			}

		}

	}

	break;
	case 2:
	/*ko17=9;
	for(j=0;j<23;j++) //used for o17
	{
		x17[j]=ko17;
		ko17++;
	}*/
	kc2=tmpc2;
	for(j=0;j<12;j++) //used for c2
	{
		xc2b[j]=kc2;
		kc2++;
	}
	kcb2=tmpbc2;
	for(j=0;j<12;j++) //used for c2
	{
		xc2[j]=kcb2;
		kcb2--;
	}
	if(y10<=25)//paste in case 2;
	{
		if(y10<=12)//only o10 will appear
		{
			obstacle10();
			y10++;
		}
		else//both o10 and o11 will appear
		{
			obstacle10();
			y10++;
			obstacle11();
			ya11++;
		}
	}
	else//o10 will disappear
	{
		if(ya11<25)
		{

			if(ya11>10)//both o11 and o12will appear
			{
				obstacle11();
				ya11=ya11+2;
				obstacle12();
				y12=y12+1;
			}
			else //only obst11 will appear
			{
				obstacle11();
				ya11=ya11+2;
			}
		}
		else//o11 will not appear
		{
				if(y12<25)
				{
					obstacle12();
					y12=y12+1;
					if(y12>12) //both o12 and o13 will appear
					{
						obstacle13();
						y13++;
					}
				}
				else//o12 will disappear
				{
					if(y13<25)
					{
						if(y13<16)//only 13 will appear
						{
							obstacle13();
							y13=y13+3;
						}
						else
						{       obstacle13();
							y13++;


							ya14=ya14+1;yb14=yb14+1;
							yc14=yc14+1;yd14=yd14+1;ye14=ye14+1;
							yf14=yf14+1;yg14=yg14+1;

							if(yg14<=16)
							{
								obstacle14();
								x14=x14+4;
							}
							else if((yg14>16)&&(x14>=13))
							{
								obstacle14();
								x14=x14-4;

							}

						}
					}
					else//o13 will disappear
					{





						if(yg14<25)//o14 will appear
						{
							if(yg14<18)//only o14 will appear
							{
								ya14=ya14+1;yb14=yb14+1;
								yc14=yc14+1;yd14=yd14+1;ye14=ye14+1;
								yf14=yf14+1;yg14=yg14+1;
								if(yg14<=20)// for horizontal movement of o14
								{
									obstacle14();
									x14=x14-4;
								}
								else  // for horizontal movement of o14

								{
									obstacle14();
									x14=x14+4;
								}

							}

							else if((yg14>=18)&&(yg14<=19))//o14 and o15 will appear
							{

								ya14=ya14+1;yb14=yb14+1;
								yc14=yc14+1;yd14=yd14+1;ye14=ye14+1;
								yf14=yf14+1;yg14=yg14+1;
								if(yg14<=20)
								{
									obstacle14();
									x14=x14-4;
								}
								else if((yg14>20)&&(yg14<25))

								{
									obstacle14();
									x14=x14+4;
								}
								obstacle15();
								y15=y15+2;

							}
							else//yg14 is greater than 19, now o14, o15 and o16 will appear
							{

								ya14=ya14+1;yb14=yb14+1;
								yc14=yc14+1;yd14=yd14+1;ye14=ye14+1;
								yf14=yf14+1;yg14=yg14+1;
								if(yg14<=20)
								{
									obstacle14();
									x14=x14-4;
								}
								else if((yg14>20)&&(yg14<25))

								{
									obstacle14();
									x14=x14+4;
									//yb14=ya14=yc14=yd14=ye14=yf14=yg14=25;
								}
								obstacle15();
								y15=y15+2;
								obstacle16();
								y16=y16+2;

							}
						}
						else//o14 will disappear
						{
							yb14=ya14=yc14=yd14=ye14=yf14=yg14=25;
							if(y15<25)//both o15 and o16 will appear
							{
								obstacle15();
								y15=y15+2;
								obstacle16();
								y16=y16+2;
								//cout<<y16; at 15
								if(y16>=12)//o17 will also appear
								{
									obstacle17();
									y17=y17++; //at y17=9.
									if(y17>=6)
									{
										obstacle17b();
										y17b++;

									}

								}
							}
							else//o15 will disappear
							{
								if(y16<25)
								{
									obstacle16();
									y16=y16+2;
									//	cout<<y16;
									if(y16>=15)//y17 will also appear
									{
										if(y17<25)
										{
											obstacle17();
											y17=y17+1;
										}
										if(y17>=6)
										{
											obstacle17b();
											y17b++;

										}
									}
								}
								else//o16 will disappear
								{
									if(y17<25)
									{
										if(y17<17)//o17 and o17b will appear
										{
											obstacle17();
											y17=y17+1;

											if(y17>=6)
											{
												obstacle17b();
												y17b++;

											}
										}
										else//o17,o17b and c2 will appear
										{
											obstacle17();
											y17=y17+1;
											if(y17>=6)
											{
												obstacle17b();
												y17b++;

											}
										}
									}
									else//y17 will not appear
									{
										if(y17b<25)// o17b and c2 will appear
										{
											obstacle17b();
											y17b++;

											if(tmpc2<21)
											{
												comment2();
												tmpc2=tmpc2+1;
												tmpbc2=tmpbc2-1;
												//cout<<"\a";

												gotoxy(14,9);
												if(t%2==0)
												cout<<"WELL DONE :D";
												else
												cout<<"\a";
												t++;
											}

										}
										else //o17b will not appear
										{
											if(tmpc2<21)
											{

												comment2();
												tmpc2=tmpc2+2;
												tmpbc2=tmpbc2-2;
												//cout<<"\a";

												gotoxy(14,9);
												if(t%2==0)
												cout<<"WELL DONE :D";
												else
												cout<<"\a";
												t++;
											}
											else
											phase++;
										}



									    }


									}


								}
							}
						}



					}
				}
			}
		}

	break;//end of case 2
	case 3:
	if(ya18<25)
	{
		if(ya18<15)//only o18
		{
			obstacle18();
			ya18++;
			yb18++;
		}
		else //both o18 and o19
		{
			obstacle18();
			ya18++;
			yb18++;
			obstacle19();
			y19=y19++;
			if(yb18>20)
			{
				delay(2000);
			}
		}
	}
	else//o18 will disappear
	{
		yb18=25,ya18=25;
		if(y19<25)
		{
			if(y19<20)//only o19
			{
				obstacle19();
				y19=y19+1;
			}
			else //o19 and o20 both will appear
			{
				obstacle19();
				y19=y19+1;
				obstacle20();
				ya20=ya20+1;yb20=yb20+1;
				yc20=yc20+1;yd20=yd20+1;ye20=ye20+1;
				yf20=yf20+1;yg20=yg20+1;
				obstacle21();

				ya21=ya21+1;yb21=yb21+1;
				yc21=yc21+1;yd21=yd21+1;ye21=ye21+1;
				yf21=yf21+1;yg21=yg21+1;
				if(yg20<=20)// for horizontal movement of o20
				{
					//obstacle20();
					x20=x20+4;
					//obstacle21();
					x21=x21-4;
				}
				else  // for horizontal movement of o20

				{
					//obstacle20();
					x20=x20-4;
					//obstacle21();
					x21=x21+4;
				}


			}
		}
		else//o19 will disappear
		{
			if(yg20<25)
			{
				if(yg20<15)//o20 and o21 will appear
				{
					obstacle20();
					ya20=ya20+1;yb20=yb20+1;
					yc20=yc20+1;yd20=yd20+1;ye20=ye20+1;
					yf20=yf20+1;yg20=yg20+1;
					obstacle21();
					ya21=ya21+1;yb21=yb21+1;
					yc21=yc21+1;yd21=yd21+1;ye21=ye21+1;
					yf21=yf21+1;yg21=yg21+1;
					if(yg20<=20)// for horizontal movement of o20
					{
						//obstacle20();
						x20=x20-1;
						//obstacle21();
						x21=x21+1;
						//cout<<yg20;
					}
					else  // for horizontal movement of o20

					{
						//obstacle20();
						x20=x20+1;
						//obstacle21();
						x21=x21-1;
						//cout<<yg20;
					}

				}
				else//o20,o21 and o22 will appear
				{
					obstacle20();
					ya20=ya20+1;yb20=yb20+1;
					yc20=yc20+1;yd20=yd20+1;ye20=ye20+1;
					yf20=yf20+1;yg20=yg20+1;
					obstacle21();
					ya21=ya21+1;yb21=yb21+1;
					yc21=yc21+1;yd21=yd21+1;ye21=ye21+1;
					yf21=yf21+1;yg21=yg21+1;
					if(yg20<=20)// for horizontal movement of o20
					{
						//obstacle20();
						x20=x20-1;
						//obstacle21();
						x21=x21+1;
						//cout<<yg20;
					}
					else  // for horizontal movement of o20

					{
						//obstacle20();
						x20=x20+1;
						//obstacle21();
						x21=x21-1;
						//cout<<yg20;
					}
					obstacle22();
					y22++;
				}

			}
			else//o20 and o21 will disappear
			{
				ya20=yb20=yc20=yd21=ye20=yf20=yg20=25; //to remuv foul ambiguity after disappearance of o20 and o21
				ya21=yb21=yc21=yd21=ye21=yf21=yg21=25;; //to remuv error in rt lft fouls
				if(y22<25)
				{
					if(y22<15)//only o22 will appear
					{
						obstacle22();
						y22++;
					}
					else //both o22 and o23 will appear
					{
						obstacle22();
						y22++;
						ya23=5,yb23=6,yc23=7,yd23=9,ye23=11,yf23=13,yg23=15;
						obstacle23();
						//y--;


					}
				}
				else//o22 will disappear
				{

					if((y>3)&&(t23==1))//o23 will appear
					{
						ya23=5,yb23=6,yc23=7,yd23=9,ye23=11,yf23=13,yg23=15;
						/*the above values will be given to these varaibles ya23,
						yb23....only at the tym of execution of o23
						this is done to bring the foul feature(tr,lft) for o23*/
						//	ya23++,yb23++,yc23++,yd23++,ye23++,
						//	yf23++,yg23++;
						obstacle23();
						scoreboard();
						gotoxy(35,22);
						cout<<"PRESS W TO MOVE UP";
						while(y!=3)
						{
							char ch2;
							ch2=getch();
							scoreboard();
							//gotoxy(x,23);
							//cout<<" ";
							if(ch2=='w')
							{
								obstacle23();
								y--;

								gotoxy(x,y);
								cout<<"@";
								gotoxy(x,y+1);
								cout<<" ";
								gotoxy(x,y+2);
								cout<<" ";
								gotoxy(80,25);//to hide the cursor

							}
							else if(ch2=='a')
							{
								left();
								gotoxy(x,y);
								cout<<"@";
							}
							else if(ch2=='d')
							{
								right();
								gotoxy(x,y);
								cout<<"@";
							}
							else if(ch2==27)
							y=3;
							else
							cout<<"\a";

						}
					      //	gotoxy(x,y);
					       //	cout<<" ";
					}
					else//o23 will disappear
					{
						t23=0;
						ya23=yb23=yc23=yd23=ye23=yf23=yg23=25;
						//cout<<"\a";
						if((y==3)&&(t23==0))
						{
							while(y!=22)
							{
								y++; //reverse gear
								x=9;  // to print comment at left most end
								//delay(100);
								gotoxy(x,y);
								cout<<"GOING BACK";
								gotoxy(x,y-1);
								cout<<"           ";
								x=20;//to print car in centre
							}

						}
						if(y24<25)
						{

							if(y24<15)//only o24 will appear
							{
								obstacle24();
								y24++;
								//delay(50);
								//cout<<y24;at y=15
							}
							else //o24 and o25 will appear
							{



								obstacle24();
								y24++;
								//cout<<y24;at y=15
								//if(xh25<=31)
								//{

									obstacle25();
									xa25++,xb25++,xc25++,xd25++,
									xe25++,xf25++,xg25++,xh25++;
									obstacle26();
									xa26++,xb26++,xc26++,xd26++,
									xe26++,xf26++,xg26++,xh26++;
									obstacle28();
									xa28++,xb28++,xc28++,xd28++;
									//delay(500);
									//gotoxy(x,y);
									//cout<<"P";

								//}




							}
						}
						else
						{
							phase++;
							obstacle27();
							gotoxy(x,y+1);
							cout<<" ";//to remuv @, no idea from where it came
							gotoxy(35,22);
							cout<<"<--  SIT ON THE TROLLEY";
							gotoxy(35,23);
							cout<<"     AND PRESS W TO MOVE IT UPWARD";
						}
					}
				}

			}

		}

	}

	break;
	case 4:
	//gotoxy(10,10);
	//cout<<"4";
	//delay(100);
	//gotoxy(35,22);
	//cout<<"<--  SIT ON THE TROLLEY";
	gotoxy(35,23);
	cout<<"         PRESS W TO MOVE IT UPWARD";
	if((y27>=20)&&(ttrolley==1))//o25,o26,o28 and o27 will appear
	{

		obstacle25();//o25,o26 and o28 will move right
		xa25++,xb25++,xc25++,xd25++,
		xe25++,xf25++,xg25++,xh25++;
		obstacle26();
		xa26++,xb26++,xc26++,xd26++,
		xe26++,xf26++,xg26++,xh26++;
		obstacle27();//lift
		y27--;

		//cout<<y27;
		obstacle28();
		xa28++,xb28++,xc28++,xd28++;
		if((y27==21)&&((x==21)||(x==22)||(x==23)||(x==24)||(x==25)||(x==26)||(x==27)||(x==28)))
		t27=1;
		/*at this particular instant that is when y27==21,
		'@' has to sit on the lift, and this instant is
		marked by t27=1  */
		if((x!=21)&&(x!=22)&&(x!=23)&&(x!=24)&&(x!=25)&&(x!=26)
		&&(x!=27)&&(x!=28))
		t27=0;
		if(t27==1)
		y--;

	}
	else
	{
		if((y27>9)&&(ttrolley==1)) //the horizontal movement of o25,o26 and o28 will get reversed
		{
			obstacle25();//now o25,o26 and o28 will move towards left
			xa25--,xb25--,xc25--,xd25--,
			xe25--,xf25--,xg25--,xh25--;
			obstacle26();
			xa26--,xb26--,xc26--,xd26--,
			xe26--,xf26--,xg26--,xh26--;
			obstacle27();
			y27--;
			//cout<<y27;
			obstacle28();
			xa28--,xb28--,xc28--,xd28--;

			if(t27==1)
			{	//if '@' sat on the lift when y27 was 23
				y--;
				if((x!=21)&&(x!=22)&&(x!=23)&&(x!=24)&&(x!=25)&&(x!=26)
				&&(x!=27)&&(x!=28))
				t27=0;//if'@' moves out of the lift by changing its x cordinate
				//if @ leaves the lift when y27<13 then o29 will not appear
			}

			else //if '@' doesnt take the lift on time , it will have to touch obs29
			{
				if(y27>=9)// till this value of o27, o29 will reach '@"
				{
						obstacle29();
						y29=y29+1;

				}
				if((x!=21)&&(x!=22)&&(x!=23)&&(x!=24)&&(x!=25)&&(x!=26)
				&&(x!=27)&&(x!=28))
				t27=0;//if'@' moves out of the lift by changing its x cordinate
				//if @ leaves the lift when y27<13 then o29 will not appear

			}
		}
		else//o25,o26,o27 and o28 will disappear
		{
			y29=25;//to remuv rt left error problem
			while(y27!=23)
			{
				delay(200);
				y27++;
				obstacle27();
				gotoxy(xa27,y27-1);
				cout<<"           ";
				gotoxy(5,12);//to take the cursor away from the main track
			}
			while((y!=22)&&(ttrolley==1))
			{

				y++; //reverse gear
				x=24;  // to print comment at left most end
				delay(100);
				gotoxy(x,y);
				cout<<"@";
				gotoxy(x,y-1);
				cout<<" ";
				gotoxy(5,12);//to take the cursor away from the main track
			}
			ttrolley=0;
			phase++;
		}
	}
	break;
	case 5:
	if(y30a<25)//o30a 'X' will appear
	{
		y30a++;
		obstacle30a();										if(y30a>20)// 30,o31 and o32 will also appear
		{
			ya30++,yb30++,yc30++,yd30++,ye30++;
			xa30++,xb30++,xc30++,xd30++,xe30++;
			obstacle30();
			ya31++,yb31++,yc31++,yd31++,ye31++;
			xa31--,xb31--,xc31--,xd31--,xe31--;
			obstacle31();
			ya32++,yb32++,yc32++,yd32++,ye32++;
			//xa31--,xb31--,xc31--,xd31--,xe31--;
			obstacle32();
		}
	}
	else//o30a will disappear
	{
		if(yd30<25)
		{
			ya30++,yb30++,yc30++,yd30++,ye30++;
			xa30++,xb30++,xc30++,xd30++,xe30++;
			obstacle30();
			ya31++,yb31++,yc31++,yd31++,ye31++;
			xa31--,xb31--,xc31--,xd31--,xe31--;
			obstacle31();
			ya32++,yb32++,yc32++,yd32++,ye32++;
			//xa31--,xb31--,xc31--,xd31--,xe31--;
			obstacle32();
			delay(500);

		}
		else
		phase++;//end of phase 3
	}
	break;
	case 6:
	if(yfl<=20)
	{
		for(rtyb=1,ltyb=1;rtyb<=25,ltyb<=25;ltyb++,rtyb++)
		{
			gotoxy(32,rtyb);
			cout<<"|";
			gotoxy(8,ltyb);
			cout<<"|";
		}
		chamberscoreboard();
		ladder();
		gotoxy(x,y);
		cout<<"@";
		if(yfl==20)
		{
			cout<<"\a\a";
			while((y!=14)&&(tl==0))//@ climbs the ladder
			{
				y--;
				x=20;//
				gotoxy(x,y);
				cout<<"@";
				if(y<=18)
				{

					gotoxy(x,y+1);
					cout<<"_";

				}
				else
				{

					gotoxy(x,y+1);
					cout<<" ";
				}
				delay(200);
			}
			gotoxy(32,15); //to make way for the trolley
			cout<<" ";     //deleting 3 components of right boundry
			gotoxy(32,14);
			cout<<" ";
			gotoxy(32,13);
			cout<<" ";
			while(t2xh!=80)//trolley reaches the rightmost end
			{
				trolley2();
				if(t2xa==9)//first glimpse of trollry
				delay(500);
				t2xa++,t2xb++,t2xc++,t2xd++,t2xe++,
				t2xf++,t2xg++,t2xh++;
				if(t2xd>=20)//lift reaches '@'
				{
					gotoxy(t2xd,t2y);
					cout<<"@";
					//gotoxy(x,y);
					//cout<<" ";
				}
				delay(50);
				gotoxy(46,10);
				cout<<"MOVING TO THE CHAMBER  --->";
			}
			gotoxy(46,16);
			cout<<"Press W to move to the chamber";
		}
		yal++,ybl++,ycl++,ydl++,yel++,yfl++;
		//gotoxy(60,12);
		//cout<<"x="<<x<<"   y="<<y;
		/*if(t2xh>=79)
		{
			x=15,y=19;
			gotoxy(x,y);
			cout<<"A";
		}useless, cant remove @ from ladder*/
	  }
	  else // chamber will appear
	  {
		phase++;//in case , chamber will be there
		clrscr();
		c2frame();
		basementtrolley();
		x=15;
		y=19;


		gotoxy(25,23);
		cout<<"Press w to move into the chamber";

	  }
	  break;
	  case 7:
	  if(fxa>=30)	//tl=1;
	  {
			/*if(btxa==11)//to clear the screen just once
			{//when the lift will appear,just before that clear screen will be done
				gotoxy(5,15);
				cout<<"Press w to move into the chamber";
				delay(500);
			}*/
			//gotoxy(x-1,y);
			//cout<<"P";
			y=19;
			x=15;

			c2frame();
			delay(200);
			while(btxh<=43)
			{
				basementtrolley();
				gotoxy(x,y);
				cout<<"@";
				if(btxa==11)
				delay(500);
				gotoxy((x-1),y);
				cout<<" ";
				x++;
				btxa++,btxb++,btxc++,btxd++,btxe++,btxf++,btxg++,btxh++;
				delay(100);
				football();
				football2();
				football3();
				football4();
				football5();
				gotoxy(80,25);//to hide the cursor
			}

			basementtrolley();

			while(fxa>=30)
			{
				fxa--,fxb--,fxc--,fxd--,fxe--;
				gotoxy((fxe+1),fya);
				cout<<" ";
				gotoxy((fxd+1),fyb);
				cout<<" ";
				gotoxy((fxd+1),fyd);
				cout<<" ";
				gotoxy((fxc+1),fyc);
				cout<<" ";
				gotoxy((fxc+1),fye);
				cout<<" ";
				gotoxy((fxb+1),fyb);
				cout<<" ";
				gotoxy((fxb+1),fyd);
				cout<<" ";
				gotoxy((fxa+1),fya);
				cout<<" ";
				football();
				f2xa++,f2xb++,f2xc++,f2xd++,f2xe++;
				gotoxy((f2xe-1),f2ya);
				cout<<" ";
				gotoxy((f2xd-1),f2yb);
				cout<<" ";
				gotoxy((f2xd-1),f2yd);
				cout<<" ";
				gotoxy((f2xc-1),f2yc);
				cout<<" ";
				gotoxy((f2xc-1),f2ye);
				cout<<" ";
				gotoxy((f2xb-1),f2yb);
				cout<<" ";
				gotoxy((f2xb-1),f2yd);
				cout<<" ";
				gotoxy((f2xa-1),f2ya);
				cout<<" ";
				football2();
				f4xa--,f4xb--,f4xc--,f4xd--,f4xe--;
				gotoxy((f4xe+1),f4ya);
				cout<<" ";
				gotoxy((f4xd+1),f4yb);
				cout<<" ";
				gotoxy((f4xd+1),f4yd);
				cout<<" ";
				gotoxy((f4xc+1),f4yc);
				cout<<" ";
				gotoxy((f4xc+1),f4ye);
				cout<<" ";
				gotoxy((f4xb+1),f4yb);
				cout<<" ";
				gotoxy((f4xb+1),f4yd);
				cout<<" ";
				gotoxy((f4xa+1),f4ya);
				cout<<" ";
				football4();
				f5xa++,f5xb++,f5xc++,f5xd++,f5xe++;
				gotoxy((f5xe-1),f5ya);
				cout<<" ";
				gotoxy((f5xd-1),f5yb);
				cout<<" ";
				gotoxy((f5xd-1),f5yd);
				cout<<" ";
				gotoxy((f5xc-1),f5yc);
				cout<<" ";
				gotoxy((f5xc-1),f5ye);
				cout<<" ";
				gotoxy((f5xb-1),f5yb);
				cout<<" ";
				gotoxy((f5xb-1),f5yd);
				cout<<" ";
				gotoxy((f5xa-1),f5ya);
				cout<<" ";
				football5();
				//delay(100);
			}
			football();
			football2();
			football3();
			football4();
			football5();

	  }
	  else//automatic motion of spiny footballs will stop
	  {
			if(y!=1)//at y==1, @ will exit from the chamber
			{
				c2frame();
				football();
				football2();
				football3();
				football4();
				football5();
				/*gotoxy(10,10);
				cout<<"x="<<x;
				gotoxy(50,23);
				cout<<"fxa"<<fxa;
				gotoxy(56,23);
				cout<<"f2xa"<<f2xa; */
				if(y>1)
				{
					y--;
				}
				/*gotoxy(10,11);
				cout<<"y="<<y; */
				if(y==6)
				{
					if(x>40)
					{
						while(x!=40)//taking out from chamber through pipe
						{
							x--;
							gotoxy(x,y);
							cout<<"@";
							gotoxy(x+1,y);
							cout<<" ";
							delay(200);
						}
						end = clock();//timer stops
					 }
					if(x<40)
					{
						while(x!=40)//taking out from chamber through pipe
						{
							x++;
							gotoxy(x,y);
							cout<<"@";
							gotoxy(x-1,y);
							cout<<" ";
							delay(200);
						}
						end = clock();//timer stops
					 }
					 if(x==40)
					 end = clock();//timer stops
					delay(500);
					cout<<"\a";
					while(y!=1)//taking out from chamber through pipe
					{
						y--;
						gotoxy(x,y);
						cout<<"@";
						gotoxy(x,(y+1));
						cout<<" ";
						delay(200);
					}
					phase++;
				}



			}


	  }

	break;
	case 8:
	clrscr();
	chamberscoreboard();
	gotoxy(30,20);
	cout<<"Time elapsed:";
	gotoxy(44,20);
	cout<<(end - start) / CLK_TCK;
	finalobstacle();
	finalpipe(); //x=5
	x=5;y=1;
	gotoxy(tax,18);//showing the trolley
	cout<<"|";
	gotoxy(thx,17);
	cout<<"|";
	gotoxy(tbx,18);
	cout<<"-";
	gotoxy(tcx,18);
	cout<<"-";
	gotoxy(tdx,18);
	cout<<"-";
	gotoxy(tex,18);
	cout<<"-";
	gotoxy(tfx,18);
	cout<<"-";
	gotoxy(tgx,18);
	cout<<"|";
	gotoxy(tix,17);
	cout<<"|";
	gotoxy(38,17); //queen, before meeting the king
	cout<<"@";
	gotoxy(38,16);
	cout<<"^";
	gotoxy(st1x,st1y);//star shedof the trolley
	cout<<"*";
	gotoxy(st2x,st2y);//star shedof the trolley
	cout<<"*";
	gotoxy(st3x,st3y);//star shedof the trolley
	cout<<"*";
	gotoxy(st4x,st4y);//star shedof the trolley
	cout<<"*";
	gotoxy(st5x,st5y);//star shedof the trolley
	cout<<"*";
	for(y=1;y<=18;y++)
	{
		gotoxy(x,y);
		cout<<"@";
		gotoxy(x,y-1);
		cout<<" ";
		gotoxy(70,25); //to hide the cursor
		delay(100);
	}
	for(x=5;x<=17;x++)
	{
		gotoxy(x,18);
		cout<<"@";
		gotoxy(x-1,18);
		cout<<" ";
		delay(100);
	}
	for(x=17,y=18;y>=12;x=x+1,y--)
	{
		gotoxy(x,y);
		cout<<"@";
		gotoxy(x-1,y+1);
		cout<<" ";
		gotoxy(16,19);/*to fill up the gap created on the
		road due to space bar printed in the above statement */
		cout<<"_";
		gotoxy(10,22) ;
		delay(100);

	} //ends at x=22
	for(x=23,y=12;y<=18;x=x+1,y++)
	{
		gotoxy(x,y);
		cout<<"@";
		gotoxy(x-1,y-1);
		cout<<" ";
		gotoxy(10,22) ;
		//cout<<x;
		delay(50);
	}//ends at x=29
	for(x=29;x<=34;x++)
	{
		gotoxy(x,18);
		cout<<"@";
		gotoxy(x-1,18);
		cout<<" ";
	       delay(50);
	}//ends at x=34
	while(tgx!=79)//moving the trolley
	{
		y=17;
		if(tax==35)
		delay(200);
		gotoxy(tax,18);
		cout<<"|";
		gotoxy(thx,17);
		cout<<"|";
		gotoxy(tbx,18);
		cout<<"-";
		gotoxy(tcx,18);
		cout<<"-";
		gotoxy(tdx,18);
		cout<<"-";
		gotoxy(tex,18);
		cout<<"-";
		gotoxy(tfx,18);
		cout<<"-";
		gotoxy(tgx,18);
		cout<<"|";
		gotoxy(tix,17);
		cout<<"|";
		gotoxy(st1x,st1y);//star shedof the trolley
		cout<<"*";
		gotoxy(st2x,st2y);//star shedof the trolley
		cout<<"*";
		gotoxy(st3x,st3y);//star shedof the trolley
		cout<<"*";
		gotoxy(st4x,st4y);//star shedof the trolley
		cout<<"*";
		gotoxy(st5x,st5y);//star shedof the trolley
		cout<<"*";
		gotoxy(x+1,17); //x=34,king
		cout<<"@";
		gotoxy(x,17); //deleting king
		cout<<" ";
		gotoxy(x+3,17);//queen
		cout<<"@";
		gotoxy(x+3,16);//queens crown
		cout<<"^";
		gotoxy(x+2,16);//deleting queens crown
		cout<<" ";
		gotoxy(x+2,17);//deleting queen
		cout<<" ";
		gotoxy(tax-1,18);
		cout<<" ";
		gotoxy(tix-1,17);
		cout<<" ";
		gotoxy(thx-1,17);
		cout<<" ";
		gotoxy(st1x-1,st1y);//deleting stars
		cout<<" ";
		gotoxy(st2x-1,st2y);
		cout<<" ";
		gotoxy(st3x-1,st3y);
		cout<<" ";
		gotoxy(st4x-1,st4y);
		cout<<" ";
		gotoxy(st5x-1,st5y);
		cout<<" ";
		tax++,tbx++,tcx++,tdx++,tex++,tfx++,tgx++,thx++,tix++,x++;
		st1x++,st2x++,st3x++,st4x++,st5x++;
		gotoxy(70,25); //to hide the cursor
		delay(100);
		//phase++;
	}
	gotoxy(27,8);
	cout<<"T H A N K  Y O U  G I N N I !";
	gotoxy(25,10);
	delay(500);
	cout<<"Y O U R  Q U E S T  I S  O V E R";
	//cout<<"\nThe time was: "<< (end - start) / CLK_TCK;

	getch();
	exit(0);
	/*break;
	case 7://the game is over.
	exit(0);//to take you out of the run screen*/
	}//close of switch
	if((170-((t1 - start) / CLK_TCK))<=0)
	{
		for(i=1,j=70;i<70;i++,j--)
		{
			gotoxy(i,6);
			cout<<" TIME UP";
			gotoxy(j,18);
			cout<<"TIME UP ";
			gotoxy(35,12);
			cout<<"GAME OVER";
			delay(50);
		}
		getch();
		exit(0);
	}
}// end of function up
void main()
{
	clrscr();
	//textcolor(15);
	y=22;
	c=0;
	x=20;
	ya23=yb23=yc23=yd23=ye23=yf23=yg23=25;//for o23
	intropage();
	if((phase!=0)||(phase!=7))
	{
		for(rtyb=1,ltyb=1;rtyb<=25,ltyb<=25;ltyb++,rtyb++)
		{

			gotoxy(32,rtyb);
			cout<<"|";
			gotoxy(8,ltyb);
			cout<<"|";
		}
	}

	obstacle1();
	obstacle2();
	obstacle3();

	if((phase!=4)&&(phase!=7))
	scoreboard();
	else if((phase==4)||(phase==7))
	chamberscoreboard();
	//ch=='w';
	if((phase!=4)&&(phase!=7)&&(phase!=8))//this if condition is useful in case there is direct jump to a case
	do
	{
		gotoxy(x,y);
		cout<<"@";
		again:while((!kbhit()))
		{
			if((phase!=4)&&(phase!=7)&&(phase!=8))
			{
				up();
				delay(50);
			}
			else
			break;
		}
		if((phase!=4)&&(phase!=7)&&(phase!=8))
		{
			ch=getch();
			if(ch=='d')
			{
				right();
				goto again;
			}
			else if(ch=='a')
			{
				left();
				goto again;
			}
			/*else if(ch=='s')
			down();  */
			else if(ch==27)
			break;
			else
			cout<<"\a";
		}
		else
		break;
	} while(ch!=27);
	if((phase==4)||(phase==7)||(phase==8))
	do
	{
		if(phase==5)
		goto again;
		gotoxy(x,y);
		cout<<"@";
		ch=getch();
		if(ch=='w')
		up();
		else if(ch=='d')
		right();
		else if(ch=='a')
		left();
		/*else if(ch=='s')
		down();  */
		else if(ch==27)
		break;

	}while(c==0);
	if((phase==5)&&(ch!=27))
	goto again;
	/*ch!=27 is added in the if condition to avoid the execution of
	"goto again" once esc is pressed while phase 5 is running.
	If this ch!=27 is not witten, then on pressing esc (during phase 5),
	the compiler wll take out from while(kbhit) but due to this last
	if condition "(if phase==5)", the exexution of while kbhit is done again and again*/
}

