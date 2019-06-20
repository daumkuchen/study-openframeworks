#version 400 core
precision highp float;

in vec4 position;
in vec2 texcoord;

out vec4 vPosition;
out vec2 vTexCoord;

uniform mat4 modelViewProjectionMatrix;

void main(){

    vPosition = position;
    vTexCoord = texcoord;
    gl_Position = modelViewProjectionMatrix * position;

}