#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void DesenhaCirculo(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); //calcula o angulo 
        float x = r * cosf(theta); //calcula o ponto x
        float y = r * sinf(theta); //calcula o ponto y 
        glVertex2f(x + cx, y + cy); 
    }
    glEnd();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // gramado
     glBegin(GL_QUADS);
     glColor3f(0.1f, 0.5f, 0.1f);
     glVertex2i(0, 20);
     glVertex2i(0, 0);
     glVertex2i(300, 0);
     glVertex2i(300, 20);               
     glEnd();

     // frente da casa
     glBegin(GL_QUADS);
     glColor3f(1.0f, 0.5f, 0.0f);
     glVertex2i(100, 80);
     glVertex2i(100, 10);
     glVertex2i(200, 10);
     glVertex2i(200, 80);               
     glEnd();

     // lateral da casa
     glBegin(GL_POLYGON);
     glColor3f(0.9f, 0.4f, 0.0f);
     glVertex2i(200, 80);
     glVertex2i(200, 10);
     glVertex2i(250, 20);
     glVertex2i(250, 90);               
     glEnd();
     

     // telhado frente
     glBegin(GL_TRIANGLES);
     glColor3f(0.8f, 0.0f, 0.0f);
     glVertex2i(90, 80);
     glVertex2i(150, 130);
     glVertex2i(210, 80);
     glEnd();

      // telhado lado
     glBegin(GL_POLYGON);
     glColor3f(0.6f, 0.0f, 0.0f);
     glVertex2i(150, 130);
     glVertex2i(210, 80);
     glVertex2i(255, 90);
     glVertex2i(200, 130);
     glEnd();

     // porta
     glBegin(GL_QUADS);
     glColor3f(0.6f, 0.4f, 0.12f);
     glVertex2i(140, 60);
     glVertex2i(140, 10);
     glVertex2i(160, 10);
     glVertex2i(160, 60);               
     glEnd();

     // porta
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2i(145, 35);
     glEnd();

     // janela1
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.5f, 1.0f);
     glVertex2i(170, 60);
     glVertex2i(170, 40);
     glVertex2i(190, 40);
     glVertex2i(190, 60);               
     glEnd();

     // janela2
     glBegin(GL_QUADS);
     glVertex2i(110, 60);
     glVertex2i(110, 40);
     glVertex2i(130, 40);
     glVertex2i(130, 60);               
     glEnd();

     // janela lateral
     glBegin(GL_QUADS);
     glVertex2i(220, 63);
     glVertex2i(220, 43);
     glVertex2i(240, 48);
     glVertex2i(240, 68);              
     glEnd();
     

     // janela redonda
     DesenhaCirculo(150, 100, 10, 100);

     // grades da janela
     glColor3f(0.0f, 0.0f, 0.0f);
     glBegin(GL_LINES);
     glVertex2i(150, 110);
     glVertex2i(150, 90);
     glVertex2i(140, 100);
     glVertex2i(160, 100);
     glEnd();
     
     // arvore
     glBegin(GL_TRIANGLES);
     glColor3f(0.1f, 0.5f, 0.1f);
     glVertex2i(25, 30);
     glVertex2i(40, 45);
     glVertex2i(55, 30);
     glVertex2i(30, 40);
     glVertex2i(40, 55);
     glVertex2i(50, 40);
     glVertex2i(33, 50);
     glVertex2i(40, 60);
     glVertex2i(48, 50);
     glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.6f, 0.4f, 0.12f);
     glVertex2i(38, 30);
     glVertex2i(38, 15);
     glVertex2i(42, 15);
     glVertex2i(42, 30);               
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    if (key == 27) { // ESC
        glutDestroyWindow(glutGetWindow());
    }
}

// Programa Principal 
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("5. Casinha 2D");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutKeyboardFunc(GerenciaTeclado);
     Inicializa();
     glutMainLoop();
}