#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.14
GLfloat sec_angle=90,min_angle=0,hr_angle=270;
GLfloat factor=pi/180;
GLfloat angle=0.0;
void init(){
  glClearColor(0.5,0.5,0.5,0.0);
  glColor3f(0.0,0.0,0.0);
  glPointSize(3);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-240.0,240.0,-240.0,240.0);
}
void midpoint(int xc,int yc,int r){
  int p=1-r;
  int x1=0;
  int y1=r;
  for(int i=0;x1<=y1;i++){
      if(p<=0){
         x1+=1;
         p=p+(2*x1)+1;
      }
      else if(p>0){
         x1+=1;
         y1-=1;
         p=p+(2*x1)+1-(2*y1); }
 
        glVertex2d(xc+x1 ,yc+y1 );
        glVertex2d(xc+y1 ,yc+x1 );
        glVertex2d(xc-x1 ,yc+y1 );
        glVertex2d(xc+y1 ,yc-x1 );
        glVertex2d(xc-x1 ,yc-y1 );
        glVertex2d(xc-y1 ,yc-x1 );
	glVertex2d(xc-y1 ,yc+x1 );
	glVertex2d(xc+x1 ,yc-y1 ); 
 }
}

void myDisplay(){
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POINTS);
   glColor3f(0.0,0.0,0.0);
   midpoint(0,0,100);
   int i=0;
   angle=0;
   /*while(i<12)
   {
     glVertex2d(90*cos(angle*factor),90*sin(angle*factor));
     i++;
     angle+=30;
   }*/
   glEnd();   
   glBegin(GL_LINES);
   glColor3f(1.0,0.0,1.0);
   glVertex2d(0,0);
   glVertex2d(100*cos(sec_angle*factor),100*sin(sec_angle*factor));
   glColor3f(1.0,1.0,0.0);
   glVertex2d(0,0);
   glVertex2d(75*cos(min_angle*factor),75*sin(min_angle*factor));
   glColor3f(0.0,1.0,1.0);
   glVertex2d(0,0);
   glVertex2d(50*cos(hr_angle*factor),50*sin(hr_angle*factor));
   glEnd();
   
   glFlush();
 }



void timer(int value){
  sec_angle-=6;
 
     min_angle-=6;
   
        hr_angle-=6;
    
   glutPostRedisplay();
   glutTimerFunc(100,timer,0); }

int main(int argc,char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(480,480);
  glutCreateWindow("Analog CLock");
  init();
  glutDisplayFunc(myDisplay);
  glutTimerFunc(1000,timer,0);
  glutMainLoop();
  return 0;
}
