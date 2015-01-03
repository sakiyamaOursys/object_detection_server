物体検出サーバー
=======================

object_detection_vagrantから呼び出される<br/>
OpenCVのcv::CascadeClassifierクラスを実行して物体検出するシステム
  
<h2>フォルダ構成</h2>

api_obj_detection.php<br/>
クライアント側から呼び出され、画像認識プログラムの実行ファイルを呼び出すapi<br/>
<br/>
haarcascades<br/>
学習データを保存するフォルダ。object_detection_vagrantから呼び出されるとここにOpenCVの学習データがコピーされる<br/>
<br/>
index.html<br/>
クライアント側のファイル。jQueryのajaxを使い画像を転送し、OpenCVjsを使って矩形を描画する<br/>
<br/>
LICENSE<br/>
ライセンスファイル<br/>
<br/>
object_detection_main<br/>
| OpenCVを利用した画像認識プログラムとそのビルドファイルがあるフォルダ<br/>
|<br/>
|--build_cppfile.sh<br/>
|  ビルドを行うシェルスクリプト。実行後はbuildフォルダが生成されその直下に実行ファイルが生成される<br/>
|<br/>
|--CMakeLists.txt<br/>
|  OpenCVのライブラリを関連付けてcppファイルをビルドするためのmakeファイルを生成するファイル<br/>
|<br/>
|--obj_detection.cpp<br/>
   OpenCVを用いた画像認識のプログラム<br/>
