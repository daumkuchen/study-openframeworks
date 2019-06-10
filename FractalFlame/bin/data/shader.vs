#version 150
precision mediump float;

// from oF default params
uniform mat4 modelViewProjectionMatrix;
in vec4 position;
out vec4 color;

// uniform data
uniform float uWeight[2];
uniform float uAffineParams[18];
uniform float uVariationParams[15];
uniform float uColorParams[9];
uniform vec2 uScale;
uniform vec2 uShift;
uniform int uNumColor;
uniform float uSeed;

// random func
float random(inout vec2 randomVec2) {
    
    float r = fract(sin(dot(randomVec2, vec2(12.9898, 78.233))) * 43758.5453);
    randomVec2[0] = randomVec2[1];
    randomVec2[1] = r;
    
    return r;
    
}

void affine(inout vec2 p, in float a, in float b, in float c, in float d, in float e, in float f) {
    
    float x = p.x;
    float y = p.y;
    
    p.x = a*x + b*y + c;
    p.y = d*x + e*y + f;
    
}

// linear
vec2 var1(in vec2 p) {
    vec2 _p = vec2(p.xy);
    return _p;
}

// spherical
vec2 var2(in vec2 p, in float r2) {
    vec2 _p = vec2(p.xy);
    _p = _p / r2;
    
    return _p;
}

// Fisheye
vec2 var3(in vec2 p, in float r2) {
    vec2 _p = vec2(p.xy);
    float r = sqrt(r2);
    _p = _p * (2.0 / (r + 1.0));
    
    return _p;
}

// tangent
vec2 var4(in vec2 p) {
    vec2 _p = vec2(sin(p.x)/cos(p.y), tan(p.y));
    return _p;
}

// bubble
vec2 var5(in vec2 p, in float r2) {
    vec2 _p = vec2(p.xy);
    _p = _p * (4.0 / (r2 + 4.0));
    return _p;
}

void variation(inout vec2 p, in float v1, in float v2, in float v3, in float v4, in float v5) {
    float r2 = p.x * p.x + p.y * p.y + 0.00001;
    p = var1(p) * v1 + var2(p, r2) * v2 + var3(p, r2) * v3 + var4(p) * v4 + var5(p, r2) * v5;
}

void main() {
    
    float weight2 = uWeight[0] + uWeight[1];
    if (weight2 > 0.9999) weight2 = 1.0001;
    
    vec3 count = vec3(0.0);
    int firstColorIteration = 9 - uNumColor;
    
    vec2 p2 = vec2(position.xy);
    
    vec2 randomVec2 = vec2(p2.x * uSeed, p2.y * fract(uSeed * 100.0));
    float randomN;
    
    for (int i = 0; i < 21; i++) {
        randomN = random(randomVec2);
        
        if (randomN < uWeight[0]) {
            affine(p2, uAffineParams[0], uAffineParams[1], uAffineParams[2], uAffineParams[3], uAffineParams[4], uAffineParams[5]);
            variation(p2, uVariationParams[0], uVariationParams[1], uVariationParams[2], uVariationParams[3], uVariationParams[4]);
            if (i >= firstColorIteration) count[0]++;
        } else if (randomN < weight2) {
            affine(p2, uAffineParams[6], uAffineParams[7], uAffineParams[8], uAffineParams[9], uAffineParams[10], uAffineParams[11]);
            variation(p2, uVariationParams[5], uVariationParams[6], uVariationParams[7], uVariationParams[8], uVariationParams[9]);
            if (i >= firstColorIteration) count[1]++;
        } else {
            affine(p2, uAffineParams[12], uAffineParams[13], uAffineParams[14], uAffineParams[15], uAffineParams[16], uAffineParams[17]);
            variation(p2, uVariationParams[10], uVariationParams[11], uVariationParams[12], uVariationParams[13], uVariationParams[14]);
            if (i >= firstColorIteration) count[2]++;
        }
    }
    
    p2.x = (p2.x * uScale.x) + uShift.x;
    p2.y = (p2.y * uScale.y) + uShift.y;
    
    // define color
    vec3 colorWeight = vec3(0.0);
    colorWeight[0] = min(1.0 / (uWeight[0] + 0.00001), 3.0);
    colorWeight[1] = min(1.0 / (uWeight[1] + 0.00001), 3.0);
    colorWeight[2] = min(1.0 / (1.00001 - weight2), 3.0);
    
    colorWeight = count * colorWeight;
    colorWeight = (colorWeight/(colorWeight[0]+colorWeight[1]+colorWeight[2])) * 1.5;
    color.r = uColorParams[0] * colorWeight[0] + uColorParams[3] * colorWeight[1] + uColorParams[6] * colorWeight[2];
    color.g = uColorParams[1] * colorWeight[0] + uColorParams[4] * colorWeight[1] + uColorParams[7] * colorWeight[2];
    color.b = uColorParams[2] * colorWeight[0] + uColorParams[5] * colorWeight[1] + uColorParams[8] * colorWeight[2];
    color.a = 0.8;
    
    gl_Position = modelViewProjectionMatrix * vec4(p2.x, p2.y, 0, 1.0);
    // gl_Position = modelViewProjectionMatrix * vec4(position.xyz, 1.0);
    
}
