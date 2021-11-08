

			#include<GL/glut.h>
			#include<iostream>
			#include<math.h>
			#include<time.h>

			using namespace std;
			void timer(int);
			void display(void);

			GLfloat angle = 0.0f, angle1 = 45.0f, angle2 = 30.0f;

			void init()
			{
				glClearColor(1.0, 1.0, 1.0, 0.0);
				glClearDepth(1.0f);
				glColor3f(1.0f, 1.0f, 1.0f);
				glPointSize(2);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(-240.0, 240.0, -240.0, 240.0, -240.0, 240.0);
			}

			int main(int argc, char **argv)
			{
				glutInit(&argc, argv);
				glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
				glutInitWindowSize(480, 480);
				glutCreateWindow("Snake And Ladder");
				glutDisplayFunc(display);
				glutTimerFunc(0, timer, 0);
				init();
				glutMainLoop();
				return 0;
			}

			void display()
			{

				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glColor3f(0.4f, 0.7f, 0.7f);
				GLfloat theta = 360.0f;
				glBegin(GL_POINTS);
				while (theta > 0.0f) {
					glVertex3f(230.0f * cos(theta), 150.0f * sin(theta), 0.0f);
					theta -= 0.05;
				}
				glEnd();
				glFlush();
				glColor3f(0.9f, 0.9f, 0.3f);
				glutSolidSphere(25.0, 25, 25);
				glColor3f(0.7f, 0.4f, 0.4f);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(230.0 * cos(angle2), 150.0 * sin(angle2), 0.0f);
				glutSolidSphere(10.0, 25, 25);
				glutSwapBuffers();
			}

			void timer(int value) {
				angle2 += 0.07f;
				
				glutPostRedisplay();
				glutTimerFunc(50, timer, 0);


			}

