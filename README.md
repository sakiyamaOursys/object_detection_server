object_detection_server
=======================

物体検出をするサーバープログラム

object_detection_vagrantから呼び出される
OpenCVのcv::CascadeClassifierクラスを実行して物体検出するシステム

フォルダ構成
api_obj_detection.php  クライアント側から呼び出され、画像認識プログラムの実行ファイルを呼び出すapi
|
haarcascades 学習データを保存するフォルダ。object_detection_vagrantから呼び出されるとここにOpenCVの学習データがコピーされる
|
index.html クライアント側のファイル。jQueryのajaxを使い画像を転送し、OpenCVjsを使って矩形を描画する
|
LICENSE ライセンスファイル
|
object_detection_main OpenCVを利用した画像認識プログラムとそのビルドファイルがあるフォルダ
|
--build_cppfile.sh ビルドを行うシェルスクリプト。実行後はbuildフォルダが生成されその直下に実行ファイルが生成される
|
--CMakeLists.txt OpenCVのライブラリを関連付けてcppファイルをビルドするためのmakeファイルを生成するファイル
|
--obj_detection.cpp OpenCVを用いた画像認識のプログラム
