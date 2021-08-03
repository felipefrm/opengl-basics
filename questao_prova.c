#include <GL/gl.h>
#include <GL/glut.h>

void quadrado() 
{
    glBegin(GL_QUADS);
        glVertex2f(-0.5, 0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(0.5, 0.5);
    glEnd();
}

void triangulo() 
{
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, 0.0);
        glVertex2f(0.5, 0.0);
        glVertex2f(0.0,1.0);
    glEnd();
}

void display(void)
{
    glMatrixMode(GL_MODELVIEW);

/*  clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
       
    // glColor3f (0.0, 0.0, 0.0);
    // glBegin(GL_LINE_STRIP);
    //     glVertex2f(0.01, 1.0);
    //     glVertex2f(0.01, 0.01);
    //     glVertex2f(1.0, 0.01);
    // glEnd();

    glPushMatrix();
    glColor3f (0.0, 0.0, 0.0);
    glTranslatef(0.5, 0.35, 0.0);       // X = 0.5; Y = 0.3/2 + 0.2 = 0.35
    glScalef(0.1, 0.3, 1.0);            // X = 0.1; Y = 0.3
    quadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f (1.0, 1.0, 0.0);
    glTranslatef(0.5, 0.55, 0.0);   // X = 0.5; Y = 0.2 + 0.3 + 0.1/2 = 0.55
    glScalef(0.3, 0.1, 1.0);         // X = 0.3; Y = 0.1
    quadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f (1.0, 0.0, 0.0);  
    glTranslatef(0.4, 0.6, 0.0);   // X = 0.5 - 0.1; Y = 0.2 + 0.3 + 0.1 = 0.6
    glScalef(0.1, 0.1, 1.0);       // X = 0.1; Y = 0.1
    triangulo();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0.0, 0.0, 1.0);
    glTranslatef(0.6, 0.6, 0.0);    // X = 0.5 + 0.1; Y = 0.2 + 0.3 + 0.1 = 0.6
    glScalef(0.1, 0.1, 1.0);       // X = 0.1; Y = 0.1
    triangulo();
    glPopMatrix();


/*  don't wait!  
 *  start processing buffered OpenGL routines 
 */
    glFlush ();
}

void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (1.0, 1.0, 1.0, 1.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    
}

/* 
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (350, 350); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Prova");
    init();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}