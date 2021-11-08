#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

int val1=0,val2=0;
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
   glBegin(GL_LINE_LOOP);
   glVertex2d(-50,-10);
   glVertex2d(-50,90);
   glVertex2d(50,90);
   glVertex2d(50,-10);
   glEnd();
   glBegin(GL_LINE_LOOP);
   glVertex2d(45,0);
   glVertex2d(-45,0);
   glVertex2d(-45,80);
   glVertex2d(45,80);
   glEnd();
   glBegin(GL_POINTS);
   midpoint(-45,-5,5);
    midpoint(-45,85,5);
   midpoint(45,85,5);
   midpoint(45,-5,5);
   //glTranslatef(val1,val2,0.0);
   midpoint(val1,val2,5);
   glEnd();
   glFlush();
 }



void timer(int value){
  if(val2<=85){
      val2+=1;
      val1+=1;
   }

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
