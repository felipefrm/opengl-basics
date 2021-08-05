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

    float triangle_w = 1.0, triangle_h = 1.0, black_rectangle_w = 1.0, 
    black_rectangle_h = 3.0, yellow_rectangle_w = 3.0, yellow_rectangle_h = 1.0;

    glPushMatrix();

        // desenha o retangulo preto, iniciando em x = 5 e y = 2
        glTranslatef(5.0, 2.0 + black_rectangle_h/2.0, 0.0);  
        glColor3f (0.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(black_rectangle_w, black_rectangle_h, 10.0);  
            quadrado();
        glPopMatrix();
   
        // transalada para imediatamente acima do retangulo preto 
        glTranslatef(0.0, black_rectangle_h/2.0, 0.0); 

        // desenha o retangulo amarelo
        glColor3f (1.0, 1.0, 0.0);
        glTranslatef(0.0, yellow_rectangle_h/2.0, 0.0);
        glPushMatrix();
            glScalef(yellow_rectangle_w, yellow_rectangle_h, 10.0);      
            quadrado();
        glPopMatrix();

        // translada para imediatamente acima do retangulo amarelo
        glTranslatef(0.0, yellow_rectangle_h/2.0, 0.0); 
        glScalef(triangle_w, triangle_h, 10.0);     
        
        // desenha o triangulo ma extremidade esquerda do retangulo amarelo
        glPushMatrix();
            glColor3f (1.0, 0.0, 0.0);  
            glTranslatef(-yellow_rectangle_w/2.0 + triangle_w/2.0, 0.0, 0.0);   
            triangulo();
        glPopMatrix();

        // desenha o triangulo ma extremidade direita do retangulo amarelo
        glPushMatrix();
            glColor3f (0.0, 0.0, 1.0);
            glTranslatef(yellow_rectangle_w/2.0 - triangle_w/2.0, 0.0, 0.0);   
            triangulo();
        glPopMatrix();

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
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
    
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
    glutCreateWindow ("Questão da Prova");
    init();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}