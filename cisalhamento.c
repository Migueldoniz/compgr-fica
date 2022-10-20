/*PrimeiroPrograma - Prof. Leandro Alves Neves
 Um programa OpenGL simples que abre uma janela GLUT
 Este código está baseado no Simple.c, exemplo 
 disponível no livro "OpenGL SuperBible" e "OpenGl: uma abordagem prática e objetiva" , 
 2nd Edition, de Richard S. e Wright Jr.*/

#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

void DISPLAY ();
void Desenha();


// Inicializa parâmetros de rendering
void DISPLAY ()
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION); //Ativa matriz de projeção
    glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo possíveis erros.    
    gluOrtho2D(-200,230,-200,200);//Define tipo de projeção (2D) e o tamanho
    glMatrixMode(GL_MODELVIEW);//Ativa matriz de visualização
    glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo possíveis erros.
	//Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* "limpa" um buffer particular ou combinações de buffers, 
                                                         onde buffer é uma área de armazenamento para informações da imagem. 
                                                        Nesse caso, está "limpando os buffers para suportarem animações */
   //Chamada para Função  ou funções para desenhar o objeto/cena...
   //---------------------------------------------------------------- 
   Desenha(); 
   glutSwapBuffers();
   
}
void Desenha()
{  
    //int x=0, y=0;
   
  glColor3f(1,1,1);//Define uma cor para a primitiva	
    int x[5] = {50,70,70,40,40};
    int y[5] = {105,90,50,50,90};
    int x1=0;
    int y1=0;
    glBegin(GL_LINES);
	    glVertex3f(x[0],y[0],0);
        glVertex3f(x[1],y[1],0);
        glVertex3f(x[1],y[1],0);
        glVertex3f(x[2],y[2],0);
        glVertex3f(x[2],y[2],0);
        glVertex3f(x[3],y[3],0);
        glVertex3f(x[3],y[3],0);
        glVertex3f(x[4],y[4],0);
        glVertex3f(x[4],y[4],0);
        glVertex3f(x[0],y[0],0);
    glEnd();

    char op;
    printf("Deseja fazer o cisalhamento em x ou y? ");
    scanf("%c",&op);   
    switch (op) {
        case 'x':
        printf("Insira um valor para o cisalhamento em X:");
        scanf("%d",&x1);
        for(int i=0;i<=4;i++){
        x[i]=x[i]+x1*y[i];
        }
        break;
        case 'y':
        printf("Insira um valor para o cisalhamento em Y:");
        scanf("%d",&y1);
        for(int i=0;i<=4;i++){
        y[i]=y[i]+y1*x[i];/©»“
        }
        break;

        

    }
        glBegin(GL_LINES);
	    glVertex3f(x[0],y[0],0);
        glVertex3f(x[1],y[1],0);
        glVertex3f(x[1],y[1],0);
        glVertex3f(x[2],y[2],0);
        glVertex3f(x[2],y[2],0);
        glVertex3f(x[3],y[3],0);
        glVertex3f(x[3],y[3],0);
        glVertex3f(x[4],y[4],0);
        glVertex3f(x[4],y[4],0);
        glVertex3f(x[0],y[0],0);
        glEnd();
     
     //printf("Insira um valor para a transformação de escala  em Y:");
     //scanf("%d",&y1);

    

    
}
  //x+=2;
 /* do{
      glBegin(GL_POINTS);
	   glVertex3f(x,y,0);
           glVertex3f(-x,y,0);
           glVertex3f(-x,-y,0);
	   glVertex3f(x,-y,0);
        glEnd();	//Executa os comandos OpenGL 
      x+=1; y+=1;
   }while(x<=200);*/


int main(int argc,char **argv)
{
   glutInit(&argc, argv); // Initializes glut
    
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   /*Avisa a GLUT que modo de exibição deve ser usado quando a janela é criada. 
   //  Nesse caso, permite: uma única janela; cores compostas por Verm. Verde e Azul; e, */
   glutInitWindowSize(600,400);
   glutInitWindowPosition(100,100);
   glutCreateWindow("Aula 01 (OpenGL) - Meu Primeiro Programa");
   glutDisplayFunc(DISPLAY);
   glutMainLoop();
   return 0;
}
