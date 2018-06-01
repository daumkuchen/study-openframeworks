#version 120

uniform sampler2DRect tex0; // ソースのテクスチャ
uniform float difference; // 閾値
uniform vec3 chromaKeyColor; // キーの色
varying vec2 texCoordVarying;

void main() {
    
    // テクスチャーの色を取得
    vec4 texel0 = texture2DRect(tex0, texCoordVarying);
    
    // キーの色との差分を計算
    float diff = length(chromaKeyColor - texel0.rgb);
    
    if(diff < difference){
        // もしキーの色より差分が少なかったら描画しない
        discard;
        
        // gl_FragColor = vec4(vec3(1.0, 0.0, 1.0), 1.0);
    } else {
        // キーの色より差分が多かったら、そのまま描画
        gl_FragColor = texel0;
    }
}
