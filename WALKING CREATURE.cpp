#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>

float cameraX = 0.0;
float cameraY = 0.0;
float cameraZ = 5.0;

float rotationAngle = 0.0;
float rotationSpeed = 2.0; // Adjust the rotation speed as needed
float moveSpeed = 0.1;    // Adjust the movement speed as needed

// Define leg rotation speeds
float frontLeftLegRotationSpeed = 1.0;
float frontRightLegRotationSpeed = -1.0;
float backLeftLegRotationSpeed = -1.0;
float backRightLegRotationSpeed = 1.0;
float lowerneckRotationSpeed = 0.2;  // Rotation speed for lower neck
float faceRotationSpeed = 0.2;  // Rotation speed for face

float frontLeftLegRotation = 0.0;  // Rotation angle for front left leg
float frontRightLegRotation = 0.0; // Rotation angle for front right leg
float backLeftLegRotation = 0.0;   // Rotation angle for back left leg
float backRightLegRotation = 0.0;  // Rotation angle for back right leg

float lowerneck = 0.0;  // Rotation angle for lower neck
float face = 0.0;  // Rotation angle for face


float maxLegRotation = 20.0; // Maximum leg rotation angle
float maxNeck = 5.0;

// Variables for mouse movement
int prevMouseX = 0;
int prevMouseY = 0;
bool mouseMoved = false;

float cameraYaw = 0.0;
float cameraPitch = 0.0;

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            cameraYaw += rotationSpeed; // Adjust the camera's yaw (horizontal) rotation
            break;
        case GLUT_KEY_RIGHT:
            cameraYaw -= rotationSpeed; // Adjust the camera's yaw (horizontal) rotation
            break;
        case GLUT_KEY_UP:
            // Move the camera forward along its viewing direction
            cameraX -= moveSpeed * sin(cameraYaw * 3.14159265 / 180.0);
            cameraZ += moveSpeed * cos(cameraYaw * 3.14159265 / 180.0);
            break;
        case GLUT_KEY_DOWN:
            // Move the camera backward along its viewing direction
            cameraX += moveSpeed * sin(cameraYaw * 3.14159265 / 180.0);
            cameraZ -= moveSpeed * cos(cameraYaw * 3.14159265 / 180.0);
            break;
        case GLUT_KEY_PAGE_UP:
            // Move the camera upward along the Y-axis
            cameraY += moveSpeed;
            break;
        case GLUT_KEY_PAGE_DOWN:
            // Move the camera downward along the Y-axis
            cameraY -= moveSpeed;
            break;
    }
    glutPostRedisplay();
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0}; // Light source position
    GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0};   // Ambient light
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};   // Diffuse light
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};  // Specular light

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

void drawTreeAt(float x, float z) {
    glPushMatrix();
    glTranslatef(0, -0.5, -4); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //2nd
    glPushMatrix();
    glTranslatef(1, -0.5, -4); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //3rd
    glPushMatrix();
    glTranslatef(2, -0.5, -4); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //4th
    glPushMatrix();
    glTranslatef(3, -0.5, -4); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //5th
    glPushMatrix();
    glTranslatef(-3, -0.5, -4); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //6th
    glPushMatrix();
    glTranslatef(-2, -0.5, -4); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //7th
    glPushMatrix();
    glTranslatef(-1, -0.5, -4); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //8th
    glPushMatrix();
    glTranslatef(-1, -0.5, -2); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //8th
    glPushMatrix();
    glTranslatef(1, -0.5, -2); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //8th
    glPushMatrix();
    glTranslatef(3, -0.5, -2); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //8th
    glPushMatrix();
    glTranslatef(5, -0.5, -2); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //8th
    glPushMatrix();
    glTranslatef(-5, -0.5, -2); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();

    //8th
    glPushMatrix();
    glTranslatef(-3, -0.5, -2); // Position the tree at the specified x and z coordinates
    glColor3f(0.36f, 0.25f, 0.20f); // Brown color for the trunk
    glBegin(GL_QUADS); // Draw the trunk as a simple quadrilateral
    glVertex3f(-0.05, 0.0, -0.05);
    glVertex3f(-0.05, 1.0, -0.05); // Increase the height of the trunk
    glVertex3f(0.05, 1.0, -0.05);  // Increase the height of the trunk
    glVertex3f(0.05, 0.0, -0.05);
    glEnd();

    // Draw leaves
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for leaves
    glTranslatef(0.0, 1.0, 0.0); // Move to the top of the trunk
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate for 3D appearance
    glScalef(1.5,4.0,5.0);
    glutSolidCone(0.15, 0.4, 20, 5); // Draw a cone as leaves
    glPopMatrix();


}


void display() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST); // Enable depth testing


    glLoadIdentity();
    // Apply camera rotation
    gluLookAt(
        cameraX, cameraY, cameraZ,
        cameraX + sin(cameraYaw * 3.14159265 / 180.0), cameraY + sin(cameraPitch * 3.14159265 / 180.0), cameraZ - cos(cameraYaw * 3.14159265 / 180.0),
        0.0, 1.0, 0.0
    );


    // Draw the green floor
    glColor3f(0.0, 1.0, 0.0); // Set color to green
    glBegin(GL_QUADS);
    glVertex3f(-10.0, -0.5, -10.0); // Define vertices
    glVertex3f(-10.0, -0.5, 10.0);
    glVertex3f(10.0, -0.5, 10.0);
    glVertex3f(10.0, -0.5, -10.0);
    glEnd();





    // Apply rotation
    glPushMatrix();
    glRotatef(rotationAngle, 0.0, 1.0, 0.0); // Rotate around the Y-axis

    // Left Eye
    glPushMatrix();
    glColor4f(0.0, 0.0, 0.0, 1.0);
    glTranslatef(-0.85, 0.23, 0.05); // Translate to the left eye position
    glRotatef(90.0 + face, 0.0, 0.0, 1.0); // Use the same face rotation angle
    glColor3f(1.0, 1.0, 1.0); // Set eye color (white)
    glutSolidSphere(0.05, 20, 10); // Draw the left eye as a white sphere
    glPopMatrix();

    // Right Eye
    glPushMatrix();
    glColor4f(0.0, 0.0, 0.0, 1.0);
    glTranslatef(-0.85, 0.23,-0.05); // Translate to the right eye position
    glRotatef(90.0 + face, 0.0, 0.0, 1.0); // Use the same face rotation angle
    glColor3f(1.0, 1.0, 1.0); // Set eye color (white)
    glutSolidSphere(0.05, 20, 10); // Draw the right eye as a white sphere
    glPopMatrix();

    // Draw a tree at the far end of the camera view
    drawTreeAt(8.0, -8.0);

    initLighting(); // Initialize lighting

    // Define a light brown color
    GLfloat light_brown_diffuse[] = {0.6, 0.4, 0.2, 1.0};

    // Front left leg
    glPushMatrix();
    glTranslatef(-0.35, -0.3, 0.15);
    glRotatef(frontLeftLegRotation, 0.0, 0.0, 1.0); // Rotate the front left leg
    glScalef(0.4, 1.0, 0.4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse); // Set material color
    glutSolidSphere(0.25, 20, 5);
    glPopMatrix();

    // Front right leg
    glPushMatrix();
    glTranslatef(-0.35, -0.3, -0.15);
    glRotatef(frontRightLegRotation, 0.0, 0.0, 1.0); // Rotate the front right leg
    glScalef(0.4, 1.0, 0.4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
    glutSolidSphere(0.25, 20, 5);
    glPopMatrix();

    // Back left leg
    glPushMatrix();
    glTranslatef(0.35, -0.3, 0.15);
    glRotatef(backLeftLegRotation, 0.0, 0.0, 1.0); // Rotate the back left leg
    glScalef(0.4, 1.0, 0.4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
    glutSolidSphere(0.25, 20, 5);
    glPopMatrix();

    // Back right leg
    glPushMatrix();
    glTranslatef(0.35, -0.3, -0.15);
    glRotatef(backRightLegRotation, 0.0, 0.0, 1.0); // Rotate the back right leg
    glScalef(0.4, 1.0, 0.4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
    glutSolidSphere(0.25, 20, 5);
    glPopMatrix();


    // Body
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(2.0, 0.5, 1.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
    glutSolidSphere(0.25, 20, 5);
    glPopMatrix();

    // Neck lower
    glPushMatrix();
    glTranslatef(-0.6, 0.1, 0.0);
    glRotatef(45.0 + lowerneck, 0.0, 0.0, 1.0);
    glScalef(0.4, 1.0, 0.4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
    glutSolidSphere(0.25, 20, 5);
    glPopMatrix();

    // Neck connection
    glPushMatrix();
    glTranslatef(-0.45, 0.0, 0.0);
    glScalef(0.5, 0.5, 0.4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
    glutSolidSphere(0.15, 20, 5);
    glPopMatrix();

    // face
    glPushMatrix();
    glTranslatef(-0.85, 0.2, 0.0);
    glRotatef(90.0 + face, 0.0, 0.0, 1.0);
    glScalef(0.4, 1.0, 0.4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
    glutSolidSphere(0.25, 20, 5);
    glPopMatrix();


// Front left leg connection
glPushMatrix();
glTranslatef(-0.4, -0.1, 0.15);
glRotatef(frontLeftLegRotation, 0.0, 0.0, 1.0); // Apply the same rotation as the leg
glTranslatef(0.05, 0.0, 0.0); // Translate along the X-axis
glScalef(0.5, 0.5, 0.4);
glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
glutSolidSphere(0.15, 20, 5);
glPopMatrix();

// Front right leg connection
glPushMatrix();
glTranslatef(0.4, -0.1, 0.15);
glRotatef(frontRightLegRotation, 0.0, 0.0, 1.0); // Apply the same rotation as the leg
glTranslatef(-0.05, 0.0, 0.0); // Translate along the X-axis
glScalef(0.5, 0.5, 0.4);
glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
glutSolidSphere(0.15, 20, 5);
glPopMatrix();

// Back left leg connection
glPushMatrix();
glTranslatef(-0.4, -0.1, -0.15);
glRotatef(backLeftLegRotation, 0.0, 0.0, 1.0); // Apply the same rotation as the leg
glTranslatef(0.05, 0.0, 0.0); // Translate along the X-axis
glScalef(0.5, 0.5, 0.4);
glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
glutSolidSphere(0.15, 20, 5);
glPopMatrix();

// Back right leg connection
glPushMatrix();
glTranslatef(0.4, -0.1, -0.15);
glRotatef(backRightLegRotation, 0.0, 0.0, 1.0); // Apply the same rotation as the leg
glTranslatef(-0.05, 0.0, 0.0); // Translate along the X-axis
glScalef(0.5, 0.5, 0.4);
glMaterialfv(GL_FRONT, GL_DIFFUSE, light_brown_diffuse);
glutSolidSphere(0.15, 20, 5);
glPopMatrix();


    glPopMatrix(); // End rotation

    glDisable(GL_DEPTH_TEST); // Disable depth testing
    glDisable(GL_LIGHTING);   // Disable lighting for the rest of the scene

    /* flush drawing routines to the window */
    glutSwapBuffers();
}

void animate(int value) {
    frontLeftLegRotation += frontLeftLegRotationSpeed; // Update front left leg rotation angle
    frontRightLegRotation += frontRightLegRotationSpeed; // Update front right leg rotation angle
    backLeftLegRotation += backLeftLegRotationSpeed; // Update back left leg rotation angle
    backRightLegRotation += backRightLegRotationSpeed; // Update back right leg rotation angle
    lowerneck += lowerneckRotationSpeed;
    face += faceRotationSpeed;

    // Apply maximum leg rotation limit
    if (frontLeftLegRotation > maxLegRotation || frontLeftLegRotation < -maxLegRotation)
        frontLeftLegRotationSpeed *= -1;
    if (frontRightLegRotation > maxLegRotation || frontRightLegRotation < -maxLegRotation)
        frontRightLegRotationSpeed *= -1;
    if (backLeftLegRotation > maxLegRotation || backLeftLegRotation < -maxLegRotation)
        backLeftLegRotationSpeed *= -1;
    if (backRightLegRotation > maxLegRotation || backRightLegRotation < -maxLegRotation)
        backRightLegRotationSpeed *= -1;
    if (lowerneck > maxNeck || lowerneck < -maxNeck)
        lowerneckRotationSpeed *= -1;
    if (face > maxNeck || face < -maxNeck)
        faceRotationSpeed *=-1;

     if (mouseMoved) {
        // Adjust camera rotation based on mouse movement
        rotationAngle += (prevMouseX - glutGet(GLUT_WINDOW_WIDTH) / 2) * 0.1;
        glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2); // Reset mouse position
        prevMouseX = glutGet(GLUT_WINDOW_WIDTH) / 2;
        prevMouseY = glutGet(GLUT_WINDOW_HEIGHT) / 2;
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, animate, 0); // 60 FPS animation
}

void mouseMotion(int x, int y) {
    if (prevMouseX == 0 && prevMouseY == 0) {
        prevMouseX = x;
        prevMouseY = y;
    } else {
        rotationAngle += (x - prevMouseX) * 0.1;
        glutWarpPointer(prevMouseX, prevMouseY); // Reset mouse position
    }
    mouseMoved = true;
}

int main(int argc, char* argv[]) {
    /* initialize GLUT, using any command-line parameters passed to the program */
    glutInit(&argc, argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Enable depth buffer and double buffering

    /* create and set up a window */
    glutCreateWindow("Hello, Oval Spheres!");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); // Register reshape callback
    glutSpecialFunc(specialKeys); // Register special key callback

    glutTimerFunc(0, animate, 0); // Start the animation timer

    // Register mouse motion callback
    glutPassiveMotionFunc(mouseMotion);

    glutSetCursor(GLUT_CURSOR_NONE); // Hide the mouse cursor

    /* tell GLUT to wait for events */
    glutMainLoop();
}
