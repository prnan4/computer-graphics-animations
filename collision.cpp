#include<GL/glut.h>
#include<iostream>

using namespace std;
int ball=1;
int x=-200,y=0;
void init()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glClearDepth(1.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-240.0, 240.0, -240.0, 240.0, -240.0, 240.0);
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  
  if(ball==1){
   glLoadIdentity();
    glColor3f(0.9,0.7,0.7);
   glutSolidSphere(20,25,25); 
   glLoadIdentity();
  glTranslatef(x,0.0,0.0);
  glColor3f(1.0,0.0,0.0);
  glutSolidSphere(20,25,25);
  }
  
   if(ball==2){
    glLoadIdentity();
  glTranslatef(x,0.0,0.0);
  glColor3f(1.0,0.0,0.0);
  glutSolidSphere(20,25,25); 
  glLoadIdentity();
   glTranslatef(y,0.0,0.0);
  glColor3f(0.9,0.7,0.7);
  glutSolidSphere(20,25,25);
   }
 glFlush();
 glutSwapBuffers();
}
  
void timer(int value){
  if(x<-40)
    x+=1;
  if(ball==2 && y<220)
    y+=1;
  if(x==-40){  
    ball=2;
     }
  if(y==220)
   {
     x=-200;
      ball=1;
     y=0; } //stays in the same place
  glutPostRedisplay();
  glutTimerFunc(10,timer,0);
}
int main(int argc,char* argv[])
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(480,480);
  glutCreateWindow("Collision");
  init();
  glutDisplayFunc(display);
  glutTimerFunc(10,timer,0);
  glutMainLoop();
  return 0;
}
  
