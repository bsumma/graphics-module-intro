/* sierpinski gasket with vertex arrays */

#include "Angel.h"
#include "shader.h"

using namespace std;

GLuint tri_vao;
GLuint tri_buffer;

GLuint vloc;

vec2 triangle[3]        = { vec2( -1.0, -1.0 ),  vec2( 0.0, 1.0 ),  vec2( 1.0, -1.0 ) };

//----------------------------------------------------------------------------

void
init( void )
{
  
    // Create a vertex array object
    glGenVertexArraysAPPLE( 1, &tri_vao );
  
    //Set GL state to use vertex array object
    glBindVertexArrayAPPLE( tri_vao );
  
    //Generate buffer to hold our vertex data
    glGenBuffers( 1, &tri_buffer );
  
    //Set GL state to use this buffer
    glBindBuffer( GL_ARRAY_BUFFER, tri_buffer );
  
    //Send vertex data to GPU
    glBufferData( GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW );
  
    // Load shaders
    std::string vshader = shader_path + "vshader_simple.glsl";
    std::string fshader = shader_path + "fshader_simple.glsl";
    GLuint program = InitShader( vshader.c_str(), fshader.c_str() );
  
    //Set GL state to use shader program
    glUseProgram( program );
  
    // Initialize the vertex position attribute from the vertex shader
    vloc = glGetAttribLocation( program, "vPosition" );
    //Enable it
    glEnableVertexAttribArray( vloc );

    //Reset state back to inital (optional)
    glBindVertexArrayAPPLE(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);

    glClearColor( 1.0, 1.0, 1.0, 1.0 ); /* white background */
}

//----------------------------------------------------------------------------

void
display( void )
{
    glClear( GL_COLOR_BUFFER_BIT );
  
    //Set GL state to use this vertex array
    glBindVertexArrayAPPLE( tri_vao );
    //Set GL state to use this buffer
    glBindBuffer( GL_ARRAY_BUFFER, tri_buffer );
    //Use this Attribute pointer
    glVertexAttribPointer( vloc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    //Draw
    glDrawArrays( GL_TRIANGLES, 0, 3 );
  
    glBindVertexArrayAPPLE(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);

    glFlush();
}

//----------------------------------------------------------------------------

void
keyboard( unsigned char key, int x, int y )
{
    switch ( key ) {
    case 033:
    case 'q':
        exit( EXIT_SUCCESS );
        break;
    }
}

//----------------------------------------------------------------------------

int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA );
    glutInitWindowSize( 768, 768 );
    glutCreateWindow( "Simple GLSL example" );

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );

    glutMainLoop();
    return 0;
}
