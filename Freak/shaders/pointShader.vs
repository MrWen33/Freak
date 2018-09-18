#version 330 core
uniform vec3 aPos;
void main(){
	gl_Position = vec4(aPos.x, aPos.y, 0, 1.0);
    gl_PointSize = 80;
}