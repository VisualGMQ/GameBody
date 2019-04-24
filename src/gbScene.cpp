#include "gbScene.hpp"

gbScene::gbScene(){
    init();
}

void gbScene::changeToNextScene(string key){
   GameBody* director = DirectorSiglton::getInstance(); 
    director->setScene(key);
}