#include "ShowImage.h"

void ShowImage::draw(){
    
    // before
    // image.draw(x, y, size, size);
    
    // after
    // 参照元のデータを使用する場合、アロー演算子に変更
    image->draw(x, y, size, size);
    
}
