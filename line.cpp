#define GL_SILENCE_DEPRECATION
#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define NENDS 2/* number of end "points" to draw */
#define width 500
#define height 500
int ends[NENDS][2];       /* array of 2D points */

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
       for (int i = 0; i < NENDS; ++i) {
         glVertex2iv((GLint *) ends[i]);
       }
    glEnd();
    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
      ends[0][0] = (int)(0.25*width);  /* (0,0) is the lower left corner */
      ends[0][1] = (int)(0.75*height);
      ends[1][0] = (int)(0.75*width);
      ends[1][1] = (int)(0.25*height);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Points");
    glutDisplayFunc(display);

    myinit();
    glutMainLoop();
}
