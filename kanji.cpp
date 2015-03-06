//Svetoslav Iliev Krustev 80803 grupa-2
#include <GL/glfw.h>
#include <math.h>

void init()
{
    int width, height;

    glfwInit();
    if( !glfwOpenWindow( 640, 480, 0, 0, 0, 0, 8, 0, GLFW_WINDOW ) ) return;

    glfwGetWindowSize( &width, &height );
    height = height > 0 ? height : 1;

    glViewport( 0, 0, width, height );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 65.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(0.0f, -10.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f );
}

bool running()
{
    return( !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam( GLFW_OPENED) );
}

void finit()
{
    glfwTerminate();
}

void drawOxyz()
{
    // Рисуване на лъчите
    glColor3ub( 0, 0, 0 );
    glBegin( GL_LINES );
        // OX
        glVertex3f( 0.0, 0.0, 0.0 );
        glVertex3f( 5.0, 0.0, 0.0 );
        // OY
        glVertex3f( 0.0, 5.0, 0.0 );
        glVertex3f( 0.0, 0.0, 0.0 );
        // OZ
        glVertex3f( 0.0, 0.0, 5.0 );
        glVertex3f( 0.0, 0.0, 0.0 );
    glEnd();

    // Рисуване на стрелките
    glColor3ub( 0, 0, 0 );
    glBegin( GL_TRIANGLES );
        // OX
        glVertex3f( 5.0, 0.0, 0.0 );
        glVertex3f( 4.5, 0.2, 0.0 );
        glVertex3f( 4.5,-0.2, 0.0 );
        // OY
        glVertex3f( 0.0, 5.0, 0.0 );
        glVertex3f( 0.2, 4.5, 0.0 );
        glVertex3f(-0.2, 4.5, 0.0 );
        // OZ
        glVertex3f( 0.0,  0.0,  5.0 );
        glVertex3f(+0.14,-0.14, 4.5 );
        glVertex3f(-0.14,+0.14, 4.5 );
    glEnd();
}


void drawBoxTorus(float x, float y, float z, float a, float b, float c)
{

    a=a/2;
    b=b/2;
    c=c/2;

    //външни 4 стени
    //y-
    glBegin( GL_POLYGON );
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3f(x-a, y-a, z-c);
        glVertex3f(x-a, y-a, z+c);
        glVertex3f(x+a, y-a, z+c);
        glVertex3f(x+a, y-a, z-c);
    glEnd();
    //x+
    glBegin( GL_POLYGON );
        glNormal3f(1.0, 0.0, 0.0);
        glVertex3f(x+a, y-a, z+c);
        glVertex3f(x+a, y-a, z-c);
        glVertex3f(x+a, y+a, z-c);
        glVertex3f(x+a, y+a, z+c);
    glEnd();
    //y+
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(x-a, y+a, z-c);
        glVertex3f(x-a, y+a, z+c);
        glVertex3f(x+a, y+a, z+c);
        glVertex3f(x+a, y+a, z-c);
    glEnd();
    //z-
    glBegin( GL_POLYGON );
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3f(x-a, y-a, z+c);
        glVertex3f(x-a, y-a, z-c);
        glVertex3f(x-a, y+a, z-c);
        glVertex3f(x-a, y+a, z+c);
    glEnd();

    //вътрешни 4 стени
    //y-
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(x-b, y-b, z-c);
        glVertex3f(x-b, y-b, z+c);
        glVertex3f(x+b, y-b, z+c);
        glVertex3f(x+b, y-b, z-c);
    glEnd();
    //x+
    glBegin( GL_POLYGON );
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3f(x+b, y-b, z+c);
        glVertex3f(x+b, y-b, z-c);
        glVertex3f(x+b, y+b, z-c);
        glVertex3f(x+b, y+b, z+c);
    glEnd();

    //y+
    glBegin( GL_POLYGON );
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3f(x-b, y+b, z-c);
        glVertex3f(x-b, y+b, z+c);
        glVertex3f(x+b, y+b, z+c);
        glVertex3f(x+b, y+b, z-c);
    glEnd();
    //x-
    glBegin( GL_POLYGON );
        glNormal3f(1.0, 0.0, 0.0);
        glVertex3f(x-b, y-b, z+c);
        glVertex3f(x-b, y-b, z-c);
        glVertex3f(x-b, y+b, z-c);
        glVertex3f(x-b, y+b, z+c);
    glEnd();


    //Горни 4 стени
    //y-
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(x-a, y-a, z+c);
        glVertex3f(x+a, y-a, z+c);
        glVertex3f(x+b, y-b, z+c);
        glVertex3f(x-b, y-b, z+c);

    glEnd();
    //x+
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(x+a, y-a, z+c);
        glVertex3f(x+a, y+a, z+c);
        glVertex3f(x+b, y+b, z+c);
        glVertex3f(x+b, y-b, z+c);
    glEnd();

    //y+
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(x+a, y+a, z+c);
        glVertex3f(x-a, y+a, z+c);
        glVertex3f(x-b, y+b, z+c);
        glVertex3f(x+b, y+b, z+c);
    glEnd();
    //x-
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(x-a, y-a, z+c);
        glVertex3f(x-a, y+a, z+c);
        glVertex3f(x-b, y+b, z+c);
        glVertex3f(x-b, y-b, z+c);
    glEnd();

    //долни 4 стени
    //y-
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(x-a, y-a, z-c);
        glVertex3f(x+a, y-a, z-c);
        glVertex3f(x+b, y-b, z-c);
        glVertex3f(x-b, y-b, z-c);

    glEnd();
    //x+
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(x+a, y-a, z-c);
        glVertex3f(x+a, y+a, z-c);
        glVertex3f(x+b, y+b, z-c);
        glVertex3f(x+b, y-b, z-c);
    glEnd();

    //y+
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(x+a, y+a, z-c);
        glVertex3f(x-a, y+a, z-c);
        glVertex3f(x-b, y+b, z-c);
        glVertex3f(x+b, y+b, z-c);
    glEnd();
    //x-
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(x-a, y-a, z-c);
        glVertex3f(x-a, y+a, z-c);
        glVertex3f(x-b, y+b, z-c);
        glVertex3f(x-b, y-b, z-c);
    glEnd();
}

void drawUpBox(float x, float y, float z, float a, float b, float c, float angle_rad)
{
    a=a/2;
    b=b/2;
    float r=sqrt(a*a + b*b);
    float angle=angle_rad;
    float alpha=atan(b/a);
    float dx=r*cos(alpha);
    float dy=r*sin(alpha);

    //страна z+
    glBegin( GL_POLYGON );
        glNormal3f(0, 0, 1);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z+c);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z+c);
        glVertex3f(x+r*cos(-alpha +M_PI+angle - M_PI/8), y+r*sin(-alpha+M_PI+angle - M_PI/8), z+c);
        glVertex3f(x+r*cos(alpha+M_PI+angle ), y+r*sin(alpha+M_PI+angle ), z+c);
    glEnd();

    //страна z-
    glBegin( GL_POLYGON );
        glNormal3f(0, 0, -1);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z);
        glVertex3f(x+r*cos(-alpha +M_PI+angle - M_PI/8), y+r*sin(-alpha+M_PI+angle - M_PI/8), z);
        glVertex3f(x+r*cos(alpha+M_PI+angle ), y+r*sin(alpha+M_PI+angle ), z);
    glEnd();

    //околни страни
    glBegin( GL_POLYGON );
        glNormal3f( cos(angle/2), sin(angle/2), 0 );
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z+c);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z+c);
    glEnd();

    glBegin( GL_POLYGON );
        glNormal3f( cos(M_PI/2 + angle/2 - M_PI/8), sin(M_PI/2 + angle/2 - M_PI/8), 0 );
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z);
        glVertex3f(x+r*cos(-alpha +M_PI+angle - M_PI/8), y+r*sin(-alpha+M_PI+angle - M_PI/8), z);
        glVertex3f(x+r*cos(-alpha +M_PI+angle - M_PI/8), y+r*sin(-alpha+M_PI+angle - M_PI/8), z+c);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z+c);
    glEnd();

    glBegin( GL_POLYGON );
        glNormal3f( cos(M_PI + angle/2 - M_PI/8), sin(M_PI + angle/2 - M_PI/8), 0 );
        glVertex3f(x+r*cos(-alpha +M_PI+angle - M_PI/8), y+r*sin(-alpha+M_PI+angle - M_PI/8), z);
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z);
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z+c);
        glVertex3f(x+r*cos(-alpha +M_PI+angle - M_PI/8), y+r*sin(-alpha+M_PI+angle - M_PI/8), z+c);
    glEnd();

    glBegin( GL_POLYGON );
        glNormal3f( cos(-M_PI/2 + angle/2), sin(-M_PI/2 + angle/2), 0 );
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z+c);
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z+c);
    glEnd();
}

void drawRing(float x, float y, float z,float r1,float r2, float h, float start_alpha, float end_alpha)
{
    int n=64;
    float alpha= start_alpha;
    float dalpha= 2*M_PI/n;



    //рисуване на начална "тапа"
    glBegin(GL_POLYGON);
        glVertex3f(x+r1*cos(alpha), y+r1*sin(alpha), z);
        glVertex3f(x+r1*cos(alpha), y+r1*sin(alpha), z+h);
        glVertex3f(x+r2*cos(alpha), y+r2*sin(alpha), z+h);
        glVertex3f(x+r2*cos(alpha), y+r2*sin(alpha), z);
    glEnd();

    for(int i=0; i<n && alpha<end_alpha; i++)
    {
        float dx1A=r1*cos(alpha);
        float dy1A=r1*sin(alpha);

        float dx2A=r1*cos(alpha+dalpha);
        float dy2A=r1*sin(alpha+dalpha);

        float dx1B=r2*cos(alpha);
        float dy1B=r2*sin(alpha);

        float dx2B=r2*cos(alpha+dalpha);
        float dy2B=r2*sin(alpha+dalpha);

        //долна основа
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, -1);
            glVertex3f(x+dx1A, y+dy1A, z);
            glVertex3f(x+dx2A, y+dy2A, z);
            glVertex3f(x+dx2B, y+dy2B, z);
            glVertex3f(x+dx1B, y+dy1B, z);
        glEnd();

        //горна основа
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            glVertex3f(x+dx1A, y+dy1A, z+h);
            glVertex3f(x+dx2A, y+dy2A, z+h);
            glVertex3f(x+dx2B, y+dy2B, z+h);
            glVertex3f(x+dx1B, y+dy1B, z+h);
        glEnd();

        //външна околни стена
        glBegin(GL_POLYGON);
            glNormal3f( cos(alpha+dalpha/2), sin(alpha+dalpha/2), 0 );
            glVertex3f(x+dx1A, y+dy1A, z);
            glVertex3f(x+dx2A, y+dy2A, z);
            glVertex3f(x+dx2A, y+dy2A, z+h);
            glVertex3f(x+dx1A, y+dy1A, z+h);
        glEnd();

        //вътрешна околни стена
        glBegin(GL_POLYGON);
            glNormal3f(-cos(alpha+dalpha/2), -sin(alpha+dalpha/2), 0 );
            glVertex3f(x+dx2B, y+dy2B, z);
            glVertex3f(x+dx1B, y+dy1B, z);
            glVertex3f(x+dx1B, y+dy1B, z+h);
            glVertex3f(x+dx2B, y+dy2B, z+h);
        glEnd();

        alpha += dalpha;
    }

    //крайна "тапа"
    glBegin(GL_POLYGON);
        glVertex3f(x+r1*cos(alpha), y+r1*sin(alpha), z);
        glVertex3f(x+r1*cos(alpha), y+r1*sin(alpha), z+h);
        glVertex3f(x+r2*cos(alpha), y+r2*sin(alpha), z+h);
        glVertex3f(x+r2*cos(alpha), y+r2*sin(alpha), z);
    glEnd();
}

void drawBoxRotated(float x, float y, float z, float a, float b, float c, float angle_rad)
{
    a=a/2;
    b=b/2;
    float r=sqrt(a*a + b*b);
    float angle=angle_rad;
    float alpha=atan(b/a);
    float dx=r*cos(alpha);
    float dy=r*sin(alpha);

    //страна z+
    glBegin( GL_POLYGON );
        glNormal3f(0, 0, 1);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z+c);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z+c);
        glVertex3f(x+r*cos(-alpha +M_PI+angle), y+r*sin(-alpha+M_PI+angle), z+c);
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z+c);
    glEnd();

    //страна z-
    glBegin( GL_POLYGON );
        glNormal3f(0, 0, -1);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z);
        glVertex3f(x+r*cos(-alpha +M_PI+angle), y+r*sin(-alpha+M_PI+angle), z);
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z);
    glEnd();

    //околни страни
    glBegin( GL_POLYGON );
        glNormal3f( cos(angle/2), sin(angle/2), 0 );
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z+c);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z+c);
    glEnd();

    glBegin( GL_POLYGON );
        glNormal3f( cos(M_PI/2 + angle/2), sin(M_PI/2 + angle/2), 0 );
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z);
        glVertex3f(x+r*cos(-alpha +M_PI+angle), y+r*sin(-alpha+M_PI+angle), z);
        glVertex3f(x+r*cos(-alpha +M_PI+angle), y+r*sin(-alpha+M_PI+angle), z+c);
        glVertex3f(x+r*cos(alpha+angle), y+r*sin(alpha+angle), z+c);
    glEnd();

    glBegin( GL_POLYGON );
        glNormal3f( cos(M_PI + angle/2), sin(M_PI + angle/2), 0 );
        glVertex3f(x+r*cos(-alpha +M_PI+angle), y+r*sin(-alpha+M_PI+angle), z);
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z);
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z+c);
        glVertex3f(x+r*cos(-alpha +M_PI+angle), y+r*sin(-alpha+M_PI+angle), z+c);
    glEnd();

    glBegin( GL_POLYGON );
        glNormal3f( cos(-M_PI/2 + angle/2), sin(-M_PI/2 + angle/2), 0 );
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z);
        glVertex3f(x+r*cos(-alpha +angle), y+r*sin(-alpha+angle), z+c);
        glVertex3f(x+r*cos(alpha+M_PI+angle), y+r*sin(alpha+M_PI+angle), z+c);
    glEnd();

}

int main()
{
    init();

    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_LIGHTING );
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_LIGHT0 );

    while( running() )
    {
        glClear( GL_COLOR_BUFFER_BIT+GL_DEPTH_BUFFER_BIT );
        glRotatef( 0.05, 0.4, 0, 0);
        //glRotatef( 0.05, 0.4, -0.2, 0.7);

        drawOxyz();
        glColor3ub( 255, 0, 0 );

        drawBoxRotated(0, 3.5, -0.3, 6, 0.6, 0.6, 0);
        drawBoxRotated(1.0, 3.5, -0.3, 0.6, 2.0, 0.6, 0);
        drawBoxRotated(-1.0, 3.5, -0.3, 0.6, 2.0, 0.6, 0);

        drawBoxRotated(0.0, -1.0, -0.3, 6.0, 0.6, 0.6, 0);
        drawBoxRotated(0.0, -1.5, -0.3, 0.6, 3.0, 0.6, 0);

        drawBoxTorus(0.0, 1.0, 0.0, 2.0, 1.2, 0.6);
        drawBoxRotated(0.0, 1.0, -0.3, 1.2, 0.4, 0.6, 0);

        drawUpBox(0.0, 2.2, -0.3, 1, 0.5, 0.6, -1.8);

        drawRing(3.2, 0.9, -0.3, 4, 3.4, 0.6, 3.6, 4.5);
        drawRing(-3.2, 0.9, -0.3, 4, 3.4, 0.6, 4.8, 5.7);

        //zavurtqni kytii
        drawBoxRotated(-2, 1.7, -0.3, 1, 0.5, 0.6, -0.4);
        drawBoxRotated(-2, 0.5, -0.3, 1.6, 0.6, 0.6, 0.5);
        drawBoxRotated(2, 0.5, -0.3, 1.5, 0.6, 0.6, -0.45);
        drawBoxRotated(1.8, 1.7, -0.3, 1.2, 0.5, 0.6, 0.6);


        glfwSwapBuffers();
    }

    finit();
    return 0;
}
