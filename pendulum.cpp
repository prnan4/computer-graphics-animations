#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.14
GLfloat angle1=30,angle2=150,angle3=270,x1val,y1val,x2val,y2val,x3val,y3val;
int dir=1;
GLfloat factor=pi/180;
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
         x1+=3;
         p=p+(2*x1)+1;
      }
      else if(p>0){
         x1+=3;
         y1-=3;
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
   midpoint(0,0,100);
   glEnd();
   x1val=100*cos(angle1*factor);
   y1val=100*sin(angle1*factor);
   x2val=100*cos(angle2*factor);
   y2val=100*sin(angle2*factor);
   x3val=100*cos(angle3*factor);
   y3val=100*sin(angle3*factor);
   glBegin(GL_TRIANGLES);
   glVertex2d(x1val,y1val);
   glVertex2d(x2val,y2val);
   glVertex2d(x3val,y3val);
   glEnd();
   glFlush();
 }



void timer(int value){
   angle1+=10;
   angle2+=10;
   angle3+=10;
   if(angle1>360)
      angle1=0;
   if(angle2>360)
      angle2=0;
   if(angle3>360)
      angle3=0;
   glutPostRedisplay();
   glutTimerFunc(100,timer,0); 
}

int main(int argc,char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(480,480);
  glutCreateWindow("Analog CLock");
  init();
  glutDisplayFunc(myDisplay);
  glutTimerFunc(100,timer,0);
  glutMainLoop();
  return 0;
}
