#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 resolution;
uniform float time;

void main() {
    vec2 uv = gl_FragCoord.xy / resolution.xy;
    vec3 color = 0.5 + 0.5 * cos(time + uv.xyx + vec3(0.0, 2.0, 4.0));
    gl_FragColor = vec4(color, 1.0);
}
