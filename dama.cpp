#include "stdio.h"
#include "graphics.h"
#include "conio.h"




int main()
{
     int mhs=0,mh[10][3],oyun[8][8]={{0,-1,-1,0,0,1,1,0},
                                     {0,-1,-1,0,0,1,1,0},
                                     {0,-1,-1,0,0,1,1,0},
                                     {0,-1,-1,0,0,1,1,0},
                                     {0,-1,-1,0,0,1,1,0},
                                     {0,-1,-1,0,0,1,1,0},
                                     {0,-1,-1,0,0,1,1,0},
                                     {0,-1,-1,0,0,1,1,0}
                                     },x,y,os=1,yskontrol=0,x2,y2,yms=0,yss=0;



     unsigned size;
     void *buf[2][3];


      initwindow(800,610,"Dama");

     int i,k,m=1,x3,y3;

     basadon:
     setbkcolor(LIGHTGREEN);
     cleardevice();

     setcolor(MAGENTA);
     settextstyle(GOTHIC_FONT,0,5);
     outtextxy(180,150,"DAMA OYUNU");


     setfillstyle(1,BLUE);
     bar(250,250,500,300);

     setbkcolor(BLUE);
     setcolor(YELLOW);
     settextstyle(6,0,4);
     outtextxy(260,262,"Oyuna Ba�la");


     bar(235,325,530,375);
     outtextxy(240,330,"TAL�MATLAR");

     setfillstyle(1,RED);
     bar(275,400,450,450);

     setbkcolor(RED);
     setcolor(GREEN);
     outtextxy(280,410,"CIKI�!!!");

     setcolor(BLACK);
     setbkcolor(LIGHTGREEN);
     settextstyle(6,0,2);
     outtextxy(300,580,"(mouse kullan�n)");

     while(1)
     {
              while (!ismouseclick(WM_LBUTTONDOWN));
              getmouseclick(WM_LBUTTONDOWN, x, y);

              if((x>250&&x<500)&&(y>250&&y<300)) break;
              if((x>275&&x<450)&&(y>400&&y<450)) return 0;
              if((x>235&&x<530)&&(y>325&&y<375))
              {
                     cleardevice();
                     settextstyle(1,0,2);
                     outtextxy(0,30,"**Ta�lar� se�mek ve hareket edece�i yeri belirtmek i�in");
                     outtextxy(0,60,"sol t�klay�n");
                     outtextxy(0,90,"**Oyun mavilerle ba�lar");
                     outtextxy(0,120,"**Kural d��� hamle yap�lamaz");
                     outtextxy(0,150,"**Eger rakip tas� yeme sans�n varsa baska hamle");
                     outtextxy(0,180,"yap�lamaz");

                     bar(250,570,450,610);
                     setbkcolor(RED);
                     outtextxy(260,580,"ANA MEN�");

                     while(!(x>250&&x<450&&y>570))
                     {
                     while (!ismouseclick(WM_LBUTTONDOWN));
                     getmouseclick(WM_LBUTTONDOWN, x, y);
                     }
                     goto basadon;
              }
     }




     setbkcolor(MAGENTA);        //arka plan reng� ayar�
     cleardevice();



     setcolor(LIGHTGREEN);
     rectangle(1,1,605,605);   //buyuk kare//
                                                        //OYUN TAHTASI (kareler 70*70,ara 5 pixel)
     for(i=0;i<600;i+=75)      //kucuk kareler//
              for(k=0;k<600;k+=75)
                    rectangle(5+i,5+k,76+i,76+k);

                                                    ///////////////////////////////
     setfillstyle(INTERLEAVE_FILL,LIGHTBLUE);      ///kareler�n aras�n� doldur////
     floodfill(2,2,LIGHTGREEN);                   ///////////////////////////////





     for(k=0;k<580;k+=75,m*=-1)
     for(i=0;i<580;i+=75)                                      ////////////////////////////////////////
     {                                                        ////kucuk kareler� s�yah beyaz boyar////
              if(m==-1) setfillstyle(SOLID_FILL,WHITE);      ////////////////////////////////////////
              else setfillstyle(SOLID_FILL,BLACK);
              floodfill(41+i,41+k,LIGHTGREEN);
              m*=-1;
     }

     ///////////////////////////////////////////////////////////////////////////
     /////Pullar� c�zme ve bellege res�m olarak kayded�yorum////////////////////
     ///////////////////////////////////////////////////////////////////////////
     setcolor(DARKGRAY);
     circle(41,41,30);
     setfillstyle(SOLID_FILL,LIGHTCYAN);
     floodfill(22,22,DARKGRAY);

     setfillstyle(SOLID_FILL,DARKGRAY);


     int po[10]={40,18,25,60,40,46,55,60,40,18},uc[8]={19,32,40,46,61,32,29,32};////zem�n s�yah dama tas�////

     fillpoly(5,po);                  //Y�ld�z
     fillpoly(4,uc);

     size = imagesize(6, 6, 75, 75);      //resm�n boyutunu kayded�yoruz

     buf[1][0]=malloc(size);              //res�m �c�n s�ze kadar bellek talep ed�yoruz

     getimage(6,6,75,75,buf[1][0]);       //resm� buf a kayded�yoruz

     setfillstyle(SOLID_FILL,BLACK);      //c�zd�g�m�z resm� s�l�yoruz
     floodfill(6,6,LIGHTGREEN);



     po[0]=115;po[2]=100;po[4]=115;po[6]=130;po[8]=115;
     uc[0]=94;uc[2]=115;uc[4]=136;uc[6]=104;

     setcolor(DARKGRAY);
     circle(116,41,30);
     setfillstyle(SOLID_FILL,LIGHTCYAN);                                        ////zem�n beyaz dama tas�////
     floodfill(97,22,DARKGRAY);

     setfillstyle(SOLID_FILL,DARKGRAY);
     fillpoly(5,po);                     //Y�ld�z
     fillpoly(4,uc);

     buf[1][1]=malloc(size);

     getimage(6+75,6,75+75,75,buf[1][1]);



     setfillstyle(SOLID_FILL,RED);

     floodfill(81,6,LIGHTGREEN);

     setcolor(DARKGRAY);
     circle(116,41,30);
     setfillstyle(SOLID_FILL,LIGHTCYAN);                                        ////zem�n k�rm�z� dama tas�////
     floodfill(97,22,DARKGRAY);

     setfillstyle(SOLID_FILL,DARKGRAY);
     fillpoly(5,po);                     //Y�ld�z
     fillpoly(4,uc);


     buf[1][2]=malloc(size);

     getimage(6+75,6,75+75,75,buf[1][2]);

     setfillstyle(SOLID_FILL,WHITE);
     floodfill(81,6,LIGHTGREEN);


     setcolor(DARKGRAY);
     circle(41,416,30);
     setfillstyle(SOLID_FILL,LIGHTCYAN);
     floodfill(22,397,DARKGRAY);

     setcolor(DARKGRAY);
     circle(41,416,10);                                                         ////zem�n beyaz normal tas////
     setfillstyle(SOLID_FILL,DARKGRAY);
     floodfill(41,420,DARKGRAY);

     buf[0][1]=malloc(size);

     getimage(6,6+5*75,75,75+5*75,buf[0][1]);


     setcolor(DARKGRAY);
     circle(41+75,416,30);
     setfillstyle(SOLID_FILL,LIGHTCYAN);
     floodfill(22+75,397,DARKGRAY);

     setcolor(DARKGRAY);
     circle(41+75,416,10);                                                      ////zem�n siyah normal tas////
     setfillstyle(SOLID_FILL,DARKGRAY);
     floodfill(41+75,420,DARKGRAY);

     buf[0][0]=malloc(size);

     getimage(6+75,6+5*75,75+75,75+5*75,buf[0][0]);



     setfillstyle(1,RED);
     floodfill(6+75,6+5*75,LIGHTGREEN);

     setcolor(DARKGRAY);
     circle(41+75,416,30);
     setfillstyle(SOLID_FILL,LIGHTCYAN);
     floodfill(22+75,397,DARKGRAY);

     setcolor(DARKGRAY);
     circle(41+75,416,10);                                                      ////zem�n siyah normal tas////
     setfillstyle(SOLID_FILL,DARKGRAY);
     floodfill(41+75,420,DARKGRAY);

     buf[0][2]=malloc(size);

     getimage(6+75,6+5*75,75+75,75+5*75,buf[0][2]);

     setfillstyle(1,BLACK);
     floodfill(6+75,6+5*75,LIGHTGREEN);


     ///////////////////////////////////////////////////////////////////////////

     for(k=0;k<2;k++)
      for(i=0;i<8;i++)
      {
            putimage(6+i*75,81+k*75,buf[0][(i+k)%2==1?0:1],0);                  ///sar� taslar� d�zer////
            setfillstyle(1,YELLOW);
            floodfill(22+i*75,97+k*75,DARKGRAY);
      }


      for(k=4;k<6;k++)
         for(i=0;i<8;i++)                                                       ////mav� taslar� d�zer////
             putimage(6+i*75,81+k*75,buf[0][(i+k)%2==1?0:1],0);



     setfillstyle(1,LIGHTGREEN);
     bar(700,0,800,40);

     setcolor(BLACK);
     setbkcolor(LIGHTGREEN);
     settextstyle(6,0,3);
     outtextxy(707,10,"CIKI�");



     for(;1;) {
            while(1) {while(1)
                     {do
                     {
                     while (!ismouseclick(WM_LBUTTONDOWN));	//sol t�klayana bekl�yor
                     getmouseclick(WM_LBUTTONDOWN, x, y);   //sol t�klay�nca koord�natlar� x ve y ye yaz�yor

                     if(x>700&&y<40) return 0;

                     x=x/75;   y=y/75;   //koordinatlar� 75 bolunce kac�nc� karede oldugunu buluyoruz tahtaya gore
                     }while(x>7||y>7);


                     if(mhs>0)//mecburi hamle varsa!!
                     {
                     for(i=0;i<mhs;i++)                                          ///////////////////////////////////////////
                                       if(mh[i][0]==x&&mh[i][1]==y) goto a;     ////hamle dogru �se 3 sat�r alttan(a:) kodlar devam ed�yor////
                     }                                                         ///////////////////////////////////////////
                     else break;   //mecbur� hamle yoksa
                     }

                     a:                                                           //  <<<--------------


                     if(oyun[x][y]==os||oyun[x][y]==2*os)//kendi tas�n� sect�g�nde devam ed�l�yor
                      {
                      while(1)
                            {
                             putimage(6+x*75,6+y*75,buf[oyun[x][y]==2*os?1:0][2],0);
                             if(os==-1)
                             {                                                  ////sec�len tas�n zem�n�n� k�rm�z� boyar
                                       setfillstyle(1,YELLOW);
                                       floodfill(22+x*75,22+y*75,DARKGRAY);
                             }


                             while(1)
                            {
                                     while (!ismouseclick(WM_LBUTTONDOWN));
                                     getmouseclick(WM_LBUTTONDOWN, x2, y2);       ////2. sol t�klama rakip pula t�klay�nca b�r daha t�k �st�yor////

                                     if(x2>700&&y2<40) return 0;

                                     x2=x2/75;   y2=y2/75;

                                     if(x2<8&&y2<8)
                                     if(oyun[x2][y2]!=-os)
                                        if(oyun[x2][y2]!=-2*os) break;
                            }


                             if(oyun[x][y]==2*os) goto damakontrolu;
                             if(mhs==0||((x==x2&&y-y2==2*os&&(oyun[x][(y+y2)/2]==-os||oyun[x][(y+y2)/2]==-2*os))||(y==y2&&((x-x2==2||x-x2==-2)&&(oyun[(x+x2)/2][y]==-os||oyun[(x+x2)/2][y]==-2*os)))))
                                if(oyun[x2][y2]==0) break;                   ////sec�len 2. kare bossa ve dogru hamleyse (mh) while(1) dongusunden c�k�yor////


                             ///////////////////////////////////////////////////////////////////
                             ////2. t�klamada da kend� tas�n� secerse buras� devreye g�r�yor////
                             ///////////////////////////////////////////////////////////////////

                             if(mhs==0)//mecbur� hamle YOKSA
                             {
                                       putimage(6+x*75,6+y*75,buf[oyun[x][y]==2*os?1:0][(x+y)%2==1?1:0],0);
                                       if(os==-1)
                                       {                                                  ////�lk sec�len tas�n reng�n� normale cev�r�yor
                                              setfillstyle(1,YELLOW);
                                              floodfill(22+x*75,22+y*75,DARKGRAY);
                                       }


                             x=x2;  y=y2;   //2. pul sec�m�n� 1. pul olarak deg�st�r�yor.1. olarak deg�st�r�len pulun arkas�n� k�rm�z�ya
                                            //boyuyor.ve 2. tas�n g�r�lmes� �st�yor.
                             }

                             else //2. t�klama da kend� tas�n� secersen ve mecbur� hamle VARSA
                             {yenidensec:
                                 for(i=0;i<mhs;i++)
                                       if(mh[i][0]==x2&&mh[i][1]==y2)//eger sectigi tas� mecbur� hamles� yoksa secm�yor
                                        {
                                              putimage(6+x*75,6+y*75,buf[oyun[x][y]==2*os?1:0][(x+y)%2==1?1:0],0);
                                              if(os==-1)
                                              {                                                  //sect�g� tas�nda mecbur� hamles� varsa sec�m� deg�st�r�yor
                                                        setfillstyle(1,YELLOW);
                                                        floodfill(22+x*75,22+y*75,DARKGRAY);
                                              }

                                              x=x2;  y=y2; break;
                                       }
                             }

                            }//while 2. tas sec�m� �c�n

                             break;
                      }//if
                     }//while


          ////////////////////////////////////////////////////////////////////////////////
          ////bu bolume k�smen dogru hamle g�r�l�nce gel�n�r ve pulun hareket� yap�l�r////
          ////////////////////////////////////////////////////////////////////////////////

          if(oyun[x][y]==2*os)//eger oynanan tas damaysa :)
          {
               damakontrolu:
               m=1;
               if(x==x2&&y<y2)
                        for(i=y+1;i<=y2;i++)
                        {
                                 if(i==y2)
                                 {
                                  if(mhs==0||(mhs>0&&m==-1)) goto oynat;
                                  if(mhs>0&&m==1) goto yenidensec;
                                 }
                                 if(oyun[x][i]==os) break;
                                 if(oyun[x][i]==-os||oyun[x][i]==-2*os)
                                     if(m==-1) break;
                                     else
                                     {
                                     m=-1;
                                     x3=x;y3=i;
                                     }
                        }
                         m=1;
               if(x==x2&&y>y2)
                        for(i=y-1;i>=y2;i--)
                        {
                                  if(i==y2)
                                   {
                                    if(mhs==0||(mhs>0&&m==-1)) goto oynat;
                                    if(mhs>0&&m==1) goto yenidensec;
                                   }
                                 if(oyun[x][i]==os) break;
                                 if(oyun[x][i]==-os||oyun[x][i]==-2*os)
                                 {
                                     if(m==-1) break;
                                      else
                                     {
                                     m=-1;
                                     x3=x;y3=i;
                                     }
                                 }
                        }
                         m=1;
               if(y==y2&&x<x2)
               {
                        for(i=x+1;i<=x2;i++)
                        {
                                  if(i==x2)
                                   {
                                    if(mhs==0||(mhs>0&&m==-1)) goto oynat;
                                    if(mhs>0&&m==1)  goto yenidensec;
                                   }
                                 if(oyun[i][y]==os) break;
                                 if(oyun[i][y]==-os||oyun[i][y]==-2*os)
                                     if(m==-1) break;
                                     else
                                     {
                                     m=-1;
                                     x3=i;y3=y;
                                     }
                        }
               }
                m=1;
               if(y==y2&&x>x2)
                        for(i=x-1;i>=x2;i--)
                        {
                                 if(i==x2)
                                  {
                                    if(mhs==0||(mhs>0&&m==-1)) goto oynat;
                                    if(mhs>0&&m==1)  goto yenidensec;
                                  }
                                 if(oyun[i][y]==os) break;
                                 if(oyun[i][y]==-os||oyun[i][y]==-2*os)
                                     if(m==-1) break;
                                      else
                                     {
                                     m=-1;
                                     x3=i;y3=y;
                                     }
                        }

               goto duzelt;
          }


          if(mhs==0||((x==x2&&y-y2==2*os&&(oyun[x][(y+y2)/2]==-os||oyun[x][(y+y2)/2]==-2*os))||(y==y2&&((x-x2==2||x-x2==-2)&&(oyun[(x+x2)/2][y]==-os||oyun[(x+x2)/2][y]==-2*os)))))
             if(((x==x2&&y-y2==os)||(y==y2&&(x-x2==1||x-x2==-1)))||((x==x2&&y-y2==2*os&&(oyun[x][(y+y2)/2]==-os||oyun[x][(y+y2)/2]==-2*os))||(y==y2&&((x-x2==2||x-x2==-2)&&(oyun[(x+x2)/2][y]==-os||oyun[(x+x2)/2][y]==-2*os)))))
                    {

                     oynat:

                                                                             /////////////////////////////////
                     setfillstyle(SOLID_FILL,(x+y)%2==1?WHITE:BLACK);       ////tas�n esk� yer�n� s�l�yor////
                     floodfill(7+x*75,7+y*75,LIGHTGREEN);                  /////////////////////////////////


                     if((os==1&&y2==0)||os==-1&&y2==7)
                     {                      //son sat�ra gelm�sse dama yap :)
                           oyun[x2][y2]=2*os;
                           x3=(x+x2)/2;  y3=(y+y2)/2;
                     }
                     else
                           if(oyun[x][y]==2*os) oyun[x2][y2]=2*os;
                           else oyun[x2][y2]=os;
                     oyun[x][y]=0;

                     putimage(6+x2*75,6+y2*75,buf[oyun[x2][y2]==2*os?1:0][(x2+y2)%2==1?1:0],0);
                     if(os==-1)
                     {                                                  ////tas� yen� yer�ne c�z�yor
                              setfillstyle(1,YELLOW);
                              floodfill(22+x2*75,22+y2*75,DARKGRAY);
                     }

                     mhs=0;

                     ///////////////////////////////////////////////////////////////////////////////////////////
                     ////eger b�r tas yenm�s �se burda yen�len pul s�l�n�yor ve hamle hakk� kontrol ediliyor////
                     ///////////////////////////////////////////////////////////////////////////////////////////

                     if((oyun[x2][y2]==2*os&&m==-1)||((x==x2&&y-y2==2*os&&(oyun[x][(y+y2)/2]==-os||oyun[x][(y+y2)/2]==-2*os))||(y==y2&&((x-x2==2||x-x2==-2)&&(oyun[(x+x2)/2][y]==-os||oyun[(x+x2)/2][y]==-2*os)))))
                     {
                           //printf("%d   %d",x3,y3);
                           if(oyun[x2][y2]!=2*os)
                           {
                                   setfillstyle(SOLID_FILL,((x+x2)/2+(y+y2)/2)%2==1?WHITE:BLACK);
                                   floodfill(7+(x+x2)/2*75,7+(y+y2)/2*75,LIGHTGREEN);            ////yenilen pul siliniyor////

                                   if(oyun[(x+x2)/2][(y+y2)/2]==-1||oyun[(x+x2)/2][(y+y2)/2]==-2)//
                                   {
                                   putimage(606,531-(yss*15),buf[0][2],0); setfillstyle(1,YELLOW); //buras� yenilen taslar� tahtan�n yan�na diziyor
                                   floodfill(627,550-(yss*15),DARKGRAY);           yss++;
                                   if(yss==16) goto oyunsonu;
                                   }

                                   else { putimage(606,6+(yms*15),buf[0][2],0); yms++;  if(yms==16) goto oyunsonu;}         //

                                   oyun[(x+x2)/2][(y+y2)/2]=0;
                           }
                           else
                           {
                                   setfillstyle(SOLID_FILL,(x3+y3)%2==1?WHITE:BLACK);
                                   floodfill(7+x3*75,7+y3*75,LIGHTGREEN);            ////yenilen pul siliniyor////

                                   if(oyun[x3][y3]==-1||oyun[x3][y3]==-2)//
                                   {
                                   putimage(606,531-(yss*15),buf[0][2],0); setfillstyle(1,YELLOW); //buras� yenilen taslar� tahtan�n yan�na diziyor
                                   floodfill(627,550-(yss*15),DARKGRAY);           yss++;
                                   if(yss==16) goto oyunsonu;
                                   }

                                   else { putimage(606,6+(yms*15),buf[0][2],0); yms++;  if(yms==16) goto oyunsonu;}        //

                                   //oyun[(x+x2)/2][(y+y2)/2]=0;
                                   oyun[x3][y3]=0;
                           }




                      if(oyun[x2][y2]==2*os)//eger oynanan tas damaysa :)
          {
               m=1;
               if(!(x==x2&&y>y2))
                        for(i=y2+1;i<8;i++)
                        {
                                 if(oyun[x2][i]==0&&m==-1)
                                 {
                                        mh[mhs][0]=x2;
                                        mh[mhs][1]=y2;
                                        mh[mhs][2]=1;
                                        mhs++; break;
                                 }
                                 if(oyun[x2][i]==os||oyun[x2][i]==2*os) break;
                                 if(oyun[x2][i]==-os||oyun[x2][i]==-2*os)
                                     if(m==-1) break;
                                     else
                                     {
                                     m=-1;
                                     x3=x2; y3=i;
                                     }
                        }
               m=1;
               if(!(x==x2&&y<y2))
                        for(i=y2-1;i>=0;i--)
                        {
                                 if(oyun[x2][i]==0&&m==-1)
                                 {
                                        mh[mhs][0]=x2;
                                        mh[mhs][1]=y2;
                                        mh[mhs][2]=1;
                                        mhs++; break;
                                 }
                                 if(oyun[x2][i]==os||oyun[x2][i]==2*os) break;
                                 if(oyun[x2][i]==-os||oyun[x2][i]==-2*os)
                                     if(m==-1) break;
                                     else
                                     {
                                     m=-1;
                                     x3=x2; y3=i;
                                     }
                        }
               m=1;
               if(!(y==y2&&x>x2))
                        for(i=x2+1;i<8;i++)
                        {
                                if(oyun[i][y2]==0&&m==-1)
                                 {
                                        mh[mhs][0]=x2;
                                        mh[mhs][1]=y2;
                                        mh[mhs][2]=1;
                                        mhs++; break;
                                 }
                                 if(oyun[i][y2]==os||oyun[i][y2]==2*os) break;
                                 if(oyun[i][y2]==-os||oyun[i][y2]==-2*os)
                                     if(m==-1) break;
                                     else
                                     {
                                     m=-1;
                                     x3=i;y3=y2;
                                     }
                        }
               m=1;
               if(!(y==y2&&x<x2))
                        for(i=x-1;i>=0;i--)
                        {
                                 if(oyun[i][y2]==0&&m==-1)
                                 {
                                        mh[mhs][0]=x2;
                                        mh[mhs][1]=y2;
                                        mh[mhs][2]=1;
                                        mhs++; break;
                                 }
                                 if(oyun[i][y2]==os||oyun[i][y2]==2*os) break;
                                 if(oyun[i][y2]==-os||oyun[i][y2]==-os)
                                     if(m==-1) break;
                                     else
                                     {
                                     m=-1;
                                     x3=i;y3=y2;
                                     }
                        }


          }

          else
          {

                     if(x2<6)
                          if(oyun[x2+1][y2]==-os||oyun[x2+1][y2]==-2*os)
                               if(oyun[x2+2][y2]==0)
                               {
                                     mh[mhs][0]=x2;             ////mecbur� hamle kontrolu SAG////
                                     mh[mhs][1]=y2;
                                     mh[mhs][2]=1;
                                     mhs++;
                               }
                     if(os==-1)
                          if(y2<6)
                               if((oyun[x2][y2+1]==-os||oyun[x2][y2+1]==-2*os )&& oyun[x2][y2+2]==0)
                               {
                                     mh[mhs][0]=x2;              ////mecbur� hamle kontrolu ASAGI////
                                     mh[mhs][1]=y2;
                                     mh[mhs][2]=4;
                                     mhs++;
                               }
                      if(x2>1)
                          if(oyun[x2-1][y2]==-os||oyun[x2-1][y2]==-2*os)
                               if(oyun[x2-2][y2]==0)
                               {
                                     mh[mhs][0]=x2;              ////mecbur� hamle kontrolu SOLA////
                                     mh[mhs][1]=y2;
                                     mh[mhs][2]=3;
                                     mhs++;
                               }
                       if(os==1)
                          if(y2>1)
                               if((oyun[x2][y2-1]==-os||oyun[x2][y2-1]==-2*os) && oyun[x2][y2-2]==0)
                               {
                                     mh[mhs][0]=x2;               ////mecbur� hamle kontrolu YUKARI////
                                     mh[mhs][1]=y2;
                                     mh[mhs][2]=2;
                                     mhs++;
                               }
          }





                     }// if((x==x2&&y-y2==2*os&&oyun[x][(y+y2)/2]==-os)||(y==y2&&((x-x2==2||x-x2==-2)&&oyun[(x+x2)/2][y]==-os)))

          ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          ///////////////////bu bolum mecbur� hamle olmay�nca s�ray� kars�ya ver�r ve mecbur� hamle kontrolu yapar///////////////////////
          ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                     if(mhs==0)                      //////////////////////////////////////
                     { os=-os;                      ////hamle s�ras� kars�ya gecer    ////
                       mhs=0;                      ////          ve                  ////
     for(y=0;y<8;y++)                             ////mecbur� hamle kontrolu yap�l�r////
          for(x=0;x<8;x++)                       //////////////////////////////////////
          {
               if(oyun[x][y]==os)
               {
                     if(x<6)
                          if(oyun[x+1][y]==-os||oyun[x+1][y]==-2*os)
                               if(oyun[x+2][y]==0)
                               {
                                     mh[mhs][0]=x;             ////mecbur� hamle kontrolu SAG////
                                     mh[mhs][1]=y;
                                     mh[mhs][2]=1;
                                     mhs++;
                               }
                     if(os==-1)
                          if(y<6)
                               if((oyun[x][y+1]==-os || oyun[x][y+1]==-2*os) && oyun[x][y+2]==0)
                               {
                                     mh[mhs][0]=x;              ////mecbur� hamle kontrolu ASAGI////
                                     mh[mhs][1]=y;
                                     mh[mhs][2]=4;
                                     mhs++;
                               }
                      if(x>1)
                          if(oyun[x-1][y]==-os||oyun[x-1][y]==-2*os)
                               if(oyun[x-2][y]==0)
                               {
                                     mh[mhs][0]=x;              ////mecbur� hamle kontrolu SOLA////
                                     mh[mhs][1]=y;
                                     mh[mhs][2]=3;
                                     mhs++;
                               }
                       if(os==1)
                          if(y>1)
                               if((oyun[x][y-1]==-os || oyun[x][y-1]==-2*os) && oyun[x][y-2]==0)
                               {
                                     mh[mhs][0]=x;               ////mecbur� hamle kontrolu YUKARI////
                                     mh[mhs][1]=y;
                                     mh[mhs][2]=2;
                                     mhs++;
                               }
               }


               if(oyun[x][y]==2*os)//eger tas damaysa
               {
                        m=1;
                        for(i=y+1;i<8;i++)
                        {
                                 if(oyun[x][i]==0&&m==-1)
                                 {
                                        mh[mhs][0]=x;
                                        mh[mhs][1]=y;
                                        mh[mhs][2]=1;
                                        mhs++; break;
                                 }
                                 if(oyun[x][i]==os||oyun[x][i]==2*os) break;
                                 if(oyun[x][i]==-os||oyun[x][i]==-2*os)
                                     if(m==-1) break;
                                     else m=-1;
                        }
                        m=1;
                        for(i=y-1;i>=0;i--)
                        {
                                 if(oyun[x][i]==0&&m==-1)
                                 {
                                        mh[mhs][0]=x;
                                        mh[mhs][1]=y;
                                        mh[mhs][2]=1;
                                        mhs++; break;
                                 }
                                 if(oyun[x][i]==os||oyun[x][i]==2*os) break;
                                 if(oyun[x][i]==-os||oyun[x][i]==-2*os)
                                     if(m==-1) break;
                                     else m=-1;

                        }
                        m=1;
                        for(i=x+1;i<8;i++)
                        {
                                if(oyun[i][y]==0&&m==-1)
                                 {
                                        mh[mhs][0]=x;
                                        mh[mhs][1]=y;
                                        mh[mhs][2]=1;
                                        mhs++; break;
                                 }
                                 if(oyun[i][y]==os||oyun[i][y]==2*os) break;
                                 if(oyun[i][y]==-os||oyun[i][y]==-2*os)
                                     if(m==-1) break;
                                     else m=-1;
                        }
                        m=1;
                        for(i=x-1;i>=0;i--)
                        {
                                 if(oyun[i][y]==0&&m==-1)
                                 {
                                        mh[mhs][0]=x;
                                        mh[mhs][1]=y;
                                        mh[mhs][2]=1;
                                        mhs++; break;
                                 }
                                 if(oyun[i][y]==os||oyun[i][y]==2*os) break;
                                 if(oyun[i][y]==-os||oyun[i][y]==-2*os)
                                     if(m==-1) break;
                                     else m=-1;
                        }
               }//if(oyun[x][y]==2*os)
          }

                     }


                    }
             else//�k� uzun �f in deg�l� !
             {duzelt:
                 putimage(6+x*75,6+y*75,buf[oyun[x][y]==2*os?1:0][(x+y)%2==1?1:0],0);
                 if(os==-1)
                 {                                                  //hamle yap�lmad�g� k�rm�z� reng� normale cev�r�yor
                        setfillstyle(1,YELLOW);
                        floodfill(22+x*75,22+y*75,DARKGRAY);
                 }

             }

          }//for  oyun dongusu


     oyunsonu:
     setbkcolor(YELLOW);
     cleardevice();

     settextstyle(6,0,6);
     setcolor(BLUE);
     if(yms==16) outtextxy(200,200,"SARILAR");
     else outtextxy(200,200,"MAV�LER");

     outtextxy(220,400,"KAZANDI");

     while (!ismouseclick(WM_LBUTTONDOWN));


     closegraph();
     return 0;
}
