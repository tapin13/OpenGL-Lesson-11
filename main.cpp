#include "GL/freeglut.h"
#include "GL/gl.h"

float WinWid = 400.0;
float WinHei = 400.0;

float rot = 0.0;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -100.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(15.0, 20.0, 20.0);
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
        glRotatef(rot, 0.0, 1.0, 0.0);
        glTranslatef(60.0, 0.0, 0.0);
        glutSolidSphere(5.0, 20.0, 20.0);
    glPopMatrix();
    glPushMatrix();
        glRotatef(45, 1.0, 0.0, 0.0);
        glRotatef(rot-50.0, 0.0, 1.0, 0.0);
        glTranslatef(80.0, 0.0, 0.0);
        glutSolidSphere(5.0, 20.0, 20.0);
    glPopMatrix();
    rot+=10;
    if(rot >= 360) {
        rot -= 360;
    }
    glDisable(GL_DEPTH_TEST);
    glutSwapBuffers();
}

void Timer(int v) {
    glutPostRedisplay();
    glutTimerFunc(100, Timer, 0);
    Draw();
}

void Initsialaize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
    gluPerspective(90.0 , 1, 1.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Lesson 11");
    
    glutDisplayFunc(Draw);
    glutTimerFunc(100, Timer, 0);
    Initsialaize();
    glutMainLoop();
    
    return 0;
}