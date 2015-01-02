#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"


/**
 * 定数定義
 */
const int RTN_ERROR = 1; //エラー戻り値
const int RTN_SUCCESS = 0;//成功戻り値

const int READ_GRAY_SCALE = 0; //画像読み込みモードをグレースケールにする
const int READ_COLOR = 1;//画像読み込みモードをカラーにする

const int NUMBER_OF_PARAMS = 3; //入力値の個数

//サポートされている画像拡張子
const std::array<std::string, 4> SUPPORT_IMG_EXTENTIONS =
{
    "jpg",
    "jpeg",
    "bmp",
    "png"
};


/**
 *  入力値の個数チェック
 *
 *  @param argc argv配列の個数
 *  @param argv 入力値の配列
 *
 *  @return RTN_SUCCESS/RTN_ERROR
 */
int inputValidation(int argc, char *argv[]){
    //入力値の数を確認
    if(argc < NUMBER_OF_PARAMS){
        std::cout << "引数が足りてません" << std::endl;
        for (int i = 0; i < argc; i++) {
            std::cout << "arg[" << i << "] = " << argv[i] << std::endl;
        }
        return RTN_ERROR;
    }
    
    return RTN_SUCCESS;
}

/**
 *  画像拡張子のチェック
 *
 *  @param imgFileName 画像のファイル名
 *
 *  @return RTN_SUCCESS/RTN_ERROR
 */
int imgFileExtentionValidation(const std::string & imgFileName){
    bool isSupport = false;
    for(auto imgExtention : SUPPORT_IMG_EXTENTIONS){
        auto loc = imgFileName.find(imgExtention, 0);
        if( loc != std::string::npos ){
            isSupport = true;
            break;
        }
    }
    
    if(!isSupport){
        std::cout << imgFileName << " はサポートされていないファイル形式です" << std::endl;
        std::cout << "サポートされているファイル形式" << std::endl;
        for(auto imgExtention : SUPPORT_IMG_EXTENTIONS){
            std::cout << imgExtention << std::endl;
        }
    }
    return RTN_SUCCESS;
}

/**
 *  学習データの拡張子チェック
 *
 *  @param cascadeFileNameFullPath 学習データのファイル名
 *
 *  @return RTN_SUCCESS/RTN_ERROR
 */
int cascadeFileExtentionValidation(const std::string & cascadeFileNameFullPath){
    if( cascadeFileNameFullPath.find(".xml", 0) == std::string::npos ){
        std::cout << cascadeFileNameFullPath << " はサポートされていないファイル形式です" << std::endl;
        return RTN_ERROR;
    }
    return RTN_SUCCESS;
}


/**
 *  メインメソッド
 * 
 * 使い方
 * ./obj_detection 画像ファイル名 カスケードファイル名
 *
 * 標準出力
 * 検出した物体の座標と大きさをjson形式で出力する
 * (0, 0)に縦100 横100の大きさの物体を検出した場合は以下
 * [x:0 y:0 width:100 height:100]
 *
 *  @return RTN_SUCCESS/RTN_ERROR
 *
 */
int main(int argc, char* argv[]){
    
    //入力値のチェック
    if(RTN_SUCCESS != inputValidation(argc, argv) ||
    RTN_SUCCESS != imgFileExtentionValidation(argv[1]) ||
    RTN_SUCCESS != cascadeFileExtentionValidation(argv[2])){
        std::cout << "xml_detection imgFilePath xmlFilePath" << std::endl;
        return RTN_ERROR;
    }
    
    std::string imgFileNameFullPath = argv[1];
    std::string cascadeFileNameFullPath = argv[2];
   
    //画像の読み込み
    cv::Mat img = cv::imread(imgFileNameFullPath, READ_GRAY_SCALE);
    
    if(img.empty()){
        std::cout << imgFileNameFullPath << "は読み込めませんでした" << std::endl;
        return RTN_ERROR;
    }
    
    //学習データの読み込み
    cv::CascadeClassifier cascade;
     if( !cascade.load( cascadeFileNameFullPath ) ){
         std::cout << cascadeFileNameFullPath << "が読み込めませんでした" << std::endl;
         return RTN_ERROR;
     }
    
    //物体検出
    std::vector<cv::Rect> detections;
    cascade.detectMultiScale(img, detections, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30) );

    //json形式に変換
    std::cout << "[";
    for(unsigned int i = 0 ; i < detections.size() ; i++){
        auto detection = detections.at(i);
        std::cout << "{\"x\":" << detection.x << ",\"y\":" << detection.y << ",\"width\":" << detection.width << ",\"height\":" << detection.height << "}" ;
        if(i != detections.size() - 1)std::cout << ",";
    }
    std::cout << "]" << std::endl;
	
	return RTN_SUCCESS;
}
