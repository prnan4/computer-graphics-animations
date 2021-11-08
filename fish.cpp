#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

GLfloat xRotatad, yRotated, zRotated;
int refreshTime = 5;
GLfloat x = -0.3f;
GLfloat angle = 0.0f;
int direction = -1;
void display(void);
void reshape(int, int);
void timer(int);
void init()
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(350, 350);
	glutCreateWindow("3d Scenes");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(x, 0.0f, -5.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glScalef(1.0f, 0.5f, 1.0f);
	glutSolidSphere(0.5, 25, 25);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.8f, 0.25f, 0.0f);
	glVertex3f(0.8f, -0.25f, 0.0f);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void reshape(int x, int y)
{
	if (x == 0 || y == 0) {
		return;
	}
	GLdouble aspect = (GLdouble)x / (GLdouble)y;
	glViewport(0, 0, x, y);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.6, 21.0);	

}

void timer(int value)
{
	x += direction*0.005f;
	if (x > 1.0f || x < -1.0f) {
		direction = 0 - direction;
		angle = 180.0f - angle;
	}
	
	glutPostRedisplay();
	glutTimerFunc(refreshTime, timer, 0);
}
